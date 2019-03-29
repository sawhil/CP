#include <bits/stdc++.h>
int vis[10000];
using namespace std;
int bfs(vector<int> adjl[],int vertex,int dest){
	queue<int> q;
	vis[vertex] = 1;
	q.push(vertex);
	while(!q.empty()){
		int k = q.front();
		if(k == dest) return 1;
		q.pop();
		for(int i = 0;i<adjl[k].size();i++){
			if(!vis[adjl[k][i]]){
				vis[adjl[k][i]] = 1;
				q.push(adjl[k][i]);
			}
		}
	}
	return 0;
}
int main() {
	long long int n,s;
	cin>>n>>s;
	vector<int> graph[n+1];
	int a[n+1],b[n+1];
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++) cin>>b[i];
	if(a[1]){
	    for(int i = 1;i<n;i++){
			if(a[i] == 1){
				for(int j = i+1;j<=n;j++){
					if(a[j] == 1) graph[i].push_back(j);
				}
			}
		}
		for(int i = n;i>1;i--){
			if(b[i] == 1){
				for(int j = i-1;j>=1;j--){
					if(b[j] == 1) graph[i].push_back(j);
				}
			}
		}
		int ans = bfs(graph,1,s);
		if(ans == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else cout<<"NO"<<endl;
	return 0;
}
//https://codeforces.com/contest/1055/problem/A
