#include "matrix4f.h"
#include "vector4f.h"

Matrix4f::Matrix4f():
  m00(0), m01(0), m02(0), m03(0),
  m10(0), m11(0), m12(0), m13(0),
  m20(0), m21(0), m22(0), m23(0),
  m30(0), m31(0), m32(0), m33(0) {}

Matrix4f::Matrix4f(Vector4f row1, Vector4f row2, Vector4f row3, Vector4f row4) {
  m00 = row1.x(); m01 = row1.y(); m02 = row1.z(); m03 = row1.w();
  m10 = row2.x(); m11 = row2.y(); m12 = row2.z(); m13 = row2.w();
  m20 = row3.x(); m21 = row3.y(); m22 = row3.z(); m23 = row3.w();
  m30 = row4.x(); m31 = row4.y(); m32 = row4.z(); m33 = row4.w();
}