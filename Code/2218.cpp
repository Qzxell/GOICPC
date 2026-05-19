#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


void so(int test){
	int n,m;
	cin >> n >> m;
	vi b(n);
	forn(i,n)
		cin >> b[i];
	auto f = [&](int pos)->bool{
		if(pos + 1 < n && b[pos + 1] < b[pos])
			return true;
		if(pos - 1 >= 0 && b[pos - 1] < b[pos])
			return true;
		return false;
	};
	vi ti(n+ 1,0);
	forn(i,n){
		ti[b[i]]++;
		if(b[i] == 0)
			continue;
		if(!f(i)){
			cout << 0 << '\n';
			return;
		}
	}
	const int mod = 676767677;
	int ans = 1;
	auto mul = [&](int a, int b)->int{
		return a*1ll*b %mod;
	};
	vi ps(m , 0);
	ps[0] = ti[0];
	forsn(i,1,m)
		ps[i] = ps[i-1] + ti[i];
	forn(i,n){
		if(b[i] == 0)continue;
		bool ok = 1;
		if(i - 1 >= 0 && b[i-1] < b[i] && b[i-1] != b[i] - 1)
			ok = 0;
		if(i + 1 < n && b[i+1] < b[i] && b[i+1] != b[i] - 1)
			ok = 0;
		if(ok){
			ans = mul(ans, ps[b[i] -1]);
		}
		else{
			ans = mul(ans, ti[b[i] -1]);
			//cout << ti[b[i] - 1] << ' ';
		}
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

