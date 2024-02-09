#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <iterator>
#include <stdexcept>
#include <cmath>
#include <string>
struct  Point
{
    double x,y;
    Point()=default;
    Point(double xx, double yy): x{xx}, y{yy} {}
};
std::istream& operator >>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}
std::ostream& operator <<(std::ostream& os, const Point& p)
{
    os <<p.x<<" "<<p.y;
    return os;
}
auto read(const std::string& filename){
    std::ifstream ifs{filename};
    if(!ifs)
        throw std::runtime_error{"Cant open file '" + filename + "'"};
    return std::vector<Point>{std::istream_iterator<Point>{ifs}, std::istream_iterator<Point>{}};
        
}
struct coef{
    double value; //coefficient estimate
    double delta; // confidence band
    coef (double v, double d): value{v}, delta{d}{}
};
auto least_squares(const std::vector<Point>& points)
{
    size_t N{points.size()};
    double x_ave{0.0};
    double y_ave{0.0};
    double xy_ave{0.0};
    double xz_ave{0.0};

for(const auto& p:points){
    x_ave+=p.x;
    y_ave+=p.y;
    xy_ave+=p.x*p.y;
    xz_ave+=p.x*p.x;
}
x_ave /= N;
y_ave /= N;
xy_ave /= N;
xz_ave /= N;
double b{(xy_ave-x_ave*y_ave)/(xz_ave-x_ave*x_ave)};
if(!std::isfinite(b))
    throw std::overflow_error{"division by zero"};
double a{y_ave-b*x_ave};
return std::make_tuple(coef{a,0.0}, coef{b,0.0});
}
int main(int argc, char * argv[])
{
    if (argc!=2){
        std::cerr << "usage:" << argv[0] <<" fail_with_data"<<std::endl;
        return 2;
    }
    try{
        std::string datafile{argv[1]};
        auto [a,b] = least_squares(read(datafile));
    std::cout << datafile << " " << a.value << " " << a.delta<<" "<<b.value<<" "<<b.delta<<std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "error: " << e.what()<<std::endl;
        return 1;
    }
    return 0;
}