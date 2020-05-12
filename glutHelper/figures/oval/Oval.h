#pragma once
#ifndef OVAL_H
#define OVAL_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <cmath>

#include "../pixel/Pixel.h"
#include "../Fill.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Oval : public Pixel, public Fill {
protected:
    float rx = 0; // Радиус по оси X
    float ry = 0; // Радиус по оси Y
public:
    Oval() = default;
    Oval(float x, float y, float rx, float ry, const char* hex, bool fill = false, float width = 1);
    ~Oval() override = default;

    // Отрисовка на экране
    void draw() override;

    // Геттеры
    virtual float get_rx();
    virtual float get_ry();

    // Сеттеры
    virtual void set_rx(float rx);
    virtual void set_ry(float ry);
};

#endif //OVAL_H
