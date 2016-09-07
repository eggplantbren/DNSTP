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
    if(!enough_levels(levels) &&
        (all_above.size() >= options.new_level_interval))
    {
        // Create the level
        std::sort(all_above.begin(), all_above.end());
        int index = static_cast<int>((1. - 1./compression)*all_above.size());
        std::cout<<"# Creating level "<<levels.size()<<" with log likelihood = ";
        std::cout<<std::setprecision(12);
        std::cout<<all_above[index].get_value()<<"."<<std::endl;

        levels.push_back(Level(all_above[index]));
        all_above.erase(all_above.begin(), all_above.begin() + index + 1);
        for(auto& a:above)
            a.clear();

        // If last level
        if(enough_levels(levels))
        {
            DNest4::Level::renormalise_visits(levels,
                static_cast<int>(0.1*options.new_level_interval));
            all_above.clear();
            options.max_num_levels = levels.size();
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
    DNest4::Level::recalculate_log_X(levels, compression,
                                                options.new_level_interval);

    // Save levels if one was created
    if(created_level)
        this->save_levels();

    if(count_mcmc_steps_since_save >= options.save_interval)
    {
        this->save_particle();

        // If a level was not created, save anyway because of the time
        if(!created_level)
            this->save_levels();
    }
}



} // namespace DNSTP

