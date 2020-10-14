// Dread it. Run from it. Destiny arrives all the same.

/**
 *   author:  Blind_is_love
 *   created: 26.07.2019, 16:23
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 4005;
const double PI = 3.1415926;
const double EPS = 1e-5;
const ll INF = 1e18;

template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

#define endl "\n"
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

typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 


int gauss(vector<vector<double> > &a, vector<double> &ans) { // a is n*(m+1) matrix, last column is B, ans returned in ans;
	int n = a.size();
	int m = a[0].size()-1;
	vector<int> where(m,-1);
	for(int row = 0, col = 0; row < n && col < m; ++col) {
		int cur = row;
		for(int i = cur; i < n; ++i){
			if (fabs(a[i][col]) > fabs(a[cur][col])) cur = i; // find maximum value pivot
		}
		if (fabs(a[cur][col]) < EPS) continue; // entire column in 0;
		for(int i = col; i <= m; ++i){
			swap(a[cur][i], a[row][i]);
		}
		where[col] = row;
		
		double temp = a[row][col];

		for(int i = col; i <= m; ++i){
			a[row][i] /= temp;
		}

		for(int i = 0; i < n; ++i){
			if (i == row) continue;
			temp = a[i][col];
			for(int j = col; j <= m; ++j){
				a[i][j] -= (temp*a[row][j]);
			}
		}
		++row;
	}
	
	ans.assign(m,0);
	for(int i = 0; i < m; ++i){
		if (where[i] == -1) continue;
		ans[i] = a[where[i]][m];
	}

	for(int i = 0; i < n; ++i){
		double sum = 0;
		for(int j = 0; j < m; ++j){
			sum += (ans[j]*a[i][j]);
		}
		if (fabs(sum - a[i][m]) > EPS) return 0;
	}
	for(int i = 0; i < m; ++i){
		if (where[i] == -1) return INF;
	}
	return 1;
}


int power(int a, int b){
	if (b == 0) return 1;
	int temp = power(a, b>>1);
	if (b&1) return (((temp*temp)%mod)*a)%mod;
	return (temp*temp)%mod;
}

int mod_gauss(vector<vector<int> > &a, vector<int> ans){
	int n = a.size();
	int m = a[0].size()-1;
	int row = 0,col = 0;
	vector<int> where(m,-1);
	for(; col < m && row < n; ++col){
		int cur = row;
		for(int i = row; i < n; ++i) cur = (fabs(a[i][col]) > fabs(a[cur][col])) ? i : cur
			;
		if (fabs(a[cur][col]) == 0) continue;
		for(int i = col; i <= m; ++i) swap(a[row][i], a[cur][i])
			;
		cur = row;
		where[col] = row;
		int temp = power(a[row][col], mod-2);
		for(int i = col; i <= m; ++i) {
			a[row][i] *= temp;
			a[row][i] %= mod;
		}
		for(int i = 0; i < n; ++i){
			if (i == row) continue;
			temp = a[i][col];
			for(int j = col; j <= m; ++j){
				a[i][j] -= ((temp*a[row][j])%mod);
				a[i][j] += mod;
				a[i][j] %= mod;
			}
		}
		++row;
	}

	ans.assign(m,0);
	for(int i = 0; i < m; ++i){
		if (where[i] == -1) continue;
		ans[i] = a[where[i]][m];
	}

	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = 0; j < m; ++j){
			sum += ((ans[j]*a[i][j])%mod);
			sum %= mod;
		}
		if (fabs(sum - a[i][m]) > 0) return 0;
	}
	for(int i = 0; i < m; ++i){
		if (where[i] == -1) return INF;
	}
	return 1;
}


signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	clock_t t1, t2;
	t1 = clock();
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(long double)CLOCKS_PER_SEC << endl;
	return 0;
}
