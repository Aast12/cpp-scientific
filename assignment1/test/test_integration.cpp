#include "../src/integration.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(Integration, TestIntegrate) {
  auto f = [](double x) { return x; };
  double result = integrate(f, 0.0, 1.0, 1e-2);

  EXPECT_NEAR(result, 0.5, 1e-2);
}

TEST(Integration, TestNegativeTolerance) {
  auto f = [](double x) { return x; };

  EXPECT_THROW(integrate(f, 0.0, 1.0, -1e-2), std::domain_error);
}

TEST(Integration, TestZeroTolerance) {
  auto f = [](double x) { return x; };

  EXPECT_THROW(integrate(f, 0.0, 1.0, 0.0), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
