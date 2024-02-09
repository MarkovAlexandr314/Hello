#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

#include "least_squares.h"

using namespace Graph_lib;

class Scale
{
  int cbase;    //  coordinate base
  double vbase; // base of values
  double scale;

public:
  Scale(int b, double vb, double s)
      : cbase(b), vbase(vb), scale(s) {}
  int operator()(double v) const { return cbase + (v - vbase) * scale; }
};

double liner(double x) { return x; }

auto make_regression(lsm::Coeff a, lsm::Coeff b, lsm::BaseFunction f)
{
  return [a, b, f](double x)
  { return a.value + b.value * f(x); };
};

std::string as_str(lsm::Coeff a, std::streamsize precision = 3)
{
  std::ostringstream oss;
  oss.precision(precision);
  oss << std::fixed << a.value;
  return oss.str();
}

double non_liner(double x)
{
  return 10 * sin(x) * cos(2.5 * x);
}

int main()
try
{
  constexpr int xmax = 600; // window size
  constexpr int ymax = 450;
  constexpr int xoffset = 40;
  constexpr int yoffset = 40;
  constexpr int xspace = 40;
  constexpr int yspace = 40;
  constexpr int xlenght = xmax - xoffset - xspace;
  constexpr int ylenght = ymax - yoffset - yspace;
  constexpr Point orig{xoffset, ymax - yoffset};
  constexpr int rmin = 0;
  constexpr int rmax = 10;
  constexpr double xscale = double(xlenght) / (rmax - rmin);
  constexpr double yscale = double(ylenght) / 250;
  constexpr int npoints = 1000;

  Scale xs{xoffset, rmin, xscale};
  Scale ys{ymax - yoffset, 0, -yscale};

  Point lt{100, 100}; // left top window corner
  Simple_window win{lt, xmax, ymax, "Least Squares"};
  win.color(Color::white);
  win.wait_for_button();

  // ... (draw axes)
  Axis x{Axis::x, orig, xlenght, int(xlenght / xscale), "x"};
  Axis y{Axis::y, orig, ylenght, 10, "y"};
  x.label.move(xoffset + xlenght - 200, 0);
  win.attach(x);
  win.attach(y);
  win.wait_for_button();

  // ... (draw plot)
  auto data = lsm::read("data.txt");
  Marks scatter{"0"};
  for (auto p : data)
    scatter.add(Point{xs(p.x), ys(p.y)});
  win.attach(scatter);
  win.wait_for_button();

  // draw liner regression
  auto [a, b] = lsm::least_squares(data, liner);
  Function line1{make_regression(a, b, liner), rmin, rmax, orig, npoints, xscale, yscale};
  line1.set_style(Line_style{Line_style::solid, 2});
  line1.set_color(Color::red);
  win.attach(line1);
  Point p1{xoffset + 50, yspace + 20};
  Text eq1{p1, "y = " + as_str(a) + "+" + as_str(b) + "*x"};
  eq1.set_color(Color::red);
  eq1.set_font_size(15);
  win.attach(eq1);
  win.wait_for_button();

  // dodelat
  auto [a2, b2] = lsm::least_squares(data, non_liner);
  Function line2{make_regression(a2, b2, non_liner), rmin, rmax, orig, npoints, xscale, yscale};
  line2.set_style(Line_style{Line_style::solid, 2});
  line2.set_color(Color::red);
  win.attach(line2);
  Point p2{xoffset + 50, yspace + 20};
  Text eq2{p2, "y = " + as_str(a2) + "+" + as_str(b2) + "*x"};
  eq2.set_color(Color::red);
  eq2.set_font_size(15);
  win.attach(eq2);
  win.wait_for_button();
}
catch (std::exception &e)
{
  std::cerr << "error: " << e.what() << std::endl;
  return 1;
}
