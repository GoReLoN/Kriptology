#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int gcd(int, int);
string& UpCase(string&);
string& DelDouble(string&);

int main()
{
	string alpha;
	ifstream f_alpha("f_alpha.txt");
	getline(f_alpha, alpha);
	cout << DelDouble(UpCase(alpha)) << endl << alpha;
	return 0;
}

int gcd(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a < b)
			swap(a, b);
		a %= b;
	}
	return (a + b);
}

string& UpCase(string& str)
{
	for (int i = 0; i < str.size(); ++i)
		if (str[i] >= 97 && str[i] < 123)
			str[i] -= 32;
	return str;
}

string& DelDouble(string& str)
{
	string result = "";
	for (int i = 0; i < str.size(); ++i)
	{
		bool found = false;
		for (int j=0;j<result.size();++j)
			if (str[i] == result[j])
			{
				found = true;
				break;
			}
		if (!found)
			result += str[i];
	}
	str = result;
	return str;
}