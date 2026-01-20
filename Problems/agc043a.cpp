#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

int dx[] = {0,1};
int dy[] = {1,0};

void so(int test){
        int h,w;
        cin >> h >> w;
        vector<string> ma(h);

        forn(i,h) cin >> ma[i];

        int dp[h][w];
        int inf = (1<<30);

        forn(i,h) forn(j,w) dp[i][j] = inf;
        auto exi = [&](int x ,int y)->bool{
                return 0<=x and x < h and 0<=y and y < w;
        };
        dp[0][0] = ( ma[0][0] == '.'? 0 : 1);
        forn(i,h)
        forn(j,w)
        forn(k,2)
        {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(!exi(nx,ny))continue;
                if(ma[nx][ny] == '#')dp[nx][ny] = min(dp[nx][ny], dp[i][j] + (ma[i][j] == '.'));
                else dp[nx][ny] = min(dp[nx][ny] , dp[i][j]);
        }
        cout << dp[h-1][w-1] ;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


