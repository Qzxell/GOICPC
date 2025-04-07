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


vector<string> rec(int nn,char ga,int l , int r){
        if(nn = 0){
                string owo;
                owo += ga;
                vector<string> r = {owo};
                return r;
        }
        int mi = (1<<(nn-1));
        int cu_x,cu_y;
        if(l > mi){
                cu_x = 2;
                l -= mi;
        }
        else cu_x = 1;
        if(r > mi){
                cu_y = 2;
                r -= mi;
        }
        else cu_y = 1;
        char wasa = ((nn&1)? 'a' : 'm');
        //vector<string> com = rec(nn-1,wasa,mi,mi);
        vector<string> aux(mi,string(mi,' '));
        //vector<string> lost = (nn-1,ga,l,r);
        vector<string> lost(mi,string(mi, '-'));
        vector<string> ret(nn,string(nn,' '));

        auto ful = [&](int ind_x,int ind_y){
                f(i,0,mi){
                        f(j,0,mi){
                                ret[ind_x + i][ind_y +j] = lost[i][j];
                        }
                }
        };
        auto rotate = [&](){
                f(i,0,mi){
                        f(j,0,mi){
                                aux[mi-j][i] = lost[i][j];
                        }
                }
                swap(aux,lost);
        };
        ful(0,0);
        rotate();
        ful(mi,0);
        rotate();
        ful(0,mi);
        rotate();
        ful(mi,mi);
        return ret;
}


void so(int test){
        int n,l,r;	
        cin >> n >> l >> r;
        int po = 0;
        f(i,0,14){
                if((1<<i) == n)po = i;
        }
        vector<string> ans = rec(po,'.',l,r);

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
