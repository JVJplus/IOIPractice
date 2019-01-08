/***********************
*   Jay Prakash Mahto  *
*       JVJplus        *
************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long int                  ll; 
typedef pair<int,int>                  pii;
#define fi                             first
#define se                             second
#define INF                            0x3f3f3f3f
#define MOD                            1000000007
#define For(i,b)                       for(int i=0;i<b;i++)
#define FoR(i,a,b)                     for(int i=a;i>=b;i--)
#define For1(i,b)                      for(int i=1;i<=b;i++)
#define FOR(i,a,b)                     for(int i=a;i<=b;i++)
#define MS0(X)                         memset((X), 0, sizeof((X)))
#define MS1(X)                         memset((X), -1, sizeof((X)))
#define REMAX(a,b)                     (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b)                     (a)=min((a),(b));

#define fast_io                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  srand(time(NULL));
#define sublimeProblem                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("debug_log.txt", "w", stderr);

#define N 100005
int n,r,c,a,b;

set<pii> g,visited;

pii dfs(pii u){
    if(visited.count(u) || g.count(u)==0 ||u.fi<1||u.se<1||u.fi>r||u.se>c)
        return {0,0};

    visited.insert(u);

    int cc=1,adj=0;
    adj+=g.count({u.fi,u.se+1});
    adj+=g.count({u.fi,u.se-1});
    adj+=g.count({u.fi+1,u.se});
    adj+=g.count({u.fi-1,u.se});

    pii t;
    
    t=dfs({u.fi,u.se+1});
    cc+=t.fi; adj+=t.se;

    t=dfs({u.fi,u.se-1});
    cc+=t.fi; adj+=t.se;

    t=dfs({u.fi+1,u.se});
    cc+=t.fi; adj+=t.se;

    t=dfs({u.fi-1,u.se});
    cc+=t.fi; adj+=t.se;

    return {cc,adj};
}

void solve(){
    cin>>r>>c>>n;
    For(i,n){
        cin>>a>>b;
        g.insert({a,b});
    }    

    int mx=-1;
    for(auto i:g){
        if(visited.count(i))
            continue;
        pii returnValue=dfs(i);
        REMAX(mx,(4*returnValue.fi-returnValue.se));
    }
    cout<<mx;
}

int main(){

    sublimeProblem;
    fast_io;

    // int t; cin>>t; while(t--)
    { 
        solve();   
    }

}