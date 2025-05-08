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

vector<vector<int>> rec(int n) {
        if(n == 0){
                vector<vector<int>> ret = {{0}};
                return ret;
        }
        int len = (1<<n);
        int tot = len*len;
        vector<vector<int>> ret(len,vector<int>(len,0));
        vector<vector<int>> aux = rec(n-1);
        auto fil = [&](int x,int y,int in){
                int tam = len/2;
                for(int i = 0;i < tam;i++){
                        for(int j = 0;j < tam;j++){
                                ret[i+x][j+y] = aux[i][j] + in;
                        }
                }
        };
        int au = (len/2)*(len/2);
        fil(0,len/2,0);
        fil(len/2,len/2,au);
        fil(len/2,0,au+au);
        fil(0,0,au+au+au);
        return ret;
}

int main() {
        vector<vector<int>> ans = rec(2);
        for(auto x : ans){
                for(auto y : x){
                        cout << y << ' ';
                }
                cout << ln;
        }
        return 0;
}
