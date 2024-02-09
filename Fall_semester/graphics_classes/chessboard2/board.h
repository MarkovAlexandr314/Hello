#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

using Graph_lib::Address;
using Graph_lib::Point;

// struct My_window : Simple_window
// {
//   My_window (Point xy, int w, int h, const std::string& title)
//     : Simple_window{ xy, w, h, title }
//     , quit_button{ Point{x_max()-70, 20}, 70, 20, "Quit", cb_quit }
//   {
//     attach (quit_button);
//   }

//   Graph_lib::Button quit_button;

// private:
//   static void cb_quit (Address, Address widget)
//   {
//     auto& btn = Graph_lib::reference_to<Graph_lib::Button>(widget);
//     dynamic_cast<My_window&>(btn.window()).quit();
//   }
//   void quit ()  { hide(); }
// };

struct Chessboard : Graph_lib::Widget
{
  Chessboard(Point xy);

  static constexpr int N = 4; // board N by N
  static constexpr int N_max = 8;

  static_assert(N <= N_max,
                "do not allow board larger than N_max by N_max");

  Chessboard(Point xy, Graph_lib::Callback cd_clicked);
  void attach(Graph_lib::Window& win) override;

      private : static constexpr int margin = 30;
  static constexpr int width = N * Cell::size + 2 * margin + 70;
  static constexpr int height = N * Cell::size + 2 * margin;

  Graph_lib::Vector_ref<Cell> cells;
  Graph_lib::Marks x_labels;
  Graph_lib::Marks y_labels;

  Cell *selected{nullptr}; // activated cell
};

#endif // #ifndef BOARD_H
