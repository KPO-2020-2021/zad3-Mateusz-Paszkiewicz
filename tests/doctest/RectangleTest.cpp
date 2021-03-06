#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/matrix.hh"
#include "../include/rectangle.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("Rectangle Class parametrical Contructor Test")
{
  double sample[4][2]={{-10,10},{10,10},{10,-10},{-10,-10}};
  Rectangle test=Rectangle(sample);

  CHECK(test.rect[0][0] == -10);
  CHECK(test.rect[0][1] == 10);
  CHECK(test.rect[1][0] == 10);
  CHECK(test.rect[1][1] == 10);
  CHECK(test.rect[2][0] == 10);
  CHECK(test.rect[2][1] == -10);
  CHECK(test.rect[3][0] == -10);
  CHECK(test.rect[3][1] == -10);
}

TEST_CASE("Rectangle Class non-parametrical Contructor Test")
{
  Rectangle test=Rectangle();

  CHECK(test.rect[0][0] == 0);
  CHECK(test.rect[0][1] == 0);
  CHECK(test.rect[1][0] == 0);
  CHECK(test.rect[1][1] == 0);
  CHECK(test.rect[2][0] == 0);
  CHECK(test.rect[2][1] == 0);
  CHECK(test.rect[3][0] == 0);
  CHECK(test.rect[3][1] == 0);
}

TEST_CASE("Vector Translation for Rectangle class Test")
{
  double sample[4][2]={{-10,10},{10,10},{10,-10},{-10,-10}};
  Rectangle test=Rectangle(sample);

  double sample2[SIZE]={10,-10};
  Vector Vec=Vector(sample2);

  test=test+Vec;

  CHECK(test.rect[0][0] == 0);
  CHECK(test.rect[0][1] == 0);
  CHECK(test.rect[1][0] == 20);
  CHECK(test.rect[1][1] == 0);
  CHECK(test.rect[2][0] == 20);
  CHECK(test.rect[2][1] == -20);
  CHECK(test.rect[3][0] == 0);
  CHECK(test.rect[3][1] == -20);
}

TEST_CASE("Angle Translation for Rectangle class Test")
{
  double sample[4][2]={{-10,10},{10,10},{10,-10},{-10,-10}};
  Rectangle test=Rectangle(sample);

  double Angle=90;

  test.AngleTrans(Angle*M_PI/180);

  CHECK(test.rect[0][0] == -10);
  CHECK(test.rect[0][1] == -10);
  CHECK(test.rect[1][0] == -10);
  CHECK(test.rect[1][1] == 10);
  CHECK(test.rect[2][0] == 10);
  CHECK(test.rect[2][1] == 10);
  CHECK(test.rect[3][0] == 10);
  CHECK(test.rect[3][1] == -10);

  Angle=45;

  test.AngleTrans(Angle*M_PI/180);

  std::cout<<test.rect[0][0]<<std::endl;
  std::cout<<test.rect[0][1]<<std::endl;

  CHECK(abs(test.rect[0][0]- 0) < 0.00001 );
  CHECK(abs(test.rect[0][1]+ 14.14213562373) < 0.00001 );
  CHECK(abs(test.rect[1][0]+ 14.14213562373) < 0.00001 );
  CHECK(abs(test.rect[1][1]- 0) < 0.00001 );
  CHECK(abs(test.rect[2][0]- 0) < 0.00001 );
  CHECK(abs(test.rect[2][1]- 14.14213562373) < 0.00001 );
  CHECK(abs(test.rect[3][0]- 14.14213562373) < 0.00001 );
  CHECK(abs(test.rect[3][1]- 0) < 0.00001 );
}

TEST_CASE("Angle Translation for Rectangle class Test")
{
  std::string expected = "-10 10 10 10 10 -10 -10 -10 -10 10";
  std::stringstream buffer, tmp;
  std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

  double sample[4][2]={{-10,10},{10,10},{10,-10},{-10,-10}};
  Rectangle test=Rectangle(sample);

  tmp << "-10 10 10 10 10 -10 -10 -10 -10 10";
  tmp >> test;

  std::cout << test;
  std::string text = tmp.str();
  std::cout.rdbuf(prevcoutbuf);

  CHECK(text == expected);
}
