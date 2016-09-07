#include <iostream>

namespace DNSTP
{

// Constructors
template<class ModelType>
Sampler<ModelType>::Sampler(size_t num_particles, unsigned int rng_seed)
:particles(num_particles)
,rng(rng_seed)
{

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
    double logH;
    int which;

    for(unsigned int i=0; i<num_steps; ++i)
    {
        which = rng.rand_int(particles.size());

        ModelType proposal = particles[which];
        logH = proposal.perturb();

        if(rng.rand() <= exp(logH))
        {
            particles[which] = proposal;
        }
    }
}

} // namespace DNSTP

