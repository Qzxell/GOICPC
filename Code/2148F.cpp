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
        vector<string> v(n);
        f(i,0,n){
                string s;
                int lon;
                cin >> lon;
                f(i,0,lon){
                        char ki;
                        cin >> ki;
                        s += ki;
                }
                v[i] = s;
        }
        auto comp = [&](string a, string b)->bool{
                f(i,0,min(sz(a),sz(b))){
                        if(a[i] != b[i])return  a[i] < b[i];
                }
                return sz(a) < sz(b);
        };
        sort(all(v),comp);
        int tam = 0;
        int pos = 0;
        f(i,0,n){
                if(sz(v[i]) < tam)continue;
                f(j,pos,sz(v[i])){
                        cout << v[i][j] << ' ';
                }
                pos = sz(v[i]) ;
                tam = sz(v[i]);
        }
        cout << ln;


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



