#pragma once
#ifndef GAME_RAY_H
#define GAME_RAY_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include "../../../glutHelper/figures/pixel/Pixel.h"
#include "../Wall/Wall.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Ray : public Pixel {
protected:
    float dirY = 0; // Направление по оси X
    float dirX = 0; // Направление по оси Y
public:
    Ray() = default;
    Ray(float x1, float x2, int angle);
    ~Ray() override = default;

    // Нахождение пересечения со стеной
    Pixel intersection(Wall &wall);

    // Геттеры
    float getDirX();
    float getDirY();

    // Сеттеры
    void setDirX(float DirX);
    void setDirY(float DirY);
};

#endif //GAME_RAY_H
