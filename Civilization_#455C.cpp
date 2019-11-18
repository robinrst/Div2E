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
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long 
#define          pii pair<int,int>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q,mx,newRoot;
string s;
vi adj[N];
int vis[N],par[N],diameter[N],sz[N];

int getCombinedDia( int i, int j )
{
	int dia = 0;

	dia += ( diameter[i] + 1)/2;
	dia += ( diameter[j] + 1)/2;

	return dia + 1;
}

void build()
{
	fo(i,1,n+1) par[i] = i , sz[i] = 1,diameter[i] = 0;
}
 
int Root(int i)
{
	while( par[i] != i)
	{
		par[i] = par[ par[i] ];
		i = par[i];
	}
 
	return i;
}
 
void Union(int x, int y) // x is parent of y
{
	int xPar = Root(x);
	int yPar = Root(y);
 
	if( yPar == xPar ) return;
 
	if( sz[ xPar ] < sz[ yPar ]) 
		swap(sz[ xPar ] , sz[ yPar ]);
 
	diameter[xPar] = max( { diameter[xPar] , diameter[yPar] , getCombinedDia(xPar,yPar) } );
	par[ yPar ] = xPar;
	sz[ xPar ] += sz[ yPar ];

}

void dfs(int i , int  p, int dep )
{
	if( mx < dep )
	{
		mx = dep;
		newRoot = i;
	}

	for( auto j : adj[i] )
	{
		if( j != p )
		{
			dfs(j,i,dep+1);
		}
	}
}

int getDiameter( int root )
{
	mx = -1;
	dfs(root,0,0);
	mx = -1;
	// db(newRoot);
	dfs(newRoot,0,0);

	return mx;
}


void go()
{
	cin>>n>>m>>q;

	build();

	fo(i,0,m)
	{
		int u, v;
		cin>>u>>v;

		adj[u].pb(v);
		adj[v].pb(u);

		Union(u,v);
	}

	fo(i,1,n+1)
	{
		int root = Root(i);
		if( !vis[root] )
		{
			// db(root);
			vis[root] = 1;
			diameter[root] = getDiameter(root);
			// db(diameter[root]);
		}
	}

	while( q-- )
	{
		int choice,xx,yy;
		cin>>choice;

		if( choice == 1 )
		{
			cin>>xx;
			cout << diameter[ Root(xx) ] << endl;
		}
		else
		{
			cin>>xx>>yy;
			Union(xx,yy);
		}
	}
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}