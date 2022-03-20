#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
typedef pair<int,int> par;
vector<vector<par>> graph;
int n,m;

void leer(){
    int i,j,ini,cost,fin;
    cin >> n >> m;
    graph.resize(n+1);
    for(int i = 1 ; i <= m ; i++){
        cin  >> ini >> fin >> cost;
        graph[ini].push_back({cost,fin});
        graph[fin].push_back({cost,ini});
    }
}

void mostrar(){
    for(int i = 1 ; i <= n ; i++){
        printf("%d:",i);
        for(int j = 0; j < graph[i].size() ;j++){
            printf(" {%d,%d}",graph[i][j].first,graph[i][j].second);
        }
        printf("\n");
    }
}

void dijkstra(int node){
    int cost [n+1];memset(cost,-1,sizeof(cost));
    bool visit[n+1]={};
    set<par>s;
    cost[1]=0;
    s.insert({0,1});
    while(s.size()){
        par actual  = *s.begin();
        s.erase(actual);

        if(visit[actual.second]) continue;
        visit[actual.second]=1;

        for(int i = 0 ; i < graph[actual.second].size() ; i++){
            par p = graph[actual.second][i];
            if(!visit[p.second]){
                int nuevo = cost[actual.second]+p.first;
                int old = cost[p.second];
                if(nuevo < old || old==-1){
                    cost[p.second]=nuevo;
                    s.insert({nuevo,p.second});
                }
            }
        }
    }
    printf("cost each node, from node 1: \n");
    for(int i = 1 ; i <= n ; i++) printf("node: %d cost: %d visit:%d\n",i,cost[i],visit[i]);
}

int main(){
    FILES
    leer();
    mostrar();
    dijkstra(1);
    return 0;
}