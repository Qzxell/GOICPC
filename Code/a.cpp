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
	set<ii> s1,s2;
	forn(i,n){
		int x;
		cin >> x;
		s1.insert({x,i});
		s2.insert({i,x});
	}
	int ans = 0;
	while(sz(s1) > 0){
		while(sz(s2) >= 2){
			auto it = s2.begin();
			auto it2 = next(s2.begin());
			if (it -> second == it2 -> second){
				s1.erase(s1.find({it->second,it->first}));
				s1.erase(s1.find({it2->second,it2->first}));
				s2.erase(it);
				s2.erase(it2);
				ans++;
			}else break;
		}
		if(sz(s1) == 0)break;
		auto it = s1.begin();
		s2.erase(s2.find({it->second,it->first}));
		s1.erase(it);
		ans++;
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

