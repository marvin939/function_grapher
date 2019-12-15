#include "camera.h"
#include "globals.h"

camera camera_create(vec3 * const center, real width, real height, real zoomfactor)
{
    real const half_width = width / 2.;
    real const half_height = height / 2.;

    return (camera){
        .center = *center,
        .width = width,
        .height = height,
        .half_width = half_width,
        .half_height = half_height,
        .zoom_factor = zoomfactor,
        .correction = {{}}
    };
}

void camera_update(camera* const cam)
{
    cam->x = cam->center.x - cam->half_width;
    cam->y = cam->center.y - cam->half_height;
    // World to camera matrix
    cam->correction = (matrix33){{  // flips y axis then transposes
        1, 0, -cam->x,
        0, -1, -cam->y,
        0, 0, 1
    }};
}

void camera_drawFunction(camera* const cam, real (*myMathFunction)(real))
{
    static vec3 const o = {0,0,1};   // zero vector
    matrix33 transform;

    ALLEGRO_COLOR plot_colour = COLOR_BLUE;
    real x;
    for (x = cam->x; x < cam->x + cam->width; ++x) {
        real y;
        real zoomed_x, zoomed_y;

        zoomed_x = x / cam->zoom_factor;    // multiplying x with a number 0 < s < 1 slows down function
        y = myMathFunction(zoomed_x);
        zoomed_y = cam->zoom_factor * y;    // multiplying y with number |t| > 0 amplifies it

        vec3 plot;
        plot = (vec3){x, zoomed_y, 1};    // zoomed, 1:1 with camera
        vec3 scplot = matrix33_vmul(&cam->correction, &plot);
        al_draw_circle(scplot.x, scplot.y, 0.5, plot_colour, 0);
    }

    // Draw O vector as square
    /*
    vec3 oplot = matrix33_vmul(&cam->correction, &o);
    al_draw_rectangle(oplot.x - 5, oplot.y - 5, oplot.x + 5, oplot.y + 5, al_map_rgb(0,0,0), 1);
    */
}


void camera_drawGrid(camera* const cam)
{
    ALLEGRO_COLOR gridColour = COLOR_GREY_LIGHT;

    vec3 plot;
    real x, y;

    // Draw horizontal lines
    // THIS WORKS :D... Now do this one for vert lines
    real const nearestHorizLine = -fmod(cam->y, cam->zoom_factor);
    for (y = nearestHorizLine; y <= cam->height; y += cam->zoom_factor) {
        al_draw_line(0, y, cam->width, y, gridColour, 1);
    }

    // Draw vertical lines
    /*
    real const nearestVertLine = cam->x - fmod(cam->x, cam->zoom_factor);
    real max_x = cam->x + cam->width;
    for (x = nearestVertLine; x < max_x; x += cam->zoom_factor) {
        plot = (vec3){x, 0, 1};    // zoomed, 1:1 with camera; y is not used
        vec3 scplot = matrix33_vmul(&cam->correction, &plot);
        al_draw_line(scplot.x, 0, scplot.x, cam->height, gridColour, 1);
    }
    */
    real const nearestVertLine = -fmod(cam->x, cam->zoom_factor);
    for (x = nearestVertLine; x <= cam->width; x += cam->zoom_factor) {
        al_draw_line(x, 0, x, cam->height, gridColour, 1);
    }
}

void camera_drawAxes(camera* const cam)
{
    static vec3 const o = {0, 0, 1};    // O vector

    ALLEGRO_COLOR axesColour = COLOR_BLACK;
    vec3 plot;
    real x, y;

    // Draw vertical lines
    vec3 screen_plot = matrix33_vmul(&cam->correction, &o);
    al_draw_line(screen_plot.x, 0, screen_plot.x, cam->height, axesColour, 1);
    al_draw_line(0, screen_plot.y, cam->width, screen_plot.y, axesColour, 1);
}
