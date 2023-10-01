#include <bits/stdc++.h>
using namespace std;
struct vertex
{
	int string_ends;
	vector<int> next;
	vertex(int k)
	{
		string_ends = 0;
		next.resize(k, -1);
	}
};
struct Trie
{
	int k;
	vector<vertex> nodes;
	Trie(int k)
	{
		this->k = k;
		nodes.push_back(vertex(k));
	}
	void add(string s)
	{
		int curr = 0;
		for (char c : s)
		{
			if (nodes[curr].next[c - 'a'] == -1)
			{
				nodes[curr].next[c - 'a'] = nodes.size();
				nodes.push_back(vertex(k));
			}
			curr = nodes[curr].next[c - 'a'];
		}
		nodes[curr].string_ends++;
	}
	bool search(string s)
	{
		int curr = 0;
		for (char c : s)
		{
			if (nodes[curr].next[c - 'a'] == -1)
			{
				return false;
			}
			curr = nodes[curr].next[c - 'a'];
		}
		return nodes[curr].string_ends > 0;
	}
	bool starts_with(string s)
	{
		int curr = 0;
		for (char c : s)
		{
			if (nodes[curr].next[c - 'a'] == -1)
			{
				return false;
			}
			curr = nodes[curr].next[c - 'a'];
		}
		return true;
	}
	void print(int x, vector<bool> &list, string &s)
	{
		for (int i = 0; i < (int)list.size() - 1; i++)
		{
			if (list[i])
				cout << "    ";
			else
				cout << "|   ";
		}
		if (!list.empty())
			cout << "|--";
		cout << x << " " << x << " " << nodes[x].string_ends << endl;
		int mx = -1;
		for (int i = 0; i < k; i++)
		{
			if (nodes[x].next[i] != -1)
			{
				mx = i;
			}
		}
		list.push_back(false);
		for (int i = 0; i < k; i++)
		{
			if (nodes[x].next[i] != -1)
			{
				s.push_back('a' + i);
				if (i == mx)
					list.back() = true;
				print(nodes[x].next[i], list, s);
				s.pop_back();
			}
		}
		list.pop_back();
		return;
	}
};
int main()
{
	Trie t(26);
	int n;
	cin >> n;
	vector<string> temp;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		temp.push_back(s);
		t.add(s);
	}
	// string temp;
	// vector<bool> temp2;
	// t.print(0,temp2,temp);
}