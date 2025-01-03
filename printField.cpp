#include <Player.h>
#include <Ball.h>
#include <Field.h>


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
                std::cout << 'O';
            } 
            if (player1.getX() == i && player1.getY() == j) {
                std::cout << ')';
            } 
            if (player2.getX() == i && player2.getY() == j) {
                std::cout << '(';
            } 
            else {
                std::cout << field[i][j];
            }
        }
        std::cout << std::endl;
    }
}

