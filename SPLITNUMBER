#include <iostream>
#include <fstream>
using namespace std;
//DATA & VARIABLES
const char *finp = "SPLITNUMBER.inp";
const char *fout = "SPLITNUMBER.out";
const int nmax = 100;
int n;
int x[nmax+1];
int t[nmax+1];
//PROTOTYPE
void import();
void tachso(int i);
void outport(int i);
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> n;
    fi.close();
    ofstream fo(fout);
    fo.close();
}

void tachso(int i){
    for(int j=x[i-1]; j<=(n-t[i-1]); j++){ // x[i-1] <= x[i] <= n - t[i-1]
        x[i] = j;
        t[i] = t[i-1] + j;
        if(t[i] == n) // Nếu t[i] = n
            outport(i); // In ra từ x[1] đến x[i]
        else tachso(i+1);
    }
}

void outport(int i){
    ofstream fo(fout, ios::app);
    for(int j=1; j<=i-1; j++)
        fo << x[j] << "+";
    fo << x[i];
    fo << endl;
    fo.close();
}

int main()
{
    import();
    x[0] = 1; // Mảng x có n+1 phần tử
    t[0] = 0;
    tachso(1); // Mảng nghiệm tính từ i = 1
    return 0;
}
