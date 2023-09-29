#include <bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int visited[100001] ;
int dis[100001];

void dfs(int node,int distant){

    if(visited[node] == 1)return ;

    visited[node] = 1 ;
    dis[node] = distant ;
    for(int child:ar[node])if(!visited[child])dfs(child,distant+1) ;

}

int main(){
    
    int n;
    cin >> n;

    for(int i = 1; i < n;i++){
        int a,b ;
        cin >> a >> b ;
        ar[a].push_back(b) ;
        ar[b].push_back(a) ;
    }

    dfs(1,0) ;
    int ans = 1 ;
    dis[1] = INT_MAX ;
    for(int i = 2; i <= n;i++){
        if(dis[i] < dis[ans])ans = i;
    }

    cout << ans << endl;

    return 0 ;
}