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
        string s,t;
        cin >> s >> t;
        int p_s = 0;
        int p_t = 0;
        int inf = 1e9;
        vi lon_pref(n+2,inf);
        vi lon_suf(n+2,inf);
        while(p_s < n and p_t < m){
                if(s[p_s] == t[p_t]){
                        lon_pref[p_t+1] = p_s;
                        p_s++;
                        p_t++;
                        continue;
                }
                p_s++;
        }
        p_s = n-1;
        p_t = m-1;
        while(p_s >= 0 and p_t >= 0){
                if(s[p_s] == t[p_t]){
                        lon_suf[m-p_t] = p_s;
                        p_s--;
                        p_t--;
                        continue;
                }
                p_s--;
        }
        int ans = 1;
        f(i,1,m){
                if(lon_suf[i] != inf and lon_pref[m-i] != inf)
                        ans = max(ans,lon_suf[i] - lon_pref[m-i]);
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
