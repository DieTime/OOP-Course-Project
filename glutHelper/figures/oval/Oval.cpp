#include "Oval.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Oval::Oval(float x, float y, float rx, float ry, const char *hex, bool fill, float width) : Pixel(x, y, hex, width) {
    this->rx = rx;
    this->ry = ry;
    this->fill = fill;
}

// Отрисовка на экране
void Oval::draw() {
    // Число сегментов (чем больше тем плавнее)
    const int segments = 50;

    // Установка цвета
    glColor3f(r, g, b);

    // Если овал с заливкой
    if (fill) {
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x, y);
            for (int i = 0; i <= segments; i++) {
                glVertex2f(
                (x + (rx * (float)cos(i * 6.2831 / segments))),
                (y + (ry * (float)sin(i * 6.2831 / segments)))
                );
            }
        glEnd();

    // Овал без заливки
    } else {
        // Радиус внутреннего овала
        float rx1 = rx - width;
        float ry1 = ry - width;

        // Радиус внешнего овала
        float rx2 = rx + width;
        float ry2 = ry + width;

        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= segments; i++) {
            glVertex2f (
            (x + (rx1 * (float)cos(i * 2 * M_PI / segments))),
            (y + (ry1 * (float)sin(i * 2 * M_PI / segments)))
            );
            glVertex2f (
            (x + (rx2 * (float)cos(i * 2 * M_PI / segments))),
            (y + (ry2 * (float)sin(i * 2 * M_PI / segments)))
            );
        }
        glEnd();
    }
}

// Геттеры
float Oval::get_rx() { return rx; }
float Oval::get_ry() { return ry; }

// Сеттеры
void Oval::set_rx(float Rx) { rx = Rx; }
void Oval::set_ry(float Ry) { ry = Ry; }
