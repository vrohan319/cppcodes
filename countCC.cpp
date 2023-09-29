#include <bits/stdc++.h>
using namespace std;

int visited[10001] ;
vector<int> ar[10001] ;
void dfs(int node){
	if(visited[node] == 1)return ;
	visited[node] = 1 ;
	for(int child : ar[node])if(!visited[child])dfs(child) ;
}

int main() {
	int node,edge,a,b ;
	cin >> node >> edge;

	for(int i = 1; i <= edge ;i++){
		cin >> a >> b ;
		ar[a].push_back(b) ;
		ar[b].push_back(a) ;
	}

	int cc = 0 ;
	for(int i = 1 ; i <= node ;i++){
		if(!visited[i]){
			cc++ ;
			dfs(i) ;
		}
	}
	cout << cc << endl ;
}
