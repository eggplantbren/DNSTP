#ifndef DNSTP_MyModel
#define DNSTP_MyModel

#include "DNest4/code/DNest4.h"
#include <ostream>

namespace DNSTP
{

class MyModel
{
    public:
        // How many objective functions are there in this problem?
        static constexpr size_t num_objective_functions = 2;

    private:
        // Dimensionality of the example
        static constexpr size_t num_dimensions = 100;

        // The parameters
        std::vector<double> params;

    public:
        // Constructor only gives size of params
        MyModel();

        // Generate the point from the prior
        void from_prior(DNest4::RNG& rng);

        // Metropolis-Hastings proposals
        double perturb(DNest4::RNG& rng);

        // Return the two objective functions
        std::vector<double> objective_functions() const;

        // "Likelihood function" that DNest4 uses
        // We want this to be proportional to -Phi[X(l1, l2)]
        double log_likelihood() const;

        // Print to stream
        void print(std::ostream& out) const;

        // Return string with column information
        std::string description() const;
};

} // namespace DNSTP

#endif

