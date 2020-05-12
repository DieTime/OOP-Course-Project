#pragma once
#ifndef PIXEL_H
#define PIXEL_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <GL/glut.h>

#include "../Color.h"
#include "../IDraw.h"
#include "../IMove.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Pixel : public IDraw, public IMove, public Color {
protected:
    float x = 0; // коордитана X
    float y = 0; // координата Y
    float width = 1; // толщина
public:
    Pixel() = default;
    Pixel(float x, float y, const char* hex, float width = 1);
    virtual ~Pixel() = default;

    // Отрисовка на экране
    void draw() override;

    // Перемещение фигуры на экране
    void move(float dx, float dy) override; // move shape on window

    // Геттеры
    float get_x();
    float get_y();

    // Сеттеры
    void set_x(float x);
    void set_y(float y);
};

#endif //PIXEL_H
