#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/matrix.hh"
#include "../include/rectangle.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("Vector parametrical constructor")
{
  double sample[SIZE]={2,3};
  Vector vec=Vector(sample);

  CHECK(vec[1] == 2);
  CHECK(vec[2] == 3);
}

TEST_CASE("Vector non-parametrical constructor")
{
  Vector vec=Vector();

  CHECK(vec[0] == 0);
  CHECK(vec[1] == 0);
}
