#include "vector.h"

struct out_of_range{};

template <typename T, typename A>
Vector<T> &Vector<T, A>::operator=(const Vector<T> &a)
{
    if (this == &a)
        return *this; // самоприсваивание, ничего делать не нужно

    if (a.sz <= space)
    {
        for (int i{0}; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    T *p = new T[a.sz];
    for (int i{0}; i < a.sz; ++i)
        p[i] = a[i];
    delete[] elem;
    sz = a.sz;
    elem = p;
    space = sz;
    return *this;
}

template <typename T, typename A>
void Vector<T, A>::push_back(const T &val)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(sz * 2);
    alloc.construct(&elem[sz], val);
    ++sz;
}

template <typename T, typename A>
void Vector<T, A>::resize(int newsize, T val = T())
{ // можем менять размер вектора
    reserve(newsize);
    for (int i{sz}; i < newsize; ++i)
        alloc.construct(&elem[i], val);
    for (int i{newsize}; i < sz; ++i)
        alloc.destroy(&elem[i]);
    sz = newsize;
}

template <typename T, typename A>
void Vector<T, A>::reserve(int newalloc)
{ // добавляем память для новых элементов
    if (newalloc <= space)
        return;
    T *p = alloc.allocate(newalloc);
    for (int i{0}; i < sz; ++i)
    {
        alloc.constructor(&p[i], elem[i]);
    }
    for (int i{0}; i < sz; ++i)
    {
        alloc.destroy(&elem[i]);
    }
    alloc.dellocate(elem, space);
    elem = p;
    space = newalloc;
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector<T> &&a) : sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

// template <typename T, typename A>
// Vector<T, A> &Vector<T, A>::operator=(Vector<T, A> &&a)
// {
//     delete[] elem;
//     elem = a.elem;
//     sz = a.sz;
//     a.elem = nullptr;
//     a.sz = 0;
//     return *this;
// }

template <typename T, typename A>
Vector<T, A>::Vector(const Vector<T> &arg) : sz{arg.sz}, elem{new T[arg.sz]}
{ // copy constructor
    copy(arg.elem, arg.elem + sz, elem);
}

template <typename T, typename A>
T& Vector<T, A>::at(int n){
    if (n<0 || sz<=n ) throw out_of_range();
    return elem[n];
}

template <typename T, typename A>
T& Vector<T, A>::operator[](int n){
    return elem[n];
}
