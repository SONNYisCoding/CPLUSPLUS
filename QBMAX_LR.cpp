#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
//DATA & VARIABLES
const char * finp = "QBMAX_LR.inp";
const char * fout = "QBMAX_LR.out";
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
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
    int16_t maxtem,i;
    for(int j=1;j<=m;j++){
        a[0][j] = 0;
        a[n+1][j] = 0;
    }
    for(int j=2;j<=m;j++){
        for(i=1;i<=n;i++){
            a[i][j] = Max3(a[i-1][j-1],a[i][j-1],a[i+1][j-1]) + a[i][j];
        }
    }
    s = a[1][m];
    for(i=1;i<=n;i++){
        if(s < a[i][m]) s = a[i][m];
        st[m] = i;
    }
    for(int j=m;j>=2;j--){
        i = st[j];
        maxtem = Max3(a[i-1][j-1],a[i][j-1],a[i+1][j-1]);
        if(maxtem == a[i-1][j-1]) st[j-1] = i-1;
        else if(maxtem == a[i][j-1]) st[j-1] = i;
        else st[j-1] = i+1;
    }
}

void outport(){
    QBMAX();
    ofstream fo(fout);
    fo << s << endl;
    for(int i = 1; i <= m; i++){
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
