#include<iostream>
using namespace std;

class Counter
{
public:
    Counter();  // default constructor
    void look() const;
    void click();
    void reset();
private:
    int count;
};


int main()
{
    Counter x{};
    x.look();
    x.click();
    x.click();
    x.look();
    x.reset();
    x.look();
}


Counter::Counter()
{
    this->count = 0;
}

void Counter::look() const
{
    cout << "COUNT: " << this->count << endl;
}

void Counter::click()
{
    this->count++;
}

void Counter::reset()
{
    this->count = 0;
}

