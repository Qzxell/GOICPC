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
	int n,k;
	cin >> n >> k;
	int tot = n * k;
	vector<array<int,3>> app(tot);
	set<array<int,3>> s; // poison, size, id
	forn(i,tot){
		int a,b;
		cin >> a >> b;
		app[i] = {a,b,i};
		s.insert({b,a,i});
	}

	vi vis(tot,0);
	sort(all(app));
	for(auto [si,po,_] : app){
		cout << si << ' ' << po << '\n';
	}
	cout << '\n';

	ll ans = 0;
	for(auto [si,p,id] : app){
		if(vis[id])continue;

		cout << "===================\n";
		cout << p << ' ' << si << ' ' << id << '\n';
		ans += p;
		auto it = s.find({p,si,id});
		s.erase(it);
		vector<array<int,3>> era;
		int co = 0;
		for(auto ut = s.begin() ;co < n-1 &&  ut !=s.end();co++ , ut++){
			auto [pa,sa,ida] = *ut;
			vis[ida] = 1;
			era.push_back(*ut);
		}
		for(auto [pa,sa,id] : era){
			cout << pa << ' ' << sa << ' ' << id << '\n';
			auto it = s.find({pa,sa,id});
			s.erase(it);
		}
	}
		cout << "===================\n";
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

