#include "APerson.h"

APerson::APerson(float x, float y, float vx, float vy, const char *hex, float width) : Pixel(x, y, hex, width) {
    this-> vx = vx;
    this-> vy = vy;
}

void APerson::draw() {
    int segments = 50;

    // Установка цвета
    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        glVertex2f(
                (x + (width * (float)cos(i * 6.2831 / segments))),
                (y + (width * (float)sin(i * 6.2831 / segments)))
        );
    }
    glEnd();
}