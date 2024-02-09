
#ifndef GRAPH_BOX_H
#define GRAPH_BOX_H

#include "Graph.h"
namespace Graph_lib
{
    struct Box2 : Rectangle
    {
        Box2(const Point &center, int w, int h, int radius);
        Box2(const Point &p1, const Point &p2, int r);

        void set_radius(int r) {radius = r;}
        int get_radius () const {return radius;}
        protected:
            void draw_lines() const override;
        private:
        
    };
}