#include "matrix4f.h"
#include "point3f.h"

#ifndef CAMERA_H
#define CAMERA_H

// Boxfilter-film
class Camera {
  Matrix4f* matrix;
  Point3f* eye;
  Point3f* lookAt;
  Point3f* up;
  float fov;
  float aspectRatio;
  float width;
  float height;

  public:

  Camera(Point3f* eye, Point3f* lookAt, Point3f* up, float fov, float aspectRatio, float width, float height);
  Matrix4f* transformation();
};

#endif
