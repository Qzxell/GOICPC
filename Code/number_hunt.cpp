#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

bool is_prime(int n){
	if(n == 1)return false;
	forsn(i,2,sqrt(n) + 1){
		if(n%i == 0)return false;
	}
	return true;
}

void so(int test){
	int x;
	cin >> x;
	int cn = 0;
	vi ans(2);
	forsn(i,x, x + 402){
		if(is_prime(i)){
			ans[cn++] = i;
			if(cn == 2)break;
		}
	}
	cout << ans[0]*1ll*ans[1] << '\n';
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

