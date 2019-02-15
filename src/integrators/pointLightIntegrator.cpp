#include <iostream>
#include <algorithm>
#include "pointLightIntegrator.h"
#include "../materials/material.h"

bool PointLightIntegrator::isOccluded(Point3f* hitPosition, Point3f* lightDir, float eps) {
  Ray* shadowRay = new Ray(
    new Point3f(hitPosition),
    lightDir
  );
  HitRecord* shadowHit = scene->intersectableList->intersect(shadowRay);
  if (!shadowHit->isValid()) {
    return true;
  }

  Point3f* dist_shad_hit_view_hit2 = (new Point3f(shadowHit->position));
  dist_shad_hit_view_hit2->sub(hitPosition);
  return shadowHit->material->castsShadows() && dist_shad_hit_view_hit2->dot() < eps;
}

Spectrum* PointLightIntegrator::contributionOf(PointLight* lightSource, HitRecord* hitRecord) {
  HitRecord* lightHit = lightSource->sample();
  Point3f* lightDir = new Point3f(lightHit->position);
  lightDir->sub(hitRecord->position);

  float d2 = lightDir->dot();
  lightDir->normalize();

  if (isOccluded(hitRecord->position, lightDir, d2)) {
    return new Spectrum();
  }

  Spectrum* brdfContribution = hitRecord->material->evaluateBrdf(hitRecord, hitRecord->wIn, lightDir);

  // shading: brdf * emission * dot(normal,light_dir) * geom_term
  Spectrum* contribution = new Spectrum(brdfContribution);

  Point3f* oppositeLightDir = new Point3f(lightDir);
  oppositeLightDir->negate();

  Spectrum* lightEmission = lightHit->material->evaluateEmission(lightHit, oppositeLightDir);
  contribution->mult(lightEmission);

  float angle = hitRecord->normal->dot(lightDir);
  float cosTheta = 0 > angle ? 0 : angle;
  contribution->scale(cosTheta);

  // find a better scaling approach
  contribution->scale(1.0 / d2);
  return contribution;
}

PointLightIntegrator::PointLightIntegrator(Scene* scene): scene(scene) {}

Spectrum* PointLightIntegrator::integrate(Ray* ray) {
  HitRecord* hitRecord = scene->intersectableList->intersect(ray);
  if (!hitRecord->isValid()) {
    return new Spectrum();
  }

  Spectrum* contribution = new Spectrum();
  for(auto const& lightSource: *scene->lightList) {
    Spectrum* currentContribution = contributionOf(lightSource, hitRecord);
    contribution->add(currentContribution);
  }

  return contribution;
}
