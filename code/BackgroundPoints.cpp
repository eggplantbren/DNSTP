#include "BackgroundPoints.h"
#include "DNSTP.h"
#include <stdexcept>

namespace DNSTP
{

BackgroundPoints::BackgroundPoints()
{

}

size_t BackgroundPoints::corner_count(unsigned int which_stage,
                        const std::vector<double>& objective_functions) const
{
    if(which_stage >= points.size())
        throw std::domain_error("which_stage too high.");

    size_t count = 0;

    for(size_t i=0; i<points[which_stage].size(); ++i)
    {
        if(is_above(points[which_stage][i], objective_functions))
            ++count;
    }

    return count;
}

void BackgroundPoints::add_point
                    (unsigned int which_stage, const std::vector<double>& point)
{
    if(which_stage > points.size())
        throw std::domain_error("which_stage too high.");
    else if(which_stage == points.size())
        points.push_back(std::vector<std::vector<double>>());        
    points[which_stage].push_back(point);
}

} // namespace DNSTP

