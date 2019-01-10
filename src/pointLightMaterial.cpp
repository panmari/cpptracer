#include "pointLightMaterial.h"

PointLightMaterial::PointLightMaterial(Spectrum* emission): emission(emission) {}

Spectrum* PointLightMaterial::evaluateBrdf(HitRecord* , Point3f* , Point3f* ) {
  return new Spectrum();
}

Spectrum* PointLightMaterial::evaluateEmission(HitRecord*, Point3f*) {
  return new Spectrum(emission);
}

bool PointLightMaterial::hasSpecularReflection() {
  return false;
}

bool PointLightMaterial::hasSpecularRefraction() {
  return false;
}

bool PointLightMaterial::castsShadows() {
  return false;
}