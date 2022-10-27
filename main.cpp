#include <iostream>
#include"cell.h"
#include"intcell.h"
#include"doublecell.h"
#include"stringcell.h"
#include"Matrix.h"
#include<vector>
#include<fstream>
#include <string>
#include <stdlib.h>
using namespace std;
int main(){
    string str;
    atoi( str.c_str() );

    Matrix m1(4,4);
    intcell p1(0);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            m1.edit(i,j,&p1);
        }
    }
    string kk="rr";
    intcell c1(4);
    doublecell c2(4.5);
    stringcell c3("=r0c0+r1c1");
    stringcell c4(kk);
    m1.edit(0,0,&c1);
    m1.edit(1,1,&c2);
    m1.edit(2,2,&c3);
    m1.edit(3,3,&c4);
    cout<<endl;
    //m1.print(4,4);
   cout<<endl;




    double thatnumber=m1.getcellvalue(m1.getAddressx1(2,2, &c3),m1.getAddressy1(2,2, &c3))
                    + m1.getcellvalue(m1.getAddressx2(2,2, &c3),m1.getAddressy2(2,2, &c3));
    doublecell c5(thatnumber);
    m1.edit(2,2,&c5);
    //m1.print(4,4);



/*
    string a;
    fstream mat;
    int maxrows=0;
    mat.open("123.txt");
    while(getline(mat,a)){
        cout<<a<<endl;
    }
    mat.close();
*/





    //Matrix m2(1,1);
    //m2.print(1,1);


       /*
    if(matrix[i][j]->getType() == "string"){
            string thatstring=((stringcell*)matrix[i][j])->getValue();
            if(thatstring[0]!='='){
                cout<<((stringcell*)matrix[i][j])->getValue();
            }
            else{
                if(thatstring[5]=='+'){
                    //that double matrix[x][y]=content;
                    doublecell thatcell(thatdoubleplus(i,j,matrix[i][j]));
                    //edita m1.edit(2,2,&thatcell);
                }
                if(thatstring[5]=='-'){
                    //that double
                    doublecell thatcell(thatdoubleminus(i,j,matrix[i][j]));
                    //edita m1.edit(2,2,&thatcell);
                }
                if(thatstring[5]=='*'){
                    //that double
                    doublecell thatcell(thatdoublemultiply(i,j,matrix[i][j]));
                    //edita m1.edit(2,2,&thatcell);
                }
                if(thatstring[5]=='/'){
                    //that double
                    doublecell thatcell(thatdoubledivide(i,j,matrix[i][j]));
                    //edita m1.edit(2,2,&thatcell);

                }


    m1.getcellvalue(m1.getAddressx1(x,y, &content),m1.getAddressy1(x,y, &content))
                    + m1.getcellvalue(m1.getAddressx2(x,y, &content),m1.getAddressy2(x,y, &content));


double Matrix::thatdoubleminus(int x, int y, cell* content){
    return matrix.getcellvalue(m1.getAddressx1(x,y, &content),m1.getAddressy1(x,y, &content))
                    - m1.getcellvalue(m1.getAddressx2(x,y, &content),m1.getAddressy2(x,y, &content));
}
double Matrix::thatdoublemultiply(int x, int y, cell* content){
    return matrix.getcellvalue(m1.getAddressx1(x,y, &content),m1.getAddressy1(x,y, &content))
                    * m1.getcellvalue(m1.getAddressx2(x,y, &content),m1.getAddressy2(x,y, &content));
}
double Matrix::thatdoubledivide(int x, int y, cell* content){
    return matrix.getcellvalue(m1.getAddressx1(x,y, &content),m1.getAddressy1(x,y, &content))
                    / m1.getcellvalue(m1.getAddressx2(x,y, &content),m1.getAddressy2(x,y, &content));
}
*/
    Matrix thematrix(10,10);
    stringcell z(" ");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            thematrix.edit(i,j,&z);
        }
    }
    string nameoffile;
    fstream thefile;
    int x=0;


    while(x!=7){
        cout<<"Press 1 to open table"<<endl;
        cout<<"Press 2 to close table"<<endl;
        cout<<"Press 3 to save table"<<endl;
        cout<<"Press 4 to save as table"<<endl;
        cout<<"Press 5 to edit a cell"<<endl;
        cout<<"Press 6 to print the matrix"<<endl;
        cout<<"Press 7 to exit table"<<endl<<endl<<endl;
        cin>>x;

        switch(x){
            case 1:{
            cout<<"File name with .txt: ";
            cin>>nameoffile;
            thefile.open (nameoffile.c_str());
            string str;
            int row=0;
            int column=0;
            while (getline(thefile, str)){
                column=0;
                string newstring;
                int j=-1;
                int sizee=str.length();
                for(int i=0; i<sizee; i++){
                    newstring.clear();
                    j=i;
                    while(str[i]!=',' && i<sizee){
                        i++;
                    }
                    newstring=str.substr(j,i-j);
                    //cout<<newstring;
                    //cout<<endl;


                    thematrix.edit(row,column,(new stringcell(newstring)));
                    //cout<<"Just eddited cell["<<row<<"]["<<column<<"]"<<endl;
                    column++;
                }
                row++;
                //cout<<thematrix.convertfromaddresstovalue(thematrix.getcelladdress(1,0));

            }
            break;
            }
            case 2:{


                stringcell m(" ");
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        thematrix.edit(i,j,&m);
                    }
                }
                thefile.close();
                cin.get();
                break;
            }

            case 3:{
                fopen(nameoffile.c_str(),"w");
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){

                        //thefile<<thematrix.convertfromaddresstovalue(thematrix.getcelladdress(0,0));
                        thefile<<"dfijkghndfijkghdfojghdf \n";
                    }
                    thefile<<endl;
                }


            break;
            }

            case 4:{
                string newfilename;
                cin>>newfilename;



            break;
                }

            case 5:{
                int editx,edity;
                cout<<"Input x: ";
                cin>>editx;
                cout<<"Input y: ";
                cin>>edity;
                string edittedstring;
                cin>>edittedstring;
                stringcell k1(edittedstring);
                thematrix.edit(editx,edity,&k1);

            break;
                }

            case 6:{
            thematrix.print(10,10);
            break;
            }
        }
    }









    return 0;
}

