#ifndef CELL_H
#define CELL_H 1

#include <Graph_lib/Simple_window.h>


using Graph_lib::Point;


struct Cell : Graph_lib::Button
{
  enum Type { black, white };


  Cell (Point xy, Graph_lib::Callback cb, Type t);

  void attach (Graph_lib::Window& win) override;

  void activate ()  { if (pw) pw->color (FL_SELECTION_COLOR); }
  void deactivate ()  { reset_color(); }

  bool is_black () const  { return type == black; }

  static constexpr int size = 100;

private:
  Type type;

  void reset_color ();
};

#endif // #ifndef CELL_H
