#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back

void solve(){
	int n;
	cin>>n;
	vi adj[n+1];
	vector<pii> edges;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		edges.emplace_back(u,v);
	}
	//vector<bool> visited(n+1,false);
	int ans = 0;
	function<void(int,int,int,int,int&,int&)> dfs;
	dfs = [&](int node,int p,int cur,int forbid,int& temp,int &far){
		if(cur>=temp){
			temp = cur;
			far = node;
		}

		for(auto i:adj[node]){
			if(i==p||i==forbid) continue;
			
			dfs(i,node,cur+1,forbid,temp,far);
			// cout<<node<<" "<<temp<<" "<<orig<<endl;
		}

		return;
	};

	for(int i=0;i<n-1;i++){
		int a1=0,a2=0,b1=0,b2=0;
		int tmp = 0,tmp2=0;
		dfs(edges[i].f,edges[i].s,0,-1,a1,a2);
		dfs(a2,-1,0,edges[i].s,tmp,tmp2);
		a1 = tmp,tmp = 0,tmp2=0;
		dfs(edges[i].s,edges[i].f,0,-1,b1,b2);
		dfs(b2,-1,0,edges[i].f,tmp,tmp2);
		b1 = tmp;
		// printf("%d %d %d %d\n",a1,b1);
		ans = max(ans,(a1)*(b1));
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T=1;
	// cin>>T;
	while(T--)
		solve();

	return 0;
}