#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class UFDS
{
private:
	vector<ll> parent, rank, size_set;
	ll disjoint_set_count;

public:
	UFDS(ll sz)
	{
		rank.assign(sz, 0);
		parent.assign(sz, 0);
		size_set.assign(sz, 1);
		disjoint_set_count = sz;
		for (ll i = 0; i < sz; i++)
			parent[i] = i;
	}
	ll findSet(ll node)
	{
		return parent[node] == node ? node : (parent[node] = findSet(parent[node]));
	}
	void unionSet(ll node_a, ll node_b)
	{
		ll parent_a = findSet(node_a), parent_b = findSet(node_b);
		if (parent_b == parent_a)
			return;

		disjoint_set_count--;

		if (rank[parent_a] > rank[parent_b])
		{
			parent[parent_b] = parent_a;
			size_set[parent_a] += size_set[parent_b];
		}
		else
		{
			size_set[parent_b] += size_set[parent_a];
			parent[parent_a] = parent_b;
			if (rank[parent_b] == rank[parent_a])
				rank[parent_b]++;
		}
	}
	ll getSizeOfSet(ll node)
	{
		ll parent = findSet(node);
		return size_set[parent];
	}

	ll getDisjointSetCount()
	{
		return disjoint_set_count;
	}
};

int main()
{

#ifdef vanshaj
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	UFDS ufds(6);
	printf("%lld %lld %lld \n", ufds.getDisjointSetCount(), ufds.findSet(3), ufds.getSizeOfSet(5));

	ufds.unionSet(1, 2);
	ufds.unionSet(3, 4);
	ufds.unionSet(3, 5);

	printf("%lld %lld %lld", ufds.getDisjointSetCount(), ufds.findSet(5), ufds.getSizeOfSet(4));
	return 0;
}
