#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
float angle = 0.0f;

void leaf(void)
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.2, 0.2);
        glVertex2f(-0.2, 0.2);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.2);
        glVertex2f(0.4, 0.3);
        glVertex2f(0.0, 0.4);
        glVertex2f(-0.4, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 0.4);
        glVertex2f(0.55, 0.55);
        glVertex2f(0.3, 0.65);
        glVertex2f(-0.3, 0.65);
        glVertex2f(-0.55, 0.55);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(-0.3, 0.65);
        glVertex2f(0.3, 0.65);
        glVertex2f(0.45, 0.75);
        glVertex2f(0.0, 1.0);
        glVertex2f(-0.45, 0.75);
    glEnd();

}

void object(void)
{
    for(int i = 36; i <=360; i += 72)
    {
        glPushMatrix();
        glRotatef(float(i), 0.0, 0.0, 1.0);
        glScalef(0.3, 1.0, 1.0);
        leaf();
        glPopMatrix();
        glFlush();
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(angle >= 360) angle = 0.0f;

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0);
    object();
    glPopMatrix();
    angle += 0.10f;
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void keyboard(char key, int x, int y)
{

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(200, 400);
    glutCreateWindow("Practice");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
