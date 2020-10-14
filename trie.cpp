#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(ll x[], ll n)
{
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

int id(char c)
{
	return (int)c - int('a');
}
const int numChildren = 20;
struct node
{
	char data;
	node *children[20];
	int endingHere;
	node(char c)
	{
		data = c;
		endingHere = 0;
		for(int i = 0; i < 20; i++)
			children[i] = NULL;
	}
};
void insert(node *root, string s)
{
	node *temp = root;
	int index;
	for(int i = 0; i < s.length(); i++)
	{
		index = id(s[i]);
		if(temp->children[index]==NULL)
		{
			temp->children[index] = new node(s[i]);
		}
		temp = temp->children[index];
		if(i==s.length()-1)
			temp->endingHere++ ;
	}
}

bool search(node *root, string s)
{
	node *temp = root;
	int index, count = 0;
	for(int i = 0; i < s.length(); i++)
	{
		index = id(s[i]);
		if(temp->children[index] != NULL)
		{
			count++;
			temp = temp->children[index];
		}
		else
			return false;
		if(count==s.length())
			break;
	}
	if(temp->endingHere > 0)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	// node *root = new node('\0');
	// insert(root, binary(9));
	// insert(root, binary(6));
	node *root = new node('\0');
	insert(root, "ab");
	insert(root, "cd");
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		int j = id(c);
		
	}

	
	return 0;
}
