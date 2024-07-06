#include <iostream>
#include <sstream>
#include <stdexcept>

#include <vec/vec2d.h>
#include <Graph_lib/Point.h>
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <Graph_lib/GraphShape.h>

using namespace Graph_lib;
int main()
{
    Point t{300, 300};
    float angle{180.0};
    size_t r{50};
    Point w{400, 400};
    int n{15};

    Simple_window win({100, 100}, 800, 800, "LOLZ");
    win.wait_for_button();

    Arc2 arc(Point(w.x - r / 2, w.y), r / 2, r / 2, angle, angle + 180.0);
    arc.set_color(Color::dark_magenta);

    win.attach(arc);

    // gold_spiral(n, angle);
    // for (int i = 0; i < vr.size(); ++i)
    // {
    // vr[i].set_color(Color::black);
    // }

    win.wait_for_button();
    return 0;
}