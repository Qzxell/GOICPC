#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m; 

bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
}

void so(int test){
        cin >> n >> m;
        vector<string> v(n);
        vector<vi> vis(n,vi(m,0));
        forn(i,n)cin >> v[i];

        auto ga = [&](int x, int y){
                int ind = 0;
                int i_x,i_y;
                i_x = x;
                i_y = y;
                string uwu;
                while(true){
                        if(!vis[x][y]){
                                uwu += v[x][y];
                        }
                        vis[x][y] = 1;
                        int nx,ny;
                        nx = x + dx[ind];
                        ny = y + dy[ind];
                        if(nx == i_x and ny == i_y)break;
                        if(!check(nx,ny)){
                                ind = (ind+1)%4;
                                continue;
                        }
                        if(vis[nx][ny]){
                                ind = (ind+1)%4;
                                continue;
                        }
                        x = nx;
                        y = ny;
                }
                int lon = sz(uwu);
                int ret = 0;
                forn(i,lon){
                        string xd;
                        xd += uwu[i];
                        xd += uwu[(i+1)%lon];
                        xd += uwu[(i+2)%lon];
                        xd += uwu[(i+3)%lon];
                        if(xd == "1543"){
                                ret++;
                        }
                }
                return ret;
        };
        int ans = 0;
        for(int i= 0,j = 0 ; i <n && j < m ; i++,j++){
                if(!vis[i][j])ans += ga(i,j);
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


