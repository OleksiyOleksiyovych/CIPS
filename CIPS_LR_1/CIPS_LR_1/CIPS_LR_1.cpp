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
	glutCreateWindow("Лабораторна №1"); 
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
	cout << "\tЗробiть вибiр: \r\n"
		<< "\t <0> - зображення\r\n"
		<< "\t <1> - точки\r\n"
		<< "\t <2> - лiнiї\r\n"
		<< "\t <3> - трикутники\r\n"
		<< "\t <4> - чотирикутники\r\n"
		<< "\t <5> - списки\r\n"
		<< "\t <esc> - ВИХIД\r\n";
}

void keyboard(unsigned char key, int x, int y) 
{ 
	switch (key)
	{
	case '1':	// точки
		system ("cls");
		glutDisplayFunc(displayPoints);
		cout << "--- Точки ---\r\n"
			<< " червона: (0.9, 0.9),  розмiр:6px, без згладження\r\n"
			<< " зелена : (-0.1, 0.5), розмiр:6px, без згладження\r\n"
			<< " синя   : (0.1, -0.1), розмiр:7px, зi згладженням\r\n"
			<< " бiла   : (0.0, 0.0),  розмiр:7px, зi згладженням\r\n" ;
		Menu();
		break;
	case '2':	// лінії
		system ("cls");
		glutDisplayFunc(displayLines);
		cout << "--- Лiнiї ---\r\n"
			<< " зелена  : GL_LINES,      товщина:2px, без згладження\r\n"
			<< " чорна   : GL_LINES,      товщина:2px, зi згладженням\r\n"
			<< " червона : GL_LINES,      товщина:4px, зi згладженням, штриховка (dashed)\r\n"
			<< " бiла    : GL_LINES,      товщина:4px, без згладження, штриховка (dashed)\r\n"
			<< " жовта   : GL_LINE_STRIP, товщина:1px, без згладження\r\n"
			<< " блакитна: GL_LINE_LOOP,  товщина:1px, без згладження\r\n" ;
		Menu();
		break;
	case '3':	// трикутники
		system ("cls");
		glutDisplayFunc(displayTriangles);
		cout << "--- Трикутники ---\r\n"
			<< " зелений : GL_TRIANGLES,       товщина:4px, без згладження, штриховка (dashed)\r\n"
			<< " синiй   : GL_TRIANGLES_STRIP, товщина:1px, без згладження\r\n"
			<< " червоний: GL_TRIANGLES_FAN,   товщина:1px, без згладження\r\n" ;
		Menu();
		break;
	case '4':	// прямокутники
		glutDisplayFunc(displayQuads);
		system ("cls");
		cout << "--- Прямокутники ---\r\n"
			<< " зелений: GL_QUADS\r\n"
			<< " бiлий  : GL_QUAD_STRIP\r\n"
			<< " чорний : GL_POLYGON\r\n" ;
		Menu();
		break;
	case '5':	// багатокутник		
		system ("cls");
		glutDisplayFunc(displayList);
		cout << "--- Списки ---\r\n";
		Menu();
		break;
	case '0':	// 
		system ("cls");
		glutDisplayFunc(display);	
		cout << "--- Зображення iз примiтивiв ---\r\n";
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
	glColor3f (1.0, 1.0, 1.0);	// білий
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
	glColor3f (1.0, 0.0, 0.0);	// червоний  
	glVertex2f (.90, .90);
	glEnd ();

	glBegin (GL_POINTS); 
	glColor3f (0.0, 1.0, 0.0);  // зелена
	glVertex2f (-.10, .50); 
	glEnd ();

	glPointSize(7.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin (GL_POINTS); 
	glColor3f (0.0, 0.0, 1.0);  // синій
	glVertex2f (.10, -.10); 
	glColor3f (1.0, 1.0, 1.0);  // білий
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
	glColor3f (0.0, 1.0, 0.0);	// зелена 
	glVertex2f (0.5, 0.6); 
	glVertex2f (-0.5, 0.65); 
	glEnd ();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);               

	glBegin (GL_LINES); 
	glColor3f (0.0, 0.0, 0.0);	// чорна 
	glVertex2f (0.5, 0.35); 
	glVertex2f (-0.5, 0.45); 
	glEnd ();

	glEnable (GL_LINE_STIPPLE);
	glLineWidth(4.0);
	glLineStipple (3, 0x1C47);	// dashed 
	glBegin (GL_LINES); 
	glColor3f (1.0, 0.0, 0.0);	// червона
	glVertex2f (0.3, -0.2); 
	glVertex2f (-0.2, -0.3); 
	glEnd ();

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);	

	glBegin (GL_LINES); 
	glColor3f (1.0, 1.0, 1.0);	// біла 
	glVertex2f (0.6, -0.7); 
	glVertex2f (-0.6, 0.7); 
	glEnd ();
	glDisable (GL_LINE_STIPPLE); 

	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glColor3f (1.0, 1.0, 0.0);	// жовта
	glVertex2f (0.7, 0.7); 
	glVertex2f (0.5, 0.5); 
	glVertex2f (0.2, 0.7); 
	glVertex2f (-0.1, 0.5); 
	glVertex2f (-0.5, 0.7); 
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f (0.0, 1.0, 1.0);	// блакитна
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
	glColor3f (0.0, 1.0, 0.0);	// зелений 
	glVertex2f (0.9, 0.9); 
	glVertex2f (-0.9, 0.8); 
	glVertex2f (-0.1, -0.8); 
	glEnd();
	glDisable(GL_POLYGON_SMOOTH_HINT);
	glDisable(GL_BLEND);


	glEnable (GL_POLYGON_STIPPLE);
	glPolygonStipple (halftone);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f (1.0, 0.0, 0.0);	// червоний 
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
	glColor3f (0.0, 0.0, 1.0);	// синій 
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
	glColor3f (0.0, 1.0, 0.0);	// зелений 
	glVertex2f (0.7, 0.7); 
	glVertex2f (-0.5, 0.7); 
	glVertex2f (-0.7, -0.7); 
	glVertex2f (0.5, -0.7); 
	glEnd();
	glDisable(GL_POLYGON_SMOOTH_HINT);
	glDisable(GL_BLEND);

	glBegin(GL_QUAD_STRIP);
	glColor3f (1.0, 1.0, 1.0);	// білий
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
	glColor3f (0.0, 0.0, 0.0);	// чорний
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

//малювання торусу
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