
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
        int pl,ps,hl,hs,e,g,H;
        cin >> pl >> hl >> ps >> hs >> e >> g >> H;
        int li1,li2;
        li1 = H/hl;
        li2 = H/hs;
        int mi = INT_MAX;
        int mi_f = INT_MAX;
        f(i,0,li1+1){
                f(j,0,li2+1){
                        if(i*hl + j*hs >= H){
                                int pre = i*pl + j*ps;
                                pre += (pre >= g ? 0 : e);
                                if(pre < mi){
                                        mi = pre;
                                }
                        }
                }
        }
        f(i,0,li1+1){
                f(j,0,li2+1){
                        if(i*hl + j*hs >= H){
                                int pre = i*pl + j*ps;
                                if(pre < g){
                                        int dif = g - pre;
                                        int l1,l2;
                                        l1 = (dif+pl-1)/pl;
                                        l2 = (dif+ps-1)/ps;
                                        f(k,0,l1+1) f(m,0,l2+1){
                                                int aux = pre + k*pl + m*ps;
                                                if(aux < g)continue;
                                                if(aux < mi_f){
                                                        mi_f = aux;
                                                }
                                        }
                                }
                        }
                }
        }
        if(mi < mi_f){
                f(i,0,li1+1){
                        f(j,0,li2+1){
                                if(i*hl + j*hs >= H){
                                        int pre = i*pl + j*ps;
                                        pre += (pre >= g ? 0 : e);
                                        if(pre == mi){
                                                cout << pre << ' ' << i << ' ' << j ;
                                                return;
                                        }
                                }
                        }
                }
        }
        f(i,0,li1+1){
                f(j,0,li2+1){
                        if(i*hl + j*hs >= H){
                                int pre = i*pl + j*ps;
                                if(pre < g){
                                        int dif = g - pre;
                                        int l1,l2;
                                        l1 = (dif+pl-1)/pl;
                                        l2 = (dif+ps-1)/ps;
                                        f(k,0,l1+1) f(m,0,l2+1){
                                                int aux = pre + k*pl + m*ps;
                                                if(aux < g)continue;
                                                if(aux == mi_f){
                                                        cout << aux << ' ' << i+k << ' ' << j+m << ln;
                                                        return;
                                                }
                                        }
                                }
                        }
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
