#include <iostream>
#include "DNest4/code/DNest4.h"
#include "MyModel.h"
#include "Sampler.h"

int main(int argc, char** argv)
{
    // Create the DNSTP sampler
    DNSTP::Sampler<DNSTP::MyModel> sampler
                    (DNest4::setup<DNSTP::MyModel>(argc, argv));

	return 0;
}

