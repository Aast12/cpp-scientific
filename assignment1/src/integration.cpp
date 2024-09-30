#include "integration.hpp"
#include <cmath>
#include <stdexcept>

double simpson_rule(const std::function<double(double)>& f, double alpha,
                    double beta) {
  const double midpoint = (alpha + beta) / 2;
  return (beta - alpha) / 6 * (f(alpha) + 4 * f(midpoint) + f(beta));
}

double integrate(const std::function<double(double)> &f, double alpha, double beta, double tolerance) {
  if (tolerance <= 0.0)
    throw std::domain_error("Integration tolerance must be positive");

  const double midpoint = (alpha + beta) / 2;
  const double upper_bound = simpson_rule(f, alpha, beta);
  const double lower_bound =
      simpson_rule(f, alpha, midpoint) + simpson_rule(f, midpoint, beta);

  const double error = std::fabs(upper_bound - lower_bound);
  if (error < 15 * tolerance) {
    return lower_bound;
  }
  return integrate(f, alpha, midpoint, tolerance / 2.0) +
         integrate(f, midpoint, beta, tolerance / 2.0);
}
