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
        int x = 1e6 + 5;
        vector<bool> comp(x+1,0);
        comp[1] = 1;
        for (int i = 2; i < x; i++) {
                for(int j = (i<<1); j < x ; j += i)comp[j] = 1;
        }
        f(i,0,n){
                ll nu;cin >> nu;
                ll sq = sqrt(nu);
                if(sq*sq == nu){
                        cout << (!comp[sq] ? "YES" : "NO") << ln;
                        continue;
                }
                cout << "NO" << ln;

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



