#ifndef MATRIX_H
#define MATRIX_H
#include"cell.h"
#include"stringcell.h"
#include"doublecell.h"
#include"intcell.h"
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
class Matrix{
    public:
        Matrix(int _height, int _width);
        void print(int _height, int _width);

        stringcell* getcelladdress(int i, int j);
        string convertfromaddresstovalue(stringcell* gotcell);

        void edit(int x, int y, cell* content);


        bool checkifcellisint(stringcell* gotcell);
        bool checkifcellisdouble(stringcell* gotcell);

        intcell* convertcelltoint(stringcell* gotcell);
        doublecell* convertcelltodouble(stringcell* gotcell);

        void convert();


        int getheight(){return height;}
        int getwidth(){return width;}

        double getcellvalue(int x, int y);
        int getAddressx1(int x, int y, cell* content);
        int getAddressy1(int x, int y, cell* content);
        int getAddressx2(int x, int y, cell* content);
        int getAddressy2(int x, int y, cell* content);


        Matrix&operator=(Matrix& other);

        ~Matrix();

    protected:

    private:
        vector<vector<cell*> > matrix;
        int height;
        int width;
};

#endif // MATRIX_H
