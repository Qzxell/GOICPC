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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void so(int test){
        int h,w,x,y;
        cin >> h >> w >> x >> y;
        x--;y--;

        string ma[h];
        map<ii,bool> vis;
        string T;

        f(i,0,h)cin >> ma[i];
        cin >> T;
        string Move = "RDLU";
        f(i,0,sz(T)){
                f(j,0,4)if(Move[j] == T[i]){
                        int n_x = x + dx[j],n_y = y + dy[j];
                        if(ma[n_x][n_y] == '#')continue;
                        x = n_x;
                        y = n_y;
                        if(ma[x][y] == '@')vis[{x,y}] = 1;
                }
        }
        int ans = 0;
        for(auto x : vis)ans++;
        cout << x+1 << ' ' << y+1  << ' ';
        cout << ans << ' ';

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
