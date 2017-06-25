#include <GL/glui.h>
#include <iostream>
using namespace std;
GLUI *glui;
void control(int cm)
{}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	// glutInitWindowPosition(0,0);
	// glutInitWindowSize(500,500);
	// glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

	//win1=glutCreateWindow("Window1");
	//GLUI_master.setMouseFunc(mouse);

	glui=GLUI_Master.create_glui("ABOUT",0,600,200);

	//glui->add_button(glui,"ENTER",ENTER_ID,control);
	// new GLUI_TextBox(glui,"\t\t\t\t\t\tDESCRIPTION: Illuminating paradigm is a computer graphics project with the aim of providing building blocks for shadow rendering and visualization toolkit. 
	// 	A user can dynamically vary the light properties as well as the position and orientation of the object.\n\n\n
	// 	DEVELOPED BY:\n
	// 	ADITYA AGARWAL (1PE14CS014)\n
	// 	AMRIT M BHAT (1PE14CS022) \n\n\n
	// 	GUIDED BY:\n
	// 	K S V K SRIKANTH\n
	// 	BIDISHA GOSWAMI
	// 	");

	GLUI_TextBox *moo=new GLUI_TextBox(glui,true,1,control);
	moo->set_text("DESCRIPTION:\n\tIlluminating paradigm is a computer graphics project with the aim of\n\tproviding building blocks for shadow rendering and visualization toolkit."
		"\n\tA user is able to dynamically vary the light properties as well as the\n\tposition and orientation of the object.\n\n"
		"DEVELOPED BY:\n"
		"\tADITYA AGARWAL (1PE14CS014)\n"
		"\tAMRIT M BHAT (1PE14CS022) \n\n"
		"GUIDED BY:\n"
		"\tK S V K SRIKANTH\n"
		"\tBIDISHA GOSWAMI");
	moo->set_h(240);
	moo->set_w(480);
	moo->disable();
	
	glutMainLoop();
}