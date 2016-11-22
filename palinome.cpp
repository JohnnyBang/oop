#include <iostream>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <map>
using namespace std;

//struct StructName{
//    int v;
//};

class ClassName{
public:
    ClassName();
    
    ClassName(ClassName &a){
        v = a.v;
        c = a.getC();
    }
    
    ClassName(int _v, int _c) : v(_v), c(_c) {};
    
    bool operator> (const ClassName &a) const{
//        c = 5;
        return c > a.getC();
        
    }
    
    int v;
    int *a = new int(5);
    int getC() const {return c;};
    void setC(int newC) {c = newC;};
    ~ClassName(){
        v = 0;
        c = 0;
        delete a;
    }
    //....
private:
    int c;
    //....
//protected:
    //...
};


class Palinome{
public:
    Palinome();
    
    Palinome(string &a){
        
    }
private:
    map <int, int> a;
};



ClassName::ClassName(){
    
}

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    ClassName a(3, 4);
    ClassName b(a);
    cout << a.getC() << " "<< b.getC() << endl;
    cout << (a > b ? 1 : 0);
    
}
