/*
 *  Author: shpsi
 *  Time: 2019-08-22 00:15:03  
 **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
#define Accepted 0
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fout(S,x)            cout<<fixed<<setprecision(x)<<(S)<<endl
#define pb push_back
#define mp make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define PI 3.141592653589793238462643383279502884197169399375105820974944
#define T() ll t;cin>>t;while(t--)
#define mem(input,b) memset(input,b,sizeof(input))
#define all(s) s.begin(),s.end()
#define lbi(input, val) (lower_bound(all(input), val) - input.begin())
#define ubi(input, val) (upper_bound(all(input), val) - input.begin())
#define ff first
#define ss second
#define pc(x) __builtin_popcount(x)
#define ln(x)                    (ll(log2(LD(x))))
#define dig(x)                   (ll(log10(LD(x)))+1)
#define ceil(input,b)                (ll(ceil(LD(input)/LD(b))))
#define etm cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n'
#define fread(input) freopen("input","r",stdin)
#define fwrite(b) freopen("b","w",stdout)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
ll MODpow(ll input,ll n,ll difference){ll res=1,y=input;while(n>0){if(n&1)res=(res*y)%difference;y=(y*y)%difference;n/=2;}return res%difference;}
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T input, T b) { return (!(input < b) ? input : b); }
template< class T > T _min(T input, T b) { return (input < b ? input : b); }
template< class T > T gcd(T input, T b) { return (b != 0 ? gcd<T>(b, input%b) : input); }
template< class T > T lcm(T input, T b) { return (input / gcd<T>(input, b) * b); }
inline int fi(){int n=0;int ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9')n=(n<<3)+(n<<1)+ch-'0',ch=getchar();return n;}
inline void fo(int input){char snum[20];int iterator=0;do{snum[iterator++]=input%10+48;input=input/10;}while(input!=0);iterator=iterator-1;while(iterator>=0)putchar(snum[iterator--]);putchar('\n');}
int MOD=1e9+7, INF=1e9;
ll INFLL =1e18;
llu INFLLU=18446744073709551615ULL;
ld EPS = 1e-12;
inline int inv(int input, int p = MOD) {return MODpow(input, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline void addMOD(int& input, int val, int p = MOD) {if ((input = (input + val)) >= p) input -= p;}
inline void subMOD(int& input, int val, int p = MOD) {if ((input = (input - val)) < 0) input += p;}
const int maxn = 1e5+10;
int main(){
    fastio;
    int m;
    cin >>m;
    int fact[maxn];
    int inv[maxn];
    int tmp[maxn];
    fact[0] = fact[1] = tmp[1] = inv[0] = inv[1] = 1;
    FOR(i,2,m){
        fact[i] = fact[i-1]*1ll*i%MOD;
        tmp[i] = (MOD-MOD/i)*1ll*tmp[MOD%i]%MOD;
        inv[i] = tmp[i]*1ll*inv[i-1]%MOD;
    }
    ll ans = 0;
    int p[maxn];
    for(int i = m; i >= 2; i--) {
        int k = m/i;
        for(int j = 1; j <= k; j++) {
            p[i] = ((k*1ll*(2*m-k)%MOD)*tmp[m]%MOD)*tmp[m-k]%MOD;
        }
        for(int j = 2; j*i <= m; j++) {
            if(j & 1) p[i] = (p[i]-p[i*j]+MOD)%MOD;
            else p[i] = (p[i]-p[i*j]+MOD)%MOD;
        }
        ans += p[i];

    }
    ans = (ans+tmp[m])%MOD;
    cout<<ans<<endl;
    etm;
    return Accepted;
}
