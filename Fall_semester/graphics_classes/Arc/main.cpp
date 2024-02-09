#include <iostream>
#include <sstream>
#include <stdexcept>

#include <vec/vec2d.h>
#include <Graph_lib/Point.h>
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <Graph_lib/GraphShape.h>

using namespace Graph_lib;

Vector_ref<Arc2> vr;

Vec2d rotated(const Vec2d &v, double angel_rad)
{
    double sin_a = std::sin(angel_rad);
    double cos_a = std::cos(angel_rad);
    double new_vx = cos_a * v.x + sin_a * v.y;
    double new_vy = (-1) * sin_a * v.x + cos_a * v.y;
    return Vec2d{new_vx, new_vy};
};

int fib(int n)
{
    switch (n)
    {
    case 1:
        return 0;
        break;

    case 2:
        return 1;
        break;
    default:
        return fib(n - 2) + fib(n - 1);
        break;
    }
}

void gold_spiral(int n, float angle)
{
    int r{1};
    Vec2d w{400, 400};
    Vec2d e{-1, 0};
    Vec2d m;
    int y{2};
    int t{4};
    int r1;

    vr.push_back(new Arc2(Point(w.x - r / 2, w.y), r / 2, r / 2, angle, angle + 180.0));
    angle += 180;
    m = w + (e * fib(y) * r);

    for (int i{0}; i < n; ++i)
    {
        r1 = r * fib(t - 1);
        vr.push_back(new Arc2(Point(m.x, m.y), r1, r1, angle, angle + 90.0));

        e = rotated(e, pi / 2);
        m = m + (e * r * fib(y));
        ++t;
        ++y;

        angle += 90.0;
    };
}

int main()
{
    Point t{300, 300};
    float angle{180.0};
    int n{15};

    Simple_window win({100, 100}, 800, 800, "LOLZ");
    win.wait_for_button();

    gold_spiral(n, angle);
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].set_color(Color::yellow);
        win.attach(vr[i]);
    }

    win.wait_for_button();
    return 0;
}
