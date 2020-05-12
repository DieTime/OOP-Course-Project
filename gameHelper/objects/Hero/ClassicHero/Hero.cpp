#include "Hero.h"
#include <cmath>

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Hero::Hero(float x, float y, float vx, float vy, const char *hex,
           float width) : APerson(x, y, vx, vy, hex, width) {}

// Перемещение игрока по сцене
void Hero::run(float w, float h) {
    // Получение текущей позиции
    float x = get_x();
    float y = get_y();

    // Изменение текущей позиции
    if (GetAsyncKeyState(0x41) || GetAsyncKeyState(VK_LEFT)) {
        // Изменение координат если перемещение возможно
        if (x - vx > 0) move(-vx, 0);
    }
    if (GetAsyncKeyState(0x44) || GetAsyncKeyState(VK_RIGHT)) {
        // Изменение координат если перемещение возможно
        if (x + vx < w) move(vx, 0);
    }
    if (GetAsyncKeyState(0x57) || GetAsyncKeyState(VK_UP)) {
        // Изменение координат если перемещение возможно
        if (y - vy > 0) move(0, -vy);
    }
    if (GetAsyncKeyState(0x53) || GetAsyncKeyState(VK_DOWN)) {
        // Изменение координат если перемещение возможно
        if (y + vy < h) move(0, vy);
    }

    draw(); // Отрисовка героя на сцене с новыми координатами
}

// Добавление границы героя для проверки обнаружения
void Hero::addCollisionBox(std::vector<Wall> &walls) {
    walls.emplace_back(x - width / 2, y, x +  width / 2, y, "hero");
    walls.emplace_back(x, y -  width / 2, x, y +  width / 2, "hero");
}

// Удаление границы героя для последующего обновления
void Hero::removeCollisionBox(std::vector<Wall> &walls) {
    walls.erase(walls.end() - 2, walls.end());
}

// Проверка нахождения героем двери
bool Hero::findDoor(Wall& door) {
    // Расчет длины двери для радиуса колизии
    float vecX = door.get_x2() - door.get_x();
    float vecY = door.get_y2() - door.get_y();
    float r = std::sqrt(vecX * vecX + vecY * vecY) / 2;

    // Вернуть 1 - если дверь нашлась, 0 - если нет
    return (pow(door.middleX() - x, 2) + pow(door.middleY() - y, 2) <= r * r);
}
