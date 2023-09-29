#include <bits/stdc++.h>
using namespace std ;

int main(){
    int edges,nodes ;
    cin >> edges , nodes ;
    vector<int> ar[nodes+1] ;

    while(edges--){
        int a,b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
}
