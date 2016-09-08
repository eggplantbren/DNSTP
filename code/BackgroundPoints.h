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
        // A collection of background points.
        std::vector<std::vector<double>> points;

    public:
        // Initialises everything empty
        BackgroundPoints();

        // Evaluate something we can use (eventually)
        // to create an approximation to log[X(l1, l2)]
        size_t corner_count
                       (const std::vector<double>& objective_functions) const;

        // Add a point
        void add_point(const std::vector<double>& point);
};

} // namespace DNSTP

#endif

