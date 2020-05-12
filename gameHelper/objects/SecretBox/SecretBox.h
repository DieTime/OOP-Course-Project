#pragma once
#ifndef SECRET_BOX_H
#define SECRET_BOX_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include "../../../glutHelper/figures/pixel/Pixel.h"
#include "../Hero/ClassicHero/Hero.h"

// ------------------- ОПИСАНИЕ КЛАССА ------------------- //

class SecretBox: public Pixel {
public:
    SecretBox() = default;
    SecretBox(float x, float y);

    // Отрисовка на экране
    void draw() override;

    // Коллизия с героем
    bool isPickUp(Hero* hero);
};

#endif //SECRET_BOX_H
