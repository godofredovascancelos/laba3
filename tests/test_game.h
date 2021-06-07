#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <cstdlib>
#include "game.h"

TEST(game_drawBoard, positive)
{

    std::string output_text = " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n";

    testing::internal::CaptureStdout();

    DrawBoard();


    std::string text = testing::internal::GetCapturedStdout();


    EXPECT_STREQ(text.c_str(), output_text.c_str());



}

TEST(game_getInput, negative){


    std::string output_text = "INVALID POSITION, TRY AGAIN...\n";

    testing::internal::CaptureStdout();

    GetInput(10);

    std::string text = testing::internal::GetCapturedStdout();


    EXPECT_STREQ(text.c_str(), output_text.c_str());


}
TEST(game_getInput, negative2){


    std::string output_text = "INVALID POSITION, TRY AGAIN...\n";

    testing::internal::CaptureStdout();

    GetInput(-1);

    std::string text = testing::internal::GetCapturedStdout();


    EXPECT_STREQ(text.c_str(), output_text.c_str());


}

TEST(game_getInput, positive){


    std::string output_text = " 1 | 2 | 3 \n-----------\n 4 | X | 6 \n-----------\n 7 | 8 | 9 \n";

    testing::internal::CaptureStdout();

    GetInput(5);
    DrawBoard();

    std::string text = testing::internal::GetCapturedStdout();


    EXPECT_STREQ(text.c_str(), output_text.c_str());



}

TEST(game_getInput, positive2){

    player = O;
    //возвращаем игровое поле в исходное состояние
    board[4] = '5';
    std::string output_text = " 1 | 2 | 3 \n-----------\n 4 | 5 | O \n-----------\n 7 | 8 | 9 \n";

    testing::internal::CaptureStdout();

    GetInput(6);
    DrawBoard();
    std::string text = testing::internal::GetCapturedStdout();


    EXPECT_STREQ(text.c_str(), output_text.c_str());



}

TEST(game_checkWinner, negative){


    ASSERT_FALSE(CheckWinner());

}

TEST(game_checkWinner, positive){
    //const int X = 1;		// Player X
    //const int O = 2;		// Player Y
    player = X;

    board[0] = 'X';
    board[1] = 'X';
    board[2] = 'X';

    EXPECT_EQ(CheckWinner(), 1);

    // ASSERT_TRUE(CheckWinner());

}


TEST(game_checkWinner, positive3){
    //    player = X;
    //возвращаем игровое поле в исходное состояние
    board[1] = '2';
    board[2] = '3';


    board[0] = 'X';
    board[3] = 'X';
    board[6] = 'X';

    EXPECT_EQ(CheckWinner(), 1);

    // ASSERT_TRUE(CheckWinner());


}
TEST(game_checkWinner, positive4){
    //const int X = 1;		// Player X
    //const int O = 2;		// Player Y
    //возвращаем игровое поле в исходное состояние
    board[3] = '4';
    board[6] = '7';

    board[0] = 'X';
    board[4] = 'X';
    board[8] = 'X';



    EXPECT_EQ(CheckWinner(), 1);

    //ASSERT_TRUE(CheckWinner());

}
