#include "logic.h"

namespace logic
{

    Element::Element(const std::string &name, State out_state)
        : elem_name{name}, out_st{out_state}
    {
    }

    bool Element::output() const
    {
        return (out_st == State::direct) ? out : !out;
    }

    std::ostream &operator<<(std::ostream &os, const Element &rhs)
    {
        os << rhs.name() << ": " << rhs.output();
        return os;
    }

    Source::Source(const std::string &name, Signal out, State out_state)
        : Element{name, out_state}
    {
        set_output(out);
    }

    Input::Input(Element &el, State st) : elem{el}, in_st{st}
    {
        /*all done*/
    }

    bool Input::output() const
    {
        bool out = elem.get().output();
        return (in_st == State::direct) ? out : !out;
    }

    void Operation::calculate()
    {
        for (auto &item : elem_ins)
        {
            try
            {
                dynamic_cast<Operation &>(item.element()).calculate();
            }
            catch (std::bad_cast &)
            {
                /* ok, it`s not an operation */
            }
        }
    }

    void And::calc()
    {
        out = true;
        for (auto &item : inputs())
        {
            if (!item.output())
            {
                out = false;
                break;
            }
        }
    }

    void Or::calc()
    {
        out = false;
        for (auto &item : inputs())
        {
            if (item.output())
            {
                out = true;
                break;
            }
        }
    }
}

;