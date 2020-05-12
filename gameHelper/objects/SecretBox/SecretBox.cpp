#include "SecretBox.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

SecretBox::SecretBox(float x, float y) : Pixel(x, y, "#fb00ff", 15) {}

// Отрисовка на экране
void SecretBox::draw() {
    // Установка цвета
    glColor3f(r, g, b);

    // Рисование фигуры
    glBegin(GL_QUADS);
        glVertex2f(x - width, y - width);
        glVertex2f(x - width, y + width);
        glVertex2f(x + width, y + width);
        glVertex2f(x + width, y - width);
    glEnd();

    // Вывод символа на экран
    glColor3f(255.0, 255.0, 255.0);
    glRasterPos2i(GLint(x - width / 3), GLint(y + width / 2));
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)'?');
}

// Коллизия с героем
bool SecretBox::isPickUp(Hero *hero) {
    // Если герой вошел в область коробки - вернуть 1, иначе 0
    return pow(hero->get_x() - x, 2) + pow(hero->get_y() - y, 2) <= width * width;
}
