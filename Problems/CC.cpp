#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	vector<array<ll,4>> posi;
	vector<array<ll,4>> nega;
	forn(i,n){
		ll a,b,c;
		cin >> a >> b >> c;
		if(a > 0 ){
			posi.push_back({a,b,c,i});
		}else{
			nega.push_back({a,b,c,i});
		}
	}
	auto vert = [&](auto e1)->ii{
		auto [a1,b1,c1,id] = e1;
		ll nu = 4*a1*c1 - b1*b1;
		ll de = 4*a1;
		ll gc =gcd(nu,de);
		if(gc >0){
			de /= gc;
			nu /= gc;
		}
		return {nu,de};
	};
	auto ga =[&](auto e1, auto e2)->bool{
		auto [a1,b1,c1,id] = e1;
		auto [a2,b2,c2,id2] = e2;
		ii fr1 = vert(e1);
		ii fr2 = vert(e2);
		return fr1.fi * fr2.se < fr2.fi*fr1.se;
	};
	auto uwu = [&](auto e1, auto e2){
		return e1[0] < e2[0];
	};
	auto uwu1 = [&](auto e1, auto e2){
		return e1[0] > e2[0];
	};
	//sort(all(posi),uwu);
	//sort(all(nega),uwu1);
	sort(all(posi),ga);
	sort(all(nega),ga);
	auto posible = [&](auto e1 , auto e2)->bool{
		auto [a1,b1,c1,id] = e1;
		auto [a2,b2,c2,id2] = e2;
		return (b1-b2)*(b1-b2) - 4*(a1-a2)*(c1-c2) < 0;
	};

	vi dp1(sz(posi)+1,1);
	vi dp2(sz(nega)+1,1);
	forn(i,sz(posi)){
		forn(j,i){
			if(posible(posi[i],posi[j]))
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	vi res(n,0);
	forn(i,sz(nega)){
		forn(j,i){
			if(posible(nega[i],nega[j]))
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	forn(i,sz(posi)){
		auto [a,b,c,id] = posi[i];
		res[id] = dp1[i];
		forn(j,sz(nega)){
			if(posible(posi[i],nega[j])){
				res[id] = max(res[id],dp1[i]+dp2[j]);
			}
		}
	}
	forn(i,sz(nega)){
		auto [a,b,c,id] = nega[i];
		res[id] = dp2[i];
		forn(j,sz(posi)){
			if(posible(posi[j],nega[i])){
				res[id] = max(res[id],dp1[j]+dp2[i]);
			}
		}
	}
	forn(i,n){
		cout << res[i] << ' ';
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
