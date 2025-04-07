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


int po;
vector<string> rec(int nn,char ga,int l , int r){
        if(nn == 0){
                string owo;
                owo += ga;
                vector<string> r = {owo};
                return r;
        }
        int mi = (1<<(nn-1));
        int len = (1<<nn);
        int cu_x,cu_y;

        if(l > mi){
                cu_x = 2;
                l -= mi;
        } else cu_x = 1;

        if(r > mi){
                cu_y = 2;
                r -= mi;
        } else cu_y = 1;

        char wasa = 'A' + po - nn;
        vector<string> com = rec(nn-1,ga,l,r);
        vector<string> lost = rec(nn-1,wasa,mi,mi);
        vector<string> aux(mi,string(mi,' '));
        //vector<string> lost(mi,string(mi, '-'));

        vector<string> ret(len,string(len,' '));

        auto ful = [&](int ind_x,int ind_y){
                f(i,0,mi){
                        f(j,0,mi){
                                ret[ind_x + i][ind_y +j] = lost[i][j];
                        }
                }
        };
        auto ful1 = [&](int ind_x,int ind_y){
                f(i,0,mi){
                        f(j,0,mi){
                                ret[ind_x + i][ind_y +j] = com[i][j];
                        }
                }
        };
        auto rotate = [&](){
                f(i,0,mi){
                        f(j,0,mi){
                                aux[mi-j-1][i] = lost[i][j];
                        }
                }
                swap(aux,lost);
        };
        auto aum1 = [&](int u){
                f(i,0,mi){
                        f(j,0,mi){
                               if(com[i][j] !='.')com[i][j] += u;
                        }
                }
        };
        auto aum = [&](int u){
                f(i,0,mi){
                        f(j,0,mi){
                                lost[i][j] += u;
                        }
                }
        };
        ful(0,0);
        char yu = lost[mi-1][mi-1] ;
        rotate();
        aum(1);

        ful(mi,0);
        rotate();
        aum(-1);

        ful(mi,mi);
        rotate();
        aum(1);

        ful(0,mi);
        ret[mi-1][mi-1] = ret[mi][mi] = ret[mi-1][mi] = ret[mi][mi-1] = yu;

        ful1(mi*(cu_x-1),mi*(cu_y-1));
        return ret;
}


void so(int test){
        int n,l,r;	
        cin >> n >> l >> r;
        po = 0;
        f(i,0,14){
                if((1<<i) == n)po = i;
        }
        vector<string> ans = rec(po,'.',l,r);
        f(i,0,n)cout << ans[i] << ln;


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
