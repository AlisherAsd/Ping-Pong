#pragma once
#include <string>
#include <iostream>


class Ball
{

public:
    int x;
    int y;
    int direction = 1;
    int prevx;
    int prevy;

    Ball(int x, int y);

    int getDirection();

    void setDirection(int d);

    void setVector();

    void move();
    void getInfo();
        
    void infoVector();
};
