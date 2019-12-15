#ifndef CAMERA_H
#define CAMERA_H

// A Scrolling Camera for functions

#include "includeall.h"
#include "vec3.h"
#include "matrix33.h"

typedef struct {
    vec3 center;
    real x;
    real y;
    real const width;
    real const height;
    real const half_width;
    real const half_height;
    real zoom_factor;
    matrix33 correction;
} camera;

camera camera_create(vec3 * const center, real width, real height, real zoomfactor);
void camera_update(camera* const cam);
void camera_drawFunction(camera* const cam, real (*myMathFunction)(real));
void camera_drawGrid(camera* const cam);
void camera_drawAxes(camera* const cam);

#endif // CAMERA_H
