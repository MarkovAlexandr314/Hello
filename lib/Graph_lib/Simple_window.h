#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1
#include <iostream>

#include "GUI.h" // for Simple_window only (doesn't really belong in Window.h)

// Simple_window is basic scaffolding for ultra-simple interaction with graphics
// it provides one window with one "next" button for ultra-simple animation

struct Simple_window : Graph_lib::Window
{
  Simple_window(Graph_lib::Point xy, int w, int h, const std::string &title)
      : Graph_lib::Window{xy, w, h, title}, next_button{Graph_lib::Point{x_max() - 70, 0}, 70, 20, "Next", cb_next}
  {
    attach(next_button);
  }

  void wait_for_button()
  // modified event loop
  // handle all events (as per default), but quit when button_pushed becomes true
  // this allows graphics without control inversion
  {
    while (!button_pushed && Fl::wait())
      ;
    button_pushed = false;
    Fl::redraw();
  }

  Graph_lib::Button next_button;

private:
  bool button_pushed{false};

  static void cb_next(Graph_lib::Address, Graph_lib::Address addr) // callback for next_button
  {
    auto *pb = static_cast<Graph_lib::Button *>(addr);
    static_cast<Simple_window &>(pb->window()).next();
  }

  void next() { button_pushed = true; }
};

struct My_window : Simple_window
{
  My_window(Graph_lib::Point xy, int w, int h, const std::string &title)
      : Simple_window(xy, w, h, title), quit_button{Graph_lib::Point{x_max() - 70, 25}, 70, 20, "Quit", cb_quit}
  {
    attach(quit_button);
  }

  Graph_lib::Button quit_button;

private:
  static void cb_quit(Graph_lib::Address, Graph_lib::Address addr) // callback for next_button
  {
    auto *pb = static_cast<Graph_lib::Button *>(addr);
    static_cast<My_window &>(pb->window()).quit();
  }

  void quit() { this->hide(); }
};

class Clock : public Graph_lib::Window
{
public:
  Clock(Graph_lib::Point xy, int ww, int hh, const std::string &title) : Graph_lib::Window(xy, ww, hh, title), p{xy}, r{100} {}

  void tik_tok();

private:
  Graph_lib::Point p;
  int r;
};

void Clock::tik_tok()
{
  Graph_lib::Point start{x_max() / 2, y_max() / 2};
  Graph_lib::Point end{start.x + r, start.y};
  Graph_lib::Point end_min{start.x + r, start.y};

  double angle_sec{0};
  double angle_min{0};
  double angle_hour{0};
  double angle_num{-Graph_lib::pi * 60 / 180};

  Graph_lib::Vector_ref<Graph_lib::Line> Arrows_sec;
  Graph_lib::Vector_ref<Graph_lib::Line> Arrows_min;
  Graph_lib::Vector_ref<Graph_lib::Line> Arrows_hour;
  Graph_lib::Vector_ref<Graph_lib::Text> Numbers;
  // numbers
  for (size_t i = 1; i <= 12; i++)
  {
    end = Graph_lib::Point{start.x + cos(angle_num) * r * 1.2, start.y + sin(angle_num) * r * 1.2};
    Graph_lib::Text *number = new Graph_lib::Text{Graph_lib::Point{end}, std::to_string(i)};
    number->set_color(Graph_lib::Color::dark_blue);
    Numbers.push_back(number);
    angle_num += Graph_lib::pi * 30 / 180;
    attach(*number);
  }

  // seconds
  for (size_t i = 0; i < 60; i++)
  {
    Graph_lib::Line *arrow_sec = new Graph_lib::Line{start, end};
    arrow_sec->set_color(Graph_lib::Color::black);
    Arrows_sec.push_back(arrow_sec);
    angle_sec += Graph_lib::pi * 6 / 180;
    end = Graph_lib::Point{start.x + cos(angle_sec) * r, start.y + sin(angle_sec) * r};
  }
  // minutes
  double scale1 = 0.8;
  for (size_t i = 0; i < 60; i++)
  {
    end = Graph_lib::Point{start.x + cos(angle_min) * r * scale1, start.y + sin(angle_min) * r * scale1};
    Graph_lib::Line *arrow_min = new Graph_lib::Line{start, end};
    arrow_min->set_color(Graph_lib::Color::dark_blue);
    Arrows_min.push_back(arrow_min);
    angle_min += Graph_lib::pi * 6 / 180;
  }
  // hours
  double scale2 = 0.8;
  for (size_t i = 0; i < 60; i++)
  {
    end = Graph_lib::Point{start.x + cos(angle_hour) * r * scale2, start.y + sin(angle_hour) * r * scale2};
    Graph_lib::Line *arrow_hour = new Graph_lib::Line{start, end};
    arrow_hour->set_color(Graph_lib::Color::dark_red);
    Arrows_hour.push_back(arrow_hour);
    angle_hour += Graph_lib::pi * 6 / 180;
  }
  Graph_lib::Circle *clock_face = new Graph_lib::Circle{start, r};
  clock_face->set_color(Graph_lib::Color::dark_magenta);
  Window::attach(*clock_face);

  while (true)
  {
    for (size_t k = 0; k < 60; k++)
    {
      attach(Arrows_hour[k]);
      for (size_t j = 0; j < 60; j++)
      {
        attach(Arrows_min[j]);
        for (size_t i = 0; i < 60; i++)
        {
          attach(Arrows_sec[i]);
          Fl::wait();
          Sleep(1000);
          detach(Arrows_sec[i]);
          Window::redraw();
        }
        detach(Arrows_min[j]);
      }
      detach(Arrows_hour[k]);
    }
  }
}

#endif // SIMPLE_WINDOW_GUARD
