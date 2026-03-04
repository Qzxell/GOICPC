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
#define f(i, a, b)  for(int i = a; i < b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        int n;
        cin >> n;
        vi a_par(n+1,-1);
        vi a_odd(n+1,-1);
        vi b_par(n+1,-1);
        vi b_odd(n+1,-1);
        vii ind_a(n+1,{-1,-1});
        vii ind_b(n+1,{-1,-1});
        f(i,0,n){
                int x;
                cin >> x;
                if(i&1){
                        a_odd[x] = max(a_odd[x],i);
                }else a_par[x] = max(a_par[x],i);
                ind_a[x] = {ind_a[x].se,i};
        }
        f(i,0,n){
                int x;
                cin >> x;
                if(i&1){
                        b_odd[x] = max(b_odd[x],i);
                }else b_par[x] = max(b_par[x],i);
                ind_b[x] = {ind_b[x].se,i};
        }
        int ans = 0;
        f(i,1,n+1){
                auto [x,y] = ind_a[i];
                ans = max(ans,x+1);
                ans = max(ans,ind_b[i].fi+1);
        }
        f(i,1,n+1){
                ans = max(ans,min(a_par[i],b_par[i]) + 1);
                ans = max(ans,min(a_odd[i],b_odd[i]) + 1);
                if(abs(a_odd[i]-b_par[i]) > 1)ans = max(ans,min(a_odd[i],b_par[i]) + 1);
                if(abs(a_par[i]-b_odd[i]) > 1)ans = max(ans,min(a_par[i],b_odd[i]) + 1);
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



