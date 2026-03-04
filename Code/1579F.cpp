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
        int n,d;
        cin >> n >> d;
        vi v(n);
        vi fr(3,0);
        vi vis(n+1,0);
        f(i,0,n){
                cin >> v[i];
                fr[v[i]]++;
        }
        if(fr[0] == n){
                cout << 0 << ln;
                return;
        }
        if(fr[1] == n){
                cout << -1 << ln;
                return;
        }
        int ans = 0;
        f(i,0,n){
                if(vis[i])continue;
                vi aux;
                int in = i;
                int cer = 0;
                while(!vis[in]){
                        vis[in] = 1;
                        cer += (v[in] == 0);
                        aux.pb(v[in]);
                        in = (in+d)%n;
                }
                int lon = sz(aux);
                //cout << "+============================" << ln;
                //f(j,0,2*lon)cout << aux[j%lon] << ' ';
                //cout << ln;
                int rec = 0;
                int ma = 0;
                f(j,0,2*lon){
                        if(aux[j%lon] == 0){
                                ma = max(rec,ma);
                                rec = 0;
                        }else{
                                rec++;
                        }
                }
                if(ma == 0 and cer != lon){
                        cout << -1 << ln;
                        return;
                }
                ans = max(ans,ma);
        }
        cout <<ans << ln;
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
