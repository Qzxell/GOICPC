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
        vector<string> ma(n);
        f(i,0,n)cin >> ma[i];
        vi punt(n+1,0);
        f(i,0,m){
                int un = 0;
                f(j,0,n)un += (ma[j][i] == '1');
                int cer = n - un;
                if(un == 0 and cer == 0){
                        f(k,0,n){
                                punt[k] += 1;
                        }
                        continue;
                }
                if(un < cer){
                        f(k,0,n){
                                punt[k] += (ma[k][i] == '1');
                        }
                        continue;
                }
                f(k,0,n){
                        punt[k] += (ma[k][i] == '0');
                }
        }
        int num = *max_element(all(punt));
        f(i,0,n)if(punt[i] == num)cout << i+1 << ' ';
        cout << ln;
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
