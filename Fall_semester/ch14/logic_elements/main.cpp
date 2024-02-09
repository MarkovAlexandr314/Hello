#include <iostream>

#include "logic.h"

int main()
{
    logic::Source src1{"src1"};
    logic::Source src2{"src2", logic::Signal::off};
    logic::Source src3{"src3", logic::Signal::on};
    logic::Or or1{"or1"}, or2{"or2"};
    logic::And and1{"and1"};

    src1 >> and1;
    src2 >> and1;

    and1.calculate();

    std::cout << src1 << "\n";
    std::cout << src2 << "\n";
    std::cout << and1 << std::endl;
}