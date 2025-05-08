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
        string s;
        cin >> n;
        cin >> s;
        if(n == 2){
                cout << stoi(s) << ln;
                return;
        }
        int ans = 1e9;
        f(i,0,n-1){
                vi part;
                for(int j = 0; j < n ; j++){
                        string to_in ;
                        to_in += s[j];
                        if(j == i){
                                to_in += s[j+1];
                                j++;
                        }
                        part.pb(stoi(to_in));
                }
                int sum = 0;
                bool equal_1 = 1;
                f(j,0,sz(part)-1){
                        if(part[j] == part[j+1] and part[j] == 1){
                        }else equal_1 = 0;
                }
                f(j,0,sz(part)){
                        if(part[j] == 1) continue;
                        sum += part[j];
                }
                f(j,0,sz(part))if(part[j] == 0){
                        sum = 0;
                }
                if(equal_1) sum = 1;
                ans= min(ans,sum);
        }
        cout << ans  << ln;
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
