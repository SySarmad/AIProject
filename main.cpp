#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "sheep.h"

using namespace std;

int numSheep = 100;
Sheep** sheeps;

void initSheep()
{
	sheeps = new Sheep*[numSheep];
	
	SheepInfo* info = new SheepInfo(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, false);
	
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i] = new Sheep(500, 500, info);
	}
}

void updateSheep()
{
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i]->dogCheck();
	}
	
	glutPostRedisplay();
}

void renderScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Point p;

	glBegin(GL_POINTS);
		for(int i = 0; i < 100; i++)
		{
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
