#ifndef DNSTP_Sampler
#define DNSTP_Sampler

#include <vector>
#include "DNest4/code/RNG.h"

namespace DNSTP
{

/*
* An instance of this class is a DNSTP sampler.
* Not parallel for now - just want to get a working algorithm.
*/

template<class ModelType>
class Sampler
{
    private:
        // The particles
        std::vector<ModelType> particles;

        // Background points
        BackgroundPoints background;

        // Random number generator to use
        DNest4::RNG rng;

    public:
        // Constructor. Pass in the number of particles
        // and an RNG seed (defaults to zero).
        Sampler(size_t num_particles, unsigned int rng_seed=0);
};

} // namespace DNSTP

#include "SamplerImpl.h"

#endif

