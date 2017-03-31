#include <iostream>
float angle=0.0;

float lx=0.0f,lz=-1.0f;

float x=0.0f,z=5.0f;

#include "reshape.cpp"
#include "keyboard.cpp"
#include "drawsnowman.cpp"
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

using namespace std;
//float angle=0.0f;
void renderScene(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//glColor3f(1.0,0.0,0.0);
	glLoadIdentity();

	gluLookAt(x,1.0f,z,
			  x+lx,1.0f,z+lz,
			  0.0f,1.0f,0.0f);

	//glRotatef(angle,0.0f,1.0f,0.0f);

	glColor3f(red,green,blue);
	/*
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,-5.0);
		glVertex3f(0.5,0.0,-5.0);
		glVertex3f(0.0,0.5,-5.0);
	glEnd();
	*/
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();
	//angle+=0.1f;
	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawSnowMan();
			glPopMatrix();
		}
	glutSwapBuffers();
}

int main(int argc,char **argv)
{
	pid_t pid;
	glutInit(&argc,argv);
	glutInitWindowPosition(-1,-1);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutCreateWindow("Primitive House");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(NormalKeyRes);
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 1;
}