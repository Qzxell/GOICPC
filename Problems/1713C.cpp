#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)

vi sq;

void con(int ul, vi &ans){
	if(ul < 0) return;
	int su = sq[lower_bound(all(sq),ul)-sq.begin()];
	if(su > ul+ul){
		return;
	}
	int co = su - ul;
	f(i,co,ul + 1)ans[i] = su - i;
	con(su - ul - 1, ans);
}
void so(int test){
	int n;
	cin >> n;
	vi ans(n,-1);
	con(n-1,ans);
	f(i,0,n)if(ans[i] == -1){
		cout << -1 << ln;
		return;
	}
	f(i,0,n)cout << ans[i] << ' ';
	cout << ln;
	f(i,0,n)cout << ans[i] + i << ' ';
	cout << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0 ; i < 1000; i++){
        if (i*i < 100001) {
            sq.pb(i*i);
        }
        sq.pb(i*i);
    }
    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
