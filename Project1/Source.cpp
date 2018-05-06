#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>

void drawButtons();
void drawRainbow();

void OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		double xpos, ypos;

		//get coordintates of mouse cursor
		xpos = x; 
		ypos = y;

		std::cout << "Mouse left button is clicked ! \n";
		std::cout << "x = " << xpos << " ";
		std::cout << "y = " << ypos << "\n";

		
		//first button
		if (xpos >= 85 && xpos <= 237 && ypos >= 680 && ypos <= 785)
		{
			std::cout << "Mouse left button is clicked ! \n";
			std::cout << "x = " << xpos << " ";
			std::cout << "y = " << ypos << "\n";

			drawRainbow();
		}
   
	}
}

void display() {

	drawButtons();
	//drawRainbow();
	
}

void drawButtons()
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity(); //clear matrix
    
	//draw first button
	glTranslatef(-0.6f, -0.8f, 0.0f);
	glScalef(0.4, 0.2, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glLoadIdentity();
	
	//draw second button
	glTranslatef(0.0f, -0.8f, 0.0f);
	glScalef(0.4, 0.2, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); 
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glLoadIdentity();

	//draw third button
	glTranslatef(0.6f, -0.8f, 0.0f);
	glScalef(0.4, 0.2, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glFlush();  // Render now
}

void drawRainbow()
{
	float dx = 0.0;
	float dy = 0.0;
	float w = 0.014;
	float step = (1.0 - 0.5) / 5.0;

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity(); //clear matrix

	//draw rainbow
	glTranslatef(-0.25f, 0.2f, 0.0f);
	glScalef(0.8, 0.5, 1.0);
	// The rainbow is made of 50 small rectangles that have rainbow shading. They are painted one after the other but the y coordinate is mapped to a sine wave.
	for (int i = 0;i<50;i++)
	{
		glBegin(GL_QUAD_STRIP);

		glColor3f(1, 0, 0); //Red
		glVertex2f(dx, dy);
		glVertex2f(dx + w, dy);

		glColor3f(1, 0.6, 0); //Orange
		glVertex2f(dx, dy - step);
		glVertex2f(dx + w, dy - step);

		glColor3f(1, 1, 0);//Yellow
		glVertex2f(dx, dy - step * 2);
		glVertex2f(dx + w, dy - step * 2);

		glColor3f(0.2, 1, 0); //Green
		glVertex2f(dx, dy - step * 3);
		glVertex2f(dx + w, dy - step * 3);

		glColor3f(0, 0.6, 1); //Blue
		glVertex2f(dx, dy - step * 4);
		glVertex2f(dx + w, dy - step * 4);

		glColor3f(0.4, 0.2, 1); //Purple
		glVertex2f(dx, dy - step * 5);
		glVertex2f(dx + w, dy - step * 5);
		glEnd();

		dx += w;
		dy += 0.01*sin(i*3.14 / 5.0);
	}
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	//glutInitWindowPosition(500, 500); //place of window on the screen
	glutCreateWindow("Click on Rectangle");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(OnMouseClick);
	glutMainLoop();
	return 0;          
}