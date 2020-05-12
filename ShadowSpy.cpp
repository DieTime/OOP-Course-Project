/* --------------- КАФЕДРА № 304 2 КУРС ООП --------------- //

    Project Type  : CMake Project
    Project Name  : ShadowSpy Game
    File Name     : ShadowSpy.cpp
    Language      : C/C++
    Programmer    : Глазков Д.А.
    Modified By   :     ---
    Created       : 20.04.20
    Last Revision : 07.05.20
    Comment       : Игра, главная цель которой оставаться
                    незамеченным, добираться до двери
                    следующего уровня и по желанию подбирать
                    секретные коробки с модификациями.

// ---------------- НЕОБХОДИМЫЕ ЗАВИСИМОСТИ --------------- */

#include "glutHelper/glutHelper.h"
#include "gameHelper/gameHelper.h"

// -------------------- ПАРАМЕТРЫ СЦЕНЫ ------------------- //

const int WIDTH = 800;  // Ширина окна
const int HEIGHT = 500; // Высота окна

// ----------------- ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ---------------- //

Hero *hero;            // Игрок
Walls walls;           // Стены комнаты
Walls doors;           // Входная и выходная дверь
Enemies enemies;       // Враги
Boxes boxes;           // Коробки

bool GameOver = false; // Состояние конца игры
bool LevelUp = false;  // Состояние прохождения уровня
int level = 0;         // Текущий уровень

// --------------- ФУНКЦИЯ ОТРИСОВКИ СЦЕНЫ --------------- //

void Game() {
    // Показываем меню если уровень игры пройден
    if (LevelUp) {
        // Вывод текста игрового меню
        printText(textFromLevel(level), WIDTH / 2 - 53, HEIGHT / 2);
        printText(
            "Press ENTER to continue",
            WIDTH / 2 - 85, HEIGHT / 2 + 30
        );

        // Продолжение игры при нажатии на Enter
        if (GetAsyncKeyState(VK_RETURN)) {
            startGame(
                walls, enemies, doors, boxes, hero,
                GameOver, LevelUp, level, WIDTH, HEIGHT
            );
        }
    }

        // Показываем меню если конец игры
    else if (GameOver) {
        // Вывод текста игрового меню
        printText("GAME OVER", WIDTH / 2 - 45, HEIGHT / 2);
        printText(
            "Press ENTER to restart",
            WIDTH / 2 - 85, HEIGHT / 2 + 30
        );

        // Перезапуск игры при нажатии на Enter
        if (GetAsyncKeyState(VK_RETURN)) {
            startGame(
                walls, enemies, doors, boxes, hero,
                GameOver, LevelUp, level, WIDTH, HEIGHT
            );
        }
    }

    // Игровой процесс
    else {
        // Отрисовка стен, коробок и дверей на экране
        for (auto &wall : walls) wall.draw();
        for (auto &box : boxes) box.draw();
        for (auto &door : doors) door.draw();

        // Добавляем границы героя для проверки обнаружения
        hero->addCollisionBox(walls);

        // Дейстельность врагов
        for (auto &enemy : enemies) {
            // Перемещение в случайном направлении
            enemy.run(WIDTH, HEIGHT);

            // Наблюдение за комнатой (обнаружение героя)
            if (enemy.cast(walls, "#ffffff")) {
                GameOver = true;
                // Конец игры если игрок обнаружен
                return;
            }
        }

        // Удаляем границы героя для последующего обновления
        hero->removeCollisionBox(walls);

        // Перемещение пользователя в выбранном направлении
        hero->run(WIDTH, HEIGHT);

        // Проверка на прохождение уровня
        if (hero->findDoor(doors.back())) {
            LevelUp = true;
            // Если уровень пройден - генерация нового уровня
            return;
        }

        // Проверка - если коробка поднята
        pickUpBox(hero, boxes);
    }
}

// ------------------- ОСНОВНАЯ ФУНКЦИЯ ------------------ //

int main() {
    // Инициализация игры
    startGame(
        walls, enemies, doors, boxes, hero,
        GameOver, LevelUp, level, WIDTH, HEIGHT
    );
    // Запуск отрисовки сцены
    CreateGL(WIDTH, HEIGHT, "ShadowSpy", "#1f1f1f", 60, Game);
    return 0;
}