#pragma once
#ifndef RAYS_COLOR_H
#define RAYS_COLOR_H

#include <stdexcept>

class Color {
protected:
    float r = 0; // Красная составляющая цвета
    float g = 0; // Зеленая составляющая цвета
    float b = 0; // Красная составляющая цвета
public:
    // Геттеры
    float get_r() { return r; };
    float get_g() { return g; };
    float get_b() { return b; };

    // Сеттеры
    void setColor(const char* hex) {
        int red, green, blue;

        // Получение составляющих цветов из 16-ричной строки
        if (sscanf(hex + 1, "%02x%02x%02x", &red, &green, &blue) == 3) {
            // component normalization
            r = (float)red / 255;
            g = (float)green / 255;
            b = (float)blue / 255;
        }
        // если строка не корректна - выброс исключения
        else {
            throw std::runtime_error("Incorrect color entered!");
        }
    };
    void set_r(float R) { r = R; };
    void set_g(float G) { g = G; };
    void set_b(float B) { b = B; };
};

#endif //RAYS_COLOR_H