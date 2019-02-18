#include "..\header\cHead.h"



Head::Head()
{
}

Head::Head(float _x, float _y, float _z)
{
	x = _x-1.5;
	y = _y;
	z = _z;
	r1 = (float)171 / 255;
	g1 = (float)160 / 255;
	b1 = (float)157 / 255;
	r2 = (float)84 / 255;
	g2 = (float)86 / 255;
	b2 = (float)88 / 255;
	r3 = (float)68 / 255;
	g3 = (float)73 / 255;
	b3 = (float)77 / 255;
	rothead = 0;
	angle = 45;
}


Head::~Head()
{
}


void Head::axes() {
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

void Head::draw()
{
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glPushMatrix(); {
			glColor3f(r1, g1, b1);
			glPushMatrix(); {
				glScalef(4.0, 0.7, 5);
				glutSolidCube(1);
			}
			glPopMatrix();
			glPushMatrix();{
				glTranslatef(0, 1.6, 0);
				glPushMatrix(); {
					glTranslatef(-1, 0, 0);
					glPushMatrix(); {
						glRotatef(90, 1, 0, 0);
						glutSolidCylinder(0.5, 1.5, 20, 20);
					}
					glPopMatrix();
					glPushMatrix(); {
						glTranslatef(0, 1.6, 0);
						glPushMatrix(); {
							glTranslatef(0.7, 0, 0);
							glRotatef(rothead, 0, 1, 0);
							glPushMatrix(); {
								glScalef(5.0, 3, 3);
								glutSolidCube(1);
							}
							glPopMatrix();
							glPushMatrix(); {
								glTranslated(0, 0, 1);
								glPushMatrix(); {
									glColor3f(r2, g2, b2);
									glScalef(0.8, 0.8, 1);
									glutSolidSphere(1, 20, 20);
								}
								glPopMatrix();
								glPushMatrix(); {
									glColor3f(r3, g3, b3);
									glTranslated(-0.8, -0.2, 1);
									glRotatef(90, 0, 1, 0);
									glutSolidCylinder(0.3, 2, 20, 20);
								}
								glPopMatrix();
							}
							glPopMatrix();
							glPushMatrix(); {
								glTranslated(0, 0, -1);
								glPushMatrix(); {
									glColor3f(r2, g2, b2);
									glScalef(0.8, 0.8, 1);
									glutSolidSphere(1, 20, 20);
								}
								glPopMatrix();
								glPushMatrix(); {
									glColor3f(r3, g3, b3);
									glTranslated(-0.8, -0.2, -1);
									glRotatef(90, 0, 1, 0);
									glutSolidCylinder(0.3, 2, 20, 20);
								}
								glPopMatrix();
							}
							glPopMatrix();
							/*glPushMatrix(); {
								glTranslatef(-3.0, -0.4, 0);
								glPushMatrix(); {
									glScalef(1.3, 4, 1.5);
									glutSolidCube(1);
								}
								glPopMatrix();
							}
							glPopMatrix();*/
							glPushMatrix(); {
								glTranslatef(-2.2, 2.0, 0);
								glPushMatrix(); {
									glColor3f(r1, g1, b1);
									glRotatef(-35, 0, 0, 1);
									glTranslatef(1.0, -2.1, 0);
									glScalef(2.0, 3.2, 1.5);
									glutSolidCube(1);
								}
								glPopMatrix();
								glPushMatrix(); {
									glColor3f(r3, g3, b3);
									glTranslated(-3, -2.5, 0);
									glRotatef(90, 0, 1, 0);
									glutSolidCylinder(0.3, 2, 20, 20);
								}
								glPopMatrix();
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Head::update()
{
	angle = angle + 0.1;
	if (angle < 90) {
		rothead -= 0.2;
	}
	else if (angle < 180) {
		rothead += 0.2;
	}
	else {
		angle=0;
	}
}
