#ifndef DNSTP_Sampler
#define DNSTP_Sampler

#include <vector>

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

    public:
        // Constructor. Pass in the number of particles
        Sampler(size_t num_particles);

};

} // namespace DNSTP

#include "SamplerImpl.h"

#endif

