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
        vi A(n);
        f(i,0,n){
                cin >> A[i];
        }
        auto veri = [&](int len)->bool{
                if(len + 1 > n/2)return false;
                bool yes = 1;
                f(i,0,len+1){
                        if(2*A[i] > A[n-len-1+i])yes = 0;

                }
                return yes;
        };
        int lo = 0,lf = n/2;
        int mid;
        while(lo < lf){
                mid = (1+lo + lf)/2;
                if(veri(mid)){
                        lo = mid;
                }else lf = mid-1;
        }
        if(!veri(lo))cout << 0 << ln;
        else cout << lo + 1 << ln;

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
