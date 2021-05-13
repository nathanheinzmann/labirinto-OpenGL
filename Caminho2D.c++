#include <stdio.h>
#include <GL/glut.h>

#define TAM_JANELA 50.0
int x=-50, y=45, direction=3, erros=0, pontos=1500;

void Verifica(){
  if(
    x == -50 && y ==  45 || x == -45 && y ==  45 || x == -40  && y ==  45  || x == -35 && y ==  45 ||
    x == -30 && y ==  45 || x == -25 && y ==  45 || x == -20  && y ==  45  || x == -20 && y ==  40 ||
    x == -20 && y ==  35 || x == -20 && y ==  30 || x == -20  && y ==  25  || x == -25 && y ==  25 ||
    x == -25 && y ==  20 || x == -25 && y ==  15 || x == -25  && y ==  10  || x == -30 && y ==  10 ||
    x == -35 && y ==  10 || x == -40 && y ==  10 || x == -45  && y ==  10  || x == -45 && y ==   5 ||
    x == -45 && y ==   0 || x == -45 && y ==  -5 || x == -45  && y == -10  || x == -45 && y == -15 ||
    x == -45 && y == -20 || x == -45 && y == -25 || x == -45  && y == -30  || x == -45 && y == -35 ||
    x == -45 && y == -40 || x == -40 && y == -40 || x == -35  && y == -40  || x == -30 && y == -40 ||
    x == -25 && y == -40 || x == -20 && y == -40 || x == -15  && y == -40  || x == -10 && y == -40 ||
    x == -10 && y == -35 || x == -10 && y == -30 || x == -10  && y == -25  || x == -10 && y == -20 ||
    x == -10 && y == -15 || x == -10 && y == -10 || x == -10  && y ==  -5  || x == -10 && y ==   0 ||
    x == -10 && y ==   5 || x == -10 && y ==  10 || x == -10  && y ==  15  || x == -10 && y ==  20 ||
    x == -10 && y ==  25 || x == -10 && y ==  30 || x == -10  && y ==  35  || x == -10 && y ==  40 ||
    x == -10 && y ==  45 || x ==  -5 && y ==  45 || x ==   0  && y ==  45  || x ==   5 && y ==  45 ||
    x ==  10 && y ==  45 || x ==  15 && y ==  45 || x ==  15  && y ==  50  || x ==  20 && y ==  50 ||
    x ==  25 && y ==  50 || x ==  25 && y ==  45 || x ==  25  && y ==  40  || x ==  25 && y ==  35 ||
    x ==  25 && y ==  30 || x ==  30 && y ==  30 || x ==  35  && y ==  30  || x ==  35 && y ==  25 ||
    x ==  35 && y ==  20 || x ==  35 && y ==  15 || x ==  35  && y ==  10  || x ==  35 && y ==   5 ||
    x ==  40 && y ==   5 ){
    ;
  }
  else if(x ==  45 && y ==  5){
    printf("Acabou\nErros: %d\nPontos: %d\n", erros, pontos);
    
  }
  else{
    erros++;
    printf("Volte para dentro do percurso\n");
    pontos -= 50;
  }
}

float Modulo(float n){
	return n < 0 ?( n *(-1) ) :(n); 
}

float Distancia(float p1, float p2){
	if((p1 >= 0.00) &&(p2 >= 0.00) ||(p1 < 0.00) &&(p2 < 0.00) ) return( Modulo(p2 - p1) );
	else return((Modulo(p1) + Modulo(p2)) );
}

void FlechaRight(float x_p1, float y_p1, float altura, int quadro){
	float x_p2, y_p2, x_base;
	x_p2 = x_p1 + altura;
	y_p2 = y_p1 + altura;
		
	glColor3f(0.0f, 0.0f, 5.0f);
	x_base = Distancia(x_p1, x_p2) / 2;
	glBegin(GL_TRIANGLES);
		glVertex2f(x_p1,(y_p2 - altura) );
		glVertex2f(x_p1, y_p2);
		glVertex2f(x_p2,(y_p2 + 2.5 - altura) );
	glEnd();
}

void FlechaLeft(float x_p1, float y_p1, float altura, int quadro){
	float x_p2, y_p2, x_base;
	x_p2 = x_p1 + altura;
	y_p2 = y_p1 + altura;
		
	glColor3f(0.0f, 0.0f, 5.0f);
	x_base = Distancia(x_p1, x_p2) / 2;
	glBegin(GL_TRIANGLES);
    glVertex2f(x_p2 - 5,(y_p2 + 2.5 - altura) );
		glVertex2f(x_p1+ 5, y_p2);
		glVertex2f(x_p1+ 5,(y_p2 - altura) );
	glEnd();
}

void FlechaUp(float x_p1, float y_p1, float altura, int quadro){
	float x_p2, y_p2, x_base;
	x_p2 = x_p1 + altura;
	y_p2 = y_p1 + altura;
		
	glColor3f(0.0f, 0.0f, 5.0f);
	x_base = Distancia(x_p1, x_p2) / 2;
	glBegin(GL_TRIANGLES);
    glVertex2f(x_p2-5,(y_p2 - altura) );
		glVertex2f(x_p1+2.5, y_p2);
		glVertex2f(x_p1+5,(y_p2 - altura) );
	glEnd();
}

void FlechaDown(float x_p1, float y_p1, float altura, int quadro){
	float x_p2, y_p2, x_base;
	x_p2 = x_p1 + altura;
	y_p2 = y_p1 + altura;
		
	glColor3f(0.0f, 0.0f, 5.0f);
	x_base = Distancia(x_p1, x_p2) / 2;
	glBegin(GL_TRIANGLES);
    glVertex2f(x_p2-5,(y_p2) );
		glVertex2f(x_p1+2.5, y_p2 - altura);
		glVertex2f(x_p1+5,(y_p2) );
	glEnd();
}

void Percurso(){
/* Coordenadas do percurso correto
  |----------------------|----------------------|----------------------|----------------------|
  | x = -50 ---  y =  45 | x = -45 ---  y =  45 | x = -40 ---  y =  45 | x = -35 ---  y =  45 |
  | x = -30 ---  y =  45 | x = -25 ---  y =  45 | x = -20 ---  y =  45 | x = -20 ---  y =  40 |
  | x = -20 ---  y =  35 | x = -20 ---  y =  30 | x = -20 ---  y =  25 | x = -25 ---  y =  25 |
  | x = -25 ---  y =  20 | x = -25 ---  y =  15 | x = -25 ---  y =  10 | x = -30 ---  y =  10 |
  | x = -35 ---  y =  10 | x = -40 ---  y =  10 | x = -45 ---  y =  10 | x = -45 ---  y =   5 |
  | x = -45 ---  y =   0 | x = -45 ---  y =  -5 | x = -45 ---  y = -10 | x = -45 ---  y = -15 |
  | x = -45 ---  y = -20 | x = -45 ---  y = -25 | x = -45 ---  y = -30 | x = -45 ---  y = -35 |
  | x = -45 ---  y = -40 | x = -40 ---  y = -40 | x = -35 ---  y = -40 | x = -30 ---  y = -40 |
  | x = -25 ---  y = -40 | x = -20 ---  y = -40 | x = -15 ---  y = -40 | x = -10 ---  y = -40 |
  | x = -10 ---  y = -35 | x = -10 ---  y = -30 | x = -10 ---  y = -25 | x = -10 ---  y = -20 |
  | x = -10 ---  y = -15 | x = -10 ---  y = -10 | x = -10 ---  y =  -5 | x = -10 ---  y =   0 |
  | x = -10 ---  y =   5 | x = -10 ---  y =  10 | x = -10 ---  y =  15 | x = -10 ---  y =  20 |
  | x = -10 ---  y =  25 | x = -10 ---  y =  30 | x = -10 ---  y =  35 | x = -10 ---  y =  40 |
  | x = -10 ---  y =  45 | x =  -5 ---  y =  45 | x =   0 ---  y =  45 | x =   5 ---  y =  45 |
  | x =  10 ---  y =  45 | x =  15 ---  y =  45 | x =  15 ---  y =  50 | x =  20 ---  y =  50 |
  | x =  25 ---  y =  50 | x =  25 ---  y =  45 | x =  25 ---  y =  40 | x =  25 ---  y =  35 |
  | x =  25 ---  y =  30 | x =  30 ---  y =  30 | x =  35 ---  y =  30 | x =  35 ---  y =  25 |
  | x =  35 ---  y =  20 | x =  35 ---  y =  15 | x =  35 ---  y =  10 | x =  35 ---  y =   5 |
  | x =  40 ---  y =   5 | x =  45 ---  y =   5 |                      |                      |
  |----------------------|----------------------|----------------------|----------------------|
*/
  glBegin(GL_QUADS);
    glColor3f(0.1, 0.7, 0.7);
    glVertex3f(-50, 45, 0);
    glVertex3f(-50, 40, 0);
    glVertex3f(-45, 40, 0);
    glVertex3f(-45, 45, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-45, 45, 0);
    glVertex3f(-45, 40, 0);
    glVertex3f(-15, 40, 0);
    glVertex3f(-15, 45, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-20, 40, 0);
    glVertex3f(-20, 20, 0);
    glVertex3f(-15, 20, 0);
    glVertex3f(-15, 40, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-25, 25, 0);
    glVertex3f(-25,  5, 0);
    glVertex3f(-20,  5, 0);
    glVertex3f(-20, 25, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-45, 10, 0);
    glVertex3f(-45,  5, 0);
    glVertex3f(-25,  5, 0);
    glVertex3f(-25, 10, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-45,   5, 0);
    glVertex3f(-45, -45, 0);
    glVertex3f(-40, -45, 0);
    glVertex3f(-40,   5, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-40, -40, 0);
    glVertex3f(-40, -45, 0);
    glVertex3f( -5, -45, 0);
    glVertex3f( -5, -40, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-10,  45, 0);
    glVertex3f(-10, -45, 0);
    glVertex3f( -5, -45, 0);
    glVertex3f( -5,  45, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(-5, 45, 0);
    glVertex3f(-5, 40, 0);
    glVertex3f(20, 40, 0);
    glVertex3f(20, 45, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(15, 50, 0);
    glVertex3f(15, 45, 0);
    glVertex3f(30, 45, 0);
    glVertex3f(30, 50, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(25, 45, 0);
    glVertex3f(25, 25, 0);
    glVertex3f(30, 25, 0);
    glVertex3f(30, 45, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(30, 30, 0);
    glVertex3f(30, 25, 0);
    glVertex3f(40, 25, 0);
    glVertex3f(40, 30, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(35, 25, 0);
    glVertex3f(35,  0, 0);
    glVertex3f(40,  0, 0);
    glVertex3f(40, 25, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0, 0.45);
    glVertex3f(40, 5, 0);
    glVertex3f(40, 0, 0);
    glVertex3f(45, 0, 0);
    glVertex3f(45, 5, 0);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0, 0.66, 0.2);
    glVertex3f(45, 5, 0);
    glVertex3f(45, 0, 0);
    glVertex3f(50, 0, 0);
    glVertex3f(50, 5, 0);
  glEnd();

}

void Desenha(){
  glClearColor(0.1, 0.1, 0.1, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  Percurso();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, y, 0);

  if(direction == 0){
    FlechaUp(0, -5, 5, 1);
  }
  
  else if(direction == 1){
    FlechaDown(0, -5, 5, 1);
  }
  else if(direction == 2){
    FlechaLeft(0, -5, 5, 1);
  }
  else{
    FlechaRight(0, -5, 5, 1);
  }
  glPopMatrix();
  glFlush();
}

void TeclasEspeciais(int tecla, int x_position, int y_position){
  if(tecla == GLUT_KEY_UP){
		y += 5;
    direction = 0;
	}
	if(tecla == GLUT_KEY_DOWN){
		y -= 5;
    direction = 1;
	}
	if(tecla == GLUT_KEY_LEFT){
		x -= 5;
    direction = 2;
	}
	if(tecla == GLUT_KEY_RIGHT){
		x += 5;
    direction = 3;
	}
  pontos -= 1;
  Verifica();
  glutPostRedisplay();
}

void Inicializa(){
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-TAM_JANELA, TAM_JANELA, -TAM_JANELA, TAM_JANELA);
  glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Caminho 2D Nathan");
  glutDisplayFunc(Desenha);
  glutSpecialFunc(TeclasEspeciais);
  Inicializa();
  glutMainLoop();
  return(0);
}