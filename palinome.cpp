#include <iostream>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
long long l= 0, r = 2000000000000000000, k;


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


class Polynome{
public:
    Polynome() {}
    
    Polynome(const Polynome &a){
        for(map <int, int>::const_iterator it = a.getData().begin(); it != a.getData().end(); it++){
            data[(*it).first] = (*it).second;
        }
    }
    
    Polynome(string &a){
        if(a[0] != '-') a = '+' + a + '-';
        string lastToken = "";
        bool lastSign;
        if (a[0] == '-') lastSign = 0;
        else lastSign = 1;
        for(int i = 1; i < a.length(); i++){
            if((a[i] != '+') && (a[i] != '-')){
                lastToken += a[i];
            } else {
                pair <int, int> res = parseToken(lastToken, lastSign);
                this->data[res.first] = res.second;
                if(a[i] == '+') lastSign = 1; else lastSign = 0;
                lastToken = "";
            }
        }
    }
    
    //    Palinome() {}
    const map<int, int>& getData() const{ return data;}
    
    Polynome(const vector <int> &a){
        for(int i = 0; i < a.size(); i++){
            if(a[i] != 0) this->data[i] = a[i];
        }
    }
    
    Polynome(const map <int, int> &a){
        for(map <int, int>::const_iterator it = a.begin(); it != a.end(); it++){
            this->data[(*it).first] = (*it).second;
        }
    }
    
    ~Polynome(){
        this->data.clear();
    }
    
    bool operator == (const Polynome &a) const {
        for( map <int, int>::const_iterator it = this->data.begin(); it != this->data.end(); it++){
            if((*it).second != (*a.getData().find((*it).second)).second) return 0;
        }
        if(this->data.size() != a.getData().size()) return 0;
        return 1;
    }
    
    bool operator != (const Polynome &a) const {
        return !(a == (*this));
    }
    
    Polynome operator + (const Polynome &a) const {
        map <int, int> res;
        for(map <int, int>::const_iterator it = this->data.begin(); it != this->data.end(); it++){
            res[(*it).first] = (*a.getData().find((*it).first)).second + (*it).second;
        }
        return Polynome(res);
    }
    
    Polynome operator - (const Polynome &a) const {
        map <int, int> res;
        for(map <int, int>::const_iterator it = this->data.begin(); it != this->data.end(); it++){
            res[(*it).first] = (*it).second - (*a.getData().find((*it).first)).second;
        }
        return Polynome(res);
    }
    
    bool operator > (const Polynome &a) const {
        set <int, std::greater<int>> s;
        for(map <int, int>::const_iterator it = this->data.begin(); it != this->data.end(); it++){
            s.insert((*it).first);
        }
        for(map <int, int>::const_iterator it = a.getData().begin(); it != a.getData().end(); it++){
            s.insert((*it).first);
        }
        for(set <int, std::greater <int>>::iterator it = s.begin(); it != s.end(); it++){
            int i1 = 0, i2 = 0;
            if (data.find(*it) != this->data.end())
                i1 = (*data.find(*it)).second;
            if ((a.getData().find(*it)) != (a.getData().end()))
                i2 = (*a.getData().find((*it))).second;
            if(i1 > i2) return true;
            if (i1 < i2) return false;
        }
        return false;
    }
    
    bool operator < (const Polynome &a) const {
        return !(*this > a) && (*this != a);
    }
    
    bool operator >= (const Polynome &a) const {
        return !(*this < a);
    }
    
    bool operator <= (const Polynome &a) const {
        return !(*this > a);
    }
    
    Polynome operator * (const Polynome &a) const {
        map <int, int> res;
        for(map<int, int>::const_iterator it1 = data.begin(); it1 != data.end(); it1++){
            for(map<int, int>::const_iterator it2 = a.getData().begin(); it2 != a.getData().end(); it2++){
                res[(*it1).first * (*it2).first] += (*it1).second * (*it2).second;
            }
        }
        return Polynome(res);
    }
    
    void print(){
        for(map<int, int>::iterator it = this->data.begin(); it != this->data.end(); it++){
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
        i = int(token.length()) - 1;
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


int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    string s1, s2;
    cin >> s1 >> s2;
    //    Polynome a(s);
    //    a.print();
    Polynome x(s1), y(s2);
    if(x > y)
        printf ("1");
    else printf("0");
    return 0;
}
