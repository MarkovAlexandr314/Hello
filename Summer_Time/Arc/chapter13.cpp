#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <iostream>

int main()
{
    using namespace Graph_lib;

    constexpr Point x{100, 100};
    // int size = 20;
    Simple_window win{x, 600, 400, "Palitra"};

    Vector_ref<Graph_lib::Rectangle> rec;

    // for (int i = 0; i < 16; i++)
    // {
    //     for (int j = 0; j < 16; j++)
    //     {
    //         rec.push_back(new Graph_lib::Rectangle{Point{size * i, size * j}, size, size});
    //         rec[rec.size() - 1].set_fill_color(Color{i + j * 16});
    //         rec[rec.size() - 1].set_color(Color::invisible);
    //         win.attach(rec[rec.size() - 1]);
    //     }
    // }

    // Text t{Point{300, 300}, "A closed polyline that isn`t a polygon, \n Boom"};
    // t.set_color(Color::dark_blue);
    // t.set_font(Font::courier_bold_italic);
    // win.attach(t);

    Circle c1{Point{100, 200}, 50};
    Circle c2{Point{150, 200}, 100};
    Circle c3{Point{200, 200}, 150};

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    Mark m1{Point{100, 200}, 'x'};
    Mark m2{Point{150, 200}, 'y'};
    Mark m3{Point{200, 200}, 'z'};

    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

    // Graph_lib::Ellipse e1{Point{200, 200}, 50, 50};
    // Graph_lib::Ellipse e2{Point{200, 200}, 100, 50};
    // Graph_lib::Ellipse e3{Point{200, 200}, 100, 150};

    // win.attach(e1);
    // win.attach(e2);
    // win.attach(e3);

    // Marked_polyline mp1{"1234"};
    // mp1.add(Point{100, 100});
    // mp1.add(Point{150, 200});
    // mp1.add(Point{250, 250});
    // mp1.add(Point{300, 200});
    // mp1.set_color(Color::blue);
    // win.attach(mp1);

    // Graph_lib::Marks pp{"x", {{100, 100}, {150, 200}, {250, 250}, {300, 200}}};
    // win.attach(pp);

    win.wait_for_button();
}
