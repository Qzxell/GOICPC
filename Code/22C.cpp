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

void so(int test){
        int n,m,v;
        cin >> n >> m >> v;
        vi nod(n+1);
        f(i,1,n+1)nod[i] = i;
        swap(nod[2],nod[v]);
        vii ans;
        f(i,1,n){
                ans.pb({nod[i],nod[i+1]});
                m--;
        }
        if(m < 0){
                cout << -1 << ln;
                return;
        }

        for(int cur = 2;cur <= n; cur++){
                int pos = cur+2;
                while(m and pos <= n){
                        ans.pb({nod[cur],nod[pos]});
                        m--;pos++;
                }
        }
        if(m){
                cout << -1 << ln;
                return;
        }
        for (auto [a,b] :ans) {
                cout << a << ' ' << b << ln;
        }
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



