#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using iii = pair<int,ii>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb emplace_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 2e5 + 3;
const int ga = 1e5+1;

vector<int> ft(ga, 0);

void update(int pos,int add){ //sumo a[pos] += add
        for(++pos;pos<ga;pos+=pos&-pos){
                ft[pos] += add ;
        }
}
int sum(int pos){ //retorna la suma de a[0:pos]
        int ans=0;
        for(++pos;pos>0;pos&=pos-1) ans+=ft[pos];
        return ans;
}

void so(int test){
        int n,k;
        cin >> n >> k;
        f(i,1,n+1){
                update(i,1);
        }

        vi ans;

        int len = n;
        int fi = k;

        while(len){
                int lo = 1, lf = n;
                int mid;
                fi = fi % len;
                while(lo < lf){
                        mid = (lo+lf)/2;
                        if(sum(mid) > fi)lf = mid;
                        else lo = mid+1;
                }
                ans.pb(lo);
                update(lo,-1);
                fi += k;
                len--;
        }
        for(auto x : ans){
                cout  << x << ' ';
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
