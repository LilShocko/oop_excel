#ifndef CELL_H
#define CELL_H
#include<cstring>
#include<iostream>
using namespace std;

class cell{
    public:
        virtual string getType() const = 0;
};

#endif // CELL_H
