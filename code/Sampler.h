#ifndef DNSTP_Sampler
#define DNSTP_Sampler

#include "DNest4/code/Sampler.h"

namespace DNSTP
{

template<class ModelType>
class Sampler: public DNest4::Sampler<ModelType>
{
    private:
        DNest4::Sampler<ModelType> dnest4_sampler;

    public:
        // Constructor. You must create the DNest4 sampler
        // and pass it in.
        Sampler(DNest4::Sampler<ModelType>&& sampler);

};

} // namespace DNSTP

#include "SamplerImpl.h"

#endif

