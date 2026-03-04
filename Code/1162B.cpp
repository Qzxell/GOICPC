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
#define sz(v) (int)(v).size()

void so(int test){
        int n,m;
        cin >> n >> m;
        int M[n][m][2];
        bool dp[n][m][2];
        memset(dp, 0, sizeof(dp));

        forn(i,n) forn(j,m)
                cin >> M[i][j][0];
        forn(i,n) forn(j,m){
                cin >> M[i][j][1];
                if(M[i][j][0] > M[i][j][1]){
                        swap(M[i][j][0],M[i][j][1]);
                }
        }

        forn(i,n) forn(j,m) {
                if(!((i-1 >= 0 ? M[i-1][j][0] : -1) < M[i][j][0] 
                and (j-1 >= 0 ? M[i][j-1][0] : -1) < M[i][j][0] 
                and (i-1 >= 0 ? M[i-1][j][1] : - 1) < M[i][j][1] 
                and (j-1 >= 0 ? M[i][j-1][1] : - 1)< M[i][j][1] )){
                        cout << "Impossible";
                        return;
                }
        }
        cout << "Possible";
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


