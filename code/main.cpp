#include <iostream>
#include <ctime>

#include "MyModel.h"
#include "Sampler.h"

int main()
{
    // Create sampler
    DNSTP::Sampler<DNSTP::MyModel> sampler(1, time(0));

    // Initialise the sampler
    sampler.initialise();

    // Do some MCMC steps.
    for(int i=0; i<100; ++i)
        sampler.do_mcmc_steps(1000);

    return 0;
}

