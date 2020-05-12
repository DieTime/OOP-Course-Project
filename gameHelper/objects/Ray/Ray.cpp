#include "Ray.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Ray::Ray(float x1, float x2, int angle) : Pixel(x1, x2, "#ffffff") {
    // Перевод угла в вектор x и y
    double y = sin(angle * 3.14 / 180);
    double x = cos(angle * 3.14 / 180);

    // Расчет длины итогового вектора для нормализации
    double len = std::sqrt(x * x + y * y);

    // Инициализация направлений по осям
    dirX = float(x / len);
    dirY = float(y / len);
}

// Нахождение пересечения со стеной
Pixel Ray::intersection(Wall &wall) {
    // Координаты первого вектора (стены)
    float x1 = wall.get_x();
    float y1 = wall.get_y();
    float x2 = wall.get_x2();
    float y2 = wall.get_y2();

    // Координаты второго вектора (луча)
    float x3 = get_x();
    float y3 = get_y();
    float x4 = x3 + dirX;
    float y4 = y3 + dirY;

    // Знаменатель для нахождения пересечения
    float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    // Если знаменатель равен 0 - возращаем NAN
    if (den == 0) return Pixel(NAN, NAN, "#ffffff");

    // Параметры для нахождения пересечения
    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

    // Если пересечение существует - возвращаем точку пересечения
    if (t > 0 && t < 1 && u > 0) {
        return Pixel(x1 + t * (x2 - x1), y1 + t * (y2 - y1), "#ffffff");
    }

    // Если пересечения нет - возращаем NAN
    return Pixel(NAN, NAN, "#ffffff");
}

// Геттеры
float Ray::getDirX() { return dirX; }
float Ray::getDirY() { return dirY; }

// Сеттеры
void Ray::setDirX(float DirX) { dirX = DirX; }
void Ray::setDirY(float DirY) { dirY = DirY; }
