
#include <bits/stdc++.h>
using namespace std ;

vector<int> primes ;
vector<int> graph[10000] ;
int dis[10000] ;

bool isPrime(int n){
    for(int i = 2 ; i*i <= n ;i++ ){
        if(n%i == 0)return false ;
    }
    return true ;
}

void makePrime(){
    for(int i = 1000 ; i <= 9999 ; i++){
        if(isPrime(i))primes.push_back(i) ;
    }
}

bool isValid(int a,int b){
    int cnt = 0 ;
    while(a){
        if(a%10 != b%10)cnt++ ;
        a/=10 ;
        b/=10 ;
    }
    if(cnt == 1)return true ;
    return false ;
}

void buildGraph(){
    for(int i = 0; i < primes.size();i++){
        for(int j = i+1; j < primes.size() ; j++){
            int a = primes[i] ;
            int b = primes[j] ;
            if(isValid(a,b)){
                graph[a].push_back(b) ;
                graph[b].push_back(a) ;
            }
        }
    }
}

void bfs(int node){
    queue<int> q ;
    q.push(node) ;
    dis[node] = 0 ;
    while(!q.empty()){
        int cur = q.front() ;
        q.pop() ;
        for(auto child: graph[cur]){
            if(dis[child] == -1){
                dis[child] = dis[cur]+1 ;
                q.push(child) ;
            }
        }
    }
}

int main(){
    makePrime() ;
    buildGraph() ;

    int t ;
    cin >> t ;

    while(t--){
        int a, b ;
        cin >> a >> b ;
        memset(dis,-1,sizeof(dis)) ;
        bfs(a) ;
        if(dis[b] == -1)cout << "imposible" << endl ;
        else cout << dis[b] << endl ;
    }
    return 0 ;
}
