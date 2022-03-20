#include <bits/stdc++.h>
using namespace std;
//1 4 3 5
//MACROS
typedef pair<int,int> p;
typedef pair<int,p> pp;
typedef vector<p> v;
typedef map<int,v> m;
#define reco(i,a,b) for(i=a;i!=b;i++)
#define mos(a) cout <<a<<" ";
//VARIABLES
int nodes,edges,a,b,w;
m graph;    //< begin_node , <end_node,cost> >
set<p> path; //<cost,node>
vector<p> cost; //<cost,_previous_node>

void read(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    while (edges--)
    {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b,w));
    }
}

void dijkstra(int node){
    path.insert(make_pair(0,node));
    cost[node]=make_pair(0,-1);

    while(!path.empty()){
        p x = *path.begin();
        path.erase(*path.begin());

        int c1 = x.first;
        int n1 = x.second;
        int i;
        //mos(c1);mos(n1);mos("\n");
        reco(i,0,graph[n1].size()){
            p y = graph[n1][i];
            int n2 = y.first;
            int c2 = y.second;
            if(cost[n2].first > cost[n1].second+c2){
                cost[n2].first = cost[n1].second + c2;
                cost[n2].second = n1;
                path.insert(make_pair(cost[n2].first,c2));
            }
        }
    }
}

void way(int node){
    if(cost[node].second!=-1 || node==1){
        stack<int> s;
        s.push(node);
        while(cost[node].second!=-1){
            s.push(cost[node].second);
            node = cost[node].second;
        }
        int tam=s.size();
        for (int i = 0; i < tam-1; i++)
        {
            cout <<s.top()<<" ";
            s.pop();
        }
        cout << s.top()<<"\n";
    }else{
        cout<<"-1\n";
    }
}

int main(){
    read();
    int i;
    cost.clear();
    reco(i,0,nodes+1)
        cost.push_back(make_pair(1<<20,-1));
    dijkstra(1);
    way(nodes);
    return 0;
}