#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include "sheep.h"

using namespace std;

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POINTS);
		for(int i = 0; i < 100; i++)
		{
			glVertex2i(i, i);
		}
	glEnd();

    glutSwapBuffers();
}

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv)
{
	srand (static_cast <unsigned> (time(0)));
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
