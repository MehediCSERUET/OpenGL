#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>


void triangle(void)
{
    glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.15, -0.15);
		glVertex2f(.15,-0.15);
		glVertex2f(0.0,0.0);
	glEnd();
}

void quad(void)
{
    glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.30, -0.30);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.30, -0.3);
		glVertex2f(0.0, -0.15);
	glEnd();
}

void poly1(void)
{
    glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-0.2, -0.70);
		glVertex2f(0.2,-0.70);
		glVertex2f(0.40, -0.6);
		glVertex2f(0.0, -0.5);
		glVertex2f(-0.4, -0.6);
	glEnd();
}



void poly2(void)
{
    glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0, -1.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.25,-0.8);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.2, -0.7);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.2, -0.7);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.8);
	glEnd();

}

void leaf(void)
{
    triangle();
    quad();
    poly1();
    poly2();
	glFlush();
}


void display(void)
{
	glPushMatrix();
	leaf();
	glPopMatrix();
	glFlush();
}


void display3(void)
{
    triangle();
    quad();
    poly1();
    poly2();
	glFlush();
}

void display2(void)
{
	quad();
	glFlush();
}

void keyboard(unsigned char c, int x, int y)
{
    printf("%d", c);
    switch(c)
    {
        case 'z':
        case 'Z':
            glClear(GL_COLOR_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;

        case 'e':
        case 'E':
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(2.0, 2.0, 1.0);
            glutPostRedisplay();
            break;
        case 'r':
        case 'R':
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(30, 0.0, 0.0, 1.0);
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(0.5, 0.5, 1.0);
            glutPostRedisplay();
            break;
        case 't':
        case 'T':
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0.1, 0.1, 0.0);
            glutPostRedisplay();
            break;
        case 'q':
        case 'Q':
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
			glutPostRedisplay();
            break;
        case 27:
            exit(0);
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Spinner");
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
