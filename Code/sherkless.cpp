#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

void so(int test){
	int n,m;
	cin >> n >> m;
	vector<multiset<int>> v(m);

	for(int i = 0 ; i < n;i++) {
		for(int j = 0 ; j < m;j++){
			int x;
			cin >> x;
			v[j].emplace(x);
		}
	}

	int co = 0;
	for(int i = 1 ; i < m ; i++){
		for(auto it = v[i].begin(); it != v[i].end(); ){
			int nu = *it ;
			auto it_may = v[i-1].upper_bound(nu);
			if(it_may == v[i-1].end())break;
			if(*it_may > nu){
				co++;
				it = v[i].erase(it);
				v[i-1].erase(it_may);
			}else it++;
		}
	}
	if(co >= n){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";

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

