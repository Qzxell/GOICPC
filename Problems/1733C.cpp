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
#define point complex<long long>

void so(int test){
        int n;
        cin >> n;
        vi od;
        vi ev;
        bool even = 1;
        f(i,0,n){
                int x;
                cin >> x;
                if(i == 0 and (x&1)){
                        even = 0;
                }
                if(x&1){
                        od.pb(i+1);
                }else ev.pb(i+1);
        }
        vii ans;
        if(even){
                reverse(all(ev));
                f(i,1,sz(ev)){
                        ans.pb({ev[0],ev[i]});
                }
                f(i,0,sz(od)){
                        ans.pb({1,od[i]});
                }
                cout << sz(ans) << ln;
                for (auto [u,v] :ans) {
                        cout << min(u,v) << ' ' << max(u,v) << ln;
                }
        }else{
                reverse(all(od));
                f(i,1,sz(od)){
                        ans.pb({od[0],od[i]});
                }
                f(i,0,sz(ev)){
                        ans.pb({1,ev[i]});
                }
                cout << sz(ans) << ln;
                for (auto [u,v] :ans) {
                        cout << min(u,v) << ' ' << max(u,v) << ln;
                }
        }
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



