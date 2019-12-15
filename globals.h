#ifndef GLOBALS_H
#define GLOBALS_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FRAMES_PER_SECOND 16
#define FRAME_TIME (1000 / FRAMES_PER_SECOND)

#define GRID_SIZE 10

#include <allegro5/allegro.h>

#define COLOR_WHITE al_map_rgb(255, 255, 255)
#define COLOR_BLACK al_map_rgb(0, 0, 0)
#define COLOR_GREY_LIGHT al_map_rgb(192, 192, 192)
#define COLOR_BLUE al_map_rgb(0, 0, 255)

#define PI 3.14159265358979323846

#endif // GLOBALS_H

