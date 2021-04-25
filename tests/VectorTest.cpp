#include "../include/matrix.hh"
#include "../include/rectangle.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Vector parametrical constructor")
{
  double sample[SIZE]={2,3};
  Vector vec=Vector(sample);

  CHECK(vec[0] == 2);
  CHECK(vec[1] == 3);
}

TEST_CASE("Vector non-parametric constructor")
{
  Vector vec=Vector();

  CHECK(vec.size[0] == 0);
  CHECK(vec.size[1] == 0);
}

TEST_CASE("<< for Vector class Test")
{
  std::string expected = "[1] [2]";
  std::stringstream buffer, tmp;
  std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

  Vector vec=Vector();

  tmp << "[1] [2]";
  tmp >> vec;
  tmp << vec;

  std::cout << vec;
  std::string text = tmp.str();
  std::cout.rdbuf(prevcoutbuf);

  CHECK(text == expected);
}

TEST_CASE("Vector addition and subtraction test")
{
  double sample1[SIZE]={5,10};
  Vector vec1=Vector(sample1);

  double sample2[SIZE]={3,2};
  Vector vec2=Vector(sample2);

  vec1=vec1-vec2;

  CHECK(vec1.size[0] == 2);
  CHECK(vec1.size[1] == 8);

  vec1=vec1+vec2;

  CHECK(vec1.size[0] == 5);
  CHECK(vec1.size[1] == 10);
}

TEST_CASE("Vector == operator test")
{
  double sample1[SIZE]={5,10};
  Vector vec1=Vector(sample1);

  double sample2[SIZE]={5,10};
  Vector vec2=Vector(sample2);

  CHECK(vec1 == vec2);

}
