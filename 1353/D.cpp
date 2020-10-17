#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second

struct comparePair { 
    bool operator()(pii& p1, pii& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        if(p1.f==p2.f) return p1.s>p2.s;
        else return p1.f < p2.f; 
    } 
}; 
 
void solve(){
	int n;
	cin>>n;
	priority_queue<pii,vector<pii>,comparePair> pq;
	int numZ = n;
	int a[n];
	pq.push({n,0});
	int cur = 1;
	while(numZ&&!pq.empty()){
		auto tp = pq.top();
		//printf("%d %d\n",tp.f,tp.s );
		pq.pop();
		int k = ((tp.f-1)/2);
		a[tp.s+k] = cur;
		cur++;
		numZ--;
		if(k>0) pq.push({k,tp.s});
		if(tp.f>k+1) pq.push({tp.f-k-1,tp.s+k+1});
	}
	for(int val:a){
		cout<<val<<" ";
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
		solve();

	return 0;
}