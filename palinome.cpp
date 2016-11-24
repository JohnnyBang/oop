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
    Palinome() {}
    
    Palinome(string &a){
        if(a[0] != '-') a = '+' + a + '-';
        string lastToken = "";
        bool lastSign;
        if (a[0] == '-') lastSign = 0;
        else lastSign = 1;
        int cnt = 0;
        for(int i = 1; i < a.length(); i++){
            if((a[i] != '+') && (a[i] != '-')){
                lastToken += a[i];
            } else {
                pair <int, int> res = parseToken(lastToken, lastSign);
                data[res.first] = res.second;
                if(a[i] == '+') lastSign = 1; else lastSign = 0;
                lastToken = "";
            }
        }
    }
    
//    Palinome() {}
    
    bool operator + (const string)
    
    void print(){
        for(map<int, int>::iterator it = data.begin(); it != data.end(); it++){
            cout << (*it).first << " " << (*it).second << endl;
        }
    }
private:
    map <int, int> data;
    pair <int, int> parseToken(const string &token, const bool signToken){
        pair <int, int> res;
        int i = 0;
        while(token[i] != 'x'){
            res.second = res.second * 10 + int(token[i] - '0');
            i++;
        }
        i = token.length() - 1;
        int  p= 1;
        while(token[i] != '^'){
            if(token[i] == '-'){
                res.first = -res.first;
                break;
            } else {
                res.first = res.first + p * int(token[i] - '0');
                i--;
                p *= 10;
            }
        }
        if(signToken == 0) res.second = -res.second;
        return res;
    }
    
};



ClassName::ClassName(){
    
}

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    string s;
    cin >> s;
    Palinome a(s);
    a.print();
    return 0;
}
