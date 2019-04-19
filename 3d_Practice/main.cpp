#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>

float fovy = 60.0, aspect=1.0, znear = 1.0, zfar = 10.0;

float eyex = 1.0, eyey = 1.0, eyez = 1.0, cx = 0.0, cy = 0.0, cz = 0.0, upx = 0.0, upy = 1.0, upz = 0.0;

void drawbox(void)
{
    glBegin(GL_QUADS);
        glColor3f (1.0, 0.0, 1.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);

        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.4);
        glVertex3f(-0.2, 0.2, 0.4);

        glColor3f (0.2, 0.1, 1.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(-0.2, 0.2, 0.4);
        glVertex3f(-0.2, -0.2, 0.4);

        glColor3f (0.3, 1.0, 0.2);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.2, -0.2, 0.4);
        glVertex3f(-0.2, -0.2, 0.4);

        glColor3f (0.3, 0.4, 0.2);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.4);
        glVertex3f(0.2, -0.2, 0.4);

        glColor3f (0.3, 1.0, 0.2);
        glVertex3f(-0.2, -0.2, 0.4);
        glVertex3f(0.2, -0.2, 0.4);
        glVertex3f(0.2, 0.2, 0.4);
        glVertex3f(-0.2, 0.2, 0.4);

    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, aspect, znear, zfar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, cx, cy, cz, upx, upy, upz);

    drawbox();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);

    case 'a':
        glClear(GL_COLOR_BUFFER_BIT);
        fovy += 0.1f;
        glutPostRedisplay();
        break;

    case 'A':
        glClear(GL_COLOR_BUFFER_BIT);
        fovy -= 0.1f;
        glutPostRedisplay();
        break;

    case 's':
        glClear(GL_COLOR_BUFFER_BIT);
        aspect += 0.1f;
        glutPostRedisplay();
        break;

    case 'S':
        glClear(GL_COLOR_BUFFER_BIT);
        aspect -= 0.1f;
        glutPostRedisplay();
        break;

    case 'd':
        glClear(GL_COLOR_BUFFER_BIT);
        znear += 0.1f;
        glutPostRedisplay();
        break;

    case 'D':
        glClear(GL_COLOR_BUFFER_BIT);
        znear -= 0.1f;
        glutPostRedisplay();
        break;
    case 'f':
        glClear(GL_COLOR_BUFFER_BIT);
        zfar += 0.1f;
        glutPostRedisplay();
        break;
    case 'F':
        glClear(GL_COLOR_BUFFER_BIT);
        zfar -= 0.1f;
        glutPostRedisplay();
        break;


    case 'q':
        glClear(GL_COLOR_BUFFER_BIT);
        eyex += 0.1f;
        glutPostRedisplay();
        break;

    case 'Q':
        glClear(GL_COLOR_BUFFER_BIT);
        eyex -= 0.1f;
        glutPostRedisplay();
        break;

    case 'w':
        glClear(GL_COLOR_BUFFER_BIT);
        eyey += 0.1f;
        glutPostRedisplay();
        break;

    case 'W':
        glClear(GL_COLOR_BUFFER_BIT);
        eyey -= 0.1f;
        glutPostRedisplay();
        break;

    case 'e':
        glClear(GL_COLOR_BUFFER_BIT);
        eyez += 0.1f;
        glutPostRedisplay();
        break;

    case 'E':
        glClear(GL_COLOR_BUFFER_BIT);
        eyez -= 0.1f;
        glutPostRedisplay();
        break;

    case 'r':
        glClear(GL_COLOR_BUFFER_BIT);
        cx += 0.1f;
        glutPostRedisplay();
        break;

    case 'R':
        glClear(GL_COLOR_BUFFER_BIT);
        cx -= 0.1f;
        glutPostRedisplay();
        break;

    case 't':
        glClear(GL_COLOR_BUFFER_BIT);
        cy += 0.1f;
        glutPostRedisplay();
        break;

    case 'T':
        glClear(GL_COLOR_BUFFER_BIT);
        cy -= 0.1f;
        glutPostRedisplay();
        break;

    case 'y':
        glClear(GL_COLOR_BUFFER_BIT);
        cz += 0.1f;
        glutPostRedisplay();
        break;
    case 'Y':
        glClear(GL_COLOR_BUFFER_BIT);
        cz -= 0.1f;
        glutPostRedisplay();
        break;

    case 'u':
        glClear(GL_COLOR_BUFFER_BIT);
        upx += 0.1f;
        glutPostRedisplay();
        break;
    case 'U':
        glClear(GL_COLOR_BUFFER_BIT);
        upx -= 0.1f;
        glutPostRedisplay();
        break;

    case 'i':
        glClear(GL_COLOR_BUFFER_BIT);
        upy += 0.1f;
        glutPostRedisplay();
        break;

    case 'I':
        glClear(GL_COLOR_BUFFER_BIT);
        upy -= 0.1f;
        glutPostRedisplay();
        break;

    case 'o':
        glClear(GL_COLOR_BUFFER_BIT);
        upz += 0.1f;
        glutPostRedisplay();
        break;

    case 'O':
        glClear(GL_COLOR_BUFFER_BIT);
        upz -= 0.1f;
        glutPostRedisplay();
        break;


    default:
        printf("Wrong key");
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutCreateWindow("3D Cube");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
