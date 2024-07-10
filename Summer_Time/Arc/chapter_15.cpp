#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <iostream>
#include <sstream>

using namespace Graph_lib;

double one(double) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x * x; }

double sloping_cos(double x) { return cos(x) + slope(x); }

double fac(int n)
{
    double c{1};
    for (size_t i = 1; i <= n; i++)
    {
        c *= n;
    }
    return c;
}

double term(double x, int n)
{
    return pow(x, n) / fac(n);
}

double expe(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

int main()
{
    constexpr int xmax = 600; // Размер окна
    constexpr int ymax = 400;
    constexpr int x_orig = xmax / 2; // Центр окна (0, 0)
    constexpr int y_orig = ymax / 2;
    constexpr Point orig{x_orig, y_orig};

    constexpr int r_min = -10; // Диапазон [-10,11)
    constexpr int r_max = 11;

    constexpr int n_Points = 400; // Количество точек в диапазоне

    constexpr int x_scale = 30; // Масштабные множители
    constexpr int y_scale = 30;

    Simple_window win{Point{100, 100}, xmax, ymax, "Function graphing"};

    constexpr int xlenqth = xmax - 40;
    constexpr int ylenqth = ymax - 40;

    Axis x{Axis::x, Point{20, y_orig},
           xlenqth, xlenqth / x_scale, "one notch == 1"};
    Axis y{Axis::y, Point{x_orig, ylenqth + 20},
           ylenqth, ylenqth / y_scale, "one notch == 1"};

    x.set_color(Color::dark_red);
    y.set_color(Color::dark_red);
    win.attach(x);
    win.attach(y);

    Function real_epx{exp, r_min, r_max, orig, 200, x_scale, y_scale};
    real_epx.set_color(Color::blue);
    win.attach(real_epx);

    for (int n = 0; n < 50; ++n)
    {
        std::ostringstream ss;
        ss << "exp approxiшation ; n==" << n;
        win.set_label(ss.str());
        // Очередное приближение :
        Function e{[n](double x)
                   { return expe(x, n); },
                   r_min, r_max, orig, 200, x_scale, y_scale};
        e.set_color(Color::black);
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }

    win.wait_for_button();
}
// Function s4{cos, r_min, r_max, orig, 400, 30, 30};
// s4.set_color(Color::blue);
// Function s5{[](double x) -> double
// { return cos(x) + slope(x); }, r_min, r_max, orig, 400, 30, 30};
// s5.set_color(Color::blue);
// x.label.move(-160, 0);
// x.notches.set_color(Color::dark_blue);
// win.attach(s4);
// win.attach(s5);
// Function f1{log, 0.000001, r_max, orig, 200, 30, 30}; // ln()
// Function f2{sin, r_min, r_max, orig, 200, 30, 30};    // sin()
// f2.set_color(Color::blue);
// Function f3{cos, r_min, r_max, orig, 200, 30, 30}; // cos()
// Function f4{exp, r_min, r_max, orig, 200, 30, 30}; // ехр()
// win.attach(f1);
// win.attach(f2);
// win.attach(f3);
// win.attach(f4);
// Function s{one, r_min, r_max, orig, n_Points, x_scale, y_scale};
// Function s2{slope, r_min, r_max, orig, n_Points, x_scale, y_scale};
// Function s3{square, r_min, r_max, orig, n_Points, x_scale, y_scale};
// s.set_color(Color::dark_blue);
// s2.set_color(Color::dark_blue);
// s3.set_color(Color::dark_blue);
// win.attach(s);
// win.attach(s2);
// win.attach(s3);

// Text ts{Point{100, y_orig - 40}, "one"};
// Text ts2{Point{100, y_orig + y_orig / 2 - 20}, "x/2 "};
// Text ts3{Point{x_orig - 100, 20}, "x*x"};
// win.set_label("Function graphing: label functions");
// win.attach(ts);
// win.attach(ts2);
// win.attach(ts3);