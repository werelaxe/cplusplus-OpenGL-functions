#include <GL/glut.h>
#include <stdio.h>

float win_width = 400.0;
float win_height = 400.0;


float f(float x)
{
   return x * x / 100 - 100;
}

void draw_func()
{
   glVertex2f(-win_width / 2, f(-win_width / 2));
   for (float x = -win_width / 2; x < win_width / 2; x += 1)
   {
      glVertex2f(x, f(x));
      glVertex2f(x, f(x));
   }
}

void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glBegin(GL_LINES);
   draw_func();
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
   glOrtho(-win_width/2, win_width/2, -win_height/2, win_height/2, -200.0, 200.0);
   //glOrtho(0, win_width, win_height, 0, -200.0, 200.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{


   glutInit(&argc, argv);

   int screen_width = glutGet(GLUT_SCREEN_WIDTH);
   int screen_height = glutGet(GLUT_SCREEN_HEIGHT);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(win_width, win_height);


   glutInitWindowPosition((screen_width - win_width) / 2, (screen_height - win_height) / 2);
   glutCreateWindow("functions");
   glutDisplayFunc(Draw);
   glutMotionFunc(MousePressedMove);
   glutPassiveMotionFunc(MouseMove);
   glutMouseFunc(MousePressed);
   glutTimerFunc(50, Timer, 0);
   Initialize();
   glutMainLoop();
   return 0;
}