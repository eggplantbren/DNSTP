#include "MyModel.h"
#include "DNest4/code/DNest4.h"
#include <sstream>
#include <iomanip>

namespace DNSTP
{

MyModel::MyModel()
:params(num_dimensions)
{
}

void MyModel::from_prior(DNest4::RNG& rng)
{
    for(double& x: params)
        x = rng.rand();
}

double MyModel::perturb(DNest4::RNG& rng)
{
	double logH = 0.0;

    int reps = 1;
    if(rng.rand() <= 0.5)
        reps = static_cast<int>(pow(10.0, 2*rng.rand()));

    int which;
    for(int i=0; i<reps; ++i)
    {
        which = rng.rand_int(num_dimensions);
        params[which] += rng.randh();
        DNest4::wrap(params[which], 0.0, 1.0);
    }

	return logH;
}

double MyModel::log_likelihood() const
{
	double logL = 0.;
	return logL;
}

void MyModel::print(std::ostream& out) const
{
    out<<std::setprecision(10);
    for(double x: params)
        out<<x<<' ';
}

std::string MyModel::description() const
{
    std::stringstream s;
    for(size_t i=0; i<num_dimensions; ++i)
    {
        s<<"params["<<i<<']';
        if(i != (num_dimensions - 1))
            s<<", ";
    }
	return s.str();
}

} // namespace DNSTP

