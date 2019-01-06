#include "camera.h"
#include "point3f.h"
#include "vector4f.h"

Camera::Camera(
  Point3f* eye,
  Point3f* lookAt,
  Point3f* up,
  float fov,
  float aspectRatio,
  float width,
  float height
) :
  eye(eye),
  lookAt(lookAt),
  up(up),
  fov(fov),
  aspectRatio(aspectRatio),
  width(width),
  height(height)
{
  Point3f from(eye);
  Point3f to(lookAt);
  Point3f upCopy(up);

  // z-axis
  Point3f w(from);
  w.sub(to);
  w.normalize();
  Vector4f zc(w.x(), w.y(), w.z(), 0.0);

  // # x-axis
  Point3f u = up->cross(w);
  u.normalize();
  Vector4f xc(u.x(), u.y(), u.z(), 0.0);

  // # y-axis
  Point3f v = w.cross(u);
  Vector4f yc(v.x(), v.y(), v.z(), 0.0);
  Vector4f e(from.x(), from.y(), from.z(), 1.0);

  matrix = new Matrix4f(xc, yc, zc, e);
}

Matrix4f* Camera::transformation() {
  return this->matrix;
}
