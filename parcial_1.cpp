#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#define SOLID_SPHERE 1
#define SOLID_CUBE 2
#define SOLID_CONE 3
#define SOLID_DODECAHEDRON 4
#define SOLID_OCTAHEDRON 5
#define SOLID_TETRAHEDRON 6
#define SOLID_ICOSAHEDRON 7
#define SOLID_TEAPOT 8
#define WIRE_SPHERE 9
#define WIRE_CUBE 10
#define WIRE_CONE 11
#define WIRE_DODECAHEDRON 12
#define WIRE_OCTAHEDRON 13
#define WIRE_TETRAHEDRON 14
#define WIRE_ICOSAHEDRON 15
#define WIRE_TEAPOT 16
#define EXIT 17
#define ESC 27
#define TAB 9
void glutSolidDodecahedron 	( 	);
void glutWireDodecahedron 	( 	);

int opcion = 1;

void menuAction(int value)
{
    opcion = value;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    switch(value)
    {
    case SOLID_SPHERE:
        glutSolidSphere(1,20,20);
        break;
    case SOLID_CUBE:
        glutSolidCube(1);
        break;
    case SOLID_CONE:
        glRotatef(90,0.2,1,0.4);
        glutSolidCone(0.5,1,20,20);
        glRotatef(-90,0.2,1,0.4);
        break;
    case SOLID_DODECAHEDRON:
        glRotatef(0,5, 0, 0);
        glScalef(0.6, 0.6, 0.6);
        glutSolidDodecahedron();
                break;
    case SOLID_OCTAHEDRON:
        glutSolidOctahedron();
        break;
    case SOLID_TETRAHEDRON:
        glutSolidTetrahedron();
        break;
    case SOLID_ICOSAHEDRON:
        glutSolidIcosahedron();
        break;
    case SOLID_TEAPOT:
        glutSolidTeapot(0.5);
        break;
    case WIRE_SPHERE:
        glutWireSphere(1,20,20);
        break;
    case WIRE_CUBE:
        glutWireCube(1);
        break;
    case WIRE_CONE:
        glRotatef(90,0.2,1,0.4);
        glutWireCone(1,1,20,20);
        glRotatef(-90,0.2,1,0.4);
        break;
    case WIRE_DODECAHEDRON:
        glRotatef(0,5, 0, 0);
        glScalef(0.6, 0.6, 0.6);
        glutWireDodecahedron();
        break;
    case WIRE_OCTAHEDRON:
        glRotatef(75, 1, 0, 0);
        glScalef(0.9, 0.9, 0.9);
        glutWireOctahedron();
        break;
    case WIRE_TETRAHEDRON:
        glRotatef(60, 1, 1, 0);
        glScalef(0.9, 0.9, 0.9);
        glutWireTetrahedron();
        break;
    case WIRE_ICOSAHEDRON:
        glRotatef(30, 1, 0, 0);
        glScalef(0.7, 0.7, 0.7);
        glutWireIcosahedron();
        break;
    case WIRE_TEAPOT:
        glScalef(0.9, 0.9, 0.9);
        glutWireTeapot(0.5);
        break;
    case EXIT:
        exit(0);
        break;
    }
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h); // Establecer el tamaño del área visible.
    glMatrixMode(GL_PROJECTION); // Modificar la matriz de proyección.
    glLoadIdentity(); // Inicializar la matriz de proyección.
    glMatrixMode(GL_MODELVIEW); // Modificar la matriz de vista del modelo.
}

void display(void)
{
    glLoadIdentity(); // Inicializar la matriz de vista del modelo.

// Borrar el buffer de color y de profundidad.
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    menuAction(0);

    glutSwapBuffers(); // Intercambiar el buffer de dibujado por el buffer de despliegue.
    glFinish();
}
void menu()
{
    int submenu1,submenu2;
    submenu1 = glutCreateMenu(menuAction);
    glutAddMenuEntry("Dibujar esfera",SOLID_SPHERE);
    glutAddMenuEntry("Dibujar cubo",SOLID_CUBE);
    glutAddMenuEntry("Dibujar cono",SOLID_CONE);
    glutAddMenuEntry("Dibujar dodecaedro",SOLID_DODECAHEDRON);
    glutAddMenuEntry("Dibujar octahedro",SOLID_OCTAHEDRON);
    glutAddMenuEntry("Dibujar tetaedro",SOLID_TETRAHEDRON);
    glutAddMenuEntry("Dibujar icosaedro",SOLID_ICOSAHEDRON);
    glutAddMenuEntry("Dibujar tetera",SOLID_TEAPOT);

    submenu2 = glutCreateMenu(menuAction);
    glutAddMenuEntry("Dibujar esfera",WIRE_SPHERE);
    glutAddMenuEntry("Dibujar cubo",WIRE_CUBE);
    glutAddMenuEntry("Dibujar cono",WIRE_CONE);
    glutAddMenuEntry("Dibujar dodecaedro",WIRE_DODECAHEDRON);
    glutAddMenuEntry("Dibujar octahedro",WIRE_OCTAHEDRON);
    glutAddMenuEntry("Dibujar tetaedro",WIRE_TETRAHEDRON);
    glutAddMenuEntry("Dibujar icosaedro",WIRE_ICOSAHEDRON);
    glutAddMenuEntry("Dibujar tetera",WIRE_TEAPOT);

    glutCreateMenu(menuAction);
    glutAddSubMenu("Figura solida",submenu1);
    glutAddSubMenu("Figura alambrica",submenu2);
    glutAddMenuEntry("Salir",EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void specialKey(int key, int x, int y)
{
    if(glutGetModifiers() & GLUT_ACTIVE_SHIFT)   // testing SHIFT status
    {
        switch(key)
        {
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
        case GLUT_KEY_DOWN:
            break;
        }
    }
}
void mouse(int button, int state,int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_UP)
        {
            opcion++;
            if(opcion > 16)
            {
                opcion = 1;
            }
            menuAction(opcion);
        }
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case ESC:
        exit(0);
        break;
    case TAB:
        opcion++;
        if(opcion > 16)
        {
            opcion = 1;
        }
        menuAction(opcion);
        break;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Inicializar GLUT
// Inicializar modo de despliegue: usar profundidad, transparencia y double buffering.
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutCreateWindow("Parcial_1-2015"); // Crear una ventana con el título indicado.
    menu();
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutDisplayFunc(display); // Indicar la función para desplegar.
    glutReshapeFunc(reshape); // Indicar la función para cambios de tamaño en la ventana.
    glutMainLoop(); // Pasar el control a GLUT.

    return 0; // Regresar 0 por cortesía.
}
