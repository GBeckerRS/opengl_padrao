#include        <iostream>

#include        <GL/gl.h>
#include        <GL/glu.h>
#include        <GL/glut.h>

// Funcao de desenho
void callback_desenho ()
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_QUADS);
        glVertex2i (150, 150);
        glVertex2i (250, 150);
        glVertex2i (250, 250);
        glVertex2i (150, 250);
    glEnd ();

    glFlush ();
}

// Funcao de tratamento do teclado
void callback_teclado (unsigned char tecla, int x, int y)
{
    if( tecla == 'q' || tecla == 'Q')
    {
        exit(0);
    }
}

void inicializaOpengl (int argc, 
                 char* argv[], 
                 const char* nome_aplicacao,
                 const int& largura, 
                 const int& altura, 
                 const int& posX, 
                 const int& posY)
{
    // Inicializacoes OpenGL
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (largura, altura);
    glutInitWindowPosition (posX, posY);
    glutCreateWindow (nome_aplicacao);

    // Inicializacoes Glut
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0, largura, altura, 0.0, 0.0, 1.0);

    // Registra funcoes de callback
    glutDisplayFunc (callback_desenho);
    glutKeyboardFunc (callback_teclado);

    // Laco de execucao da glut
    glutMainLoop ();
}

int main (int argc, char* argv[])
{
    inicializaOpengl (argc, argv, "Nome", 400, 400, 100, 100);

    return 0;
}

