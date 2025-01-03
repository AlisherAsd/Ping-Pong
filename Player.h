#pragma once


#include <string>
#include <iostream>


class Player
{
protected:

    int points = 0;
    int x;
    int y;
    std::string name;

public:
    Player(int x, int y, std::string name);

    int getX();
    int getPoints();
    int getY();

    void upPoint();
    void dropPoint();


    void move(char keyPressed, int num);
    void getInfo();
};
