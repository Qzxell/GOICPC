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
        int n,k,x;
        cin >> n >> k >> x;
        map<double,int> m;
        f(i,0,n){
                double x;
                cin >> x;
                m[x]++;
        }
        while(k){
                auto it = m.rbegin();
                double num = it->first;
                int cant = it->second;
                if(k >= cant){
                        auto er = m.find(num);
                        m.erase(er);
                        m[num/2] += cant*2;
                        k -= cant;
                }else{
                        m[num] -= k;
                        m[num/2] += k*2;
                        k = 0;
                }
        }
        for(auto it = m.rbegin();it != m.rend(); ++it){
                if(it->second < x){
                        x -= it->second;
                }else{
                        cout << it->first << ln;
                        return;
                }
        }
        assert(false);
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(9) ;

        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



