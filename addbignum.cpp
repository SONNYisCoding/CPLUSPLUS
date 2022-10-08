#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//DATA & VARIABLES
const char *finp = "addbignum.inp";
const char *fout = "addbignum.out";
string n,s1,s2;
//PROTOTYPE
void import();
void add();
void outport();
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> s1 >> s2;
    fi.close();
}

void add(){
    int tem = 0;
    int carry = 0;
    string sttem;
    n = "";
    if(s1.length() < s2.length()){
        sttem = s1;
        s1 = s2;
        s2 = sttem;
    }
    for(int i=s1.length(); i>s2.length(); i--){
        s2 = '0' + s2;
    }
    for(int i=s1.length()-1; i>=0; i--){
        tem = static_cast<int>(s1[i] - 48) + static_cast<int>(s2[i] - 48) + carry;
        carry = tem/10;
        sttem = static_cast<char>(tem%10 + 48);
        n = sttem + n;
    }if(carry > 0) n = "1" + n;
}

void outport(){
    ofstream fo(fout);
    add();
    fo << n;
    fo.close();
}

int main()
{
    import();
    outport();
    return 0;
}
