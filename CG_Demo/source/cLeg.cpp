#include "..\header\cLeg.h"
#define DEGRAD 0.0174533f
#define STEPR 3
#include <math.h>

Leg::Leg(float _x, float _y, float _z, bool _canIstart, float _side)
{
	x = _x;
	z = _z;
	y = _y;
	side = _side;
	step = false;
	canIstart = _canIstart;
	rotankle = -10;
	rotfoot = 0;
	angle = 0;
	updown = 0;
	rotuleg = 0 ;
	rotlleg = 5;
	r1 = (float) 171/255;
	g1 = (float)160/255;
	b1 = (float)157/255;
}


Leg::~Leg()
{
}

void Leg::axes() {
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
void Leg::draw()
{
	glLineWidth(1.0f);
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glPushMatrix(); {
			glTranslatef(-2, 0, 0);
			axes();
			glRotatef(rotuleg, 0, 0, 1);
			glPushMatrix(); {
				glColor3f(r1, g1, b1);
				glTranslatef(-0.2, 0, side);
				glScalef(0.9, 0.9, 1.1);
				glutSolidCylinder(0.6, 0.5, 32, 32);
			}
			glPopMatrix();
			glTranslatef(2, 0, 0);
			glPushMatrix(); {
				glColor3f(r1,g1,b1);
				glScalef(4, 0.8, 0.5);
				glutSolidCube(1);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(2, 0, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glTranslatef(-0.2, 0, -0.35);
					glScalef(0.6, 0.6, 0.7);
					glutSolidCylinder(0.9, 0.8, 32, 32);
				}
				glPopMatrix();
				glRotated(-rotuleg+rotlleg, 0, 0, 1);
				glTranslatef(0, -2.8, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glScalef(0.8, 6, 0.5);
					glutSolidCube(1);
				}
				glPopMatrix();
				glTranslatef(0, -3, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glTranslatef(0, 0, -0.35);
					glScalef(0.6, 0.6, 0.7);
					glutSolidCylinder(0.7, 0.8, 32, 32);
				}
				glPopMatrix();
				glRotated(rotankle, 0, 0, 1);
				glTranslatef(0, -1.0, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glScalef(0.8, 2.4, 0.5);
					glutSolidCube(1);
				}
				glPopMatrix();
				glTranslatef(0, -1.2, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glTranslatef(0, 0, -0.3);
					glScalef(0.6, 0.6, 0.7);
					glutSolidCylinder(0.5, 0.8, 32, 32);
				}
				glPopMatrix();
				glRotated(-rotankle-rotfoot, 0, 0, 1);
				glTranslatef(-0.5, -0.1, 0);
				glPushMatrix(); {
					glColor3f(r1, g1, b1);
					glTranslatef(0, 0, -0.25);
					glScalef(1.5, 0.8, 0.5);
					glutSolidCube(1);
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
	
}

void Leg::update()
{
	if (canIstart) {
		angle = angle + 0.2;

		//Rotate ankle, move leg, rotate axes
		if (angle <= 90) {
			rotfoot -= 0.2;
			rotankle -= 0.2;
			updown -= 0.005;
			rotuleg += 0.11;
			rotlleg -= 0.08;
		}
		else if (angle <= 180) {
			rotuleg -= 0.16;
			rotlleg -= 0.02;
			rotankle += 0.13;
			rotfoot += 0.16;
		}
		else if (angle < 355) {
			rotuleg += 0.025;
			rotlleg += 0.05;
			rotankle += 0.005;
			rotfoot += 0.015;
			step = true;
		}
		else if (angle <= 360) {
			angle = 0;
			rotankle = -10;
			rotfoot = 0;
			updown = 0;
			rotuleg = 0;
			rotlleg = 5;
		}
	}
}
