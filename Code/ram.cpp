#include <bits/stdc++.h>

using namespace std;


namespace std 
{
    #define Geo std
    #define int long long
    typedef long long C ;
    typedef complex<C> P ;
    #define X real() 
    #define Y imag() 
    using ld = long double ;

    #define f(i, a, b) for (int i = a; i < b; ++i)
    #define f_(i, a, b) for (int i = a; i > b; --i)

    template<> struct hash<pair<long long, long long>> 
    {
        size_t operator()(const pair<long long, long long>& p) const {
            auto hash1 = hash<long long>{}(p.first);
            auto hash2 = hash<long long>{}(p.second);
            return hash1 ^ (hash2 << 1); // Simple XOR hashing
        }
    };

    template<> struct hash<vector<string>>
    {
        size_t operator()(const vector<string>& v) const {
            size_t seed = v.size();
            for (const string& i : v) {
                seed ^= hash<string>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    istream& operator >> (istream & cin , vector<int> & a)
    {
        for(auto &i: a) cin >> i ; 
        return cin ; 
    }
    istream& operator >> (istream & cin , vector<pair<int,int> > & a)
    {
        for(auto &i: a) cin >> i.first >> i.second ; 
        return cin ; 
    }
    ostream& operator << (ostream & cout , vector<int> & a)
    {
        for(auto &i: a) cout << i << ' ' ; 
        cout << endl ; return cout ;
    }
    istream& operator >> (istream & cin , vector<vector<int> > & a)
    {
        for(auto &i: a) cin >> i ; 
        return cin ; 
    }
    ostream& operator << (ostream & cout , vector<vector<int> > & a)
    {
        for(auto &i: a) cout << i ; 
        return cout ;
    }

    const int mod = 1e9 + 7 , mod1 = 998244353 ; 
    signed T = 1 ; 
    
}  

class Mint {
private:
    int value;
    const static int mod = 1e9+7;

public:
    Mint(int data = 0) {
        while (data < 0) data += mod * mod;
        value = data % mod;
    }
    Mint operator+(Mint a) { return Mint(value + a.value); }
    Mint operator-(Mint a) { return Mint(value - a.value + mod); }
    Mint operator*(Mint a) { return Mint(value * a.value); }
    Mint& operator*=(Mint a) {
        value = (value * a.value) % mod;
        return *this;
    }
    Mint& operator+=(Mint a) {
        value = (value + a.value) % mod;
        return *this;
    }
    Mint& operator-=(Mint a) {
        value = (value - a.value + mod) % mod;
        return *this;
    }
    static Mint exp(Mint a, int p) {
        Mint res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    Mint inv() {
        assert(gcd(value, mod) == 1);
        return exp(*this, mod - 2);
    }
    Mint operator/(Mint a) { return *this * a.inv(); }
    Mint& operator/=(Mint a) { return *this *= a.inv(); }
    bool operator!=(Mint b) { return value != b.value; }
    bool operator==(Mint b) { return value == b.value; }
    bool operator>(Mint b) { return value > b.value; }
    bool operator<(Mint b) { return value < b.value; }
    bool operator>=(Mint b) { return value >= b.value; }
    bool operator<=(Mint b) { return value <= b.value; }
    friend ostream& operator<<(ostream& os, Mint a) {
        os << a.value;
        return os;
    }
    friend istream& operator>>(istream& is, Mint& a) {
        is >> a.value;
        a.value %= mod;
        if (a.value < 0) a.value += mod;
        return is;
    }
};


#define debug(x)
#define debug1(x, n)


void solution();  unordered_map<vector<string> , int> store ; 

signed main() 
{

#ifndef ONLINE_JUDGE
    freopen("_debug.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while (T-- > 0) solution();

    return 0;
} 

class SEG
{
    private:
         int n;
         vector<int> x,tree;
         const static int Default = 0;
         static int operation(int a,int b)
         {
             return (a+b) ;
         }
     
    public:
         
         SEG(vector<int> & y) : x{y}
         {
             while((x.size() - 2) & (x.size() - 1)) x.push_back(0);
             n = x.size()-1;  tree.resize(2*n);
             
             for(int z = 0; z < n; z++)
             {
                 tree[n+z] = x[z+1];
             }
             for(int z = n-1; z > 0; z--)
             {
                 tree[z] = operation(tree[2*z],tree[2*z+1]);
             } //debug(tree) debug((int)x.size())
             
         }
         
         int size()
         {
             return n;
         }
         int query(int a,int b)
         {
             a += n-1; b += n-1;
             int s = Default;
             while(a <= b)
             {
                 if(a%2 == 1) s = operation(s,tree[a++]);
                 if(b%2 == 0) s = operation(s,tree[b--]);
                 a /= 2; b /= 2;
             } //debug(tree)
             return s;
         }
        void update(int k,int u)
         {
             if(k > n) return;
             k += n-1;
             tree[k] += u;
             for(k /= 2; k >= 1; k /= 2)
             {
                 tree[k] = operation(tree[2*k],tree[2*k+1]);
             } //debug(tree)

         }
    
}; 

namespace Geo  {
inline int operator ^ (P a , P b)
{
    
     return a.X*b.Y - b.X*a.Y ;
}

inline istream& operator >> (istream& cin , P &a)
{
    C r,i ; cin >> r >> i ; 
    a = complex(r,i) ;
    return cin ;
}

inline auto location = [](P a , P b , P p) -> int
{     
     return ((p-a)^(p-b)) ;
} ;

inline auto order = [](const P&a , const P&b) -> bool
{
   if(a.X == b.X) return a.Y < b.Y ; 
   else return a.X < b.X ;
} ;

auto area_2 = [](vector<P> &x , auto && area_2) -> int
{
    if(x.size() < 3) return 0 ;
    int n = x.size() ;

    if(n == 3)  return location(x[0],x[2],x[1]) ;
    
    int sign = location(x[n-3],x[n-1],x[n-2])*location(x[n-3],x[n-1],x[n-2]) ;

    vector<P> y = {x[n-3],x[n-2],x[n-1]} ; 
    int val = area_2(y,area_2)  ; P store = x[n-2] ; 
    swap(x[n-2],x[n-1]) ; x.pop_back() ;

    int val1 =  area_2(x,area_2) + val ;  
    x.push_back(store) ; swap(x[n-2],x[n-1]) ; 
     return val1 ;
} ;
auto area_s = [](vector<P> &p) -> int
{
   int ret = 0 , n = p.size(); 
   f(i,0,n) ret += p[i].X*p[(i+1)%n].Y - p[(i+1)%n].X*p[i].Y ;
   return abs(ret) ;
} ;

inline auto dist = [](P s1 , P s2 , P p) -> ld
{
     return (ld)location(s1,s2,p)/(ld)norm(s2-s1) ;
} ;

inline auto sign = [](int a) -> int
{
    if(a > 0) return 1 ; 
    else if(a < 0) return -1 ; 
    else return 0 ;
} ;

auto intersect = [](vector<P> x) -> bool
{
   int val[4] ; 

   f(i,0,4)  val[i] = sign(location(x[(i&2)],x[(i&2)+1],x[2-2*(i&2)+i])) ;
   
   f(i,0,2)
   {
      f(j,0,2) if(x[i] == x[j+2]) { return 1;}
   }
 
   if(val[0] == 0 && val[1] == 0)
   { debug("yes") debug(x)
      auto y = x ; 
      sort(x.begin(),x.end(),order);
     
      if(x[0] == y[0] || x[0] == y[1])
      {
         if(x[1] == y[0] || x[1] == y[1]) return 0 ;
         else return 1 ;
      }
      else if(x[1] == y[2] || x[1] == y[3]) return 0 ;
      else return 1 ;
      
   } 
 
   if(val[0]*val[1] <= 0 && val[2]*val[3] <= 0) { debug("lsdjfls") ;return 1 ; }
   else return 0 ;

} ;

inline auto seg_ct = [](P a , P b) -> int
{
     int arg1 = abs(a.X-b.X) , arg2 = abs(a.Y-b.Y) ;
     return gcd(arg1,arg2) + 1 ;
} ;

inline auto comp = [](bool choice) 
{
    return [choice](const pair<int,int> &a,const pair<int,int> &b) 
    {
    return (!choice ? (a.first < b.first || (a.first == b.first && a.second < b.second)) 
    :(a.second < b.second || (a.second == b.second && a.first < b.first))
    ) ;
    
    } ;
} ;

// pick's theorom -> area = a + b/2 - 1
}

void solution()
{
  int n ; cin >> n ; string s ; cin >> s ; 

  string S ; char prev = '1' ; int ct = 0 ; 
  S = s ; 

  n = S.size() ; vector<int> a ; debug(S)
  f(i,0,n) if(S[i] == '0') a.push_back(i) ; 
  int m = a.size() ; debug(a) debug("yes")
  if(a.empty()) {cout << "YES\n" ; return ; }
  vector<bool> dp[2] ; f(i,0,2)dp[i].assign(m,0) ;
  debug(dp[0]) debug(dp[1])
  
  if(a[m-1] == n-1) dp[1][m-1] = 1 ;
  dp[0][m-1] = 1 ; // 1 -> R , 0 -> L
  f_(i,m-2,-1)
  {
    int dis = a[i+1] - a[i] ;
     dp[1][i] = (dis == 2 ? dp[0][i+1] : (dis == 1) && (dp[0][i+1] || dp[1][i+1])) ;
     dp[0][i] = (dp[1][i+1] || (dis == 1 && dp[0][i+1])) ;
  }
  if(dp[0][0]) dp[0][0] = (a[0] == 0) ;
  debug1(dp,2)

  if(dp[0][0] || dp[1][0]) cout << "YES\n" ; 
  else cout << "NO\n" ;

  
    
}
