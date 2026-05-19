#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


void so(int test){
	int n;
	cin >> n;
	vector<int> ft(n+1,0),a(n/2),b(n/2), ans;
	for(int i = 1 ; i <= n;i++){
		ft[i]++;
		if(i + (i & -i) <= n)ft[i + (i & -i)] += ft[i];
	}
	for(auto &x : a)
		cin >> x;
	for(auto &x : b)
		cin >> x;
	auto query = [&](int pos )-> int{
		int ret = 0;
		while(pos > 0){
			ret += ft[pos];
			pos -= pos & -pos;
		}
		return ret;
	};
	auto updt = [&](int pos , int add){
		while(pos <= n){
			ft[pos] += add;
			pos += pos & -pos;
		}
	};
	for(int i = 0 ; i < n/2 ; i++){
		for(auto pos : { a[i] , b[i]}){
			int lo = 0 , lf = n + 1, mid;
			while( lf - lo > 1){
				mid = (lo + lf) >> 1;
				if(query(mid) < pos) lo = mid;
				else lf = mid;
			}
			ans.push_back(lf);
			updt(lf,-1);
		}
	}
	for(int i = 0 ; i < n ; i += 2)
		cout << ans[i] << ' ';
	cout << '\n';
	for(int i = 1 ; i < n ; i += 2)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

