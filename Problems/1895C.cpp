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
        vector<vi> m(6,vi(46,0));//m[lon][sum]
        ll ans = 0;
        vector<string> v(n);
        f(i,0,n){
                cin >> v[i];
                string s = v[i];
                int tot = 0;
                f(j,0,sz(s)){
                        tot += (s[j] - '0');
                }
                m[sz(s)][tot]++;
        }
        f(i,0,n){
                string s = v[i];
                vi ps(6,0);
                f(j,1,sz(s)+1) ps[j] = ps[j-1] + (s[j-1] - '0');
                int tot = ps[sz(s)];
                ll acu = 0;
                f(lon,1,sz(s)+1){
                        int va,rest;
                        va = ps[lon];
                        rest = tot - va;
                        if(va >= rest and 2*lon >= sz(s)) acu += m[2*lon - sz(s)][va-rest];
                        swap(va,rest);
                        if(va >= rest and 2*(sz(s)-lon) >= sz(s)) acu += m[2*(sz(s)-lon) - sz(s)][va-rest];
                }
                ans += acu;
        }
        cout << ans << ln;
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



