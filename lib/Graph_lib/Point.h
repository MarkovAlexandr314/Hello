#ifndef POINT_GUARD
#define POINT_GUARD
#include <cmath>
namespace Graph_lib
{

  struct Point
  {
    int x, y;

    Point() : x{0}, y{0} {}

    constexpr Point(int xx, int yy) : x{xx}, y{yy} {}

    Point &operator+=(Point d)
    {
      x += d.x;
      y += d.y;
      return *this;
    }

    Point &operator-=(Point d)
    {
      x -= d.x;
      y -= d.y;
      return *this;
    }
  };

  inline Point operator+(Point a, Point b) { return a += b; }

  inline Point operator-(Point a, Point b) { return a -= b; }

  inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

  inline bool operator!=(Point a, Point b) { return !(a == b); }

  // inline double dist (Point a, Point b) { return std::pow(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2), 0.5);}//наша добавка

} // namespace Graph_lib

#endif // POINT_GUARD
