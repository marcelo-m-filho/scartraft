#pragma once
#include "stdafx.h"

class Events
{
	
	
protected:
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT timer_dummy;
public:
	Events();
};