#include "spectrum.h"
#include <cmath>

Spectrum::Spectrum() {
  _r = 0;
  _g = 0;
  _b = 0;
}

Spectrum::Spectrum(float r, float g, float b) {
  _r = r;
  _g = g;
  _b = b;
}

Spectrum::Spectrum(float v) {
  _r = v;
  _g = v;
  _b = v;
}

Spectrum::Spectrum(Spectrum* s) {
  _r = s->r();
  _g = s->g();
  _b = s->b();
}

float Spectrum::r() {
  return _r;
}

float Spectrum::g() {
  return _g;
}

float Spectrum::b() {
  return _b;
}

void Spectrum::scale(float factor) {
  _r /= factor;
  _g /= factor;
  _b /= factor;
}

void Spectrum::add(Spectrum* other) {
  _r += other->r();
  _g += other->g();
  _b += other->b();
}

void Spectrum::mult(Spectrum* other) {
  _r *= other->r();
  _g *= other->g();
  _b *= other->b();
}
