#include<gl/glut.h>
#include<conio.h>
#include<stdio.h>

float x=60,y=30;
float p=0,q=0.4;
float kx=1,ky=3;
int shoot=0,choice=0,point=0;
char starts[]="Click to Start Game!!";
char _score[]="HighScore: ";
char difficulty[]="EasyMediumHard";
char go[]="Game Over !!";
int level=1;//difficulty
int window=1;//Window no
int pointu,pointt;
int attempt=8;
char inst[]="Press N for New Game , Q to quit";
char ch[]="Press P-Pause  S-Shoot  Esc-back";
char attempts[]="Attempts left";
char hs[3];



void gameover()
{

	glColor3f(0,0,0);
	glRasterPos3f(25,65,0);
	for(int i=0;go[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,go[i]);

	glRasterPos3f(25,55,0);
	for(int i=0;inst[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,inst[i]);
	glRasterPos3f(25,45,0);
	for(int i=4;_score[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,_score[i]);
	glRasterPos3f(32,45,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pointt+48);
	glRasterPos3f(33.4,45,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pointu+48);


}

void instruction_window()
{
	glColor3f(0,0,0);
	glRasterPos3f(15,35,0);
	for(int i=0;ch[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch[i]);
}

void update(int msec) 
{ 
 
        glutPostRedisplay();
        glutTimerFunc(1000, update, 3);
}



// Level window
void level_func()
{
	
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(5,34);
	glVertex2f(5,37);
	glVertex2f(13,37);
	glVertex2f(13,34);
	glEnd();

	glRasterPos3f(6,35,0);
	for(int i=0;i<=3;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,difficulty[i]);

	glBegin(GL_LINE_LOOP);
	glVertex2f(20,34);
	glVertex2f(20,37);
	glVertex2f(30,37);
	glVertex2f(30,34);
	glEnd();

	glRasterPos3f(21,35,0);
	for(int i=4;i<=9;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,difficulty[i]);

	glBegin(GL_LINE_LOOP);
	glVertex2f(36,34);
	glVertex2f(36,37);
	glVertex2f(44,37);
	glVertex2f(44,34);
	glEnd();

	glRasterPos3f(37,35,0);
	for(int i=10;i<=13;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,difficulty[i]);

}

//Pause function
void pause()
{
	glBegin(GL_QUADS);
	glVertex2f(1,68);
	glVertex2f(1.5,68);
	glVertex2f(1.5,66);
	glVertex2f(1,66);
	glVertex2f(2,68);
	glVertex2f(2.5,68);
	glVertex2f(2.5,66);
	glVertex2f(2,66);
	glEnd();
}

//Game score function
void score()
{

	glColor3f(0,0,1);
	glRasterPos3f(58,55,0);
	for(int i=4;_score[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,_score[i]);

	pointt=point/10;
	pointu=point%10;
	glRasterPos3f(65,55,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pointt+48);
	glRasterPos3f(66.5,55,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pointu+48);

	glRasterPos3f(20,55,0);
	for(int i=0;attempts[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,attempts[i]);

	glRasterPos3f(36,55,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,attempt+49);




	
}


void start()
{
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,38);
	glVertex2f(58,38);
	glVertex2f(58,33);
	glVertex2f(10,33);
	glEnd();


	glRasterPos3f(25,35,0);
	for(int i=0;starts[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,starts[i]);


}
	

// Gun definition
void gun()
{
	
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(x+0.2,y-1);
	glVertex2f(x+0.5,y-1.2);
	glVertex2f(x+4.3,y-1.2);
	glVertex2f(x+4,y-1);
	glVertex2f(x+0.2,y-1);

	glEnd();

	glBegin(GL_POLYGON);//Body
	glColor3f(0,0,0);
	glVertex2f(x,y);
	glVertex2f(x,y-0.5);
	glVertex2f(x+0.2,y-0.7);
	glVertex2f(x+0.2,y-1);
	glVertex2f(x+4,y-1);
	glVertex2f(x+4.3,y-1.2);
    glVertex2f(x+6.5,y-1.2);
	glVertex2f(x+8,y-1.2);
	glVertex2f(x+9,y-1);
	glVertex2f(x+9,y);
	glVertex2f(x,y);

	glEnd();

	glBegin(GL_POLYGON);//Handle
	glColor3f(0,0,0);
	glVertex2f(x+6.5,y-1.2);
	glVertex2f(x+6.5,y-2);
	glVertex2f(x+7.7,y-4);
	glVertex2f(x+9.7,y-4);
	glVertex2f(x+8,y-1.2);
	glEnd();

	glLineWidth(3.0);//Frame
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+3.5,y-1.1);
	glVertex2f(x+3.5,y-2.5);
	glVertex2f(x+6,y-2.5);
	glVertex2f(x+6.5,y-2);
	glVertex2f(x+6.5,y-1.1);
	glVertex2f(x+3.5,y-1.1);
	glEnd();

	glLineWidth(1.0);

	glBegin(GL_POLYGON);
	glVertex2f(x+5.5,y-1.2);
	glVertex2f(x+5.3,y-1.8);
	glVertex2f(x+4.6,y-2.3);
	glVertex2f(x+6,y-1.2);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(1,0,0);
	glVertex2f(x+6,y);
	glVertex2f(x+6.2,y-1);
	
	glColor3f(0,1,0);
	glVertex2f(x+6.2,y);
	glVertex2f(x+6.4,y-1);
	

	glColor3f(0,0,1);
	glVertex2f(x+6.4,y);
	glVertex2f(x+6.6,y-1);
	
	glColor3f(1,0,0);
	glVertex2f(x+6.6,y);
	glVertex2f(x+6.8,y-1);
	glVertex2f(x+6.8,y);
    glEnd();

}

// Bullet definition
void bullet()
{
	glColor3f(1,0.9,0.1);
	if(p-x>-0.1)
	{
		p=0.0;
	    shoot=0;
		attempt--;
		printf("%d\n",attempt);
	}

	glTranslated(-p,-q,0);
	glBegin(GL_POLYGON);
	glColor3f(1,0,1);
	glVertex2f(x,y);
	glVertex2f(x,y-0.4);
	glVertex2f(x-0.4,y-0.4);
	glVertex2f(x-0.6,y-0.2);
	glVertex2f(x-0.4,y);
	glEnd();
	glFlush();
	glLoadIdentity();
}

// Apple definition
void apple()
{

	if(ky>=45)
	ky=0;
	ky+=0.03*level;
	glTranslated(kx,ky,0);
	glColor3f(1,0,0);
	glutSolidSphere(1,8,8);
	glColor3f(0,0,0);
	glLineWidth(2.0);
	glFlush();
	glLoadIdentity();
	glutPostRedisplay();

}



void myinit(void)
{
glClearColor(1,0.995,0.995,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();	
gluOrtho2D(0,70,0,70);
glMatrixMode(GL_MODELVIEW);

}



void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);//background
	glColor4f(0.7, 0.9, 1.0, .7);
	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(0,70);
	glVertex2f(70,70);
	glVertex2f(70,0);
	glEnd();

	apple();
	gun();
	pause();
	if(p>=58 &&(ky>28 && ky<30) && (attempt))
	{
		point+=level;
		p=0;
		shoot=0;

	}
	if(shoot==1)
	{
	bullet();
	p+=0.15*level;
	}


}

//Display function handling different windows
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0,0,700,700);

	switch(window)
	{
	case 1:
	level_func();
	break;

    case 2: 
	if(!choice)
	start();
	break;
	
	case 3:
	if(attempt+1)
	{
	display2();
	score();
	}
	else
	gameover();
	glLoadIdentity();
	break;

	case 4:
	instruction_window();
	break;

	default: exit(0);
	}
	glLoadIdentity();
	glutSwapBuffers();
}

// Event handler - Keyboard 
void keys(unsigned char key,int x,int y)
{
	if(key=='s'||key=='S')
	{
	shoot=1;
	display();
	}

	else if(key=='p'||key=='P')
	{
		printf("keyboard func");
		window=4;
		display();
	}

	else if(key==27)
	{
		window--;
		display();
	}

	else if(key=='N' || key=='n')
	{
		window=3;
		attempt=8;
		point=0;
		display();
	}

	if(key=='q' || key=='Q')
		exit(0);

}


//Event handler for choosing level - Mouse
void mouse(int btn,int state,int x,int y)
{
	

	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && window==3)
	if((x>=39 || x<=326)&&(y>=17 && y<=40))
	{
		window=4;
		display();
	}


	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && window==1)
	if(y>=340 && y<=370)
	{
		if(x>=50 && x<=130)
		{
			level=1;
			window=2;
		}
		
		if(x>=200 && x<=300)
		{
			level=2;
			window=2;
		}
		
		if(x>=360 && x<=440)
		{
			level=3;
			window=2;
		}
		display();

	}


	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && window==2)
	if((y>330 && y<380) && (x>100 && x<580))
	{
		choice=0;
		window=3;
		display();
	}



}

//Main function
void main(int argc,char **argv)
{

	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(700,700);
	glutCreateWindow("SAA");
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
    
	myinit();
	glutMainLoop();
}
