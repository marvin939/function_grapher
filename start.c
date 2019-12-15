#include "start.h"

#include <windows.h>
#include "includeall.h"
#include "globals.h"
#include <math.h>

// Some test math functions
real upsideDownParabola(real const x) { return -x*x; }
real minusThree(real const x) { return -3; }
real hyperbola(real const x) { return 1 / x; }
real cubic1(real const x) { return 6 - 15.*x*x*x/27.; }

int start_runStuff( int argc, char* args[] )
{
    al_init();

    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (display == NULL) {
        fputs("Unable to create allegro display.", stderr);
        return -1;
    }

    if (!al_init_primitives_addon()) {
        fputs("Failed to initialize primitives addon.", stderr);
        return -1;
    }

    if (!al_install_keyboard()) {
        fputs("Unable to install keyboard.", stderr);
        return -1;
    }
    if (!al_install_mouse()) {
        fputs("Unable to install mouse.", stderr);
        return -1;
    }

    ALLEGRO_EVENT_QUEUE* eventq = al_create_event_queue();
    if (eventq == NULL) {
        fputs("Unable to create allegro event queue.", stderr);
        return -1;
    }
    al_register_event_source(eventq, al_get_keyboard_event_source());
    al_register_event_source(eventq, al_get_mouse_event_source());

    //Main loop flag
    bool quit = false;
    bool updateScreen = true;   // update screen once

    vec3 o = {0, 0, 1}; // The zero vector.
    //camera cam = {o, SCREEN_WIDTH, SCREEN_HEIGHT, 25};
    camera cam = camera_create(&o, SCREEN_WIDTH, SCREEN_HEIGHT, 20);
    real cam_speed = 50;
    real zoom_multiplier = 1.1;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        ALLEGRO_EVENT ret_event;
        al_wait_for_event(eventq, &ret_event);
        //al_get_next_event(eventq, &ret_event);

        if(ret_event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ret_event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: quit = true; break;

                // Movement/step
                case ALLEGRO_KEY_LEFT: cam.center.x -= cam_speed; break;
                case ALLEGRO_KEY_RIGHT: cam.center.x += cam_speed; break;
                case ALLEGRO_KEY_UP: cam.center.y -= cam_speed; break;
                case ALLEGRO_KEY_DOWN: cam.center.y += cam_speed; break;

                // Zoom
                case ALLEGRO_KEY_EQUALS: cam.zoom_factor *= zoom_multiplier; break;
                case ALLEGRO_KEY_MINUS: cam.zoom_factor /= zoom_multiplier; break;
            }
            updateScreen = true;
        }

        //Clear screen
        if (!updateScreen)  // Only update when keys are pressed.
            continue;

        al_clear_to_color(al_map_rgb(255, 255, 255));

        camera_update(&cam);
        camera_drawGrid(&cam);
        camera_drawAxes(&cam);
        camera_drawFunction(&cam, fabs);
        camera_drawFunction(&cam, sin);
        camera_drawFunction(&cam, cos);
        camera_drawFunction(&cam, upsideDownParabola);
        camera_drawFunction(&cam, minusThree);
        camera_drawFunction(&cam, hyperbola);

        //Update screen
        al_flip_display();
        //Sleep(FRAME_TIME);
        updateScreen = false;   // reset
    }

	//Free resources and close Allegro
	al_destroy_event_queue(eventq);
	al_destroy_display(display);

	return 0;
}

