#include<bits/stdc++.h>
using namespace std;

void dfs(int curr){
    if(vis[curr] == 1)return ;
    vis[curr] = 1 ;
    cout << curr << " " ;
    /*
    for(int i = 0 ; i < ar[curr].size();i++){
        int child = ar[curr][i] ;
        if(vis[child] == 0)dfs(child) ;
    } */
    for(int child: ar[curr]){
        if(vis[child] == 0)dfs(child) ;
    }
}

int main(){

}
