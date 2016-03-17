#include <iostream>
//#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h


int FPS = 30;
int WINDOW_X = 200;
int WINDOW_Y = 200;
int WINDOW_WIDTH = 200;
int WINDOW_HEIGHT = 200;

void init(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_FLAT);

        //More init
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        //Display functions

	glutSwapBuffers();
}

void timer(int v) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}

void animateScene(){

}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void processKeys(unsigned char key, int x, int y) {

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Premiere fenetre GLUT");

	init();
	glutDisplayFunc(display);
	glutIdleFunc(animateScene);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(processKeys);
	glutTimerFunc(1000 / FPS, timer, 0);

	glutMainLoop();
	return 0;
}
