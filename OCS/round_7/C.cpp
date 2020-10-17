#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second

void solve(){
	int h,w;
	cin>>h>>w;
	char grid[h][w];
	int dp[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int temp = (i?dp[i-1][j]:0)+(j?dp[i][j-1]:0)-((i&&j)?dp[i-1][j-1]:0);
			if(grid[i][j]=='.'){
				dp[i][j] = temp+(i?grid[i-1][j]=='.':0)+(j?grid[i][j-1]=='.':0);
			}
			else dp[i][j] = temp;
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int a = dp[r2-1][c2-1];
		int b = (r1>1&&c1>1?dp[r1-2][c1-2]:0);
		int c = (r1>1?dp[r1-2][c2-1]:0);
		int d = (c1>1?dp[r2-1][c1-2]:0);
		int e = (r1>1?dp[r1-2][c1-1]:0);
		int f = (c1>1?dp[r1-1][c1-2]:0);
		int g = dp[r1-1][c2-1]-b+ (r1>2&&c1>1?dp[r1-3][c1-2]:0) -e;
		int h = dp[r2-1][c1-1]-b+ (r1>1&&c1>2?dp[r1-2][c1-3]:0) -f;
		printf("%d %d %d %d %d %d\n",a,b,c,d,e,f );
		cout<<a+b-c-d-e-f<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	T = 1;
	while(T--)
		solve();

	return 0;
}