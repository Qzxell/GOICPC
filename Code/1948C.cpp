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

int n;
int N = 2e5 + 5;
vector<string> ma(2);
vector<vector<bool>> vis(2,vector<bool>(N,0));
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool exi(int x,int y){
        return (0 <= x and x < 2 and y >= 0 and y < n);
}

bool fu(int x,int y){
        vis[x][y] = 1;
        bool ret = 0;
        f(i,0,4){
                int nx,ny;
                nx = x + dx[i];
                ny = y + dy[i];
                if(!exi(nx,ny))continue;
                if(ma[nx][ny] == '<'){
                        ny--;
                }else{
                        ny++;
                }
                if(nx == 1 and ny == n-1)return true;
                if(vis[nx][ny])continue;
                ret |= fu(nx,ny);
        }
        return ret;
}


void so(int test){
        cin >> n;
        cin >> ma[0] >> ma[1];
        f(i,0,2)f(j,0,n)vis[i][j] = 0;
        cout << (fu(0,0) ? "YES" : "NO") << ln;

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
