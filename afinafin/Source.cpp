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
	int a, b, m;
	string alpha;
	ifstream input("f_alpha.txt");
	getline(input, alpha);
	alpha = Sort(DelDouble(UpCase(alpha)));
	m = alpha.size();
	cout << "Alpha= [" << alpha << "], size= " << m << endl;
	cout << "Entry keys a, b: ";
	cin >> a >> b;
	if (gcd(a, m) == 1)
	{
		int choice;
		cout << "gcd(" << a << ", " << m << ")= " << gcd(a, m) << endl;
		string delta = "", text;
		for (int i = 0; i < m; ++i)
		{
			int key = (a * i + b) % m;
			delta += alpha[key];
		}
		cout << "Alpha for cript= [" << delta << "]\n";
		cout << "Cript (1) or Decript (2) message?: ";
		cin >> choice;
		if (choice == 1)
		{
			input.close();
			cout << "Entry text: ";
			cin.ignore();
			getline(cin, text);
			text = UpCase(text);
			for (int i = 0; i < text.size(); ++i)
			{
				int key = Search(alpha, text[i]);
				if (key == -1)
					text[i] = '*';
				else
					text[i] = delta[key];
			}
			cout << "Cripted= " << text << endl;
			ofstream output("f_alpha.txt");
			output << alpha << endl;
			output << text << endl;
			output.close();
		}
		else if (choice == 2)
		{
			getline(input, text);
			text = UpCase(text);
			cout << "Cripted= " << text << endl;
			for (int i = 0; i < text.size(); ++i)
			{
				int key = Search(delta, text[i]);
				if (key == -1)
					text[i] = '*';
				else
					text[i] = alpha[key];
			}
			cout << "Text= " << text << endl;
			input.close();
		}
		cout << "READY!" << endl;
	}
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
		for (int j=0;j<result.size();++j)
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