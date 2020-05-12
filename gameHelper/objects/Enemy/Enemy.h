#pragma once
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <vector>

#include "../Wall/Wall.h"
#include "../Ray/Ray.h"
#include "../Person/APerson.h"


// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Enemy : public APerson {
protected:
    float delay = 0; // Время до следующей смены направления
    int dirY = 0;    // Направление по оси X
    int dirX = 0;    // Направление по оси Y
public:
    Enemy() = default;
    Enemy(float x, float y, float vx, float vy, const char *hex = "#000000", float width = 10);
    ~Enemy() override = default;

    // Отрисовка линий в зони видимости
    int cast(std::vector<Wall>& walls, const char* line_color);

    // Перемещение противника по сцене
    void run(float w, float h) override;

    // Узнать следующее направление движения
    void followDir();
};

#endif //GAME_ENEMY_H
