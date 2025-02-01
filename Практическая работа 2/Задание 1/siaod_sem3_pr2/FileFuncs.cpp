#include "FileFuncs.h"
#include <string>
bool create_file(string file_name, ofstream &input)
{
	int n,m,x;
	cout << " Введите количество строк для записи чисел в файл: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << " Введите количество чисел в " << i+1 << "-ой строке: ";
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			input << x;
			if (j!=m-1)
				input << " ";
		}
		if (i!=n-1)
			input << '\n';
	}
	return 0;
}

bool output_file(string file_name, ifstream& output)
{
	double x;
	while (!output.eof())
	{
		output >> x;
		cout << " " << x;
	}
	return 0;
}

void add_to_file(string file_name, ofstream& input, int x)
{
	input << " ";
	input << x;
}

int get_number(string file_name, ifstream& output, int index)
{
	int x;
	int i = 0;
	int res = -1;
	while (!output.eof() || !(i == index))
	{
		output >> x;
		output.get();
		if (i==index)
		{
			res = x;
			return res;
		}
		i++;
	}
	return res;
}

int get_total(string file_name, ifstream& output)
{
	int total = 0;
	int x;
	while (!output.eof())
	{
		output >> x;
		total++;
	}
	return total;
}

bool create_new_file(ifstream& output, string file_name,string new_file,int nod,int n)
{
	ofstream newf;
	newf.open(new_file);
	int x;
	int i = 1;
	while (!output.eof())
	{
		output >> x;
		newf << (double)x/nod;
		if (i < n)
			newf << "\n";
		i++;
	}
	return 0;
}

int get_nod(string file_name)
{
	ifstream output(file_name);
	if (!output)
	{
		return -1;
	}
	else
	{
		vector <int> data;
		int x;
		while (!output.eof())
		{
			output >> x;
			data.push_back(x);
		}
		if (data.size() == 0)
		{
			return -1;
		}
		if (data.size() == 1)
			return data[0];
		while (data[0] && data[1])
			if (data[0] > data[1]) data[0] %= data[1];
			else data[1] %= data[0];
		int res = data[1] + data[0];
		for (auto i = 2; i < data.size(); i++)
		{
			while (res && data[i])
				if (res > data[i]) res %= data[i];
				else data[i] %= res;
			res = data[i] + res;
		}
		output.close();
		return res;
	}
}