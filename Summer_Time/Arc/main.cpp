#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <iostream>

int main()
{
    using namespace Graph_lib;

    Point t1{100, 100};

    Simple_window win{t1, 1000, 800, "Canvas"};
    // x axis
    Axis xa{Axis::x, Point(20, 300), 280, 10, "x axis"};
    xa.set_color(Color::black);
    win.attach(xa);
    // y axis
    Axis ya{Axis::y, Point(20, 300), 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    // sin function
    Function sine{sin, 0, 100, Point(20, 150), 1000, 50, 50};
    sine.set_color(Color::dark_blue);
    win.attach(sine);

    Graph_lib::Polygon poly;
    poly.add(Point{350, 100});
    poly.add(Point{300, 200});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Graph_lib::Rectangle r{Point{200, 200}, 100, 50};
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point(50, 75));
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);

    Text t{Point{150, 150}, "Hello, graphical world!"};
    t.set_color(Color::dark_magenta);
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    Image ii{Point{100, 50}, "DrStone.jpg"};
    ii.move(200, 0);
    win.attach(ii);

    Circle c{Point{100, 200}, 50};
    Graph_lib::Ellipse e{Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m{Point{100, 200}, 'x'};
    win.attach(c);
    win.attach(e);

    win.set_label("Canvas #12");
    win.wait_for_button();
}
