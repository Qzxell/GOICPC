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

vi dx = {1,0,-1,0};
vi dy = {0,1,0,-1};
int vis[501][501];

void so(int test){
	int n,m,k;
	cin >> n >> m >> k;
	vector<string> v(n);
	
	f(i,0,n)cin >> v[i];

	auto exi = [&](int x, int y){
		if( x >= 0 and x < n and y >= 0 and y < m)return true;
		return false;
	};
	int cas = n*m;
	int cox,coy;
	f(i,0,n){
		f(j,0,m){
			if(v[i][j] == '#')cas--;
			if(v[i][j] == '.'){
				cox = i;
				coy = j;
			}
			vis[i][j] = 0;
		}
	}
	queue<ii> qu;
	int cont =0 ;
	auto bfs = [&] (int x,int y){
		qu.push({x,y});
		vis[x][y] = 1;
		while(!qu.empty()){
			auto [xx,yy] = qu.front();qu.pop();
			cont++;
			v[xx][yy] = 's';// intoncables;
			if(cont == cas - k)break;
			f(i,0,4){
				int x_ = xx+dx[i];
				int y_ = yy+dy[i];
				if(exi(x_,y_) and v[x_][y_] == '.' and !vis[x_][y_]){
					qu.push({x_,y_});
					vis[x_][y_] = 1;
				}

			}
		}
	};
	bfs(cox,coy);
	f(i,0,n){
		f(j,0,m){
			if(v[i][j] == '.')v[i][j] = 'X';
			if(v[i][j] == 's')v[i][j] = '.';
			cout << v[i][j];
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
