#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int>(m,0));
	vi freq(n*m + 1, 0);
	f(i,0,n)
		f(j,0,m)
			cin >> v[i][j],freq[v[i][j]] = 1;

	vi dx = {1,0,-1,0};
	vi dy = {0,1,0,-1};
	auto fu = [&](int x, int y) -> bool{
		int va = v[x][y];
		f(i,0,4) if(x+dx[i] >=0 and x+dx[i] < n and y+dy[i] >=0 and y+dy[i] < m ){
			if(va == v[x+dx[i]][y+dy[i]] ) return 1;
		}
		return 0;
	};
	f(i,0,n){
		f(j,0,m){
			if(fu(i,j))freq[v[i][j]] = 2;
		}
	}
	int un,dos;
	un = dos = 0;
	int c = 0;
	f(i,0,n*m+1){
		if(freq[i] > 0)c++;
		if(freq[i]==0)continue;
		if(freq[i]==1)un++;
		else dos++;
	}
	if(c==1){
		cout << 0 << ln;
		return;
	}
	if(dos == 0){
		cout << un - 1<< ln;
		return;
	}
	cout << min(un-1 + 2*dos,un + 2*(dos-1)) << ln;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
