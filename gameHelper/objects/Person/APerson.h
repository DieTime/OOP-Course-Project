#pragma once
#ifndef A_PERSON_H
#define A_PERSON_H

#include <cmath>
#include "../../../glutHelper/figures/pixel/Pixel.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class APerson : public Pixel {
protected:
    float vx = 0; // Скорость по оси X
    float vy = 0; // Скорость по оси Y
public:
    APerson() = default;
    APerson(float x, float y, float vx, float vy, const char* hex, float width = 1);

    // Передвижение персонажа
    virtual void run(float w, float h) = 0;

    // Отрисовка на экране
    void draw() override;

    // Геттеры
    float get_vx() { return vx; }
    float get_vy() { return vy; }

    // Сеттеры
    void set_vx(float Vx) { vx = Vx; }
    void set_vy(float Vy) { vy = Vy; }
};

#endif //A_PERSON_H
