#include "DNSTP.h"
#include <stdexcept>

namespace DNSTP
{

bool is_above(const std::vector<double>& v1,
                    const std::vector<double>& v2)
{
    if(v1.size() != v2.size())
        throw std::domain_error("Vectors must have the same length.");

    for(size_t i=0; i<v1.size(); ++i)
        if(v1[i] <= v2[i])
            return false;

    return true;
}


} // namespace DNSTP

