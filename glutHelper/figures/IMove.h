#ifndef I_MOVE_H
#define I_MOVE_H

// -------------------- ОПИСАНИЕ КЛАССА ------------------- //

class IMove {
public:
    // Перемещение по экрану
    virtual void move(float dx, float dy) = 0;
};

#endif //I_MOVE_H
