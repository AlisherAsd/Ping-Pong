#include <iostream>
#include "Field.h"
#include "Ball.h"
#include "Player.h"
#include "printField.h"



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
        ball.getInfo();
        ball.infoVector();
        printField(player1, player2, ball);
        std::cout << "Move  " << ball.getDirection() + 1 << " (w, s, d, a): ";
        std::cout << " GOUNT: " << getControl << std::endl;
        std::cin >> m;
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
    std::cout << "---------------------------------------------------------------------------" << std::endl;


    return 0;
}   