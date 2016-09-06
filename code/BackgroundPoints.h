#ifndef DNSTP_BackgroundPoints
#define DNSTP_BackgroundPoints

#include <vector>

namespace DNSTP
{

/*
* Stores points in the objective function space (i.e. (l1, l2) pairs)
* that are used to approximate -Phi[X(l1, l2)].
*/
class BackgroundPoints
{
    private:
        std::vector<double> points;
        std::vector<double> weights;

    public:
        BackgroundPoints();



};

} // namespace DNSTP

#endif

