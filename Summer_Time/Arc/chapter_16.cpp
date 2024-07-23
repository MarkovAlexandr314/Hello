#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <Graph_lib/GUI.h>
#include <iostream>
#include <sstream>
using namespace Graph_lib;
using namespace std;

struct Lines_window : Graph_lib::Window
{
    Lines_window(Point xy, int w, int h,
                 const string &title);
    Open_polyline lines;

private:
    Button next_button; // Добавляет пару (nex t_x, nex t_y) в объект l ines
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button color_button;
    bool flag{true};
    void next();
    void quit();

    static void cb_red(void *, void *);
    static void cb_blue(void *, void *);
    static void cb_black(void *, void *);

    void red_pressed()
    {
        change(Color::red);
        change_menu();
        redraw();
    }
    void blue_pressed()
    {
        change(Color::blue);
        change_menu();
        redraw();
    }
    void black_pressed()
    {
        change(Color::black);
        change_menu();
        redraw();
    }

    void change(Color c) { lines.set_color(c); }
    void color_menu_show()
    {
        color_menu.show();
        color_button.hide();
        flag = !flag;
    }
    void color_menu_hide()
    {
        color_menu.hide();
        color_button.show();
        flag = !flag;
    }
    void change_menu()
    {
        if (flag)
            color_menu_show();
        else
            color_menu_hide();
        redraw();
    }
};

Lines_window::Lines_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      next_button{
          Point{x_max() - 150, 0}, 70, 20, "Next point",
          [](void *, void *pw)
          {
              auto *pb = static_cast<Graph_lib::Button *>(pw);
              static_cast<Lines_window &>(pb->window()).next();
          }},
      quit_button{
          Point{x_max() - 70, 0}, 70, 20, "Quit",
          [](void *, void *pw)
          {
              auto *pb = static_cast<Graph_lib::Button *>(pw);
              static_cast<Lines_window &>(pb->window()).quit();
          }},
      next_x{Point{x_max() - 310, 0}, 50, 20, "next x : "},
      next_y{Point{x_max() - 210, 0}, 50, 20, "next y : "},
      xy_out{Point{100, 0}, 100, 20, "current (x,y) :"},
      color_menu{Point{x_max() - 70, 40}, 70, 20, Menu::vertical, "color"},
      color_button{Point{x_max() - 80, 40}, 80, 20, "color menu",
                   [](void *, void *pw)
                   {
                       auto *pb = static_cast<Graph_lib::Button *>(pw);
                       static_cast<Lines_window &>(pb->window()).change_menu();
                   }}
//   flag{true}
{
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "red", cb_red});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue", cb_blue});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "black", cb_black});

    attach(color_menu);
    attach(next_button);
    attach(color_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.hide();
}

void Lines_window::cb_red(void *, void *pw)
{
    auto *pb = static_cast<Graph_lib::Button *>(pw);
    static_cast<Lines_window &>(pb->window()).red_pressed();
}

void Lines_window::cb_blue(void *, void *pw)
{
    auto *pb = static_cast<Graph_lib::Button *>(pw);
    static_cast<Lines_window &>(pb->window()).blue_pressed();
}

void Lines_window::cb_black(void *, void *pw)
{
    auto *pb = static_cast<Graph_lib::Button *>(pw);
    static_cast<Lines_window &>(pb->window()).black_pressed();
}

void Lines_window::quit()
{
    hide(); // Идиома FLTK для удаления окна
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x, y});
    // Обновление текущей точки
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw(); /* старое изображение остается на экране,
                 пока не будет вызвана функция
                 redraw () из класса Window */
}

int main()
{
    try
    {
        Lines_window win{Point{100, 100}, 600, 400, "lines"};
        gui_main();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Something exception\n";
        return 2;
    }
}