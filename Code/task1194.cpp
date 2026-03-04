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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
string dir = "URDL";

void so(int test){
        int n,m;
        cin >> n >> m;
        vector<string> ma(n);
        vector<vi> dis(n,vi(m,INT_MAX));
        vector<vi> dis2(n,vi(m,INT_MAX));

        f(i,0,n)cin >> ma[i];

        auto exi = [&](int x,int y)-> bool{
                return (0 <= x and x < n and 0 <= y and y < m);
        };

        int cur_x,cur_y;
        queue<ii> qu;
        f(i,0,n)f(j,0,m){
                if(ma[i][j] == 'M'){
                        qu.push({i,j});
                        dis[i][j] = 0;
                }
                if(ma[i][j] == 'A'){
                        cur_x = i;
                        cur_y = j;
                }
        }
        if(cur_x == 0 or cur_x == n-1 or cur_y == 0 or cur_y == m-1){
                cout << "YES\n";
                cout << 0 << ln;
                return;
        }

        while(!qu.empty()){
                auto [x,y] = qu.front();qu.pop();
                int now_dis = dis[x][y];
                f(i,0,4){
                        int n_x,n_y;
                        n_x = x + dx[i];
                        n_y = y + dy[i];
                        if(!exi(n_x,n_y))continue;
                        if(ma[n_x][n_y] == '#')continue;
                        if(now_dis + 1 < dis[n_x][n_y]){
                                qu.push({n_x,n_y});
                                dis[n_x][n_y] = now_dis + 1;
                        }
                }
        }
        qu.push({cur_x,cur_y});
        dis2[cur_x][cur_y] = 0;
        while(!qu.empty()){
                auto [x,y] = qu.front();qu.pop();
                int now_dis = dis2[x][y];
                f(i,0,4){
                        int n_x,n_y;
                        n_x = x + dx[i];
                        n_y = y + dy[i];
                        if(!exi(n_x,n_y))continue;
                        if(ma[n_x][n_y] == '#')continue;
                        if(now_dis + 1 < dis[n_x][n_y] and now_dis + 1 < dis2[n_x][n_y]){
                                qu.push({n_x,n_y});
                                dis2[n_x][n_y] = now_dis + 1;
                        }
                }
        }
        int ans_x,ans_y;
        ans_x = ans_y = -1;
        for(int i = 0 ; i < m ; i++){
                if(dis2[0][i] != INT_MAX and ma[0][i] == '.'){
                        ans_x = 0;ans_y = i;
                }
                if(dis2[n-1][i] != INT_MAX and ma[n-1][i] == '.'){
                        ans_x = n-1;ans_y = i;
                }
        }
        for(int i = 0 ; i < n ; i++){
                if(dis2[i][0] != INT_MAX and ma[i][0] == '.'){
                        ans_x = i;ans_y = 0;
                }
                if(dis2[i][m-1] != INT_MAX and ma[i][m-1] == '.'){
                        ans_x = i;ans_y = m-1;
                }
        }
        if(ans_x == -1 or ans_y == -1){
                cout << "NO";
                return;
        }
        vector<char> pat;
        int con = 0;
        while(dis2[ans_x][ans_y] != 0){
                int fi = dis2[ans_x][ans_y] - 1;
                f(i,0,4){
                        int n_x,n_y;
                        n_x = ans_x + dx[i];
                        n_y = ans_y + dy[i];
                        if(!exi(n_x,n_y))continue;
                        if(ma[n_x][n_y] == '#')continue;
                        if(dis2[n_x][n_y] == fi){
                                ans_x = n_x;
                                ans_y = n_y;
                                pat.push_back((char)(dir[(i+2)%4]));
                                break;
                        }
                }
        }
        cout << "YES\n";
        cout << sz(pat) << ln;
        reverse(all(pat));
        f(i,0,sz(pat))cout << pat[i];

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
        //cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
