#pragma once
#ifndef LINE_H
#define LINE_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <cmath>
#include "../pixel/Pixel.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Line : public Pixel {
protected:
    float dx2 = 0; // Растояние 2й точки по оси X относительно первой
    float dy2 = 0; // Растояние 2й точки по оси X относительно первой
public:
    Line() = default;
    Line(float x1, float y1, float x2, float y2, const char *hex, float w = 1);
    ~Line() override = default;

    // Отрисовка на экране
    void draw() override;

    // Геттеры
    float get_x2();
    float get_y2();

    // Сеттеры
    void set_x2(float X);
    void set_y2(float Y);
};

#endif //LINE_H
