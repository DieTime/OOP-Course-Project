#pragma once
#ifndef DAMAGE_HERO_H
#define DAMAGE_HERO_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include "../ClassicHero/Hero.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class DamageHero : public Hero {
public:
    DamageHero() = default;
    DamageHero(float x, float y, float vx, float vy, const char *hex = "#ff8000", float width = 15);
    ~DamageHero() override = default;

    // Отрисовка героя на экране
    void draw() override;

    // Переопределение перемещения героя (в 2 раза медленнее)
    void move(float dx, float dy) override;
};

#endif // DAMAGE_HERO_H
