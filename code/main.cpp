#include <iostream>
#include <ctime>

#include "MyModel.h"
#include "Sampler.h"

int main(int argc, char** argv)
{
    // Create sampler
    DNSTP::Sampler<DNSTP::MyModel> sampler(5, time(0));

    return 0;
}

