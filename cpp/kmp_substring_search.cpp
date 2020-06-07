#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{

#ifdef vanshaj
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin >> t;
	while (t--)
	{
		string pattern, main_str;
		cin >> pattern >> main_str;

		// prefix suffix computation
		vector<int> pre_suf(pattern.size(), 0);
		int j = 0;
		for (int i = 1; i < pattern.size(); i++)
		{
			if (pattern[i] == pattern[j])
			{
				pre_suf[i] = j + 1;
				j++;
				continue;
			}
			while (true)
			{
				if (pattern[i] == pattern[j])
				{
					pre_suf[i] = j + 1;
					j++;
					break;
				}
				if (!j)
				{
					break;
				}
				j = pre_suf[j - 1];
			}
		}

		j = 0;
		for (int i = 0; i < main_str.size(); i++)
		{
			if (main_str[i] == pattern[j])
			{
				j++;
			}
			else
			{
				j = pre_suf[j - 1];
			}
			if (j == pattern.size())
			{
				cout << "found at position " << i - pattern.size() + 1 << endl;
				j = pre_suf[j - 1];
			}
		}
	}

	return 0;
}
