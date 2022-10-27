#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include <cell.h>


class doublecell : public cell{
    public:
        doublecell(double _value) : value(_value) {}
        double getValue() const{
            return value;
        }
        string getType() const{
            return "double";
        }
    private:
        double value;
};

#endif // DOUBLECELL_H
