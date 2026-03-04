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

void so(int test){
        int n;
        cin >> n;
        string s,c;
        cin >> s >> c;
        sort(rall(s));
        sort(rall(c));
        int j = 0;
        bool ye = 0;
        swap(c,s);
        f(i,0,n){
                while(j < n and c[j] > s[i])j++;
                if(j >= n){
                        ye = 1;
                        cout << n-i << ln;
                        break;
                }
                j++;
        }
        if(!ye){
                cout << 0 << ln;
        }
        j = 0;
        ye = 0;
        f(i,0,n){
                while(j < n and c[j] >= s[i])j++;
                if(j >= n){
                        ye= 1;
                        cout << n-( n-i) << ln;
                        break;
                }
                j++;
        }
        if(!ye){
                cout << n << ln;
        }
        

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
