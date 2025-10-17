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
#define point complex<long long>

void so(int test){
        int n;
        cin >> n;
        vi v(n);
        f(i,0,n)cin >> v[i];
        sort(rall(v));
        int a = -1;
        int ind = -1;
        f(i,0,n){
                if(i+1 < n and v[i] == v[i+1]){
                        a = v[i];
                        ind = i;
                        break;
                }
        }
        int last = -1;
        f(i,0,n){
                if(i == ind){
                        i++;
                        continue;
                }
                if(last == -1){
                        last = v[i];
                        continue;
                }
                if(a != -1 and last - v[i] < 2*a){
                        cout << a << ' ' << a << ' ' << last << ' ' << v[i] <<ln;
                        return;
                }
                last = v[i];
        }
        cout << -1 << ln;
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



