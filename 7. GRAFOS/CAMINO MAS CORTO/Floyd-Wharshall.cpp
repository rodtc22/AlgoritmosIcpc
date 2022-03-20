#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);


void floyd(){
    for(int i= 1 ; i <= n ; i++)
        dist[i][i]=0;
    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]) ;

    for(int i= 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            printf("%d %d : %d\n",i,j,dist[i][j]);
}

int main(){
    FILES
    floyd();
    return 0;
}