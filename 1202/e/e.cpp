/*
 *  Author: shpsi
 *  Time: 2019-08-16 06:06:41  
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

struct AhoCorasick {
    static const int N = 26;
    static const char A = 'a';
    struct Node {
        int ch[N];
        int fail, cnt;
        Node() {
            fill(ch, ch+N, 0);
            fail = 0;
            cnt = 0;

        }

    };

    vector<Node> t; //trie
    AhoCorasick() {
        t.reserve(200005);
        t.push_back();

    }

    void add(const string& p) {
        int x = 0;
        for (char c: p) {
            int k = c-A;
            if (!t[x].ch[k]) {
                t[x].ch[k] = t.size();
                t.push_back();

            }
            x = t[x].ch[k];

        }
        t[x].cnt++;

    }
    void build() {
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (t[0].ch[i])
                q.push(t[0].ch[i]);

        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < N; i++) {
                int v = t[u].ch[i];
                if (!v) continue;
                q.push(v);
                int f = t[u].fail;
                while (f && !t[f].ch[i]) {
                    f = t[f].fail;

                }
                f = t[v].fail = t[f].ch[i];
                t[v].cnt += t[f].cnt;

            }

        }

    }
    vector<int> query(const string& s) {
        int n = s.size();
        vector<int> res(n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            int k = s[i] - A;
            while (x && !t[x].ch[k]) {
                x = t[x].fail;

            }
            x = t[x].ch[k];
            res[i] = t[x].cnt;

        }
        return res;

    }

};

void solve() {
    AhoCorasick pre, suf;
    string T; cin >> T;
    int n; cin >> n;
    for (int _ = 0; _ < n; _++) {
        string s; cin >> s;
        pre.add(s);
        reverse(s.begin(), s.end());
        suf.add(s);

    }
    pre.build(); suf.build();
    auto f = pre.query(T);
    reverse(T.begin(), T.end());
    auto g = suf.query(T);
    reverse(g.begin(), g.end());
    long long res = 0;
    for (int i = 0; i < (int)T.size()-1; i++) {
        res += (long long) f[i] * g[i+1];

    }
    cout << res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;

}
