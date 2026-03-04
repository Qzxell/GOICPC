#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	vector<vi> v(n);
	forn(i,n){
		int l;
		cin >> l;
		vi uwu(l);
		forn(j,l)
			cin >> uwu[j];
		v[i] = uwu;
	}
	set<int> s;
	vi ans;
	vi ind;
	while(true){
		int mi = 1e9;
		
		if(ind.empty()){
			for(int i = 0 ; i < n ; i++){
				while(!v[i].empty() and s.count(v[i].back()) >0 )
					v[i].pop_back();
				if(!v[i].empty()){
					if(v[i].back() < mi){
						ind.clear();
						mi = v[i].back();
					}
					if(v[i].back() == mi){
						ind.push_back(i);
					}
				}
			}
		}else{
			vi ind2;
			for(auto i : ind){
				while(!v[i].empty() and s.count(v[i].back()) >0 )
					v[i].pop_back();
				if(v[i].empty()){
					ind2.clear();
					break;
				}
				if(!v[i].empty()){
					if(v[i].back() < mi){
						ind2.clear();
						mi = v[i].back();
					}
					if(v[i].back() == mi){
						ind2.push_back(i);
					}
				}
			}
			swap(ind2,ind);
			if(ind.empty())continue;
		}
		if(mi == 1e9)break;
		s.insert(mi);
		ans.push_back(mi);
	}
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';
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

