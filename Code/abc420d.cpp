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
#define f(i, a, b)  for(int i = a; i < b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0};
void so(int test){
        int h,w;
        cin >> h >> w;
        vector<string> ma(h);
        vector<string> ma_(h);
        f(i,0,h)cin >> ma[i];
        ma_ = ma;
        vector<vector<string>> Ma(2, vector<string>(h));
        int x ,y;
        int gox,goy;
        f(i,0,h)f(j,0,w){
                ma_[i][j] = (ma_[i][j] == 'o' ?'x' : (ma_[i][j] == 'x' ? 'o' : ma_[i][j]));
                if(ma[i][j] == 'S')x = i,y = j;
                if(ma_[i][j] == 'S')ma[i][j] = ma_[i][j] = '.';
                if(ma[i][j] == 'G')gox = i,goy = j;
        }
        Ma[0] = ma;
        Ma[1] = ma_;
        vector<vector<int>> dp[2];
        int n = h,m = w;
        vector<vi> ga(n,vi(m,INT_MAX));
        dp[0] = dp[1] = ga;
        queue<pair<ii,int>> qu;
        qu.push({{x,y},0});
        dp[0][x][y] = 0;
        int est = 0;
        auto exi = [&] (int nx,int ny){
                return 0 <= nx and nx < h and 0<= ny and ny < w;
        };
        while(!qu.empty()){
                auto [xy,st] = qu.front();qu.pop();
                auto [x_,y_] = xy;
                int dis = dp[st][x_][y_];
                f(i,0,4){
                        int nx,ny;
                        nx = x_ + dx[i];
                        ny = y_ + dy[i];
                        if(!exi(nx,ny))continue;
                        if(Ma[st][nx][ny] == '#')continue;
                        if(Ma[st][nx][ny] == 'x')continue;
                        if(Ma[st][nx][ny] == '?'){
                                if(dp[st^1][nx][ny] > dis + 1){
                                        dp[st^1][nx][ny] = dis +1 ;
                                        qu.push({{nx,ny},st^1});
                                }
                        }
                        if(Ma[st][nx][ny] != '?'){
                        if(dp[st][nx][ny] > dis + 1){
                                dp[st][nx][ny] = dis +1 ;
                                qu.push({{nx,ny},st});
                        }
                        }
                }
        }
        if(dp[0][gox][goy] == dp[1][gox][goy] and dp[0][gox][goy] == INT_MAX){
                cout << -1 << ln;
                return;
        }
        cout << min(dp[0][gox][goy],dp[1][gox][goy]) << ln;
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
