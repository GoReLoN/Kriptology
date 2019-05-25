#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int gcd(int, int);
string UpCase(string);
string DelDouble(string);
string Sort(string);
int Search(string, char);

int main()
{
	string alpha;
	ifstream input("file.txt");
	getline(input, alpha);
	input.close();
	alpha = Sort(DelDouble(UpCase(alpha)));
	cout << alpha;
	ofstream output("file.txt");
	output << alpha << endl;
	output.close();
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

string UpCase(string str)
{
	for (int i = 0; i < str.size(); ++i)
		if (str[i] >= 97 && str[i] < 123)
			str[i] -= 32;
	return str;
}

string DelDouble(string str)
{
	string result = "";
	for (int i = 0; i < str.size(); ++i)
	{
		bool found = false;
		for (int j = 0; j < result.size(); ++j)
			if (str[i] == result[j])
			{
				found = true;
				break;
			}
		if (!found)
			result += str[i];
	}
	return result;
}

string Sort(string str)
{
	for (int i = 0; i < str.size() - 1; ++i)
		for (int j = 0; j < str.size() - 1 - i; ++j)
			if (str[j] > str[j + 1])
				swap(str[j], str[j + 1]);
	return str;
}

int Search(string str, char chr)
{
	for (int i = 0; i < str.size(); ++i)
		if (str[i] == chr)
			return i;
	return -1;
}