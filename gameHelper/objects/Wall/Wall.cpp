#include "Wall.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Wall::Wall(float x1, float y1, float x2, float y2,
           const std::string & label, const char* hex, float w) : Line(x1, y1, x2, y2, hex, w) {
    this->label = label;
}

// Получение названия
std::string& Wall::getLabel() { return label; }

// Получение середины координаты X
float Wall::middleX() { return ((x + dx2) + x) / 2; }

// Получение середины координаты Y
float Wall::middleY() { return ((y + dy2) + y) / 2; }

// Установка названия
void Wall::setLabel(std::string &Label) { label = Label; }
