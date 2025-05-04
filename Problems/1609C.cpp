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

const int N = 1e6 + 5;

vi prime(N,1);


void so(int test){
        int n,e;
        cin >> n >> e;
        vi v(n);
        f(i,0,n)cin >> v[i];
        ll ans = 0;

        vi st;

        f(i,0,e){
                int cont = 0;
                vi acumu;
                bool fi_prime = 0;
                for(int j = i; j < n; j+=e){
                        if(v[j] == 1){
                                cont++;
                        }else{
                                if(prime[v[j]]){
                                        st.pb(cont);
                                        fi_prime = 1;
                                        cont = 0;
                                } else{
                                        if(fi_prime)st.pb(cont);
                                        int le = sz(st);
                                        f(k,0,le-1){
                                                ans += st[k]*1ll*(1+st[k+1]) + st[k+1] ;
                                        }
                                        cont = 0;
                                        fi_prime = 0;
                                        st.clear();
                                }
                        }
                }
                if(fi_prime)st.pb(cont);
                int le = sz(st);
                f(k,0,le-1){
                        ans += st[k]*1ll*(1+st[k+1]) + st[k+1] ;
                }
                st.clear();
        }
        cout << ans << ln;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

        prime[0] = prime[1] = 0;
        for(int i = 2;i < N;i++)if(prime[i]){
                for(int j =i + i ; j < N ; j+= i){
                        prime[j] = 0;
                }
        }
	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
