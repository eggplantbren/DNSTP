namespace DNSTP
{

// Constructor: Pass in Options object
template<class ModelType>
Sampler<ModelType>::Sampler(DNest4::Sampler<ModelType>&& sampler)
:dnest4_sampler(sampler)
{

}

} // namespace DNSTP

