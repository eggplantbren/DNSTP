#ifndef DNSTP_Sampler
#define DNSTP_Sampler

#include "DNest4/code/Sampler.h"

namespace DNSTP
{

template<class ModelType>
class Sampler: public DNest4::Sampler<ModelType>
{
    private:
        // Background points
        BackgroundPoints background;

    public:
        // These constructors call their DNest4::Sampler
        // counterparts.
        Sampler();
        Sampler(unsigned int num_threads, double compression,
                           const DNest4::Options& options);
        Sampler(unsigned int num_threads, double compression,
                           const DNest4::Options& options, bool save_to_disk);
};

} // namespace DNSTP

#include "SamplerImpl.h"

#endif

