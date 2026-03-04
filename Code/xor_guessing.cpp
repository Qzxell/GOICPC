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

        int x=0;
        int ans = 0;
        cout << "? ";
        for(int i = 1;i <= 100;i++)cout << i << " ";
        cout << '\n' << flush;

        cin >> x; 
        ans = ((x>>7)<<7);
        cout << "? ";
        for(int i = 1;i <= 100;i++)cout << (i<<7) << " ";
        cout << '\n';
        cin >> x;
        ans += x&((1<<7)-1);
        cout <<"! " <<  (ans);
        cout << '\n';
	return 0;
}
