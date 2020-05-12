#ifndef FILL_H
#define FILL_H

class Fill {
protected:
    // Состояние заливки
    bool fill = false;
public:
    // Геттер
    bool getFill() { return fill; };

    // Сеттер
    void setFill(bool Fill) { fill = Fill; };
};

#endif //FILL_H