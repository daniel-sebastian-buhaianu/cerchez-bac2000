#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MIN_K 1
#define MAX_K 1999
#define LGMIN_TXT 2
#define LGMAX_TXT 2000
#define LGMAX_ALFABET 26

int f[LGMAX_ALFABET];

int main()
{
	char s[LGMAX_TXT + 1];
	int lgtext;

	ifstream fin("BAC2000.TXT");

	if (fin.is_open())
	{
		fin.getline(s, LGMAX_TXT);

		cout << "s = '" << s << "'\n";

		lgtext = strlen(s);

		if (lgtext < LGMIN_TXT || lgtext > LGMAX_TXT)
		{
			cout << "Textul din BAC2000.TXT trebuie sa contina minim 2 si maxim 2000 caractere\n";
			return 1;
		}
	}
	else
	{
		cout << "Nu am putut deschide fisierul BAC2000.TXT\n";
		return 2;
	}

	fin.close();
	
	int i;

	for (i = 0; i < lgtext; i++)
	{
		if ((s[i] < 'A' || s[i] > 'Z') && s[i] != ' ')
		{
			cout << "Textul din BAC2000.TXT trebuie sa contina doar litere mari si spatii\n";
			return 3;
		}

		f[s[i]-'A']++;
	}

	int k;

	cout << "k = "; cin >> k;

	if (k < MIN_K || k > MAX_K)
	{
		cout << "Eroare valoare k\n";
		return 4;
	}	

	bool exista = 0;

	for (i = 0; i < LGMAX_ALFABET && !exista; i++)
	{
		if (f[i] == k)
		{
			exista = 1;
		}
	}

	if (exista)
	{
		cout << "Da";
	}
	else
	{
		cout << "Nu";
	}

	return 0;
}
