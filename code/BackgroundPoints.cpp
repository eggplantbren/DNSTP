#include "BackgroundPoints.h"
#include "DNSTP.h"
#include <stdexcept>

namespace DNSTP
{

BackgroundPoints::BackgroundPoints()
{

}

size_t BackgroundPoints::corner_count(unsigned int stage,
                        const std::vector<double>& objective_functions) const
{
    if(stage >= points.size())
        throw std::domain_error("stage too high in corner_count.");

    size_t count = 0;

    for(size_t i=0; i<points[stage].size(); ++i)
    {
        if(is_above(points[stage][i], objective_functions))
            ++count;
    }

    return count;
}

void BackgroundPoints::add_point
                    (unsigned int stage, const std::vector<double>& point)
{
    if(stage > points.size())
        throw std::domain_error("stage too high in add_point.");
    else if(stage == points.size())
        points.push_back(std::vector<std::vector<double>>());        
    points[stage].push_back(point);
}

// Evaluate goodness of a point, using all the background points.
double BackgroundPoints::goodness(unsigned int stage,
                          const std::vector<double>& objective_functions) const
{
    double result = 0.0;

    for(size_t i=0; 
}

} // namespace DNSTP

