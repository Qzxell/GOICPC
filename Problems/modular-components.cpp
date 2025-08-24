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
        int n,k;
        cin >> n >> k;
        vi mo(k,0);
        ll ans = 0;
        f(i,1,n+1){
                mo[i%k]++;
        }
        f(i,1,k)if(i != k-i){
                if(min(mo[i],mo[k-i]) == 0){
                        ans += max(mo[i],mo[k-i]);
                        continue;
                }
                ans++;
        }
        ans /= 2;
        if(mo[0])ans++;
        if( k/2 == k- k/2 and mo[k/2]){
                ans++;
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
