#include "MagicHero.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

MagicHero::MagicHero(float x, float y, float vx, float vy, const char *hex, float width)
        : Hero(x, y, vx, vy, hex, width) {}

// Переопределение коллизии (противники не замечают героя)
void MagicHero::addCollisionBox(std::vector<Wall> &walls) {}

// Переопределение коллизии (противники не замечают героя)
void MagicHero::removeCollisionBox(std::vector<Wall> &walls) {}

// Отрисовка героя на экране
void MagicHero::draw() {
    // Стандартная отрисовка
    Hero::draw();

    // Дополнительная отрисовка текста
    glColor3f(r, g, b);
    glRasterPos2i(GLint(x - 25), GLint(y - 25));
    for (const char &ch : "Magic") {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) ch);
    }
}

