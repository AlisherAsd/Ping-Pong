#include <Ball.h>
#include <string>
#include <iostream>





Ball::Ball(int x, int y) {
    this->x = x;
    this->y = y;
    this->prevx = rand() % (8 - 3 + 1) + 3;
    this->y = rand() % (27 - 3 + 1) + 3;
}

int Ball::getDirection() {
    return direction;
}

void Ball::setDirection(int d) {
        ;
    if (d == 0) prevx = rand();
    direction = d;
}

void Ball::setVector() {
    if (direction == 0 && y > 3) {    // <---
        if (y > 3 && (prevx == x)) {
            y--;
        }
        if (y > 3 && (prevx < x) && x < 8) {
            y--; //     ----
            x++; // <---
        }
        if (y > 3 && (prevx < x) && x >= 8) {
            y--; //     ----
            x--; // <---
        }
        if (y > 3 && (prevx > x) && x > 2) {
            y--; // <---
            x--; //     ----
        }
        if (y > 3 && (prevx > x) && x <= 2) {
            y--; // <---
            x++; //     ----
        }
    }
    if (direction == 1) {             // --->
        if (y < 26 && (prevx == x)) {
            y++;
        }
        if (y < 26 && (prevx < x) && x < 8) {
            y++; // ---
            x++; //    --- >
        }
        if (y < 26 && (prevx < x) && x >= 8) {
            y++; // ---
            x--; //    --- >
        }
        if (y < 26 && (prevx > x) && x > 2) {
            y++; //    --->
            x--; //  --- 
        }
        if (y < 26 && (prevx > x) && x <= 2) {
            y++; //    --->
            x++; //  --- 
        }
    }
}

void Ball::move() { // координаты до передвижения и  направление 0 <- // -> 1
    // this->prevx = this->x;
    // this->prevy = this->y; 
    this->setVector();
}

void Ball::getInfo() {
    std::cout << "direction = " << direction << std::endl;
    std::cout << "ball x = " << x << std::endl;
    std::cout << "ball y = " << y << std::endl;
}

    
void Ball::infoVector() {
    std::cout << "prevx: " << prevx << std::endl;
    std::cout << "prevy: " << prevy << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}

