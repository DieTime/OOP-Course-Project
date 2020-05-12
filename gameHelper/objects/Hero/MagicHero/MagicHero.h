#pragma once
#ifndef MAGIC_HERO_H
#define MAGIC_HERO_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <vector>

#include "../ClassicHero/Hero.h"
#include "../../Wall/Wall.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class MagicHero : public Hero {
public:
    MagicHero() = default;
    MagicHero(float x, float y, float vx, float vy, const char *hex = "#00eaff", float width = 7);
    ~MagicHero() override = default;

    // Отрисовка героя на экране
    void draw() override;

    // Переопределение коллизии (противники не замечают героя)
    void addCollisionBox(std::vector<Wall>& walls) override;
    void removeCollisionBox(std::vector<Wall>& walls) override;
};

#endif //MAGIC_HERO_H
