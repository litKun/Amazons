/**
 * Copyright (c) 2019 Guyutongxue
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef UI_H
#define UI_H

#include <conio.h>
#include <windows.h>
#include <string>
#include "amazons.h"

class UI {
public:
    UI();
    ~UI();
    void printBoardBackground();
    void printGame(const Chessboard& board);
    void printGame(const Chessboard& board,Move lastmove);
    Move getMove(Chessboard board,Player pl);
    int printMainMenu();
    int printModeMenu();
    enum class Color {
        Black,         // 黑
        Blue,          // 蓝
        Green,         // 绿
        Cyan,          // 青
        Red,           // 红
        Magenta,       // 洋红
        Brown,         // 棕
        LightGrey,     // 淡灰
        DarkGrey,      // 深灰
        LightBlue,     // 淡兰
        LightGreen,    // 淡绿
        LightCyan,     // 淡青
        LightRed,      // 淡红
        LightMagenta,  // 淡洋红
        Yellow,        // 黄
        White          // 白
    };

private:
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    short center_x;
    void clearScreen();
    void setPos(short x, short y);
    void setColor(Color foreground, Color background);
    int printMenu(const std::string& title, std::string* choices, short* pos, int num);
    constexpr static const char* boardLine[17] = {
        "┌─┬─┬─┬─┬─┬─┬─┬─┐", "│ │ │ │ │ │ │ │ │", "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │",
        "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │", "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │",
        "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │", "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │",
        "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │", "├─┼─┼─┼─┼─┼─┼─┼─┤", "│ │ │ │ │ │ │ │ │",
        "└─┴─┴─┴─┴─┴─┴─┴─┘"};
    inline COORD getCOORD(short x,short y){
        COORD r;
        r.X= center_x - 9 + x * 2 + 1;
        r.Y=y*2+1;
        return r;
    }
};

#endif  // UI_H