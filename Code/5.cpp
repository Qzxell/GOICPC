#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const int N = 2005;
const int INF = (1<<30);
int dis[N][N];

void so(int test){
	forn(i,N) forn(j,N)
		dis[i][j] = INF;
	int n,m;
	cin >> n >> m;
	int k;
	cin >> k;
	forn(i,k){
		int x,y;
		cin >> x,y;
		qu.push({x,y});
	}
	queue<ii> qu;
	auto exi = [&](int x, int y)->bool{
		return 0<= x and x < n and 0 <= y and y < m;
	};
	auto bfs = [&](int xx, int yy ){
		qu.push({xx,yy});
		dis[xx][yy] = 0;
		int mx = 0;
		int ans 
		while(!qu.empty()){
			auto[x,y] = qu.front();qu.pop();
			int cur_dis = dis[x][y];
			forn(k,4){
				int nx,ny;
				nx = x + dx[k];
				ny = y + dy[k];
				if(!exi(nx,ny))continue;
				if(cur_dis + 1 < dis[nx][ny]){
					qu.push({nx,ny});
					dis[nx][ny] = cur_dis + 1;
				}
			}
		}
	};
	
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

