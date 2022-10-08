#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <cstdint>
using namespace std;
//DATA & VARIABLES
const char *finp = "DFS.inp";
const char *fout = "DFS.out";
const uint16_t maxn = 101;
bool a[maxn][maxn];
bool visit[maxn];
int32_t trace[maxn];
uint16_t n,m,s;
int32_t t;
//PROTOTYPE
void import();
void outport();
void DFS(uint16_t n,uint16_t s);
void process(int32_t t);
//IMPLEMENTS
void import(){
    uint16_t u,v;
    ifstream fi(finp);
    memset(a,false,sizeof(a));
    memset(visit,true,sizeof(visit));
    fi >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        fi >> u >> v;
        a[u][v] = true;
    }
    fi.close();
}

void DFS(uint16_t n, uint16_t s){
    uint16_t u,v;
    stack <uint16_t> Stack;
    Stack.push(s);
    trace[s] = -1;
    visit[s] = false;
    while(!Stack.empty()){
        u = Stack.top();
        Stack.pop();
        for(v=1;v<=n;v++){
            if(a[u][v] && visit[v]){
                visit[v] = false;
                trace[v] = u;
                if(v == t) return;
                Stack.push(u);
                Stack.push(v);
                break;
            }
        }
    }
}

void process(int32_t t){
    ofstream fo(fout);
    if(trace[t] == -1) fo << t;
    else{
        fo << t;
        while(trace[t] != -1){
            t=trace[t];
            fo << "<<<" << t;
        }
    }
    fo.close();
}

void outport(){
    ofstream fo(fout);
    if(visit[t] == true) fo << "Ko co duong di";
    else process(t);
    fo.close();
}

int main()
{
    import();
    DFS(n,s);
    outport();
    return 0;
}
