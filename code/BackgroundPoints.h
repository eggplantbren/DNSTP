#ifndef DNSTP_BackgroundPoints
#define DNSTP_BackgroundPoints

#include <vector>
#include <stdlib.h>

namespace DNSTP
{

/*
* Stores points in the objective function space (i.e. (l1, l2) pairs)
* that are used to approximate -Phi[X(l1, l2)].
*/
class BackgroundPoints
{
    private:
        std::vector<std::vector<double>> points;
        std::vector<size_t> stage;

    public:
        // Initialises everything empty
        BackgroundPoints();

        // Evaluate the approximation to log[X(l1, l2)]
        double approximate_log_X
                        (const std::vector<double>& objective_functions) const;
};

} // namespace DNSTP

#endif

