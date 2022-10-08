#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//DATA & VARIABLES
const char *finp = "mulbignum.inp";
const char *fout = "mulbignum.out";
string n,st1,st2;
//PROTOTYPE
void import();
void mul();
void outport();
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> st1 >> st2;
    fi.close();
}

void mul(){
    int c[10000];
    int a,b,n1,n2;
    string sign,s1,s2;
    sign = "";
    if(((st1[0] == '-') || (st2[0] == '-')) && (st1[0] != st2[0]))sign = '-';
    n = "";
    s1 = "";
    s2 = "";
    n1 = st1.length();
    n2 = st2.length();
    if(st1[0]=='-') s1 = st1.substr(2,n1-1);
    else s1 = st1;
    if(st2[0]=='-') s2 = st2.substr(2,n2-1);
    else s2 = st2;
    n1 = s1.length();
    n2 = s2.length();
    for(int j=n2-1; j>=0; j--){
        for(int i=n1-1; i>=0; i--){
            a = static_cast<int>(s1[i])-48;
            b = static_cast<int>(s2[j])-48;
            c[i+j] = c[i+j] + a*b;
            c[i+j-1] = c[i+j-1] + c[i+j]/10;
            c[i+j] = c[i+j]%10;
        }
    }
    for(int i=n1+n2-2; i>=1; i--){
        n = static_cast<char>(c[i]+48)+n;
    }
    if(c[0] != 0) n = static_cast<char>(c[0]+48)+n;
    n = sign + n;
}

void outport(){
    ofstream fo(fout);
    mul();
    fo << n;
    fo.close();
}

int main()
{
    import();
    outport();
    return 0;
}
