#include "BackgroundPoints.h"

namespace DNSTP
{

BackgroundPoints::BackgroundPoints()
{
}

double BackgroundPoints::approximate_log_X
                    (const std::vector<double>& objective_functions) const
{
    if(points.size() == 0)
    {
        return 0.0;
    }

    return 0.0;
}

} // namespace DNSTP

