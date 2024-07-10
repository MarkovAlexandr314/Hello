#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <iostream>

using namespace Graph_lib;

int main()
{

    constexpr Point point{300, 200};
    Simple_window win{point, 600, 400, "MyArc"};
    constexpr int r = 100;

    Striped_rectangle sr{point, 200, 100};
    sr.set_color(Color::dark_blue);
    // win.attach(sr);

    Striped_circle sc{point, 100};
    win.attach(sc);
    sc.set_color(Color::blue);

    win.wait_for_button();
}