#include <Player.h>
#include <string>
#include <iostream>



Player::Player(int x, int y, std::string name) {
    this->x = x;
    this->y = y;
    this->name = name;
}

int Player::getX() {
    return x;
}
int Player::getPoints() {
    return points;
}
int Player::getY() {
    return y;
}

void Player::upPoint() {
    points++;
}
void Player::dropPoint() {
    points--;
}


void Player::move(char keyPressed, int num) {
    if (keyPressed == 'q' && num == 1 && x > 1 ) {
        this->x--;
    }
    else if (keyPressed == 'a' && num == 1 && x < 8) {
        this->x++;
    }
    if (keyPressed == 'p' && num == 2 && x > 1 ) {
        this->x--;
    }
    else if (keyPressed == 'l' && num == 2 && x < 8) {
        this->x++;
    }
}

void Player::getInfo() {
    std::cout << "player " << name << " x = " << x << std::endl;
    std::cout << "player " << name << " y = " << y << std::endl;
    std::cout << "player " << name << " points = " << points << std::endl;
}

