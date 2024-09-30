#pragma once
#include <functional>

double simpson_rule(const std::function<double(double)>& f, double alpha, double beta);

double integrate(const std::function<double(double)>& f, double alpha, double beta,
                 double tolerance);
