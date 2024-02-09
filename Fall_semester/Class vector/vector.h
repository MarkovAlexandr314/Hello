#include <memory>
template <typename T, typename A = std::allocator<T>>
class Vector
{
    A alloc;   // работает с паямятью, выделяемой для элементов
    int sz;    // размер
    T *elem;   // указатель на элемнты (или 0)
    int space; // количество элементов плюс кол-во свободных слотов

public:
    Vector() : sz{0}, elem{nullptr}, space{0} {};
    explicit Vector(int sz_) : sz{sz_}, // vector v(x) // explisit запрещает неявные преобразования
                               elem{new T[sz_]}
    {
        for (int i{0}; i < sz; ++i) // Элемнты
            elem[i] = 0.0;          // инициализации
    }

    // Копирующие конструктор и присваивание
    Vector(const Vector<T> &);
    Vector<T> &operator=(const Vector<T> &);

    // Перемещающие конструктор и присваивание
    Vector(Vector<T> &&a);
    Vector<T> &operator=(Vector<T> &&);

    ~Vector() { delete[] elem; } // Деструктор

    T &at(int n); // Доступ с проверкой памяти
    const T &at(int n) const;

    T &operator[](int n); // Доступ без проверки памяти
    const T &operator[](int n) const;

    int Size() const { return sz; }
    int capacity() { return space; }

    void resize(int newsize, T val); // Увеличение
    void push_back(const T &d);
    void reserve(int newalloc);

    // Vector(std::initializer_list<T> lst) : sz(lst.size()), elem{new T[sz]}
    // { // vector v{...}
    //     std::copy(lst.begin(), lst.end(), elem);
    // }
};
