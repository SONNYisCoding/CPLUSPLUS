#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <cstdint>
using namespace std;
//DATA & VARIABLES
const char *finp = "BFS.inp";
const char *fout = "BFS.out";
const uint16_t maxn = 101;
bool a[maxn][maxn];
bool visit[maxn];
int32_t trace[maxn];
uint16_t n,m,s;
int32_t t;
//PROTOTYPE
void import();
void outport();
void BFS(uint16_t n,uint16_t s);
void process(int32_t t);
//IMPLEMENTS
void import(){
    uint16_t u,v;
    ifstream fi(finp);
    memset(a,false,sizeof(a));
    memset(visit,true,sizeof(visit));
    fi >> n >> m >> s >> t;
    for(uint16_t i = 1; i <= m; i++){
        fi >> u >> v;
        a[u][v] = true;
    }
    fi.close();
}

void BFS(uint16_t n, uint16_t s){
    uint16_t u,v;
    queue <uint16_t> Queue;
    Queue.push(s);
    trace[s] = -1;
    visit[s] = false;
    while(!Queue.empty()){
        u = Queue.front();
        Queue.pop();
        for(v=1;v<=n;v++){
            if(a[u][v] && visit[v]){
                visit[v] = false;
                trace[v] = u;
                if(v==t) return;
                Queue.push(v);
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
    BFS(n,s);
    outport();
    return 0;
}
