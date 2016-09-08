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
    sampler.do_mcmc_steps(1000);

    return 0;
}

