/*
 Patricia Dávila Servín | A01650812
 Carlos Ivan Balcazar Martínez | A01335208
 */

// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
	#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
	#include "GL/freeglut.h"
	#include "GL/gl.h"
#endif

#include "cLeg.h"
#include "cHead.h"
Leg* leg1;
Leg* leg2;
Head* head;

#include <stdio.h>
#include <math.h>
#include <time.h>

int sides = 3;
int colors[360][3];
int rotx, dir;
float movez;
float movey;
float angle;
int steps;
float distance;
float rotleg;
float rotfoot;
float to90;
float updown;
#define STEPR 2
#define DEGRAD 0.0174533f
#define VEL 0.001f

//Axes
void axes() {
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0); //X
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);

		glColor3f(0, 1, 0); //Y 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);

		glColor3f(0, 0, 1); //Z
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	}
	glEnd();
}



void init() // FOR GLUT LOOP
{
	leg1 = new Leg(0,8,-2.5,true,0.2);
	leg2 = new Leg(0, 8, 2.5, false,-0.6);
	head = new Head(0, 8, 0);
	distance = 1;
	movez = 0;
	movey = 0;
	angle = 0;
	steps = 1;
	rotleg = -2;
	rotfoot = 0;
	to90 = 0;
	updown = 0;
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}


void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(-30.0, 20.0, 40.0,										// Where the camera is.
		0, 0, 0.0,										// To where the camera points at.
		0.0, 1.0, 0.0);
	axes();
	glLineWidth(1.0f);
	leg1->draw();
	leg2->draw();
	head->draw();
	glutSwapBuffers();												// Swap the hidden and visible buffers.
}


void idle()
															// Called when drawing is finished.
{
	if (leg1->step) {
		leg2->canIstart = true;
	}
	leg1->update();
	leg2->update();
	head->update();
	glutPostRedisplay();
											// Display again.
}


void reshape(int x, int y)											// Called when the window geometry changes.
{	
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(50.0, (GLdouble)x / (GLdouble)y, 0.5, 150.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 1.0, 4.0,
		      0.0, 0.0, 0.0,
		      0.0, 1.0, 0.0);
	display();
}


int main(int argc, char* argv[])
{
	srand(time(NULL));
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 600);
	glutCreateWindow("CG Geometric Figures");
	
	init();
	rotx = 0;
	dir =1;
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
