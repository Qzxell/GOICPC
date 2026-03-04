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
        string s;
        cin >> s;
        // index by 1
        vi ps_d(n+1,0);
        vi ps_k(n+1,0);
        int cont_D , cont_K;
        cont_D = cont_K = 0;
        f(i,0,n){
                ps_d[i+1] = ps_d[i] + (s[i] == 'D');
                ps_k[i+1] = ps_k[i] + (s[i] == 'K');
        }
        map<ii,int> ma;//propor -> cant 
        f(i,1,n+1){
                int gc = gcd(ps_d[i],ps_k[i]);
                ma[{ps_d[i]/gc,ps_k[i]/gc}]++;
                cout << ma[{ps_d[i]/gc,ps_k[i]/gc}] << ' ' ;
        }
        cout << ln;
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
