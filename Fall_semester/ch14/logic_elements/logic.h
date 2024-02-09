#ifndef LOGIC_H
#define LOGIC_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>
namespace logic
{
    class Element;
    class Operation;

    using Output = std::reference_wrapper<const Element>;

    class Connection;

    enum class State
    {
        inverted = 0,
        direct
    };

    class Element
    {
    public:
        Element(const std::string &name, State out_state = State::direct);

        bool output() const;
        const std::vector<Output> outputs() const;

        const std::string &name() const { return elem_name; }

        State output_state() const { return out_st; };

        Operation &operator>>(Operation &rsh);
        Operation &operator>>(Connection rsh);

    protected:
        bool out{false}; // output signal
        virtual void calc() = 0;

    private:
        std::string elem_name;
        std::vector<Output> elem_outs;
        State out_st; // output signal state
    };

    std::ostream& operator<<(std::ostream &os, const Element &rhs);

    enum class Signal
    {
        off = 0,
        on
    };

    class Source : public Element
    {
    public:
        Source(const std::string &name, Signal out = Signal::on,
               State out_state = State::direct);
        void set_output(Signal sig) { out = (sig == Signal::on); }

    protected:
        void calc() override{/*All done*/};
    };

    class Input
    {
    public:
        Input(Element &el, State st = State::direct);

        bool output() const;

        Element &element() { return elem; }

    private:
        std::reference_wrapper<Element> elem;
        State in_st;
    };

    struct Connection
    {
        std::reference_wrapper<Element> elem;
        State in_st;
    };

    class Operation : public Element
    {
    public:
        using Element::Element;
        const std::vector<Input> &inputs() const { return elem_ins; }

        Connection operator~() { return {*this, State::inverted}; }

        void attach(Element &elem);
        void calculate();

    private:
        std::vector<Input> elem_ins;
    };

    class And : public Operation
    {
    public:
        using Operation::Operation;

    protected:
        void calc() override;
    };

    class Or : public Operation
    {
    public:
        using Operation::Operation;

    protected:
        void calc() override;
    };

} // namespace logic
#endif
