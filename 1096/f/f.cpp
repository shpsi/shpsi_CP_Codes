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
template< class T > T _abs(T n) { return (n < 0 ? -n : n);  }
template< class T > T _max(T input, T b) { return (!(input < b) ? input : b);  }
template< class T > T _min(T input, T b) { return (input < b ? input : b);  }
template< class T > T gcd(T input, T b) { return (b != 0 ? gcd<T>(b, input%b) : input);  }
template< class T > T lcm(T input, T b) { return (input / gcd<T>(input, b) * b);  }
inline int fi(){int n=0;int ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9')n=(n<<3)+(n<<1)+ch-'0',ch=getchar();return n;}
inline void fo(int input){char snum[20];int iterator=0;do{snum[iterator++]=input%10+48;input=input/10;}while(input!=0);iterator=iterator-1;while(iterator>=0)putchar(snum[iterator--]);putchar('\n');}
int  INF=1e9;
ll INFLL =1e18;
llu INFLLU=18446744073709551615ULL;
ld EPS = 1e-12;
const int N = 200 * 1000 + 13;
const int MOD = 998244353;
int n;
int p[N];
bool used[N];
int gt[N];

int add(int a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;

}

int mul(int a, int b){
    return (a * 1ll * b) % MOD;

}

int binpow(int a, int b){
    int res = 1;
    while (b){
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;

    }
    return res;

}
int f[N];

void upd(int x){
    for (int i = x; i < N; i |= i + 1)
        ++f[i];

}

int get(int x){
    int sum = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        sum += f[i];
    return sum;

}
int main() {
    scanf("%d", &n);
    FOR(i,0, n-1){
        scanf("%d", &p[i]);
        if (p[i] != -1)
            used[p[i]] = true;

    }

    int cur = 0;
    for (int i = n; i >= 1; --i){
        gt[i] = cur;
        cur += !used[i];

    }

    int ans = mul(mul(cur, cur - 1), binpow(4, MOD - 2));

    int inv = binpow(cur, MOD - 2);

    int lft = 0;
    FOR(i,0, n-1){
        if (p[i] == -1)
            ++lft;
        else
            ans = add(ans, mul(lft, mul(gt[p[i]], inv)));

    }
    int rgh = 0;
    for (int i = n - 1; i >= 0; --i){
        if (p[i] == -1)
            ++rgh;
        else
            ans = add(ans, mul(rgh, mul(cur - gt[p[i]], inv)));

    }
    int tmp = 0;
    FOR(i,0, n-1) if (p[i] != -1){
        ans = add(ans, tmp - get(p[i]));
        upd(p[i]);
        ++tmp;

    }

    printf("%d\n", ans);
    return 0;

}
