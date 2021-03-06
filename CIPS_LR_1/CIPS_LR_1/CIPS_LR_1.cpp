#include "stdafx.h" 

void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

void display(void);
void displayPoints(void);
void displayLines(void);
void displayTriangles(void);
void displayQuads(void);
void displayPoligon(void);
void displayList(void);

void torus(int numc,int numt, double size);

void Menu(void);

GLuint theTorus; 

int main(int argc, char**argv) 
{ 
	setlocale(LC_ALL, "Russian");

	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE); //set the display to Double buffer 
	glutInitWindowSize(300, 300); 
	glutCreateWindow("����������� �1"); 
	init(); // call the init function 

	Menu();

	glutDisplayFunc(display);		//use the display function to draw everything 
	glutReshapeFunc(reshape);		//reshape the window accordingly 
	glutPostRedisplay();
	glutKeyboardFunc(keyboard);		//check the keyboard 

	glutMainLoop(); //call the main loop 
	return 0; 
}

void Menu(void)
{
	cout << "\t����i�� ���i�: \r\n"
		<< "\t <0> - ����������\r\n"
		<< "\t <1> - �����\r\n"
		<< "\t <2> - �i�i�\r\n"
		<< "\t <3> - ����������\r\n"
		<< "\t <4> - �������������\r\n"
		<< "\t <5> - ������\r\n"
		<< "\t <esc> - ���I�\r\n";
}

void keyboard(unsigned char key, int x, int y) 
{ 
	switch (key)
	{
	case '1':	// �����
		system ("cls");
		glutDisplayFunc(displayPoints);
		cout << "--- ����� ---\r\n"
			<< " �������: (0.9, 0.9),  ����i�:6px, ��� ����������\r\n"
			<< " ������ : (-0.1, 0.5), ����i�:6px, ��� ����������\r\n"
			<< " ����   : (0.1, -0.1), ����i�:7px, �i �����������\r\n"
			<< " �i��   : (0.0, 0.0),  ����i�:7px, �i �����������\r\n" ;
		Menu();
		break;
	case '2':	// ����
		system ("cls");
		glutDisplayFunc(displayLines);
		cout << "--- �i�i� ---\r\n"
			<< " ������  : GL_LINES,      �������:2px, ��� ����������\r\n"
			<< " �����   : GL_LINES,      �������:2px, �i �����������\r\n"
			<< " ������� : GL_LINES,      �������:4px, �i �����������, ��������� (dashed)\r\n"
			<< " �i��    : GL_LINES,      �������:4px, ��� ����������, ��������� (dashed)\r\n"
			<< " �����   : GL_LINE_STRIP, �������:1px, ��� ����������\r\n"
			<< " ��������: GL_LINE_LOOP,  �������:1px, ��� ����������\r\n" ;
		Menu();
		break;
	case '3':	// ����������
		system ("cls");
		glutDisplayFunc(displayTriangles);
		cout << "--- ���������� ---\r\n"
			<< " ������� : GL_TRIANGLES,       �������:4px, ��� ����������, ��������� (dashed)\r\n"
			<< " ���i�   : GL_TRIANGLES_STRIP, �������:1px, ��� ����������\r\n"
			<< " ��������: GL_TRIANGLES_FAN,   �������:1px, ��� ����������\r\n" ;
		Menu();
		break;
	case '4':	// ������������
		glutDisplayFunc(displayQuads);
		system ("cls");
		cout << "--- ������������ ---\r\n"
			<< " �������: GL_QUADS\r\n"
			<< " �i���  : GL_QUAD_STRIP\r\n"
			<< " ������ : GL_POLYGON\r\n" ;
		Menu();
		break;
	case '5':	// ������������		
		system ("cls");
		glutDisplayFunc(displayList);
		cout << "--- ������ ---\r\n";
		Menu();
		break;
	case '0':	// 
		system ("cls");
		glutDisplayFunc(display);	
		cout << "--- ���������� i� ����i���i� ---\r\n";
		Menu();
		break;
	case 27:
		exit(0);
	}

	glutPostRedisplay();
} 

void reshape(int w, int h) 
{ 
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); // set the matrix to projection 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	//set the matrix back to model
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
} 

void init(void) 
{ 
	glShadeModel(GL_SMOOTH); //set the shader to smooth shader

	theTorus=glGenLists(1); 
	glNewList(theTorus, GL_COMPILE); 

	glPolygonMode(GL_FRONT,GL_LINE); 
	glPolygonMode(GL_BACK,GL_LINE); 
	glLineWidth(1.0);

	torus(20, 50, 0.6); 

	glPolygonMode(GL_BACK,GL_FILL); 
	glPolygonMode(GL_FRONT,GL_FILL); 

	glEndList(); 
	glShadeModel(GL_FLAT); 
	glClearColor(0.0, 0.0, 0.0, 0.0); 
} 

void displayList()
{
	glClear(GL_COLOR_BUFFER_BIT);  // clear the color 
	glColor3f(1.0, 1.0, 1.0); 
	glCallList(theTorus);

	glFlush(); 
	glutSwapBuffers(); // swap the buffers 
}

void display(void) 
{ 
	glClearColor(0.2, 0.3, 1.0, 0.2);  // clear the screen to blue 
	glClear(GL_COLOR_BUFFER_BIT);  // clear the color 

	glPolygonMode(GL_FRONT,GL_LINE); 
	glPolygonMode(GL_BACK,GL_LINE); 
	glLineWidth(2.0);

	glBegin(GL_QUAD_STRIP);
	glColor3f (1.0, 1.0, 1.0);	// ����
	glVertex2f (-0.6, -0.6); 
	glVertex2f ( 0.2, -0.6);
	glVertex2f (-0.6,  0.2); 
	glVertex2f ( 0.2,  0.2); 

	glVertex2f (-0.2, 0.6); 
	glVertex2f ( 0.6, 0.6); 

	glVertex2f (-0.2, -0.2); 
	glVertex2f ( 0.6, -0.2); 

	glVertex2f (-0.6, -0.6); 
	glVertex2f ( 0.2, -0.6);
	glEnd();

	glPolygonMode(GL_BACK,GL_FILL); 
	glPolygonMode(GL_FRONT,GL_FILL); 

	glutSwapBuffers(); // swap the buffers 
}

void displayPoints(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 

	glPointSize(6.0);
	glBegin (GL_POINTS); 
	glColor3f (1.0, 0.0, 0.0);	// ��������  
	glVertex2f (.90, .90);
	glEnd ();

	glBegin (GL_POINTS); 
	glColor3f (0.0, 1.0, 0.0);  // ������
	glVertex2f (-.10, .50); 
	glEnd ();

	glPointSize(7.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin (GL_POINTS); 
	glColor3f (0.0, 0.0, 1.0);  // �����
	glVertex2f (.10, -.10); 
	glColor3f (1.0, 1.0, 1.0);  // ����
	glVertex2f (0.0, 0.0);
	glEnd ();
	glDisable(GL_POINT_SMOOTH);

	glFlush (); 
	glutSwapBuffers(); 
}

void displayLines(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 

	glLineWidth(2.0);
	glBegin (GL_LINES); 
	glColor3f (0.0, 1.0, 0.0);	// ������ 
	glVertex2f (0.5, 0.6); 
	glVertex2f (-0.5, 0.65); 
	glEnd ();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);               

	glBegin (GL_LINES); 
	glColor3f (0.0, 0.0, 0.0);	// ����� 
	glVertex2f (0.5, 0.35); 
	glVertex2f (-0.5, 0.45); 
	glEnd ();

	glEnable (GL_LINE_STIPPLE);
	glLineWidth(4.0);
	glLineStipple (3, 0x1C47);	// dashed 
	glBegin (GL_LINES); 
	glColor3f (1.0, 0.0, 0.0);	// �������
	glVertex2f (0.3, -0.2); 
	glVertex2f (-0.2, -0.3); 
	glEnd ();

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);	

	glBegin (GL_LINES); 
	glColor3f (1.0, 1.0, 1.0);	// ��� 
	glVertex2f (0.6, -0.7); 
	glVertex2f (-0.6, 0.7); 
	glEnd ();
	glDisable (GL_LINE_STIPPLE); 

	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glColor3f (1.0, 1.0, 0.0);	// �����
	glVertex2f (0.7, 0.7); 
	glVertex2f (0.5, 0.5); 
	glVertex2f (0.2, 0.7); 
	glVertex2f (-0.1, 0.5); 
	glVertex2f (-0.5, 0.7); 
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f (0.0, 1.0, 1.0);	// ��������
	glVertex2f (0.7, -0.7); 
	glVertex2f (0.5, -0.5); 
	glVertex2f (0.2, -0.6); 
	glVertex2f (-0.1, -0.5); 
	glVertex2f (-0.5, -0.7); 
	glEnd();

	glFlush (); 
	glutSwapBuffers (); 
}

void displayTriangles(void)
{
	GLubyte halftone[]= { 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55, 
		0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55 
	};

	glClear(GL_COLOR_BUFFER_BIT); 

	glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_POLYGON_SMOOTH_HINT);
	glBegin(GL_TRIANGLES);
	glColor3f (0.0, 1.0, 0.0);	// ������� 
	glVertex2f (0.9, 0.9); 
	glVertex2f (-0.9, 0.8); 
	glVertex2f (-0.1, -0.8); 
	glEnd();
	glDisable(GL_POLYGON_SMOOTH_HINT);
	glDisable(GL_BLEND);


	glEnable (GL_POLYGON_STIPPLE);
	glPolygonStipple (halftone);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f (1.0, 0.0, 0.0);	// �������� 
	glVertex2f (-0.1, -0.1); 
	glVertex2f (-0.1, -0.5); 
	glVertex2f (-0.2, -0.5); 
	glVertex2f (-0.3, -0.15); 
	glVertex2f (-0.3, -0.9); 
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);     

	glPolygonMode(GL_FRONT,GL_LINE); 
	glPolygonMode(GL_BACK,GL_LINE); 
	glLineWidth(3.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f (0.0, 0.0, 1.0);	// ����� 
	glVertex2f (0.1, 0.1); 
	glVertex2f (0.1, 0.5); 
	glVertex2f (0.2, 0.6); 
	glVertex2f (0.4, 0.6); 
	glVertex2f (0.3, 0.3); 
	glEnd();
	glPolygonMode(GL_BACK,GL_FILL); 
	glPolygonMode(GL_FRONT,GL_FILL); 

	glDisable(GL_LINE_SMOOTH);   
	glDisable(GL_BLEND);

	glFlush (); 
	glutSwapBuffers (); 
}

void displayQuads(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 

	glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_POLYGON_SMOOTH_HINT);
	glBegin(GL_QUADS);
	glColor3f (0.0, 1.0, 0.0);	// ������� 
	glVertex2f (0.7, 0.7); 
	glVertex2f (-0.5, 0.7); 
	glVertex2f (-0.7, -0.7); 
	glVertex2f (0.5, -0.7); 
	glEnd();
	glDisable(GL_POLYGON_SMOOTH_HINT);
	glDisable(GL_BLEND);

	glBegin(GL_QUAD_STRIP);
	glColor3f (1.0, 1.0, 1.0);	// ����
	glVertex2f (0.1, 0.1); 
	glVertex2f (0.1, 0.3);
	glVertex2f (0.3, 0.1); 
	glVertex2f (0.3, 0.3); 

	glVertex2f (0.5, 0.3); 
	glVertex2f (0.5, 0.5); 

	glVertex2f (0.7, 0.3); 
	glVertex2f (0.7, 0.5); 
	glEnd();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);     

	glPolygonMode(GL_FRONT,GL_LINE); 
	glPolygonMode(GL_BACK,GL_LINE); 
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glColor3f (0.0, 0.0, 0.0);	// ������
	glVertex2f (-0.2, -0.1); 
	glVertex2f (-0.3, -0.1); 
	glVertex2f (-0.4, -0.2); 
	glVertex2f (-0.4, -0.3); 
	glVertex2f (-0.3, -0.4); 
	glVertex2f (-0.2, -0.4); 
	glVertex2f (-0.1, -0.3); 
	glVertex2f (-0.1, -0.2); 
	glEnd();

	glPolygonMode(GL_BACK,GL_FILL); 
	glPolygonMode(GL_FRONT,GL_FILL); 

	glDisable(GL_LINE_SMOOTH);   
	glDisable(GL_BLEND);

	glFlush (); 
	glutSwapBuffers (); 
}

//��������� ������
void torus(int numc, int numt, double size) 
{ 
	double s,t,x,y,z; 
	double twopi = 2 * (double)3.1415; 
	for(int i=0; i<numc; i++) 
	{ 
		glBegin(GL_QUAD_STRIP); 
		for(int j=0; j<=numt; j++) 
		{ 
			for(int k=1; k>=0; k--) 
			{ 
				s = (i+k) % numc + 0.5; 
				t = j % numt; 
				x = (size+.1*cos(s*twopi/numc)) * cos(t*twopi/numt); 
				y = (size+.1*cos(s*twopi/numc)) * sin(t*twopi/numt); 
				z = .1 * sin(s*twopi/numc); 
				glVertex3f(x, y, z); 
			} 
		} 
		glEnd(); 
	} 
} 