#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
//DATA & VARIABLES
const char *finp = "QBLCS.inp";
const char *fout = "QBLCS.out";
string s1,s2,s;
int a[5000][5000];
//PROTOTYPE
void import();
void QBLCS();
void outport();
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> s1;
    fi >> s2;
    s1 = "0"+s1;
    s2 = "0"+s2;
    fi.close();
}

void QBLCS(){
    int n=s1.length();
    int m=s2.length();
    s = "";
    for(int i=1; i<=n; i++)
        a[i][0] = 0;
    for(int i=0; i<=m; i++)
        a[0][i] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            if(s1[i] == s2[j])
                a[i][j] = a[i-1][j-1]+1;
            else a[i][j] = max(a[i][j-1],a[i-1][j]);
        }
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(s1[i] == s2[j]){
            s = s1[i] + s;
            i--;
            j--;
        }
        else if(a[i][j] == a[i-1][j]) i--;
        else j--;
    }
}

void outport(){
    ofstream fo(fout);
    fo << s << endl;
    fo.close();
}

int main()
{
    import();
    QBLCS();
    outport();
    return 0;
}
