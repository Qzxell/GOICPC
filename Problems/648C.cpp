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

const int N =101;
bool vis[N][N];

void so(int test){
        int n,m;
        cin >> n >> m ;
        vector<string> ma(n);
        f(i,0,n)cin >> ma[i];
        int px,py;
        string dir = "URLD";
        vi dx = {-1,0,0,1};
        vi dy= {0,1,-1,0};

        f(i,0,n)f(j,0,m){
                if(ma[i][j] == 'S'){
                        px = i;py = j;
                }
        }
        queue<ii> qu;
        qu.push({px,py});
        string ans;
        auto exi = [&](int x,int y) -> bool{
                return ( 0<=x and x < n and 0 <= y and y < m);
         };
        int ulx,uly;
        while(!qu.empty()){
                auto [x,y] = qu.front();qu.pop();
                ulx = x,uly = y;
                vis[x][y] = 1;
                for(int i = 0 ; i < 4; i++){
                        int nx,ny;
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if(!exi(nx,ny))continue;
                        if(ma[nx][ny] != '*')continue;
                        if(vis[nx][ny])continue;
                        qu.push({nx,ny});
                        ans += dir[i];
                        break;
                }
        }
        f(i,0,4)if(exi(dx[i] + ulx , dy[i] + uly) and ma[dx[i]+ulx][dy[i]+uly] == 'S'){
                ans += dir[i];
        }

        cout << ans << ln;


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
