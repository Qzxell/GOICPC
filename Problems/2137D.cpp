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
        int n;
        cin >> n;
        vii v(n);
        vi m(n+1,0);
        set<int> s;
        f(i,0,n){
                int x;
                cin >> x,m[x]++;
                v[i] = {x,i};
                s.insert(x);
        }
        ll su = 0;
        int co = 1;
        vii ans;
        int lon = 0;

        for (auto x :s) {
                if(m[x] % x  != 0){
                        cout << -1 << ln;
                        return;
                }
                for(int i = 0 ; i < m[x];i += x){
                        ans.pb({co++,x});
                        lon += x;
                }
        }
        if(lon > n){
                cout << -1 << ln;
                return;
        }
        sort(all(v));
        vi res(n);
        int i = 0;
        for (auto [x,cnt] :ans) {
                f(j,0,cnt){
                        res[v[i].se] =  x;
                        i++;
                }
        }
        f(i,0,n)cout << res[i] << ' ';
        cout << ln;

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



