#pragma once

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <GL/glut.h>
#include <stdexcept>

#include "./figures/pixel/Pixel.h"
#include "./figures/line/Line.h"
#include "./figures/oval/Oval.h"
#include "./figures/circle/Circle.h"

// -------------------- ОСНОВНЫЕ ФУНКЦИИ ------------------ //

// Задержка для установки FPS
static unsigned int frameDelay;

// Перерисовка окна с заданым FPS
void glRedraw(int) {
    glutPostRedisplay();
    glutTimerFunc(frameDelay, glRedraw, 0);
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT);
}

// Инициализация основного окна
void CreateGL(int width, int height, const char *title, const char *bg, unsigned int fps, void func()) {
    // Аргументы для инициализации
    int argc = 0;
    char *argv = nullptr;

    // Определение цветов фона
    int red = 0, green = 0, blue = 0;
    if (sscanf(bg + 1, "%02x%02x%02x", &red, &green, &blue) != 3)
        throw std::runtime_error("Incorrect color entered!");

    // Вычисление задержки
    frameDelay = 1000 / fps;

    // Инициализация окна и основного цикла отрисовки
    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(title);
    glClearColor((float) red / 255, (float) green / 255, (float) blue / 255, 1);
    gluOrtho2D(0, width, height, 0);
    glutDisplayFunc(func);
    glRedraw(0);
    glutMainLoop();
}