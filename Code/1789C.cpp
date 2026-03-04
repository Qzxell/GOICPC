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
        int n,m;
        cin >> n >> m;
        vi v(n);
        f(i,0,n)cin >> v[i];
        vi last(n+m+1,-1);
        vi see(n+m+1,0);
        f(i,0,n)last[v[i]] = 0;
        f(i,1,m+1){
                int pos,val;
                cin >> pos >> val; pos--;
                int quit = v[pos];
                int ul = last[quit];
                see[quit] += (i-ul);
                last[val] = i;
                v[pos] = val;
        }
        f(i,0,n){
                see[v[i]] += (m + 1 - last[v[i]]);
        }
        ll ans = n*((m*1ll*(m+1))/2);
        ll aport = 0;
        f(i,1,n+m+1){
                aport += see[i]*1ll*(m+1-see[i]);
        }
        aport /= 2;
        ans += aport;
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
