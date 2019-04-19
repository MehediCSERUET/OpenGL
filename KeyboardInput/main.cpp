#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>

void leaf()
{
    glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0,-0.85);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(.25,-.60);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-.25,-.60);
	glEnd();


	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0,-0.60);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.70, -0.25);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0,0.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-.70,-.25);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0, 0.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.90,0.25);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.30, 0.50);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.30, 0.50);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.90, 0.25);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.30, 0.50);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.50,0.65);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0, 0.90);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-0.50, 0.65);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.30, 0.5);
	glEnd();
}

void display(void)
{
    glPushMatrix();
    leaf();
    glPopMatrix();
	glFlush();
}

void keyboard(unsigned char k, int x, int y)
{
    printf("%d", k);
    switch(k){
        case 114:
            //printf("Pressed  R");
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            glRotatef(60, 0.0, 0.0, 1.0);
            leaf();
            glPopMatrix();
            glFlush();
            break;

        case 115:
            //printf("Pressed  S");
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            glScalef(0.5, 0.5, 0.0);
            leaf();
            glPopMatrix();
            glFlush();
            break;
        case 116:
            //printf("Pressed  T");
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            glTranslatef(0.3, 0.20, 0.0);
            leaf();
            glPopMatrix();
            glFlush();
            break;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Lab-1");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
