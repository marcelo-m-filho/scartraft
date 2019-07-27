#include "eventTestClass.h"

eventTest::eventTest()
{
    test_queue = al_create_event_queue();
}

void eventTest::testFunction()
{
    ALLEGRO_EVENT ev;
    al_wait_for_event(test_queue, &ev);

    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        int x = 3;
    }
}