#include <unistd.h>
#include <iostream>
#include <GL/glui.h>
#include <stdlib.h>
using namespace std;
GLUI *glui;
int win1;
#define ENTER_ID 1
#define ABOUT_ID 2
#define EXIT_ID 3
#define TEXTBOX 4
void control(int cnt)
{
	if(cnt == ENTER_ID)
	{
		//cout<<"Entered";
		exit(5);
	}
	else if(cnt == ABOUT_ID)
	{
		exit(10);
	}
	else if(cnt == EXIT_ID)
	{
		exit(15);
	}
}
void mouse(int btn,int state,int x,int y)
{

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	// glutInitWindowPosition(0,0);
	// glutInitWindowSize(500,500);
	// glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

	//win1=glutCreateWindow("Window1");
	//GLUI_master.setMouseFunc(mouse);

	glui=GLUI_Master.create_glui("CG PROJECT",0,600,200);

	//glui->add_button(glui,"ENTER",ENTER_ID,control);
	// GLUI_TextBox *moo=new GLUI_TextBox(glui,"\t\t\t\t\t\tILLUMINATING PARADIGM\t\t\t\t\t");
	GLUI_TextBox *moo=new GLUI_TextBox(glui,true,1,control);
	moo->set_text("\tILLUMINATING PARADIGM OF LIGHT SOURCES");
	moo->set_h(40);
	moo->set_w(400);
	moo->disable();
	new GLUI_Separator(glui);

	new GLUI_Button( glui, "Enter", ENTER_ID, control );
	new GLUI_Button( glui, "About", ABOUT_ID, control );
	new GLUI_Button( glui, "Exit", EXIT_ID, control );
	new GLUI_Separator(glui);
	glutMainLoop();
}