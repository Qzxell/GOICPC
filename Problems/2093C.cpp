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
        int n,k;	
        cin >> n >> k;
        if(n > 1 and k > 1){
                cout << "NO";
                cout << ln;
                return;
        }
        auto fu = [&](int nu){
                int li = (int)sqrt(nu);
                int c = 0;
                f(i,2,li+1){
                        if(nu % i ==0){
                                c++;
                                while(nu % i ==0)nu/=i;
                        }
                }
                return c;
        };
        if(n == 1 and k == 1){
                cout << "NO" << ln;
                return;
        }
        if(n == 1){
                string owo;
                f(i,0,k)owo+='1';
                int ga = stoi(owo);
                int wa = fu(ga);

                if(wa){
                        cout << "NO"<<ln;
                        return;
                }
                cout << "YES" << ln;
                return;
        }
        int gu = fu(n);
        if(gu == 0){
                cout << "YES" << ln;
                return;
        }
                        cout << "NO"<<ln;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
