#pragma once
#ifndef GAME_HELPER_H
#define GAME_HELPER_H

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- //

#include <ctime>
#include <vector>
#include <sstream>

#include "objects/Enemy/Enemy.h"
#include "objects/Hero/ClassicHero/Hero.h"
#include "objects/Hero/MagicHero/MagicHero.h"
#include "objects/Hero/DamageHero/DamageHero.h"
#include "objects/Wall/Wall.h"
#include "objects/Ray/Ray.h"
#include "objects/SecretBox/SecretBox.h"

// ----------------- ОПРЕДЕЛЕНИЕ ИМЕН ТИПОВ --------------- //

typedef std::vector<Wall> Walls;
typedef std::vector<Enemy> Enemies;
typedef std::vector<SecretBox> Boxes;

// -------------------- ОСНОВНЫЕ ФУНКЦИИ ------------------ //

// Генерация стен для сцены
Walls generateWalls(int num, int width, int height) {
    // Утсановка сида генерации
    srand(unsigned(time(nullptr)));

    // Результирующий массив
    Walls walls;

    // Запонение массива случайными стенами
    for (int i = 0; i < num; i++) {
        auto x1 = float(rand() % width);
        auto x2 = float(rand() % width);
        auto y1 = float(rand() % height);
        auto y2 = float(rand() % height);
        walls.emplace_back(x1, y1, x2, y2, "random", "#ffffff", 2);
    }

    // Добавление стен на границе сцены
    walls.emplace_back(0, 0, 0, height, "side", "#ffffff", 0);
    walls.emplace_back(0, 0, width, 0, "side", "#ffffff", 0);
    walls.emplace_back(0, height, width, height, "side", "#ffffff", 0);
    walls.emplace_back(width, 0, width, height, "side", "#ffffff", 0);

    return walls;
}

// Генерация секретных коробок для сцены
Boxes generateBoxes(int num, int width, int height) {
    // Установка сида генерации
    srand(unsigned(time(nullptr)));

    // Результирующий массив
    Boxes boxes;

    // Запонение массива случайными стенами
    for (int i = 0; i < num; i++) {
        auto x = float(50 + rand() % (width - 100));
        auto y = float(50 + rand() % (height - 100));
        boxes.emplace_back(x, y);
    }

    // Добавление стен на границе сцены
    return boxes;
}

// Генерация противников
Enemies generateEnemies(int num, float vx, float vy, Hero *hero, Walls &walls, int width, int height) {
    // Выбор сида генерации
    auto seed = unsigned(time(nullptr));

    // Результирующий массив
    Enemies enemies;

    // Определяем границы героя
    hero->addCollisionBox(walls);

    // Добавление случайных противников
    for (int i = 0; i < num; i++) {
        srand(seed); // Установка сида

        // Создание пробного противника
        auto x = float(rand() % width);
        auto y = float(rand() % height);
        Enemy enemy(x, y, vx, vy, "#ffffff", 5);

        // Если герой в области видимости противника - пересоздание противника
        while (enemy.cast(walls, "#ffffff")) {
            x = float(rand() % width);
            y = float(rand() % height);
            enemy = Enemy(x, y, vx, vy, "#ffffff", 5);
        }

        // Добавление противника
        enemies.push_back(enemy);

        // Изменение сида
        seed += rand();
    }

    // Удаляем границы героя
    hero->removeCollisionBox(walls);

    return enemies;
}

// Генерация дверей
Walls generateDoors(int width, int height) {
    // Установка сида
    srand(unsigned(time(nullptr)));

    // Определение оси расположения дверей
    int axis = rand() % 2;

    // Длина дверей
    const float size = 40;

    // Результирующий массив
    Walls result;

    // Если выпала ось X - генерирация соответсвующих дверей
    if (axis) {
        float y1 = float(rand() % height);
        float y2 = float(rand() % height);
        result.emplace_back(0, y1 + size / 2, 0, y1 - size / 2, "start door", "#30ff53", 5);
        result.emplace_back(width, y2 + size / 2, width, y2 - size / 2, "end door", "#ff3661", 5);

        // Если выпала ось Y - генерирация соответсвующих дверей
    } else {
        float x1 = float(rand() % width);
        float x2 = float(rand() % width);
        result.emplace_back(x1 + size / 2, 0, x1 - size / 2, 0, "start door", "#30ff53", 5);
        result.emplace_back(x2 + size / 2, height, x2 - size / 2, height, "end door", "#ff3661", 5);
    }

    return result;
}

// Вывод текста на экран
void printText(const std::string &text, int x, int y) {
    // Установка цвета
    glColor3f(255.0, 255.0, 255.0);

    // Установка позиции курсора
    glRasterPos2i(x, y);

    // Побуквенный вывод на экран
    for (int i = 0; i < text.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) text[i]);
    }
}

// Преобразование уровня в текст для меню
std::string textFromLevel(int level) {
    // Результат
    std::string text;

    // Перевод числа в строку
    std::stringstream ss;
    ss << level;
    ss >> text;

    // Получение результата
    return "LEVEL " + text + " PASSED";
}

// Проверка коллизии героя с коробками
void pickUpBox(Hero *&hero, Boxes &boxes) {
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].isPickUp(hero)) {
            boxes.erase(boxes.begin() + i);

            int randNum = rand() % 3;
            float x = hero->get_x(), y = hero->get_y();
            float vx = hero->get_vx(), vy = hero->get_vy();

            delete hero;
            if (randNum == 0) hero = new Hero(x, y, vx, vy);
            if (randNum == 1) hero = new MagicHero(x, y, vx, vy);
            if (randNum == 2) hero = new DamageHero(x, y, vx, vy);
        }
    }
}

// Инициализация игры
void startGame(Walls &walls, Enemies &enemies, Walls &doors, Boxes &boxes, Hero *&hero, bool &GameOver,
               bool &levelUp, int &level, int WIDTH, int HEIGHT) {

    // Генерирование стен для сцены
    walls = generateWalls(7, WIDTH, HEIGHT);

    // Генерация дверей
    doors = generateDoors(WIDTH, HEIGHT);

    // Генерация коробок
    boxes = generateBoxes(3, WIDTH, HEIGHT);

    // Инициализация героя
    hero = new Hero(doors[0].middleX(), doors[0].middleY(), 4, 4);

    // Генерирование противников для сцены
    enemies = generateEnemies(1, 1, 1, hero, walls, WIDTH, HEIGHT);

    // Обновление состояния игры
    GameOver ? level = 1 : level++;
    GameOver = false;
    levelUp = false;
}

#endif //GAME_HELPER_H
