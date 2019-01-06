/***********************
*   Jay Prakash Mahto  *
*       JVJplus        *
************************/

#include<bits/stdc++.h>
using namespace std;

#define For(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vi vector<int> 
#define REMAX(a,b) a=max(a,b) 
#define N 200005
#define MOD 1000000007 //check it 
#define dbg(x) cerr<<#x<<" "<<x<<endl;

//make ipow and ms0
//think of segtree / sqrt decom.

int n,bct_sz;
int arr[N];
int lazy[N];
int maxBucket[N];


void init(){
	bct_sz=sqrt(n);
	For(i,n){
		REMAX(maxBucket[i/bct_sz],arr[i]);
	}
}

void update(int l,int r,int value){
	int b1=l/bct_sz;
	int b2=r/bct_sz;

	if(b1==b2){
		FOR(i,l,r)
			arr[i]+=value;

		int mx=-1;
		FOR(i,b1*bct_sz,(b1+1)*bct_sz-1)
			REMAX(mx,arr[i]);
		maxBucket[b1]=mx;
		return;
	}

	//starting
	while(l!=0 && l%bct_sz!=0){
		arr[l]+=value;
		l++;
	}
	int mx=-1;
	FOR(i,b1*bct_sz,(b1+1)*bct_sz-1)
		REMAX(mx,arr[i]);
	maxBucket[b1]=mx;

	//middle
	while(l<=r){
		lazy[l/bct_sz]+=value;
		l+=bct_sz;
	}

	//ends
	mx=-1;
	while(l<=r) {
		arr[l]+=value;
		REMAX(mx,arr[l]);
	    l++;
	}

	while(l<b2*bct_sz){
		REMAX(mx,arr[l]);
		l++;
	}
	maxBucket[b2]=mx;	
}

int queryMAX(int l,int r){
	int mx = -1;
	int len=bct_sz;
	int c_l = l / len,   c_r = r / len;
	if (c_l == c_r)
	    for (int i=l; i<=r; ++i)
	        REMAX(mx,arr[i]+lazy[c_l]);
	else {
	    for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
	        REMAX(mx,arr[i]+lazy[i/bct_sz]);
	    for (int i=c_l+1; i<=c_r-1; ++i)
	        REMAX(mx,maxBucket[i]+lazy[i]);
	    for (int i=c_r*len; i<=r; ++i)
	        REMAX(mx,arr[i]+lazy[i/bct_sz]);	    
	}

	return mx;
}

void printStatus(){
	For(i,n){
		cerr<<arr[i]+lazy[i/bct_sz]<<" ";
	}
	cerr<<endl;
}

void solve(){
	cin>>n;
	For(i,n){
		cin>>arr[i];
	}        
	init();

	int mx=0;
	For(i,n){
		arr[i]+=(i+1);
		REMAX(mx,arr[i]);
	}
	cout<<mx<<" ";

	init();

	for(int i=n-1;i>0;i--){
		//reduce ith by N
		update(i,i,-n);
		//update all by 1
		update(0,n-1,+1);
		cout<<queryMAX(0,n-1)<<" ";

		// printStatus();
	}

}


int main(){

         /*

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("debug_log.txt","w",stderr);
    
          // */

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    // int t; cin>>t; while(t--)
    { 
        solve();   
    }

}