#include "BackgroundPoints.h"
#include "DNSTP.h"

namespace DNSTP
{

BackgroundPoints::BackgroundPoints()
{

}

size_t BackgroundPoints::corner_count
            (const std::vector<double>& objective_functions) const
{
    size_t count = 0;

    for(size_t i=0; i<points.size(); ++i)
    {
        if(is_above(points[i], objective_functions))
            ++count;
    }

    return count;
}

void BackgroundPoints::add_point(const std::vector<double>& point)
{
    points.push_back(point);
}

} // namespace DNSTP

