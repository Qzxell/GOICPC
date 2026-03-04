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
        ll n,W;
        cin >> n >> W;
        vector<int> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];

        for (int i = 0; i < n; i++) {
                if(w[i] >= (W+1)/2 and w[i] <= W){
                        cout << 1 << ln << i+1 << ln;
                        return;
                }
        }
        ll su = 0;
        vi ans;
        for (int i = 0; i < n; i++) {
                if(w[i] > W)continue;
                if(su <= W/2){
                        su += w[i];
                        ans.pb(i+1);
                }
        }
        if(su >= (1+W)/2 and su <= W and !ans.empty()){
                cout << sz(ans) << ln;
                for (auto x :ans) {
                        cout << x << ' ' ;
                }
                cout << ln;
                return;
        }
        cout << -1<<ln;
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



