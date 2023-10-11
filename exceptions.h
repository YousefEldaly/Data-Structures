#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>
using namespace std;

class outOfRange : public runtime_error{
public:
    outOfRange()
        :runtime_error{"Attempted to access OUT OF RANGE element"}{}
};

class noPop : public runtime_error{
public:
    noPop()
        :runtime_error{"CAN'T pop, there are no elements in the Vector"}{}
};



#endif // EXCEPTIONS_H_INCLUDED
