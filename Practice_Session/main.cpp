#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

float angle = 0.0f;
void triangle(void)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.07, 0.25);
        glVertex2f(-0.07, 0.25);
    glEnd();
}

void quad(void)
{
    glBegin(GL_QUADS);
        glVertex2f(0.0, 0.25);
        glVertex2f(0.17, 0.4);
        glVertex2f(0.0, 0.55);
        glVertex2f(-0.17, 0.4);
    glEnd();
}

void poly1(void)
{
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.55);
        glVertex2f(0.22, 0.66);
        glVertex2f(0.07, 0.77);
        glVertex2f(-0.07, 0.77);
        glVertex2f(-0.22, 0.66);
    glEnd();
}

void poly2(void)
{
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0, 0.0);
        glVertex2f(0.07, 0.77);
        glColor3f(1.0,0.0, 0.0);
        glVertex2f(0.13, 0.83);
        glColor3f(0.0,0.0, 1.0);
        glVertex2f(0.0, 0.98);
        glColor3f(1.0,0.0, 0.0);
        glVertex2f(-0.13, 0.83);
        glColor3f(0.0,0.0, 1.0);
        glVertex2f(-0.07, 0.77);
    glEnd();
}

void leaf(void)
{
    glColor3f(1.0,0.0, 0.0);
    triangle();

    glColor3f(0.0, 1.0, 0.0);
    quad();

    glColor3f(0.0,0.0, 1.0);
    poly1();

    poly2();

    glFlush();
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for(int i = 0; i <= 360; i += 36){
        glPushMatrix();
        glRotatef(float(i), 0.0, 0.0, 1.0);
        leaf();
        glPopMatrix();
        glutSwapBuffers();
	}
}

void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    if(angle >= 360.0f) angle = 0.0f;

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0);
    leaf();
    glPopMatrix();

    glutSwapBuffers();
    angle += 0.10f;
    glutPostRedisplay();
}

void display3(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(angle >= 360.0f) angle = 0.0f;

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    quad();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.0, 0.0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0, 1.0);
    poly1();
    glPopMatrix();

    glPushMatrix();
    poly2();
    glPopMatrix();


    angle += 0.10f;

    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}

void init(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'c':
    case 'C':
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;

    case 27:
        exit(0);

    case 'z':
    case 'Z':
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;


    case 'q':
    case 'Q':
        glutDisplayFunc(display3);
        glutPostRedisplay();
        break;

    case 't':
    case 'T':
        glTranslatef(0.10, 0.10, 0.0);
        glutPostRedisplay();
        break;

    case 'r':
    case 'R':
        glRotatef(1, 0.0, 0.0, 1.0);
        glutPostRedisplay();
        break;

    case 'e':
    case 'E':
        glScalef(1.1, 1.1, 1.0);
        glutPostRedisplay();
        break;


    case 's':
    case 'S':
        glScalef(0.91, 0.91, 1.0);
        glutPostRedisplay();
        break;


    default:
        printf("Wrong choice");
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(500, 0);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Practice");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
