#include "../include/matrix.hh"
#include "../include/rectangle.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Matrix non-parametric Constructor test")
{
  Matrix<int, 2> mat=Matrix<int, 2>();

  CHECK(mat.value[0][0] == 0);
  CHECK(mat.value[0][1] == 0);
  CHECK(mat.value[1][0] == 0);
  CHECK(mat.value[1][1] == 0);
}

TEST_CASE("Matrix parametric Constructor test")
{
  double sample[2][2]={{1,2},{3,4}};
  Matrix<double, 2> mat=Matrix<double, 2>(sample);

  CHECK(mat.value[0][0] == 1);
  CHECK(mat.value[0][1] == 2);
  CHECK(mat.value[1][0] == 3);
  CHECK(mat.value[1][1] == 4);
}

TEST_CASE("Matrix Angle Translation Constructor test")
{
  double Translation[2][2]={{cos(0),-1*sin(0)},{sin(0),cos(0)}};
  Matrix<double, 2> mat=Matrix<double, 2>(Translation);

  CHECK(mat.value[0][0] == 1);
  CHECK(mat.value[0][1] == 0);
  CHECK(mat.value[1][0] == 0);
  CHECK(mat.value[1][1] == 1);
}

TEST_CASE("Matrix and vector multiplication test")
{
  double sample[2][2]={{1,2},{3,4}};
  Matrix<double, 2> mat=Matrix(sample);

  double sample2[2]={1,5};
  Vector vec=Vector(sample2);

  vec=mat*vec;

  CHECK(vec.size[0] == 11);
  CHECK(vec.size[1] == 23);
}

TEST_CASE("Matrix determinant evaluation with Gauss method test")
{
  double sample[3][3]={{1,2,3},{4,5,6},{7,8,10}};
  Matrix<double, 3> mat=Matrix<double, 3>(sample);

  double val;

  val=GaussMethod(mat);

  CHECK(val == -3);

}
