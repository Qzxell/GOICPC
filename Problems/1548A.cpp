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
#define sz(v) (v).begin(),(v).end()

void so(int test){
        int n,m;
        cin >> n >> m;

        vi deg(n+1,0);
        forn(i,m){
                int u,v;
                cin >> u >> v;
                if(u > v)swap(u,v);
                deg[u]++;
        }
        int ans = 0;
        forsn(i,1,n+1){
                ans += (deg[i] == 0);
        }
        int q;
        cin >> q;
        forn(i,q){
                int ti,u,v;
                cin >> ti;
                if(ti == 3){
                        cout << ans << '\n';
                        continue;
                }
                if(ti == 1){
                        cin >> u >> v;
                        if(u > v)swap(u,v);
                        if(deg[u] == 0)ans--;
                        deg[u]++;
                }else{
                        cin >> u >> v;
                        if(u > v)swap(u,v);
                        if(deg[u] == 1)ans++;
                        deg[u]--;
                }

        }


}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


