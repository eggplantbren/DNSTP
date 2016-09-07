#include <iostream>
#include "DNest4/code/DNest4.h"
#include "MyModel.h"
#include "Sampler.h"

int main(int argc, char** argv)
{
    DNest4::CommandLineOptions options(argc, argv);

    std::cout<<"# Using "<<options.get_num_threads()<<" thread"<<
    ((options.get_num_threads() == 1)?("."):("s."))<<std::endl;

    std::cout<<"# Target compression factor between levels = ";
    std::cout<<options.get_compression()<<std::endl;

    // Load sampler options from file
    DNest4::Options sampler_options(options.get_options_file().c_str());

    // Create sampler
    DNSTP::Sampler<DNSTP::MyModel> sampler(options.get_num_threads(),
                                options.get_compression_double(),
                                sampler_options,
                                true);

    // Seed RNGs
    sampler.initialise(options.get_seed_uint());

    // Run the sampler
    sampler.run();

    return 0;
}

