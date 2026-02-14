/* Shared pointers is composed of

1. A normal pointer to some resource in memory

2. A reference counter

#include <memory>
using namespace std;

shared_ptr<type> identifier{new type{[initialization-list]}};

shared_ptr<type> = make_shared<type>();

*/ 

#include <iostream>
#include <memory>   // to use sharded pointer
using namespace std;

// Declaration
void fun1(shared_ptr<int> z);
void fun2(shared_ptr<int> &y);

int main(int argc, char **argv)
{
    auto x = make_shared<int>(2); // initialise to 2
    
    fun2(x);
    
    cout << x << endl;
    
    cout << *x << endl;
    
	return 0;
}

// Defination
void fun1(shared_ptr<int> z)  // shared pointer passed by value
{
    *z = 1;                   // now set to 1
}

void fun2(shared_ptr<int> &y) // shared pointer passed by reference
{
    fun1(y);
}