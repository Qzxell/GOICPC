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
	set<pair<int,int>> s;

	forn(i,m){
		int u,v;
		cin >> u >> v;
		s.insert({u,v});
	}

	vi ans = {1};
	forsn(i,2,n+1){
		ans.push_back(i);
		int ind = sz(ans) - 1;
		for(;;){
			if(ind - 1 >= 0 && s.count({ans[ind-1],ans[ind]}) > 0){
				swap(ans[ind-1],ans[ind]);
				ind--;
			} else 
				break;
		}
	}
	forn(i,sz(ans))
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

