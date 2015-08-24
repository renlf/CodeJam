#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

unsigned long long sw(unsigned long long s, unsigned long long size)
{
	unsigned long long ret = 0;
	int count = 0;

	while (--size)
	{
		unsigned short tmp = s & 1;
		if (tmp == 0)
			ret = (1 << count) + ret;
		s = s >> 1;
		count++;
	}
	return ret;
}

unsigned long long rv(unsigned long long s, unsigned long long size)
{
	unsigned long long ret = 0;
	while (size--)
	{
		ret = ret << 1;
		ret += s & 1;
		s = s >> 1;
	}
	return ret;
}

unsigned long long sgoogol2(unsigned long long count, unsigned long long binary, unsigned long long &size)
{
	while (size < count)
	{
		unsigned long long sw_ret = sw(rv(binary, size), size);
		unsigned long long sh_ret = binary << (size + 1);
		binary = sh_ret + sw_ret;
		size = size * 2 + 1;
	}
	return binary;
}

int recur(long long int n, long long int k, bool chan)
{
	if (2 * k - 1 == n)return chan;
	else if (2 * k - 1<n)
	{
		return recur((n - 1) / 2, k, chan);
	}
	else
	{
		return recur((n - 1) / 2, n + 1 - k, !chan);
	}
}

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out", ios::app);
	int t;
	fin >> t;
	long long int k = 0;
	for (int i = 1; i <= 60; i++)
	{
		k = 2 * k + 1;
	}
	for (int i = 1; i <= t; i++)
	{
		long long int n;
		fin >> n;
		fout << "Case #" << i << ": " << recur(k, n, false) << endl;
	}
	return 0;
}
