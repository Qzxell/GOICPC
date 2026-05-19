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
	int n;
	cin >> n;
	vi v(n);
	int tot = 0;
	forn(i,n) cin>> v[i], tot += v[i];
	sort(all(v));
	if(tot - v.back() < v.back()){
		cout << "T\n";
		return;
	}
	if(tot&1){
		cout << "T\n";
		return;
	}
	cout << "HL\n";
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

