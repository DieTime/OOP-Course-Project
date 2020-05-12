#include "DamageHero.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

DamageHero::DamageHero(float x, float y, float vx, float vy, const char *hex, float width)
        : Hero(x, y, vx, vy, hex, width) {}

// Переопределение перемещения героя (в 2 раза медленнее)
void DamageHero::move(float dx, float dy) {
    Pixel::move(dx / 2, dy / 2);
}

// Отрисовка героя на экране
void DamageHero::draw() {
    // Стандартная отрисовка
    Hero::draw();

    // Дополнительная отрисовка текста
    glColor3f(r, g, b);
    glRasterPos2i(GLint(x - 30), GLint(y - 25));
    for (const char &ch : "Slowly") {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) ch);
    }
}