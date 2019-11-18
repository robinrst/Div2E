#include        "iostream"
#include        "algorithm"
#include		"numeric"
#include        "cstring"
#include        "math.h"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

using namespace std;

#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)3e5+5
#define          pb push_back
#define          mod 1000000007
#define          sz(x) x.size()
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vc vector<char>
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long int
#define          pii pair<int,int>
#define          vs vector<string>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          mst(a,v,n) fo(i,0,n) a[i]=v
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          rev(x) reverse(begin(x),end(x))
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286


inline void printA( int _a[] , int _to, int _from = 0 )
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void printV( vi _a , int _to, int _from = 0)
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
int vis[N];
vpii weight[N];
int dp[N] , dp1[N];

void go()
{
	cin>>n>>m;

	int mx = 0;

	fo(i,0,m)
	{
		int u, v, w;
		cin>>u>>v>>w;

		weight[ w ].pb( { u, v } );
	}

	// sort( all( weight ) );

	fo(i,1,N)
	{
		for( auto j : weight[i] )
		{
			int u = j.f;
			int v = j.sc;

			dp1[v] = max( dp1[v] , dp[u] + 1 );
		}

		for( auto j : weight[i] )
		{
			int v = j.sc;

			dp[v] = max( dp[v] , dp1[v] );
		}	
	}

	int ans = 0;

	fo(i,1,n+1)
	{
		// db(dp[i]);
		ans = max( ans, dp[i] );
	}

	cout << ans << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}