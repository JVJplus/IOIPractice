/***********************
*   Jay Prakash Mahto  *
*       JVJplus        *
************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long int                  ll; 
typedef pair<int,int>                  pii;
typedef pair<ll,ll>                    pll;
typedef vector<int>                    vi; 
typedef vector<bool>                   vb;
#define fi                             first
#define se                             second
#define INF                            0x3f3f3f3f
#define MOD                            20011
#define uset                           unordered_set
#define umap                           unordered_map
#define pq_max                         priority_queue<int>
#define pq_min                         priority_queue<int,vector<int>,greater<int>>
#define pb                             push_back
#define NL                             cout<<endl;
#define EL                             cerr<<endl;
#define For(i,b)                       for(int i=0;i<b;i++)
#define FoR(i,a,b)                     for(int i=a;i>=b;i--)
#define For1(i,b)                      for(int i=1;i<=b;i++)
#define FOR(i,a,b)                     for(int i=a;i<=b;i++)
#define MS0(X)                         memset((X), 0, sizeof((X)))
#define MS1(X)                         memset((X), -1, sizeof((X)))
#define forit(v,c)                    for(auto v:c)
#define whileNE(x)                     while(!x.empty())
#define present(c,x)                   ((c).find(x) != (c).end()) 
#define cntbit                         __builtin_popcountll
#define REMAX(a,b)                     (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b)                     (a)=min((a),(b));
#define sz(a)                          (int)(a.size())

// directions
const int fx[4][2] =                   {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] =                  {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
//exponentiation
ll inline ipow(ll a,ll b,ll m){ll val=1;a%=m;while(b){if(b&01)val=(val*a)%m;b>>=1;a=(a*a)%m;};return val%m;}
ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);};return val;}

#define min3(a,b,c)                    min(a,min(b,c))
#define max3(a,b,c)                    max(a,max(b,c))
#define maxall(v)                      *max_element(all(v))
#define minall(v)                      *min_element(all(v))
#define all(a)                         a.begin(), a.end()

#define display(x)                       cout<<x;
#define display2(x,y)                    cout<<x<<" "<<y;
#define accept_arr                       For(i,N) cin>>arr[i];
#define accept_array(arr,N)              For(i,N) cin>>arr[i];
#define display1d(arr,length)            for(int i=0;i<length;i++) cout<<arr[i]<<" "; cout<<'\n';
#define display1D(arr,start,length)      for(int i=start;i<length;i++) cout<<arr[i]<<" "; cout<<'\n';
#define display2d(arr,n)                 For(i,n){For(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}
#define display2D(arr,m,n)               For(i,m){For(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}
#define gets(n)                          getline(cin,n); cin.ignore();
#define input_array                      cin>>N;For(i,N) cin>>arr[i];
#define input_array1                     cin>>N;FOR(i,1,N) cin>>arr[i];

#define dbg(...) __dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __dbg(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << std::endl;}
template <typename Arg1, typename... Args>
void __dbg(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__dbg(comma+1, args...);}

#define fast_io                        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sublimeProblem                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("debug_log.txt", "w", stderr);
#define TCase                          int ___T, case_n = 1; cin>>___T; while (___T-- > 0)


//can be ignored from here

#define iNF                            -1061109567
#define PI                             3.1415926535897932384626
#define pB                             pop_back()

//Sort
#define sortva(v)                      sort(all(v))
#define sortvd(v)                      sort(v.begin(),v.end(),greater<int>());
#define sortaa(a,n)                    sort(a,a+n)
#define sortad(a,n)                    sort(a,a+n),reverse(a,a+n)  /* Better use sort(a,a+n,greater<int>())  in case of arrays*/

// Some common useful functions
#define maX                            INF
#define miN                            INT_MIN
#define checkbit(n,b)                  ((n >> b) & 1)
#define INDEX(arr,ind)                 (lower_bound(all(arr),ind)-arr.begin())
#define NP(a)                          next_permutation(all(a))

//sieve 
#define LIM1 1000006
bitset<LIM1> isp;
vi primes;
inline void sieve(){isp.set();isp.reset(0);isp.reset(1);for(int i=2;i*i<LIM1;i++){if(isp[i]){for(int j=i*i;j<LIM1;j+=i)isp.reset(j);}}FOR(i,2,LIM1){if(isp[i]){primes.pb(i);}}}

/* totient */
#define LIM4 1000006
int phi[LIM4];
void totient(){FOR(i,1,LIM4)phi[i]=i;forit(it,primes)for(int i=it;i<LIM4;i+=it)phi[i]-=phi[i]/(it);} /* Call sieve() First */

// inverse Modulo
inline ll invmod(ll a, ll b){return (isp[b])?ipow(a,b-2,b):ipow(a,phi[b]-1,b);}

// combinatorics
#define LIM2 1000006
ll fact[LIM2];
inline void Fact(){fact[0]=1;FOR(i,1,LIM2)fact[i]=(i*fact[i-1])%MOD;}
inline ll inv(ll x,ll mod){return ipow(x,mod-2,mod);}
inline ll comb(ll a, ll b){return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}

#define _N 303
int n,N,M,K,arr[_N][_N];
int dp[_N][_N][2][_N];//int;

ll f(int x,int y,int lastMove,int stepsTaken){
    if(stepsTaken>K ||x>=M|| y>=N|| arr[x][y]==0)
        return 0;
    if(x==M-1 && y==N-1)
        return 1;
    int ans=dp[x][y][lastMove][stepsTaken];
    if(ans!=-1)
        return ans;
    ans=0;

    if(lastMove==1){ //hori
        ans+=f(x,y+1,1,stepsTaken+1);
        ans%=MOD;
        ans+=f(x+1,y,0,1);

    }else{ //down
        ans+=f(x+1,y,0,stepsTaken+1);
        ans%=MOD;
        ans+=f(x,y+1,1,1);
    }

    dp[x][y][lastMove][stepsTaken]=ans%MOD;
    return ans%MOD;
}

void solve(){
    MS1(dp);
    cin>>M>>N>>K;
    For(i,M){
        For(j,N)
        cin>>arr[i][j];
    }
    ll a=f(0,1,1,1)%MOD;
    ll b=f(1,0,0,1)%MOD;
    cout << (a+b)%MOD << endl;
}

int main()
{
 //   sublimeProblem;
    fast_io;

    // TCase
    {

      solve();

  }

}