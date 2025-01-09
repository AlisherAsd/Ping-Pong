#include <iostream>
#include <ncurses.h>


const int x = 10;
const int y = 30;

char field[x][y] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// void setField() {
//     for (int i = 0; i < y; i++) {
//         for (int j = 0; j < x; j++) {
//             if (i == 0) field[i][j] = '#';
//             if (i == y - 1) field[i][j] = '#';
//             if (x == 0) field[i][j] = '#';
//             if (x == j - 1) field[i][j] = '#';
//             else field[i][j] = ' ';
//         }
//     }
// }



class Player
{
protected:

    int points = 0;
    int x;
    int y;
    std::string name;

public:
    Player(int x, int y, std::string name) {
        this->x = x;
        this->y = y;
        this->name = name;
    }

    int getX() {
        return x;
    }
    int getPoints() {
        return points;
    }
    int getY() {
        return y;
    }

    void upPoint() {
        points++;
    }
    void dropPoint() {
        points--;
    }


    void move(char keyPressed, int num) {
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

    void getInfo() {
        // std::cout << "player " << name << " x = " << x << std::endl;
        // std::cout << "player " << name << " y = " << y << std::endl;
        std::cout << "player " << name << " points = " << points << std::endl;
    }

};






class Ball
{

public:
    int x;
    int y;
    int direction = 1;
    int prevx;
    int prevy;

    Ball(int x, int y) {
        this->x = x;
        this->y = y;
        this->prevx = rand() % (8 - 3 + 1) + 3;
        this->y = rand() % (27 - 3 + 1) + 3;
    }

    int getDirection() {
        return direction;
    }

    void setDirection(int d) {
        if (d == 1) prevx = rand();
        if (d == 0) prevx = rand();
        direction = d;
    }

    void setVector() {
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

    void move() { // координаты до передвижения и  направление 0 <- // -> 1
        // this->prevx = this->x;
        // this->prevy = this->y; 
        this->setVector();
    }

    void getInfo() {
        std::cout << "direction = " << direction << std::endl;
        std::cout << "ball x = " << x << std::endl;
        std::cout << "ball y = " << y << std::endl;
    }

        
    void infoVector() {
        std::cout << "prevx: " << prevx << std::endl;
        std::cout << "prevy: " << prevy << std::endl;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }
};







void printField(Player &player1, Player &player2, Ball &ball) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (ball.x == player1.getX() && ball.y == player1.getY()) {
                ball.setDirection(1);
                player1.upPoint();
            }
         
            if (ball.x == player2.getX() && ball.y == player2.getY()) {
                ball.setDirection(0);
                player2.upPoint();
            }


            if (ball.x != player1.getX() && ball.y == player1.getY()) {
                ball.setDirection(1);
            }
         
            if (ball.x != player2.getX() && ball.y == player2.getY()) {
                ball.setDirection(0);
            }
           
            if (ball.x == i && ball.y == j) {
                std::cout << '@';
            } 
            if (player1.getX() == i && player1.getY() == j) {
                std::cout << '>';
            } 
            if (player2.getX() == i && player2.getY() == j) {
                std::cout << '<';
            } 
            else {
                std::cout << field[i][j];
            }
        }
        std::cout << std::endl;
    }
}





int main() {

    system("clear");
    std::cout << "----------  PP Hello  --------------" << std::endl;
    std::cout << "----------     GO     --------------" << std::endl;
    std::cout << "-------  enter g for game  -----------" << std::endl;
    char n = 'g';
    std::cin >> n; 

 
    system("clear");
    std::string s1;
    std::string s2;
    std::cout << "Enter name player 1: ";
    std::cin >> s1;
    std::cout << std::endl;
    std::cout << "Enter name player 2: ";
    std::cin >> s2;
    std::cout << std::endl;



    Player player1(5, 3, s1);
    Player player2(5, 26, s2);
    Ball ball(5, 15);

    char m;
    int getControl = 17;

    do
    {
        getControl++;
        system("clear");
        player1.getInfo();
        player2.getInfo();
        // ball.getInfo();
        // ball.infoVector();
        printField(player1, player2, ball);
        std::cout << "Move  " << ball.getDirection() + 1 << " (w, s, d, a): ";
        std::cout << " GOUNT: " << getControl << std::endl;
        m = getchar();
        if (ball.getDirection() == 1) {
            player2.move(m, 2);
        }
        if (ball.getDirection() == 0) {
            player1.move(m, 1);
        }   
        ball.move();
    } while (!(player1.getPoints() == 900  || player2.getPoints() == 900));

    std::string winner;
    if (player1.getPoints() == 900) winner = s1;
    else winner = s2;

    system("clear");
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------- " << winner << "  Winner! -----------------------" << std::endl;
    std::cout << "---------- player " << s1 << ": " << player1.getPoints() << " points -----------------------" << std::endl;    
    std::cout << "---------- player " << s2 << ": " << player2.getPoints() << " points -----------------------" << std::endl;  
    std::cout << "------------------------------------------------------------------------------" << std::endl;
  


    return 0;
}   