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
        f(i,0,19)
        f(j,0,19)
        f(k,0,19)
        {
                if(i*7 + j *4 + k*3 >= 250 and i >= 10){
                        cout << "CIDA :" << (i>19 ? "impo" : "-") <<  i << ln;
                        cout << "Dibujo :" << (j>19 ? "impo" : "-") << j << ln;
                        cout << "Economia :" << (k>19 ? "impo" : "-") << k << ln;
                        cout << "======================" << ln;
                }
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



