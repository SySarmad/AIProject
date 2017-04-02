#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "sheep.h"

using namespace std;

int numSheep = 1000;
Sheep** sheeps;
SheepInfo *info[5];

void initSheep()
{
	sheeps = new Sheep*[numSheep];
	info[0] = new SheepInfo(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, false);
	info[1] = new SheepInfo(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, false);
	info[2] = new SheepInfo(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, false);
	info[3] = new SheepInfo(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false);
	info[4] = new SheepInfo(1.0, 0.0, 1.0, 0.0, 0.0, 0.0, false);
	
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i] = new Sheep(500, 500, info[i%5]);
	}
}

void updateSheep()
{
	Point p;
	
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i]->dogCheck();
		p = sheeps[i]->get_location();
		if(abs((int)p.getX()) > 500 || abs((int)p.getY()) > 500)
		{
			delete sheeps[i];
			sheeps[i] = new Sheep(500, 500, info[0]);
		}
	}
	
	glutPostRedisplay();
}

void renderScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Point p;
	float* color;
	
	glBegin(GL_POINTS);
		for(int i = 0; i < numSheep; i++)
		{
			color = sheeps[i]->getColor();
			glColor3f(color[0], color[1], color[2]);
			p = sheeps[i]->get_location();
			glVertex2i((int)p.getX(), (int)p.getY());
		}
	glEnd();

    glutSwapBuffers();
    
    updateSheep();
}

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-500.0, 500.0, -500.0, 500.0);
}

int main(int argc, char **argv)
{
	srand (static_cast <unsigned> (time(0)));
	
	initSheep();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Test");

	init2D(0.0, 0.0, 0.0);

	glutDisplayFunc(renderScene);

	glutMainLoop();

	return 1;
}
