#include <vec/vec2d.h>
#include <iostream>
#include <list>
#include <Graph_lib/Point.h>
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using namespace Graph_lib;
using namespace std;

Vec2d rotated(const Vec2d &v, double angel_rad)
{
  double sin_a = std::sin(angel_rad);
  double cos_a = std::cos(angel_rad);
  double new_vx = cos_a * v.x + sin_a * v.y;
  double new_vy = (-1) * sin_a * v.x + cos_a * v.y;
  return Vec2d{new_vx, new_vy};
};

list<Vec2d> frac;

void one_koch_step(list<Vec2d> &frac)
{
  auto prev = --frac.end();
  for (auto cur = frac.begin(); cur != frac.end(); ++cur)
  {
    Vec2d v = *cur - *prev;
    Vec2d v0 = v / 3.0;
    double pi0 = pi / 3.0;
    Vec2d p1 = *prev + v0;
    Vec2d p3 = *cur - v0;
    Vec2d p2 = p1 + rotated(v0, pi0);

    frac.insert(cur, p1);
    frac.insert(cur, p2);
    frac.insert(cur, p3);

    prev = cur;
  };
};

Point Vtop(const Vec2d &v)
{
  return Point{
      round(v.x),
      round(v.y)};
}

void listToCPL(const list<Vec2d> &points, Graph_lib::Closed_polyline &poly)
{
  for (const auto &point : points)
  {
    poly.add(Vtop(point));
  }
}

std::list<Vec2d> regular_polygone(const Vec2d &c, double r, unsigned int n, double a)
{
  list<Vec2d> polyline;
  for (unsigned int i{0}; i < n; ++i)
  {
    double angel{a + 2 * pi / n * i};
    Vec2d p{c.x + r * cos(angel), c.y + r * sin(angel)};
    polyline.push_back(p);
  }
  return polyline;
}

void draw_Koch(int w, unsigned n)
{
  Simple_window win{Point{100, 100}, w, w, "Koch snowflake"};
  auto polygon{regular_polygone(Vec2d{w / 2, w / 2}, w / 2 - 20, n, pi * 0.5)};
  while (true)
  {
    Closed_polyline poly;
    poly.set_color(Color::black);
    listToCPL(polygon, poly);
    win.attach(poly);
    win.wait_for_button();
    one_koch_step(polygon);
    win.detach(poly);
    if (length(*(++polygon.begin()) - *polygon.begin()) < 1)
    {
      break;
    }
  }
}

int main()
{
  int w = 410; // window width
  int n = 1;
  draw_Koch(w, n);
}