#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int red=0,green=0,blue=0;

void NormalKeyRes(unsigned char key,int x,int y)
{
	if(key==27)
		exit(0);
}
/*
void SpecialKeysRes(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_F1:
			red=1.0;
			green=0.0;
			blue=0.0;
			break;
		case GLUT_KEY_F2:
			red=0.0;
			green=1.0;
			blue=1.0;
			break;
		case GLUT_KEY_LEFT:
			red=0.0;
			green=1.0;
			blue=0.0;
			break;
	}
}
*/

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.5f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}
