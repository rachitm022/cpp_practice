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