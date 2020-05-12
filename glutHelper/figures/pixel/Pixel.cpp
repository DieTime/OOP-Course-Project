#include "Pixel.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Pixel::Pixel(float x, float y, const char *hex, float width) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->setColor(hex);
}

// Отрисовка на экране
void Pixel::draw() {
    // Установка цвета
    glColor3f(r, g, b);

    // Отрисовка фигуры
    glBegin(GL_QUADS);
        glVertex2f(x - width, y - width);
        glVertex2f(x - width, y + width);
        glVertex2f(x + width, y + width);
        glVertex2f(x + width, y - width);
    glEnd();
}

// Перемещение по экрану
void Pixel::move(float dx, float dy) {
    x += dx;
    y += dy;
}

// Геттеры
float Pixel::get_x() { return x; }
float Pixel::get_y() { return y; }

// Сеттеры
void Pixel::set_x(float X) { x = X; }
void Pixel::set_y(float Y) { y = Y; }

