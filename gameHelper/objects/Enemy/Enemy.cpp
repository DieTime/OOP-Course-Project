// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <cmath>
#include <ctime>

#include "Enemy.h"

// ------------------- РЕАЛИЗАЦИЯ КЛАССА ------------------ //

Enemy::Enemy(float x, float y, float vx, float vy, const char *hex,
             float width) : APerson(x, y, vx, vy, hex, width) {
    // Установка сида генерации
    srand(unsigned(time(nullptr)));

    // Выбор случаного направления противника
    dirX = rand() % 2;
    dirY = rand() % 2;

    delay = 0; // Установка времени до следующей смены направления
}

// Отрисовка линий в зони видимости
int Enemy::cast(std::vector<Wall> &walls, const char *line_color) {
    // Пускаем лучи по кругу с шагом 2 градуса
    for (int i = 0; i <= 360; i += 2) {

        float min_dist = INFINITY; // Дистанция до ближайшей стены
        float min_x = INFINITY; // Координата x ближайшей стены
        float min_y = INFINITY; // Координата y ближайшей стены
        std::string label; // Название ближайшей стены

        // Создание луча под заданным углом
        Ray ray(get_x(), get_y(), i);

        // Проверяем пересечение с каждой стеной
        for (int j = 0; j < walls.size(); j++) {
            // Получаем точку пересечения луча с текущей стеной
            Pixel dot = ray.intersection(walls[j]);

            // Если точка пересечения существует
            if (!std::isnan(dot.get_x())) {
                // Расчитываем расстояние до текущей стены
                float dist_x = get_x() - dot.get_x();
                float dist_y = get_y() - dot.get_y();
                float dist = std::sqrt(dist_x * dist_x + dist_y * dist_y);

                // Если расстояние до текущей стены меньше минимальной
                if (dist < min_dist) {
                    // Обновляем данные о ближайшей стене
                    min_x = dot.get_x();
                    min_y = dot.get_y();
                    min_dist = dist;
                    label = walls[j].getLabel();
                }
            }
        }

        // Если стена была найдена
        if (min_dist != INFINITY) {
            // Если была найдена граница героя - возвращаем 1 (игрок был найден)
            if (label == "hero") return 1;

            // Отрисовка линии до стены
            Line line(get_x(), get_y(), min_x, min_y, line_color, 1);
            line.draw();
        }
    }

    // Возвращаем 0 если игрок не был найден
    return 0;
}

// Узнать следующее направление движения
void Enemy::followDir() {
    // Каждые 100 кадров изменяем направление
    if (delay++ > 200) {
        dirX = rand() % 2;
        dirY = rand() % 2;
        delay = 0;
    }
}

// Перемещение противника по сцене
void Enemy::run(float w, float h) {
    // Изменение текущей позиции в зависимости от направления
    if (dirX == 0) {
        if (x - vx > 0) set_x(x - vx);
    }
    if (dirX == 1) {
        if (x + vx < w) set_x(x + vx);
    }
    if (dirY == 0) {
        if (y - vy > 0) set_y(y - vy);
    }
    if (dirY == 1) {
        if (y + vy < h) set_y(y + vy);
    }

    //Получаем следующее направление движения
    this->followDir();
}