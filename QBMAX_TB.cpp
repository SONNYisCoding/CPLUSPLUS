#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
//DATA & VARIABLES
const char * finp = "QBMAX_TB.inp";
const char * fout = "QBMAX_TB.out";
const int8_t maxn = 101;
int16_t a[maxn][maxn];
uint16_t st[maxn];
int16_t n,m,s;
//PROTOTYPE
void import();
void outport();
int16_t Max3(int16_t a, int16_t b, int16_t c);
void QBMAX();
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi >> a[i][j];
        }
    }
    fi.close();
}

int16_t Max3(int16_t a, int16_t b, int16_t c){
    if(a > b && a > c) return a;
    else if(b > a && b > c) return b;
    else return c;
}

void QBMAX(){
    int16_t maxtem,j;
    for(int i=1;j<=m;j++){
        a[i][0] = 0;
        a[i][m+1] = 0;
    }
    for(int i=2;i<=n;i++){
        for(j=1;j<=m;j++){
            a[i][j] = Max3(a[i-1][j-1],a[i-1][j],a[i-1][j+1]) + a[i][j];
        }
    }
    s = a[n][1];
    for(j=1;j<=m;j++){
        if(s < a[n][j]){
            s = a[n][j];
            st[n] = j;
        }
    }
    for(int i=n;i>=2;i--){
        j = st[i];
        maxtem = Max3(a[i-1][j-1],a[i-1][j],a[i-1][j+1]);
        if(maxtem == a[i-1][j-1]) st[i-1] = j-1;
        else if(maxtem == a[i-1][j]) st[i-1] = j;
        else if(maxtem == a[i-1][j+1])st[i-1] = j+1;
    }
}

void outport(){
    QBMAX();
    ofstream fo(fout);
    fo << s << endl;
    for(int i=1; i<=n; i++){
        fo << st[i] << endl;
    }
    fo.close();
}

int main()
{
    import();
    outport();
    return 0;
}
