#pragma once
#ifndef GAME_HERO_H
#define GAME_HERO_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <vector>

#include "../../Person/APerson.h"
#include "../../Wall/Wall.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Hero : public APerson {
public:
    Hero() = default;
    Hero(float x, float y, float vx, float vy, const char *hex = "#ffee38", float width = 10);
    ~Hero() override = default;

    // Перемещение персонажа
    void run(float w, float h) override;

    // Добавление границы героя для проверки обнаружения
    virtual void addCollisionBox(std::vector<Wall>& walls);

    // Удаление границы героя для последующего обновления
    virtual void removeCollisionBox(std::vector<Wall>& walls);

    // Проверка нахождения героем двери
    virtual bool findDoor(Wall& door);
};

#endif //GAME_HERO_H
