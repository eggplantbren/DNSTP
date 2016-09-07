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

} // namespace DNSTP

