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

const int N = 2e5 + 5;
vector<vi> T;
int tin[N];
int line[N];
int tou[N];

int tim = 1;

void dfs(int nod,int pat){
        line[tim] = nod;
        tin[nod] = tim++;
        for(auto x : T[nod])if(x != pat){
                dfs(x,nod);
        }
        tou[nod] = tim;
}

void so(int test){
        //cout << "==============\n";
        int n;
        cin >> n;
        tim = 1;
        T.clear();
        T.resize(n);

        vi deg(n,0);

        forn(i,n-1){
                int u,v;
                cin >> u>> v;
                u--;v--;
                deg[u]++;
                deg[v]++;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        dfs(0,-1);
        vector<vi> dp(3,vi(n+2,0));

        dp[0][1] = 1;
        forsn(i,1,n+1){
                int cur = line[i];
                forn(j,3)if(dp[j][i]){
                        dp[(j+1)%3][tou[cur]] = 1;
                        if(tou[cur] - tin[cur] != 1) dp[j][i+1] = 1;
                }
        }

        //cout << "dp \n";
        //forn(i,3){
                //forsn(j,1,n+2){
                        //cout << dp[i][j] << ' ';
                //}
                //cout << '\n';
        //}
//
        //cout << "line : \n";
        //forsn(i,1,n+2){
                //cout << line[i] << " \n"[i == n+1];
        //}
//
        //forn(i,n){
                //cout << tin[i] << " \n"[i == n-1];
        //}
        //forn(i,n){
                //cout << tou[i] << ' ';
        //}
        //cout << '\n';
        cout << (dp[0][n+1] ? "YES" : "NO")<< '\n';
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


