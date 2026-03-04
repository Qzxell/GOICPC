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
        vector<int> v(n);
        for (int &val : v) {
                cin >> val;
        }
        int ans = *max_element(all(v));
        f(i,0,n){
                int punt = i;
                vi aux = v;
                int k_aux = k;
                while(punt > 0 and k_aux){
                        if(aux[punt-1] <= aux[punt]){
                                int sub = min((aux[punt] + 1 - aux[punt-1]),k_aux);
                                aux[punt-1] += sub;
                                k_aux -= sub;
                        }else break;
                        ans = max({ans,aux[punt],aux[punt-1]});
                        punt--;
                }
        }
        cout << ans << ln;
        
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



