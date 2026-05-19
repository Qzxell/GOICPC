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
#define pb push_back
#define imp(v) {for(auto x:v)cout<<x<<' ';cout<<'\n';}


void so(int test){
	string s;
	forn(j,10){
		cin >> s;
		int n = sz(s);
		bool ok = 1;
		forn(i,n){
			if(i + 1 < n && s[i+1] == s[i]){
				ok = 0;
				break;
			}
			if(i + 3 < n && s[i+3] == s[i]){
				ok = 0;
				break;
			}
		}
		if(!ok){
			cout << "FALLOOOO!!!!!!!!!!!!!!\n";
			continue;
		}
		cout << "AC\n";
	}
}

int main(){
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

