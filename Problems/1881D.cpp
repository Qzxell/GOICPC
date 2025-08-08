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
        map<int,int> m;
        f(i,0,n){
                int x;cin >> x;
                int sq = sqrt(x);
                f(j,2,sq+1){
                        while(x % j == 0){
                                m[j]++;
                                x /= j;
                        }
                }
                if(x > 1)m[x]++;
        }
        for(auto [a,b] : m){
                if(b % n != 0){
                        cout <<"NO" << ln;
                        return;
                }
        }
        cout <<"YES" << ln;

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
