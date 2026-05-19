#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>    

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
    ii, 
    null_type, 
    less<ii>, 
    rb_tree_tag, 
    tree_order_statistics_node_update> 
ordered_set;


void so(int test){
	int n,m;
	cin >> n >> m;
	vi v(n);
	vi fre(m,0);
	forn(i,n){
		cin>>v[i];
		v[i]--;
		fre[v[i]]++;
	}
	vector<pair<ll,ll>> gru;//fre,num;
	forn(i,m)
		gru.push_back({fre[i],i});
	sort(all(gru));
	//cout << "gru : num fre\n";
	//for(auto [fr,i] :gru){
		//cout <<i << ' ' << fr << '\n';
	//}
	//cout << '\n';
	ll INF = (1ll<<62);

	vl ps(m+1,0);// del segmente 1,i cuanto se va a repetir?
	forsn(i,1,m){
		ll dif = (gru[i].fi - gru[i-1].fi);
		ll apar = i*1ll*dif;
		ps[i] = ps[i-1] + apar;
	}
	ps[m] = INF;
	//forsn(i,1,m+1)
		//cout << ps[i] << ' ';
	//cout << '\n';


	int q;
	cin >> q;
	vi ans(q);
	vector<array<ll,3>> querys(q);
	ordered_set s;
	forn(i,q){
		ll x;
		cin >> x;
		if(x <= n){
			querys[i] = {-100,0,0};
			ans[i] = v[x-1] + 1 ;
			continue;
		}
		x -= n;
		int lo = 0,lf = m,mid;//fffvvv
		while(lf - lo > 1){
			mid = (lo+lf)/2;
			if(mid == m){
				lf = mid;
				continue;
			}
			if(ps[mid] >= x)lf = mid;
			else lo = mid;
		}
		x -= ps[lf-1];
		x--;
		x += lf;
		x %= lf;
		//cout << lf << ' ' << x << '\n';
		querys[i] = {lf,x,i};
	}
	sort(all(querys));
	int ind = 0;
	int aux = 1;
	for(auto [lf,x,id] : querys){
		if(lf == -100)continue;
		while(ind + 1 <= lf){
			s.insert({gru[ind].se,aux++});
			ind++;
		}
		ans[id] = s.find_by_order(x)->fi + 1;
	}
	forn(i,q)
		cout << ans[i] << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	//cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

