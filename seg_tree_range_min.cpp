#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(ll x[], ll n)
{
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

ll seg_tree[100000], n;
void build_tree(int i, int j)
{
	if(j - i > 1)
	{
		for(int k = i; k <j; k+=2)
		{
			int parent = k/2;
			seg_tree[parent] = min(seg_tree[k], seg_tree[k+1]);
		}
		build_tree(i/2, j/2);
	}
}

void update(int i, int val)
{
	i += n-1;
	ll old = seg_tree[i];
	seg_tree[i] = val;
	while(i != 1)
	{
		// seg_tree[i/2] += (val-old);
		int p = i/2;
		seg_tree[p] = min(seg_tree[2*p], seg_tree[2*p+1]);
		i = i/2;
	}
}

ll find_min(int i, int j, int cur_low, int cur_up, int cur)
{
	if(i > j)
		return 10000000000;
	if(i==cur_low && j==cur_up)
		return seg_tree[cur];
	int mid = (cur_up+cur_low)/2;
	return min(find_min(i, min(mid, j), cur_low, mid, 2*cur), find_min(max(i, mid+1), j, mid+1, cur_up, 2*cur+1));

}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	// cin >> t;
	t = 1;
	while(t--)
	{
		int l;
		cin >> l;
		float t = log2(l);
		n = pow(2, (int)t + !(t==(int)t));
		int x[l];
		for(int i = 0; i < l; i++)
			cin >> x[i];
		for(int i = 0; i < 500000; i++)
			seg_tree[i] = 10000000000;
		for(int i = n; i < n+l; i++)
			seg_tree[i] = x[i-n];

		build_tree(n, 2*n);
		// print(seg_tree, 2*n);
		int q, low, up;
		cin >> q;
		for(int i = 0; i < q; i++)
		{
			cin >> low >> up;
			cout << find_min(low+1, up+1, 1, n, 1) << endl;
		}
	}
	

	return 0;
}
