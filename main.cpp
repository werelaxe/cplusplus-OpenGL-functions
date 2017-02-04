#include <GL/glut.h>
#include <stdio.h>

float WinWid=400.0;
float WinHei=400.0;
float x=0.0, y=0.0;

void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glBegin(GL_LINES);
      for(float i=0+x; i<=WinWid+x; i+=20.0)
      {
         glVertex2f(i, 0+y);
         glVertex2f(i, WinHei+y);
      }
      for(float i=0+y; i<=WinHei+y; i+=20.0)
      {
         glVertex2f(0+x, i);
         glVertex2f(WinWid+x, i);
      }
   glEnd();
   glPopMatrix();
   glutSwapBuffers();
}

void MouseMove(int ax, int ay)
{
   glutSetWindowTitle("MouseMove called");
}

void MousePressed(int button, int state, int x, int y)
{
   switch(button)
   {
   case GLUT_LEFT_BUTTON: 
      switch(state)
      {
      case GLUT_UP: glutSetWindowTitle("Left button released"); break;
      case GLUT_DOWN: glutSetWindowTitle("Left button pressed"); break;
      }
      break;
   case GLUT_MIDDLE_BUTTON: 
      switch(state)
      {
      case GLUT_UP: glutSetWindowTitle("Middle button released"); break;
      case GLUT_DOWN: glutSetWindowTitle("Middle button pressed"); break;
      }
      break;
   case GLUT_RIGHT_BUTTON: 
      switch(state)
      {
      case GLUT_UP: glutSetWindowTitle("Right button released"); break;
      case GLUT_DOWN: glutSetWindowTitle("Right button pressed"); break;
      }
   }
}

void MousePressedMove(int ax, int ay)
{
   glutSetWindowTitle("MousePressedMove called");
}

void Timer(int value)
{
   glColor3f(1.0, 1.0, 1.0);
   //Draw();
   glutPostRedisplay();
   glutTimerFunc(50, Timer, 0);
}

void Initialize()
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
   glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   int screen_width = glutGet(GLUT_SCREEN_WIDTH);
   int screen_height = glutGet(GLUT_SCREEN_HEIGHT);

   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
   glutInitWindowSize(WinWid, WinHei);


   glutInitWindowPosition(100, 300);
   glutCreateWindow("Lesson 06");
   glutDisplayFunc(Draw);
   glutMotionFunc(MousePressedMove);
   glutPassiveMotionFunc(MouseMove);
   glutMouseFunc(MousePressed);
   glutTimerFunc(50, Timer, 0);
   Initialize();
   glutMainLoop();
   return 0;
}