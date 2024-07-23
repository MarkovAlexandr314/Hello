#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <Graph_lib/GUI.h>
#include <iostream>
#include <sstream>
using namespace Graph_lib;
using namespace std;

int main()
{
    Point p{100, 100};

    Clock win{p, 600, 400, "My_window"};
    win.tik_tok();
}
