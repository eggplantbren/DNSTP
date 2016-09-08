#include <iostream>
#include <stdexcept>

namespace DNSTP
{

// Constructors
template<class ModelType>
Sampler<ModelType>::Sampler(size_t num_particles, unsigned int rng_seed)
:particles(num_particles)
,rng(rng_seed)
{
    if(num_particles == 0)
        throw std::domain_error("Can't create sampler with 0 particles.");
}

// Generate all particles from the prior.
template<class ModelType>
void Sampler<ModelType>::initialise()
{
    for(auto& p: particles)
        p.from_prior(rng);
}

// Do some MCMC steps.
template<class ModelType>
void Sampler<ModelType>::do_mcmc_steps(unsigned int num_steps)
{
    static constexpr unsigned int thin = 10;

    // Vector of vectors to store objective function values
    // observed as we do the exploration.
    std::vector<std::vector<double>> keep(num_steps/thin,
                std::vector<double>(ModelType::num_objective_functions));

    double logH;
    int which;

    for(unsigned int i=0; i<num_steps; ++i)
    {
        which = rng.rand_int(particles.size());

        ModelType proposal = particles[which];
        logH = proposal.perturb(rng);

        if(rng.rand() <= exp(logH))
        {
            particles[which] = proposal;
        }

        if(i%thin == 0)
            keep[i/thin] = particles[which].objective_functions();
    }

    // Put objective function values into the background
    for(size_t i=0; i<keep.size(); ++i)
        background.add_point(1, keep[i]);

    // Print objective function values to the screen, then exit.
    std::cout<<std::setprecision(12);
    for(size_t i=0; i<keep.size(); ++i)
    {
        for(size_t j=0; j<keep[i].size(); ++j)
            std::cout<<keep[i][j]<<' ';
        std::cout<<std::endl;
    }
    exit(0);
}

} // namespace DNSTP

