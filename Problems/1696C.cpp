#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 2e5 + 5 ;
ll a[N];
int w[N];

void so(int test){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < k; i++){
		cin >> w[i];
		w[i]--;
	}
	sort(a,a+n,[](int u, int p){
			return u > p;
			});
	sort(w,w+k);
	ll ans = accumulate(a,a+k,0ll);
	int ind = k;
	for(int i = 0; i < k; i++){
		if(w[i] == 0){
			ans += a[i];
			continue;
		}
		ind += w[i] - 1;
		ans += a[ind];
		ind++;

	}
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
