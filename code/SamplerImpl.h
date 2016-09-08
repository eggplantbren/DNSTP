#include <iostream>
#include <stdexcept>

namespace DNSTP
{

// Constructors
template<class ModelType>
Sampler<ModelType>::Sampler(size_t num_particles, unsigned int rng_seed)
:particles(num_particles)
,corner_counts(num_particles, 0)
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

    // Declare some shit
    double logH, logA; int which; size_t proposal_corner_count;

    for(unsigned int i=0; i<num_steps; ++i)
    {
        // Choose a particle to perturb
        which = rng.rand_int(particles.size());

        // Perturb it
        ModelType proposal = particles[which];
        logH = proposal.perturb(rng);

        // Evaluate corner count of the proposal
        proposal_corner_count = background.corner_count
                                        (proposal.objective_functions());

        // Calculate acceptance probability
        logA = logH - proposal_corner_count + corner_counts[which];

        if(logA > 0.0)
            logA = 0.0;

        if(rng.rand() <= exp(logA))
        {
            // Acceptance
            particles[which] = proposal;
            corner_counts[which] = proposal_corner_count;
        }

        if(i%thin == 0)
            keep[i/thin] = particles[which].objective_functions();
    }

    // Put objective function values into the background
    for(size_t i=0; i<keep.size(); ++i)
    {
        background.add_point(keep[i]);
        for(size_t j=0; j<keep[i].size(); ++j)
            std::cout<<keep[i][j]<<' ';
        std::cout<<std::endl;
    }

    // Recalculate particle corner counts
    for(size_t i=0; i<particles.size(); ++i)
    {
        corner_counts[i] = background.corner_count
                                    (particles[i].objective_functions());
    }
}

} // namespace DNSTP

