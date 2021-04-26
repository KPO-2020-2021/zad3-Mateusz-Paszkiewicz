#include "../include/matrix.hh"
#include "../include/rectangle.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Matrix non-parametric Constructor test")
{
  Matrix mat=Matrix();

  CHECK(mat.value[0][0] == 0);
  CHECK(mat.value[0][1] == 0);
  CHECK(mat.value[1][0] == 0);
  CHECK(mat.value[1][1] == 0);
}

TEST_CASE("Matrix parametric Constructor test")
{
  double sample[SIZE][SIZE]={{1,2},{3,4}};
  Matrix mat=Matrix(sample);

  CHECK(mat.value[0][0] == 1);
  CHECK(mat.value[0][1] == 2);
  CHECK(mat.value[1][0] == 3);
  CHECK(mat.value[1][1] == 4);
}

TEST_CASE("Matrix Angle Translation Constructor test")
{
  double Translation[SIZE][SIZE]={{cos(0),-1*sin(0)},{sin(0),cos(0)}};
  Matrix mat=Matrix(Translation);

  CHECK(mat.value[0][0] == 1);
  CHECK(mat.value[0][1] == 0);
  CHECK(mat.value[1][0] == 0);
  CHECK(mat.value[1][1] == 1);
}

TEST_CASE("Matrix and vector multiplication test")
{
  double sample[SIZE][SIZE]={{1,2},{3,4}};
  Matrix mat=Matrix(sample);

  double sample2[SIZE]={1,5};
  Vector vec=Vector(sample2);

  vec=mat*vec;

  CHECK(vec.size[0] == 11);
  CHECK(vec.size[1] == 23);
}

TEST_CASE("Matrix ()operator  test")
{
  double Translation[SIZE][SIZE]={{cos(0),-1*sin(0)},{sin(0),cos(0)}};
  Matrix mat=Matrix(Translation);

  CHECK(mat(0, 0) == 1);
  CHECK(mat(0, 1) == 0);
  CHECK(mat(1, 0) == 0);
  CHECK(mat(1, 1) == 1);
}

TEST_CASE("Matrix ()operator  test")
{
  double sample[SIZE][SIZE]={{1,2,-1},{2,2,-1},{2,3,1}};
  Matrix mat=Matrix(sample);
  double Augmented[SIZE]={8,10,5};

  std::cout<<mat;


  double x[SIZE];

  GaussMethod(x,mat, Augmented);

  CHECK(abs(x[0]- 2) < 0.00001);
  CHECK(abs(x[1]- 1.4) < 0.00001);
  CHECK(abs(x[2]+ 3.2) < 0.00001);
}
