#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <iostream>

using namespace Graph_lib;

int get_y(Point p, int x, int r, int &&c)
{
    return sqrt(r * r - (x - p.x) * (x - p.x)) * c + p.y;
}

void foo(Circle &c) {};

int main()
{

    constexpr Point point{300, 200};
    Simple_window win{point, 600, 400, "MyArc"};
    constexpr int r = 100;

    Circle c{point, r};
    c.set_color(Color::blue);
    foo(c);
    win.attach(c);

    std::cout << "asdas" << std::endl;

    Point p{300 - r, 200};
    while (true)
    {
        while (p.x < point.x + r)
        {
            Mark m{Point{p.x, get_y(point, p.x, r, 1)}, 'o'};
            m.set_color(Color::black);
            win.attach(m);
            win.wait_for_button();
            p.x += 10;
        }
        while (p.x > point.x - r)
        {
            Mark m{Point{p.x, get_y(point, p.x, r, -1)}, 'o'};
            m.set_color(Color::black);
            win.attach(m);
            win.wait_for_button();
            p.x -= 10;
        }
    }
}
// Graph_lib::Arc1 arc{x, 50, 100, 0, 90};
// arc.set_color(Color::yellow);

// Box bx{x, 200, 100, 90};
// bx.set_color(Color::black);
// win.attach(bx);

// Arrow ar{x, 200, 80, 90};
// ar.set_color(Color::black);
// win.attach(ar);

// Vector_ref<Regular_hexagon> vec;

// vec.push_back(new Regular_hexagon{Point{point.x - r / 2, point.y - h}, 50});
// vec.push_back(new Regular_hexagon{Point{point.x - r / 2, point.y + h}, 50});
// vec.push_back(new Regular_hexagon{Point{point.x + r / 2, point.y - h}, 50});
// vec.push_back(new Regular_hexagon{Point{point.x + r / 2, point.y + h}, 50});
// vec.push_back(new Regular_hexagon{Point{point.x - r, point.y}, 50});
// vec.push_back(new Regular_hexagon{Point{point.x + r, point.y}, 50});

// for (int i{0}; i < vec.size(); i++)
// {
//     vec[i].set_color(Color::black);
//     win.attach(vec[i]);
// }

// rh1.set_color(Color::black);

// fl_line(point.x - r / 2, point.y - h, point.x + r / 2, point.y - h); // "--"
// fl_line(point.x - r / 2, point.y + h, point.x + r / 2, point.y + h); // "__"

// fl_line(point.x - r, point.y, point.x - r / 2, point.y - h); // "/\"
// fl_line(point.x + r, point.y, point.x + r / 2, point.y - h);

// fl_line(point.x - r, point.y, point.x - r / 2, point.y + h); // "\/"
// fl_line(point.x + r, point.y, point.x + r / 2, point.y + h);

// Regular_hexagon rh2{Point{x.x + 80, x.y - 50}, 50};
// rh2.set_color(Color::black);
// win.attach(rh1);
// win.attach(rh2);
