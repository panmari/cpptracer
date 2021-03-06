#include "intersectables/intersectableList.h"
#include <limits>
#include "hitRecord.h"

IntersectableList::IntersectableList() { container = new std::vector<Intersectable*>; }

HitRecord* IntersectableList::intersect(const Ray& ray) const {
  float minT = std::numeric_limits<float>::max();
  auto hitRecord = new HitRecord();
  for (auto const& intersectable : *container) {
    HitRecord* currentHitRecord = intersectable->intersect(ray);
    if (!currentHitRecord->isValid()) {
      delete currentHitRecord;
      continue;
    }

    // find closest hitRecord
    float currentT = currentHitRecord->t;
    if (currentT < minT && currentT > 0.0) {
      minT = currentT;
      delete hitRecord;
      hitRecord = new HitRecord(currentHitRecord);
    }

    // only delete the current hitRecord if there is more than one intersectable in the scene
    if (container->size() > 1) {
      delete currentHitRecord;
    }
  }

  return hitRecord;
}
void IntersectableList::put(Intersectable* intersectable) { container->push_back(intersectable); }
