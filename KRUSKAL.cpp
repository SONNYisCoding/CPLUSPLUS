#include <iostream>
#include <fstream>
using namespace std;
//DATA & VARIABLES
const char *finp = "KRUSKAL.inp";
const char *fout = "KRUSKAL.out";
const int maxV = 100;
const int maxE = maxV-1;
struct EDGE{int u,v,w;};
EDGE edge[maxE];
EDGE res[maxV];
int numedge;
int label[maxV];
int n,m;
bool found;
//PROTOTYPE
void import();
void init();
int getroot(int v);
void Union(int r1, int r2);
void heapify(EDGE arr[], int n, int i);
void kruskal();
void outport();
//IMPLEMENTS
void import(){
    ifstream fi(finp);
    fi >> n >> m;
    for(int i=1; i<=m; i++)
        fi >> edge[i].u >> edge[i].v >> edge[i].w;
    fi.close();
}

void init(){
    for(int i=0; i<=n; i++) label[i] = -1;
}

int getroot(int v){
    int i=v;
    while(label[i] >= 0) i = label[i];
    return i;
}

void Union(int r1, int r2){
    int x = label[r1] + label[r2];
    if(label[r1] > label[r2]){
        label[r2] = x;
        label[r1] = r2;
    }
    else{
        label[r1] = x;
        label[r2] = r1;
    }
}

void heapify(EDGE arr[], int n, int i){
    int root = i;
	int _left = 2*i ;
	int _right = _left + 1;
	if (_left <= n && arr[_left].w < arr[root].w)
		root = _left;
	if (_right <= n && arr[_right].w < arr[root].w)
		root = _right;
	if (root != i){
		swap(arr[i], arr[root]);
		heapify(arr, n, root);
	}
}

void kruskal(){
    int root1, root2;
    numedge = 1;
    found = false;
    for(int i=m/2; i>=1; i--)
        heapify(edge,m,i);
    for(int i=m; i>=1; i--){
        swap(edge[1],edge[i]);
        root1 = getroot(edge[i].u);
        root2 = getroot(edge[i].v);
        if(root1 != root2){
            Union(root1,root2);
            res[numedge] = edge[i];
            if(numedge == n-1){
                found = true;
                break;
            }
            numedge++;
        }
        heapify(edge,i-1,1);
    }
}

void outport(){
    ofstream fo(fout);
    if(found == false)
        fo << "Graph is not found" << endl;
    else{
        int weight=0;
        for(int i=1; i<=numedge; i++){
            fo << res[i].u << " " << res[i].v << " " << res[i].w << " " << endl;
            weight = weight + res[i].w;
        }
        fo << weight << endl;
    }
    fo.close();
}

int main()
{
    import();
    init();
    kruskal();
    outport();
    return 0;
}
