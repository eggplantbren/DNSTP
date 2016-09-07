#include <iostream>
#include "DNest4/code/DNest4.h"
#include "MyModel.h"
#include "Sampler.h"

int main(int argc, char** argv)
{
    // Create sampler
    DNSTP::Sampler<DNSTP::MyModel> sampler(options.get_num_threads(),
                                options.get_compression_double(),
                                sampler_options,
                                true);

    return 0;
}

