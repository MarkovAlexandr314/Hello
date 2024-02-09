#include <iostream>
class Lambda
{
    public:
        Lambda(double& sum) : s{sum} {}
        void operator() (double x) { s+=x; }
        auto Get(){return s;}
    private:
        double s{10};
};

int main(){
    double sum2{0};
    Lambda f2{sum2};
    for (double x : {1., 3., -5., 6., 0., 10.})
        f2(x);
    std::cout<<f2.Get();
}