#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Calculator{
    protected:
    int a,b;

    void getdata(){
        cout<<"Input value of a and b"<<endl;
        cin>>a>>b;
    }

    void add(){
        int res = a + b;
        cout<<"The Add result is "<<res<<endl;
    }

    public:
    void run(){
        getdata();
        add();
    }
};

class Derived: public Calculator{
    public:
    void multiply(){

        int res = a * b;

        cout<<"The multiplication result is "<<res<<endl;


    }
};


int main(){
    Calculator cal;
    cal.run();
    Derived cal2;
    cal2.run();
    cal2.multiply();

    return 0;
}