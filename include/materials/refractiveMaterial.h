#ifndef REFRACTIVE_MATERIAL_H
#define REFRACTIVE_MATERIAL_H

#include <algorithm>
#include "../hitRecord.h"
#include "../math/vector3f.h"
#include "../spectrum.h"
#include "material.h"

class RefractiveMaterial : public Material {
 private:
  // based on Schlick's approximation:
  // See https://en.wikipedia.org/wiki/Schlick%27s_approximation
  float fresnelFactor(HitRecord*) const;

  const float refractionIndex;
  const Spectrum ks;

 public:
  RefractiveMaterial(float);
  RefractiveMaterial(float, Spectrum*);

  virtual Spectrum* evaluateBrdf(HitRecord* hitRecord, Vector3f* wOut, Vector3f* wIn);
  virtual Spectrum* evaluateEmission(HitRecord* hitRecord, Vector3f* wOut);

  virtual bool hasSpecularReflection();
  virtual bool hasSpecularRefraction();
  virtual bool castsShadows();

  ShadingSample evaluateSpecularReflection(HitRecord* hitRecord) const override;
  ShadingSample evaluateSpecularRefraction(HitRecord* hitRecord) const override;
};
#endif
