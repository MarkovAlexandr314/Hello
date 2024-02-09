#ifndef CHECKERS_H
#define CHECKERS_H 1

#include <Graph_lib/GUI.h>

struct Checkers : Graph_lib::Window
{
    Checkers(Graph_lib::Point xy);

private:
    Chessboard board;

    static void cb_clicked(Address, Address widget)
    {
        auto &btn = Graph_lib::reference_to<Cell>(widget);
        dynamic_cast<Checkers &>(btn.window()).clicked(btn);
    }
    void clicked(Cell &c);
};

#endif