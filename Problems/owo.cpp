#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n = 10;
    vi v(n);
    f(i,0,n)v[i] = i+1;
    do{
      int wa1 = v[1] + v[2] + v[3] + v[0] ;
      int wa2 = v[9] + v[5] + v[7] + v[0] ;
      int wa3 = v[8] + v[1] + v[7] + v[6] ;
      int wa4 = v[8] + v[2] + v[4] + v[9] ;
      int wa5 = v[6] + v[5] + v[3] + v[4] ;
      if (wa1 == wa2 and wa3 == wa4 and wa4 == wa5 and wa1 == wa3){
        cout <<  '\t' << wa1  << ln;
        f(i,0,n)cout << v[i] << ' ';
        cout << ln;
      }
    }while(next_permutation(all(v)));
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
