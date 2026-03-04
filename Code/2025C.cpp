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
        vi v;
        map<int,int> m;
        f(i,0,n){
                int x;
                cin >> x;
                if(m.count(x) == 0)v.pb(x);
                m[x]++;
        }
        sort(all(v));
        int cab = -1;
        int ant = -1;
        ll acu = 0;
        ll ans = 0;
        f(i,0,sz(v)){
                if(cab == -1){
                        cab = i;
                        acu = m[v[i]];
                        ant = v[i];
                        ans = max(ans,acu);
                        continue;
                }
                if(v[i] -1 != ant){
                        ans = max(ans,acu);
                        cab = i;
                        acu = m[v[i]];
                        ant = v[i];
                }else{
                        if(i - cab < k){
                                acu += m[v[i]];
                                ant = v[i];
                                ans = max(ans,acu);
                        }else{
                                ans = max(ans,acu);
                                acu += m[v[i]];
                                ant = v[i];
                                acu -= m[v[cab++]];
                                ans = max(ans,acu);
                        }
                }
        }
        ans = max(ans,acu);
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
