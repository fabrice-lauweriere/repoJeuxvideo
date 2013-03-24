// ----------------- controls.cpp -----------------------

#include "constants.h"
/*

// 'mainKeyPressed' is called everytime a key is pressed
void mainKeyPressed(uchar key)
{
	g_keys[key]=1;
}

// ------------------------------------------------------------------

// 'mainKeyUnpressed' is called everytime a key is released
void mainKeyUnpressed(uchar key)
{
	g_keys[key]=0;
}*/

void actionButtons() {
	if(g_keys['q']) {
		angle2=angle2+/*M_PI*/1/100;
	} else if(g_keys['d']) {
		angle2=angle2-/*M_PI*/1/100;	
	} else if(g_keys['z']) {
		altitude+=10;
	} else if(g_keys['s']) {
		altitude-=10;
	} else if(g_keys['+']) {
		zoom += 10;
	} else if(g_keys['-']) {
		if(zoom - 10 >0)  {
			zoom-=10;
		}
	}
}