#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>

float angle = 0.0f;

void leaf(void)
{
	glScalef(0.5, 0.5, 0.0);
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.15, 0.65);
		glVertex2f(.15,0.65);
		glVertex2f(0.0,1.0);
	glEnd();


	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0,0.0);
		glVertex2f(0.3, 0.3);
		glVertex2f(0.0,0.65);
		glVertex2f(-.30,.3);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-0.12, -0.40);
		glVertex2f(0.12,-0.40);
		glVertex2f(0.40, -0.20);
		glVertex2f(0.0, 0.0);
		glVertex2f(-0.40, -0.20);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0, -1.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.25,-0.60);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.12, -0.40);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.12, -0.40);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.60);
	glEnd();


	glFlush();
}
void object_total(){
	for (int i = 36; i <= 360; i = i + 72){
		glPushMatrix();
		glRotatef(float(i), 0.0, 0.0, 1.0);
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

	if(angle >= 360.0f) angle = 0.0f;

	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	object_total();
	glPopMatrix();
	glFlush();
	angle += 0.10f;
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Lab-1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
