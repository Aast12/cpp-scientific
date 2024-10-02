#include "../src/integration.hpp"
#include <stdexcept>
#include "utest.h"

UTEST(Integration, TestIntegrate) {
  auto f = [](double x) { return x; };
  double result = integrate(f, 0.0, 1.0, 1e-2);

  ASSERT_NEAR(result, 0.5, 1e-2);
}

UTEST(Integration, TestNegativeTolerance) {
  auto f = [](double x) { return x; };

  ASSERT_EXCEPTION(integrate(f, 0.0, 1.0, -1e-2), std::domain_error);
}

UTEST(Integration, TestZeroTolerance) {
  auto f = [](double x) { return x; };

  ASSERT_EXCEPTION(integrate(f, 0.0, 1.0, -0.0), std::domain_error);
}

// Main function to run all tests
UTEST_MAIN();