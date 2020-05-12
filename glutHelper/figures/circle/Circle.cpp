#include "Circle.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Circle::Circle(float x, float y, float r, const char *hex, bool fill,
               float w) : Oval(x, y, r, r, hex, fill, w) {}

// Геттеры
float Circle::get_radius() { return rx; }
float Circle::get_rx() { return rx; }
float Circle::get_ry() { return rx; }

// Сеттеры
void Circle::set_radius(float r) { rx = r; ry = r; }
void Circle::set_rx(float rx) { set_radius(rx); }
void Circle::set_ry(float ry) { set_radius(ry); }