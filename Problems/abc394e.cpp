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
	int n;
	cin >> n;
	int mem[n+1][n+1];
	int inf = 1e9;
	f(i,0,n)f(j,0,n) mem[i][j] = inf;

	vector<string> v(n);
	f(i,0,n)cin >> v[i];
	queue<ii> qu;
	f(i,0,n){
		qu.push({i,i});
		mem[i][i] = 0;
	}

	f(i,0,n)f(j,0,n)if(i != j and v[i][j] != '-'){
		qu.push({i,j});
		mem[i][j] = 1;
	}
	while(!qu.empty()){
		auto [i,j] = qu.front();qu.pop();
		f(k,0,n)f(l,0,n){
			if(v[k][i] == v[j][l] and mem[k][l] == inf and v[k][i] != '-' and v[j][l] != '-'){
				qu.push({k,l});
				mem[k][l] = mem[i][j] + 2;
			}
		}
	}
	f(i,0,n){
		f(j,0,n){
			cout << (mem[i][j] == inf ? -1 : mem[i][j]) << ' ';
		}
		cout << ln;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
