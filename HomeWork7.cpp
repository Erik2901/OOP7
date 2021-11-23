#include <iostream>
#include <string>
#include <vector>

template<class T>
class A_ptr {
    T* m_ptr;
public:
    A_ptr(T* ptr=nullptr) : m_ptr(ptr) {}
    ~A_ptr() { delete m_ptr; }

    A_ptr& operator=(A_ptr& a)
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }

};

template<class T>
std::ostream& operator<<(std::ostream& os, const A_ptr<T>& tDate) {
    os << tDate->getDay() << "." << tDate->getMonth() << "." << tDate->getYear() << std::endl;
    return os;
}

class Date {
    int day=1;
    int month=11;
    int year=2020;
public:
    friend std::ostream& operator<<(std::ostream& os, const Date& aDate);
    Date() {};
    Date(int d, int m, int y) : day{ d }, month{ m }, year{ y }{ };
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    void setDate(int d, int m, int y) { day = d; month = m; year = y; }
};

std::ostream& operator<<(std::ostream& os, const Date& aDate) {
    os << aDate.getDay() << "." << aDate.getMonth() << "." << aDate.getYear() << std::endl;
    return os;
}

bool compare(A_ptr<Date>& a, A_ptr<Date>& b) {
    if (a->getYear() > b->getYear())
    {
        return a->getYear() > b->getYear();
    }
    else if (a->getYear() < b->getYear())
    {
        return a->getYear() > b->getYear();
    }
    if (a->getMonth() > b->getMonth())
    {
        return a->getMonth() > b->getMonth();
    }
    else if (a->getMonth() < b->getMonth())
    {
        return a->getMonth() > b->getMonth();
    }
    if (a->getDay() > b->getDay())
    {
        return a->getDay() > b->getDay();
    }
    else if (a->getDay() < b->getDay())
    {
        return a->getDay() > b->getDay();
    }
}

void change(A_ptr<Date>& a, A_ptr<Date>& b) {
    A_ptr<Date> c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    A_ptr<Date> today(new Date);
    A_ptr<Date> date;
    today->setDate(23, 11, 2020);
    std::cout << today;
    std::cout << "Today: " << (today.isNull() ? "is null" : "is not null") << std::endl;
    std::cout << "Date: " << (date.isNull() ? "is null" : "is not null") << std::endl;
    date = today;
    std::cout << "Today: " << (today.isNull() ? "is null" : "is not null") << std::endl;
    std::cout << "Date: " << (date.isNull() ? "is null" : "is not null") << std::endl;


    A_ptr<Date> date1(new Date);
    A_ptr<Date> date2(new Date);
    date1->setDate(25,11,2012);
    date2->setDate(28,12,2012);

    std::cout << (compare(date1, date2) ? date1 : date2);
    std::cout << date1;
    std::cout << date2;
    change(date1, date2);
    std::cout << date1;
    std::cout << date2;

    system("pause");
    return 0;
}