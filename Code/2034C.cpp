#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 1e3 + 2;
string ma[N];
int dp[N][N];
int n,m;

int dix[] = { 0 , 1 , 0 ,-1};
int diy[] = { 1 , 0 , -1 , 0};
char dic[] = {'R','D','L','U'};

void so(int test){
    //cout << "Test " << test << ln;
    cin >> n >> m;

    memset(dp, 0, sizeof(dp));
    f(i,0,n)cin >> ma[i];
       
    stack<ii> st;
    auto chk = [&](int u, int v){
        return ((u < n and u >= 0) and (v < m and v >= 0));
    };
    auto bfs = [&](int x, int y){
        st.push({x,y});
        while(!st.empty()){
            auto [x1,y1] = st.top();
            dp[x1][y1] = 1;
            st.pop();
            char dir = ma[x1][y1];

            int mv1,mv2;
            for(int i = 0 ; i < 4; i++)if(chk(x1 + dix[i],y1 + diy[i])){
                mv1 = x1 + dix[i];
                mv2 = y1 + diy[i];
                if (ma[mv1][mv2] == dic[(i+2)%4] ) {
                   st.push({mv1,mv2}); 
                }
            }
        }
    };
    for(int i = 0 ; i < m ; i++)if( ma[0][i] == 'U')bfs(0,i);
    for(int i = 0 ; i < m ; i++)if( ma[n-1][i] == 'D')bfs(n-1,i);
    for(int i = 0 ; i < n ; i++)if( ma[i][0] == 'L')bfs(i,0);
    for(int i = 0 ; i < n ; i++)if( ma[i][m-1] == 'R')bfs(i,m-1);

    int mv1,mv2;
    int ans = 0;
    f(i,0,n){
        f(j,0,m)if(dp[i][j] == 0){
            if(ma[i][j] == '?'){
                int wasa = 1;
                f(k,0,4)if(chk(i+dix[k],j+diy[k])){
                    mv1 = i + dix[k];
                    mv2 = j + diy[k];
                    if(dp[mv1][mv2] == 0) wasa = 0; 
                }
                dp[i][j] = wasa;
            }
            ans += 1- dp[i][j];
        }
    }
    cout << ans << ln;


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
