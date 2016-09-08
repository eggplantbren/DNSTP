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
        // 3D array. First dimension indexes 'stage',
        // then for each stage there is a set of points.
        std::vector<std::vector<std::vector<double>>> points;

        // Keep track of median corner count at each stage.
        std::vector<double> median_corner_counts;

    public:
        // Initialises everything empty
        BackgroundPoints();

        // Evaluate something we can use (eventually)
        // to create an approximation to log[X(l1, l2)]
        size_t corner_count(unsigned int stage,
                        const std::vector<double>& objective_functions) const;

        // Evaluate goodness of a point, using all the background points.
        double goodness(unsigned int stage,
                        const std::vector<double>& objective_functions) const;

        // Add a point
        void add_point(unsigned int stage, const std::vector<double>& point);
};

} // namespace DNSTP

#endif

