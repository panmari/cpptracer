#include <vector>
#include <iostream>
#include "scene.h"
#include "pointLightIntegrator.h"
#include <iostream>

Scene::Scene(int width, int height): width(width), height(height) {}

// TODO how to call this in the constructor
void Scene::setup() {
  buildFilm();
  buildCamera();
  buildIntersectables();
  buildLights();
  buildIntegrator();
}

void Scene::buildFilm() {
  Film* film = new Film(width, height);
  this->film = film;
}

void Scene::buildCamera() {
  Point3f* eye = new Point3f(0.5, 0.5, 3.0);
  Point3f* lookAt = new Point3f(0.5, 0.0, 0.0);
  Point3f* up = new Point3f(0.2, 1.0, 0.0);
  float fov = 60.0;

  float aspectRatio = (float)width / height;

  Camera* camera = new Camera(
    eye, lookAt, up, fov, aspectRatio, width, height
  );
  this->camera = camera;
}

void Scene::buildLights() {
  std::cout << "Scene#buildLights not implemented yet." << std::endl;
}

void Scene::buildIntersectables() {
  std::cout << "Scene#buildIntersectables not implemented yet." << std::endl;
}

void Scene::buildIntegrator() {
  this->integrator = new PointLightIntegrator(this);
}