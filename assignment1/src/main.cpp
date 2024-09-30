#include "integration.hpp"
#include <iostream>
#include <memory>

std::function<double(double)> make_trackable(std::function<double(double)> f,
                                             int *invocations) {
  auto tracked_f = [f, invocations](double x) {
    *invocations += 1;
    return f(x);
  };

  return tracked_f;
}

int main() {
  auto invocations = std::make_unique<int>(0);

  auto f = make_trackable([](double x) { return x + cos(pow(x, 5)); },
                          invocations.get());

  for (double tol : {1e-2, 1e-3, 1e-4, 1e-10, 1e-3}) {
    int acc = *invocations;
    double result = integrate(f, 0, M_PI, tol);
    std::cout << "Invocations: " << (*invocations - acc)
              << " (cumulative: " << *invocations << ")" << std::endl
              << "Result for tolerance: " << tol << " = " << result << std::endl
              << "---" << std::endl;
  }
}
