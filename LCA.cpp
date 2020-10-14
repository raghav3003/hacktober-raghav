// Dread it. Run from it. Destiny arrives all the same.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 4005;
const double PI = 3.1415926;

#define end "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
#define int ll

vll adj[MAX]; // graph
int dist[MAX];
vector<pll> euler; // storees the euler tour
pii times[MAX]; // stores the first(fi) and last(se) time of every node 
int counter; // must be initialised to 0
pii seg[16*MAX];

void dfs(int s, int p)
{
	times[s].fi = counter;
	euler.pb(mp(dist[s],s));
	bool flag = 0;
	for(int x : adj[s]){
		if (x == p) continue;
		counter++;
		dist[x] = dist[s]+1;
		dfs(x,s);
		flag = 1;
		euler.pb(mp(dist[s],s));
		counter++;
	}
	times[s].se = counter;
}

// 0 based euler, 1 based seg
void build(ll v, ll L, ll R)
{
	if (L == R)
		seg[v] = euler[L];
	else {
		ll mid = (L+R)/2;
		build(2*v, L, mid);
		build(2*v + 1, mid + 1, R);
		seg[v] = min(seg[2*v], seg[2*v + 1]);
	}
}

pii lca(ll v, ll L, ll R, ll x, ll y)
{
	if (y < L || x > R)
		return mp(1e18,1e18);
	else if (x <= L && R <= y)
		return seg[v];
	else {
		ll mid = (L+R)/2;
		return min(lca(2*v,L,mid,x,y), lca(2*v + 1,mid+1,R,x,y));
	}
}


signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	return 0;
}
