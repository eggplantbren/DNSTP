#include <iostream>

namespace DNSTP
{

// Constructors
template<class ModelType>
Sampler<ModelType>::Sampler()
:DNest4::Sampler<ModelType>()
{

}

template<class ModelType>
Sampler<ModelType>::Sampler(unsigned int num_threads, double compression,
                                const DNest4::Options& options)
:DNest4::Sampler<ModelType>(num_threads, compression, options)
{

}

template<class ModelType>
Sampler<ModelType>::Sampler(unsigned int num_threads, double compression,
                           const DNest4::Options& options, bool save_to_disk)
:DNest4::Sampler<ModelType>(num_threads, compression, options, save_to_disk)
{

}

template<class ModelType>
void Sampler<ModelType>::do_bookkeeping()
{
    bool created_level = false;

    // Create a new level?
    if(!this->enough_levels(this->levels) &&
        (this->all_above.size() >= this->options.new_level_interval))
    {
        // Create the level
        std::sort(this->all_above.begin(), this->all_above.end());
        int index = static_cast<int>
                        ((1. - 1./this->compression)*this->all_above.size());
        std::cout<<"# Creating level "<<this->levels.size()
                                <<" with log likelihood = ";
        std::cout<<std::setprecision(12);
        std::cout<<this->all_above[index].get_value()<<"."<<std::endl;

        this->levels.push_back(DNest4::Level(this->all_above[index]));
        this->all_above.erase(this->all_above.begin(),
                    this->all_above.begin() + index + 1);
        for(auto& a:this->above)
            a.clear();

        // If last level
        if(this->enough_levels(this->levels))
        {
            DNest4::Level::renormalise_visits(this->levels,
                static_cast<int>(0.1*this->options.new_level_interval));
            this->all_above.clear();
            this->options.max_num_levels = this->levels.size();
            std::cout<<"# Done creating levels."<<std::endl;
        }
        else
        {
            // If it's not the last level, look for lagging particles
            this->kill_lagging_particles();
        }

        created_level = true;
    }

    // Recalculate log_X values of levels
    DNest4::Level::recalculate_log_X(this->levels, this->compression,
                                     this->options.new_level_interval);

    // Save levels if one was created
    if(created_level)
        this->save_levels();

    if(this->count_mcmc_steps_since_save >= this->options.save_interval)
    {
        this->save_particle();

        // If a level was not created, save anyway because of the time
        if(!created_level)
            this->save_levels();
    }
}



} // namespace DNSTP

