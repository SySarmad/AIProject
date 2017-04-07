#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "sheep.h"
#include "Dog.h"

using namespace std;

int numSheep = 1000;
Sheep** sheeps;
SheepInfo *info[5];
Dog* dog;

void initSheep()
{
	sheeps = new Sheep*[numSheep];
	info[0] = new SheepInfo(1.0, 1.0, 1.0, 50.0, 5.0, 0.95, false);
	info[1] = new SheepInfo(1.0, 0.0, 0.0, 50.0, 5.0, 0.96, false);
	info[2] = new SheepInfo(0.0, 1.0, 0.0, 50.0, 5.0, 0.97, false);
	info[3] = new SheepInfo(0.0, 0.0, 1.0, 50.0, 5.0, 0.98, false);
	info[4] = new SheepInfo(1.0, 0.0, 1.0, 50.0, 5.0, 0.99, false);
	
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i] = new Sheep(500, 500, info[i%5]);
	}
	
	dog = new Dog();
}

void updateSheep()
{
	Point p;
	Point d = dog->getLocation();
	Point dv = dog->getVelocity();
	
	for(int i = 0; i < numSheep; i++)
	{
		sheeps[i]->dogCheck(d, dv);
		sheeps[i]->update_position();
		p = sheeps[i]->get_location();
		if(abs((int)p.getX()) > 500 || abs((int)p.getY()) > 500)
		{
			delete sheeps[i];
			sheeps[i] = new Sheep(500, 500, info[0]);
		}
	}
	
	dog->updatePosition();
	
	//glutPostRedisplay();
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
		glVertex2i((int)dog->getLocation().getX(), (int)dog->getLocation().getY());
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

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'w':
			dog->updateVelocity(new Point(0.0, 1.0));
		break;
		case 'a':
			dog->updateVelocity(new Point(-1.0, 0.0));
		break;
		case 's':
			dog->updateVelocity(new Point(0.0, -1.0));
		break;
		case 'd':
			dog->updateVelocity(new Point(1.0, 0.0));
		break;
		default:
		break;
	}
	glutPostRedisplay();
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

	glutIdleFunc(renderScene);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 1;
}
