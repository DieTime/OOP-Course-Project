#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include "../oval/Oval.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Circle : public Oval {
public:
    Circle() = default;
    Circle(float x, float y, float r, const char* hex, bool fill = false, float w = 1);
    ~Circle() override = default;

    // Геттеры
    float get_rx() override; // получить радиус по оси X
    float get_ry() override; // получить радиус по оси Н
    float get_radius();      // получить глобальный радиус

    // Сеттеры
    void set_rx(float rx) override; // установить радиус по оси X
    void set_ry(float ry) override; // установить радиус по оси Y
    void set_radius(float r);       // Установить глобальный радиус
};

#endif //CIRCLE_H
