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

} // namespace DNSTP

