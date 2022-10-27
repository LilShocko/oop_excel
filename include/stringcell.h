#ifndef STRINGCELL_H
#define STRINGCELL_H

#include <cell.h>
#include<cstring>
#include<iostream>
using namespace std;

class stringcell : public cell{
public:
    stringcell(string _value): value(_value) {}
    string getValue() const{
        return value;
    }

    string getType() const{
        return "string";
    }


private:
    string value;

};

#endif // STRINGCELL_H
