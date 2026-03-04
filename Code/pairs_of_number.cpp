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
        if(n == 1){
                cout << 0 ;
                return;
        }
        auto fu = [&](int n,int m){
                int c = 0;
                while(n != 1 or m != 1){
                        m -= n;
                        if(m == 0)return -1;
                        if(m < n)swap(n,m);
                        c++;
                }
                return c;
        };
        int ans = 1e9;
        f(i,1,n){
                if(fu(i,n) == -1)continue;
                ans = min(ans,fu(i,n));
        }
        cout << ans;
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
