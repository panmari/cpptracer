#ifndef SPECTRUM_H
#define SPECTRUM_H

/**
 * Float valued point with 3 coordinates.
 */
class Spectrum {
  float _r, _g, _b;

  public:

  Spectrum();
  Spectrum(float, float, float);

  float r();
  float g();
  float b();
};

#endif