#include "Line.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Line::Line(float x1, float y1, float x2, float y2,
           const char *hex, float w) : Pixel(x1, y1, hex, w) {
    this->dx2 = x2 - x;
    this->dy2 = y2 - y;
}

// Отрисовка на экране
void Line::draw() {
    // Установка цвета
    glColor3f(r, g, b);

    // Нахождение нормали
    float norm_x = y - (y + dy2);
    float norm_y = (x + dx2) - x;

    // Приведение нормали к единичному вектору
    float l = std::sqrt(norm_x * norm_x + norm_y * norm_y);
    norm_x = norm_x / l * width;
    norm_y = norm_y / l * width;

    // Рисование фигуры
    glBegin(GL_QUADS);
        glVertex2f(x + norm_x, y + norm_y);
        glVertex2f(x - norm_x, y - norm_y);
        glVertex2f((x + dx2) - norm_x, (y + dy2) - norm_y);
        glVertex2f((x + dx2) + norm_x, (y + dy2) + norm_y);
    glEnd();
}

// Геттеры
float Line::get_x2() { return (x + dx2); }
float Line::get_y2() { return (y + dy2); }

// Сеттеры
void Line::set_x2(float X) { dx2 = X - x; }
void Line::set_y2(float Y) { dy2 = Y - y; }