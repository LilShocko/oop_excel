#include "Matrix.h"
#include "stringcell.h"
#include "doublecell.h"
#include "intcell.h"
#include<vector>
#include<iostream>
#include<fstream>
#include <sstream>
#include<cmath>
using namespace std;
Matrix::Matrix(int _height, int _width){
    vector<vector<cell*> > newmatrix(_height, vector<cell*>(_width));
    matrix=newmatrix;
}
//=r1c1+
void Matrix::print(int _height, int _width){
    for(int i = 0; i<_height; i++){
        for(int j = 0; j<_width; j++){
        if(matrix[i][j]->getType() == "string"){
                cout<<((stringcell*)matrix[i][j])->getValue();
        }
         if (matrix[i][j]->getType() == "int"){
            cout<<((intcell*)matrix[i][j])->getValue();
        }
        if (matrix[i][j]->getType() == "double"){
            cout<<((doublecell*)matrix[i][j])->getValue();
        }
            cout<<" ";
        }
        cout<<endl;
    }
}
stringcell* Matrix::getcelladdress(int i, int j){
        return (stringcell*)matrix[i][j];
}
string Matrix::convertfromaddresstovalue(stringcell* gotcell){
        return gotcell->getValue();

}
bool checkifcellisint(stringcell* gotcell){
    string b=gotcell->getValue();
    for(int i=0; i<b.length(); i++){
        if(b[i]<'0' || b[i]>'9') return false;
    }
    return true;
}
bool checkifcellisdouble(stringcell* gotcell){
    string b=gotcell->getValue();
    int checkfordot=0;
    for(int i=0; i<b.length(); i++){
        if(b[i]<'0' || b[i]>'9') return false;
        if(b[i]=='.')checkfordot++;
    }
    if(checkfordot!=1) return false;
    return true;
}
intcell* Matrix::convertcelltoint(stringcell* gotcell){
    int arr[100];
    string b=gotcell->getValue();
    for(int i=0; i<b.length(); i++){
        arr[i]=b[i]-'0';
    }
    int sum=0;
    for(int i=0; i<b.length(); i++){
        sum=sum+arr[i]*pow(10,b.length()-i);
    }
    intcell c1(sum);
    return &c1;

}
doublecell* Matrix::convertcelltodouble(stringcell* gotcell){
    int arr[100];
    int index=0;
    string b=gotcell->getValue();
    for(int i=0; i<b.length()&& b[i]!='.'; i++){
        arr[i]=b[i]-'0';
        index++;
    }
    for(int i=index+1; i<b.length(); i++){
        arr[i]=-(b[i]-'0');
    }
    double sum=0;
    for(int i=0; i<b.length() && b[i]!='.'; i++){
        sum=sum+arr[i]*pow(10,b.length()-i);
    }
    for(int i=index+1; i<b.length(); i++){
        sum=sum+(arr[i]*pow(10,b.length()-i-(b.length()-index)))*(-1);
    }
    doublecell c1(sum);
    return &c1;
    //12.345
}





int Matrix::getAddressx1( int x, int y, cell* content){
    int x1;
    string newstring = ((stringcell*)matrix[x][y])->getValue();
    x1=newstring[2]-'0';
    return x1;
}

int Matrix::getAddressy1(int x, int y, cell* content){
    int y1;
    string newstring = ((stringcell*)matrix[x][y])->getValue();
    y1=newstring[4]-'0';
    return y1;
}
int Matrix::getAddressx2(int x, int y, cell* content){
    int x2;
    string newstring = ((stringcell*)matrix[x][y])->getValue();
    x2=newstring[7]-'0';
    return x2;
}
int Matrix::getAddressy2(int x, int y, cell* content){
    int y2;
    string newstring = ((stringcell*)matrix[x][y])->getValue();
    y2=newstring[9]-'0';
    return y2;
}
void Matrix::edit(int x, int y, cell* content){
    matrix[x][y]=content;
}
double Matrix::getcellvalue(int x, int y){
        double test;
         if (matrix[x][y]->getType() == "int"){
            test=((intcell*)matrix[x][y])->getValue();
            return test;
        }
        if (matrix[x][y]->getType() == "double"){
            test=((doublecell*)matrix[x][y])->getValue();
            return test;
        }
        return 0;
}
Matrix& Matrix::operator=(Matrix& other){
    if(this==&other){
        height=other.height;
        width=other.width;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                matrix[i][j]=other.matrix[i][j];
            }
        }
    }
    return *this;

}






Matrix::~Matrix(){



}
