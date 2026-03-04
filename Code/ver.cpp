#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n ;
	cin >> n;
        string s;
        cin >> s;
        vi v(n);
        f(i,0,n)cin >> v[i];
        f(i,0,sz(s)){
                if(s[i] == '<')if(v[i] >= v[i+1]){
                        cout << "0" << ln;
                        return;
                } else if(s[i] == '<') if( v[i] >= v[i+1]){
                        cout << "0" << ln;
                        return;
                }
        }
        cout << "1" << ln

	return 0;
}
