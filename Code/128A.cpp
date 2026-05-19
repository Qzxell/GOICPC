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

int dx[] = {0,0,1,-1,1,-1,-1,1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};

void so(int test){
	string ma[10];
	bool vis[10][10];
	forn(i,10) forn(j,10)
		vis[i][j] = 0;
	ma[0] = ma[1] = "        ";
	forsn(i,2,10)cin >> ma[i];



	auto exi = [&](int x, int y)->bool{
		return 0 <= x && x < 10 && 0 <= y && y < 8 ;
	};
	queue<ii> qu;
	auto bfs = [&](int x_, int y_){
		qu.push({x_,y_});
		vis[x_][y_] = 1;
		while(!qu.empty()){
			auto [x,y] = qu.front();qu.pop();
			forn(i,9){
				int nx,ny;
				nx = x + dx[i] - 1;
				ny = y + dy[i];
				if(!exi(nx,ny))continue;
				if(!exi(nx+1,ny))continue;
				if(ma[nx+1][ny] == 'S' or ma[nx][ny] == 'S')continue;
				if(vis[nx][ny])continue;
				qu.push({nx,ny});
				vis[nx][ny] = 1;
			}
		}
	};
	bfs(9,0);
	cout << (vis[0][7] ? "WIN" : "LOSE") << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

