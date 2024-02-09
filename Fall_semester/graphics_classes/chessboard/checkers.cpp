#include "checkers.h"
using namespace Graph_lib;
Checkers(Point xy) : Window{xy, Che}{

}


void Checkers::clicked (Cell& c)
{
  if (!c.is_black())
    return;

  if (!selected)
  {
    selected = &c;
    c.activate();
  }
  else
  {
    selected->deactivate();

    if (selected == &c)       // reset selection
    {
      selected = nullptr;
    }
    else                      // choose another cell
    {
      selected = &c;
      c.activate();
    }
  }

  Fl::redraw();
}