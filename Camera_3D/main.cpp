#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include<time.h>
#include <unistd.h>
float fovy = 60.0, aspect=1.0, znear=1.0,  zfar=10.0;

float ex = 1.0, ey = 1.0, ez = 1.0, cx = 0.0, cy = 0.0, cz = 0.0, upx = 0.0, upy = 1.0, upz = 0.0;

void drawBox(void)
{
    glBegin(GL_QUADS);
    glColor3f (0.0, 1.0, 1.0);
    glVertex3f(-0.3,-0.5,0.0);
    glVertex3f(0.3,-0.5,0.0);
    glVertex3f(0.3,0.5,0.0);
    glVertex3f(-0.3,0.5,0.0);

    glColor3f (1.0, 1.0, 0.3);
    glVertex3f(-0.3,-0.5,0.5);
    glVertex3f(0.3,-0.5,0.5);
    glVertex3f(0.3,0.5,0.5);
    glVertex3f(-0.3,0.5,0.5);

    glColor3f (0.2, 0.1, 1.0);
    glVertex3f(-0.3,0.5,0.5);
    glVertex3f(0.3,0.5,0.5);
    glVertex3f(0.3,0.5,0.0);
    glVertex3f(-0.3,0.5,0.0);

    glColor3f (0.3, 1.0, 0.2);
    glVertex3f(-0.3,-0.5,0.0);
    glVertex3f(-0.3,-0.5,0.5);
    glVertex3f(-0.3,0.5,0.5);
    glVertex3f(-0.3,0.5,0.0);

    glColor3f (0.3, 0.4, 0.2);
    glVertex3f(-0.3,-0.5,0.0);
    glVertex3f(0.3,-0.5,0.0);
    glVertex3f(0.3,-0.5,0.5);
    glVertex3f(-0.3,-0.5,0.5);


    glColor3f (0.3, 1.0, 0.2);
    glVertex3f(0.3,-0.5,0.5);
    glVertex3f(0.3,-0.5,0.0);
    glVertex3f(0.3,0.5,0.0);
    glVertex3f(0.3,0.5,0.5);
    glEnd();
}


void display(void)
{

    char my_choices[] = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O'};
    srand(time(NULL));
    for(int i = 0; ; i++)
    {
        int choice = rand() % 26;
        printf("%c ", my_choices[choice]);
        switch(my_choices[choice])
        {
        case 'a':
            fovy = fovy + 0.1;
            glutPostRedisplay();
            break;
        case 's':
            aspect = aspect * 1.1;
            glutPostRedisplay();
            break;
        case 'd':
            znear = znear + 0.1;
            glutPostRedisplay();
            break;
        case 'f':
            zfar = zfar - 0.1;
            glutPostRedisplay();
            break;
        case 'q':
            ex = ex + 0.1;
            glutPostRedisplay();
            break;
        case 'w':
            ey = ey + 0.1;
            glutPostRedisplay();
            break;
        case 'e':
            ez = ez + 0.1;
            glutPostRedisplay();
            break;
        case 'r':
            cx = cx + 0.1;
            glutPostRedisplay();
            break;
        case 't':
            cy = cy + 0.1;
            glutPostRedisplay();
            break;
        case 'y':
            cz = cz + 0.1;
            glutPostRedisplay();
            break;
        case 'u':
            upx = upx + 0.1;
            glutPostRedisplay();
            break;
        case 'i':
            upy = upy + 0.1;
            glutPostRedisplay();
            break;
        case 'o':
            upz = upz + 0.1;
            glutPostRedisplay();
            break;

        case 'A':
            fovy = fovy - 0.1;
            glutPostRedisplay();
            break;
        case 'S':
            aspect = aspect / 1.1;
            glutPostRedisplay();
            break;
        case 'D':
            znear = znear - 0.1;
            glutPostRedisplay();
            break;
        case 'F':
            zfar = zfar + 0.1;
            glutPostRedisplay();
            break;
        case 'Q':
            ex = ex - 0.1;
            glutPostRedisplay();
            break;
        case 'W':
            ey = ey - 0.1;
            glutPostRedisplay();
            break;
        case 'E':
            ez = ez - 0.1;
            glutPostRedisplay();
            break;
        case 'R':
            cx = cx - 0.1;
            glutPostRedisplay();
            break;
        case 'T':
            cy = cy - 0.1;
            glutPostRedisplay();
            break;
        case 'Y':
            cz = cz - 0.1;
            glutPostRedisplay();
            break;
        case 'U':
            upx = upx - 0.1;
            glutPostRedisplay();
            break;
        case 'I':
            upy = upy - 0.1;
            glutPostRedisplay();
            break;
        case 'O':
            upz = upz - 0.1;
            glutPostRedisplay();
            break;
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(fovy, aspect, znear, zfar);


        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(ex, ey, ez,
                  cx, cy, cz,
                  upx, upy, upz);

        drawBox();
        glutSwapBuffers();
        usleep(100000);
    }
}

void init(void)
{
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glTranslatef(0.0, 0.0, -1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D Wire cube");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
