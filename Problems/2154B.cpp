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
#define re real()
#define im imag()

void so(int test){
        int n;
        cin >> n ;
        vi v(n);
        f(i,0,n)cin >> v[i];
        ll ans = 0;
        int ma = -1;
        for(int i = 0 ; i < n ; i+=1){
                ma = max(ma,v[i]);
                if(i&1)v[i] = ma;
        }
        for(int i = 0 ; i < n ; i+=2){
                if(i == 0){
                        if(v[i] == v[i+1]){
                                ans++;
                        }
                        continue;
                }
                if(v[i] >= v[i-1]){
                        ans += (v[i] - v[i-1] + 1);
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



