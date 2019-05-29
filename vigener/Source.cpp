#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string UpCase(string); // возвращает строку с символами верхнего регистра
string DelDouble(string); // возвращает строку, в которой удалены повтор€ющеес€ символы
string Sort(string); // возвращает отсортированную строку по нумерации ј— »» от меньшего к большему (алгоритм пузырьком)
int Search(string, char); // возвращает индекс символа в строке, если символ не найден возвращает -1

int main()
{ 
	string alpha; // алфвавит
	ifstream input("file.txt");
	getline(input, alpha);
	alpha = Sort(DelDouble(UpCase(alpha))); 
	cout << "Alpha= [" << alpha << "]\n";
	
	string key, text = "", cripted = "";
	cout << "Entry key: ";
	getline(cin, key);
	key = UpCase(key);
	int len = Search(key, ' ');
	if (len != -1)
		key.resize(len);
	cout << "key= " << key << endl;
	int choise;
	cout << "Cript text (1) or Decript text (2)?: ";
	cin >> choise;
	if (choise == 1)
	{
		input.close();
		
		string text;
		cout << "Entry text: ";
		cin.ignore();
		getline(cin, text);
		text = UpCase(text);

		for (int i = 0; i < text.size(); ++i)
		{
			int ctext = Search(alpha, text[i]);
			int ckey = Search(alpha, key[i % key.size()]);
			int c = (ctext + ckey);
			if (c >= alpha.size())
				c -= alpha.size();
			if (ctext == -1 || ckey == -1)
				cripted += '*';
			else
				cripted += alpha[c];
		}

		cout << "Cripted= " << cripted << endl;
		ofstream output("file.txt");
		output << alpha << endl;
		output << cripted << endl;
		output.close();
	}
	else
	{
		getline(input, cripted);
		input.close();
		cripted = UpCase(cripted);
		cout << "Cripted= " << cripted << endl;
		
		for (int i = 0; i < cripted.size(); ++i)
		{
			int ccript = Search(alpha, cripted[i]);
			int ckey = Search(alpha, key[i % key.size()]);
			int c = (ccript - ckey);
			if (c < 0)
				c += alpha.size();
			if (ccript == -1 || ckey == -1)
				text += '*';
			else
				text += alpha[c];
		}

		cout << "Text= " << text << endl;
		ofstream output("file.txt");
		output << alpha << endl;
		output << cripted << endl;
		output.close();
	}
	
	cout << "READY!" << endl;
	return 0;
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