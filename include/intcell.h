#ifndef INTCELL_H
#define INTCELL_H

#include <cell.h>


class intcell : public cell{
    public:
        intcell(int _value) : value(_value) {}
        int getValue() const{
            return this->value;
        }
        string getType() const{
            return "int";
        }
    private:
        int value;
};

#endif // INTCELL_H
