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

vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0,};

void so(int test){
        int n,m;
        cin >> n >> m;
        int x1,y1;
        cin >> x1 >> y1 ;
        int x2,y2;
        cin >> x2 >> y2 ;
        auto exi = [&] (int x , int y) -> bool{
                return 0<= x and x < n and 0 <= y and y < m;
        };
        auto pro = [&](int x,int y)->int{
                int co = 0;
                f(i,0,4){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(exi(nx,ny))co++;
                }
                return co;
        };
        cout << min(pro(x1-1,y1-1),pro(x2-1,y2-1)) << ln;
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



