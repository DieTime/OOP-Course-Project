#pragma once
#ifndef GAME_WALL_H
#define GAME_WALL_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <string>

#include "../../../glutHelper/figures/line/Line.h"

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class Wall : public Line {
private:
    std::string label; // Название стены
public:
    Wall(float x1, float y1, float x2, float y2, const std::string& label, const char* hex = "#ffffff", float w = 1);
    ~Wall() override = default;

    // Получение названия
    std::string& getLabel();

    // Установка названия
    void setLabel(std::string &Label);

    // Получение середины координаты X
    float middleX();

    // Получение середины координаты Y
    float middleY();
};

#endif //GAME_WALL_H
