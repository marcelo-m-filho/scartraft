#include "stdafx.h"
#include "init.h"

 
int main()
{
	if(!al_init()) //Allegro Initialization
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	init boot;
	boot.start();
	return 3;
}



