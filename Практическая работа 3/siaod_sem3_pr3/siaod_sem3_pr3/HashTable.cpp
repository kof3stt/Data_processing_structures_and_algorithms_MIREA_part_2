#include "HashTable.h"

element::element()
{
}

element::element(string key, long long int pos)
{
	this->key = key;
	this->pos = pos;
}

HashTable::HashTable()
{
}

unsigned long long int hash_func1(string key, unsigned long long int size) 
{
	unsigned long long index = 0;
	unsigned long long p = 1;
	for (char symbol : key) 
	{
		index += abs(symbol) * p;
		p *= 31;
	}
	return index % size;
}


unsigned long long int hash_func2(string key, unsigned long long int size)
{
	unsigned long long index = 0;
	unsigned long long p = 1;
	for (char symbol : key)
	{
		index += abs(symbol) * p;
		p *= 31;
	}
	if (index / size % size == 0)
	{
		return index / size + 1;
	}
	return index / size;
}

void add_student(HashTable& table, element elem)
{
	table.total++;
	while (true)
	{
		unsigned long long int hash = (hash_func1(elem.key, table.size) + elem.attempt * hash_func2(elem.key, table.size)) % table.size;

		if (not table.data[hash].is_busy)
		{
			table.data[hash] = elem;
			table.data[hash].is_busy = 1;
			break;
		}
		else
		{
			elem.attempt++;
		}
	}
	if (table.total > 0.75 * table.size) 
	{
		rehash_table(table);
	}
}


void print_hash_table(const HashTable& table)
{
	for (int i = 0; i < table.size; i++)
	{
		cout << i << ": ";
		cout << table.data[i].key;
		cout << "\n";
	}
}

long long int find_student(string key, HashTable& table)
{
	int attempt = 0;
	while (true)
	{
		table.counter++;
		int hash = (hash_func1(key, table.size) + attempt * hash_func2(key, table.size)) % table.size;
		if (not table.data[hash].is_busy && not table.data[hash].is_deleted)
		{
			table.counter++;
			return -1;
		}
		else
		{
			if (table.data[hash].key == key)
			{
				table.counter++;
				return table.data[hash].pos;
			}
			attempt++;
		}
	}

}

long long int delete_student(string key, HashTable& table)
{
	int attempt = 0;
	while (true)
	{
		int hash = (hash_func1(key, table.size) + attempt * hash_func2(key, table.size)) % table.size;
		if (not table.data[hash].is_busy && not table.data[hash].is_deleted)
		{
			return -1;
		}
		else
		{
			if (table.data[hash].key == key)
			{
				table.data[hash].is_deleted = 1;
				table.data[hash].is_busy = 0;
				table.data[hash].key = "";
				return 0;
			}
			attempt++;
		}
	}
}

void rehash_table(HashTable& table)
{
	HashTable new_table;
	new_table.total = table.total;
	new_table.counter = table.counter;
	new_table.size = table.size * 2;
	new_table.data = new element[new_table.size];
	for (int i = 0; i < table.size; i++)
	{
		element elem;
		elem.key = table.data[i].key;
		elem.pos = table.data[i].pos;
		while (true)
		{
			long long int hash = (hash_func1(elem.key, new_table.size) + elem.attempt * hash_func2(elem.key, new_table.size)) % new_table.size;
			if (not new_table.data[hash].is_busy)
			{
				new_table.data[hash] = elem;
				new_table.data[hash].is_busy = 1;
				break;
			}
			else
			{
				elem.attempt++;
			}
		}
	}
	delete[] table.data;
	table = new_table;
	cout << " Rehash: " << table.size << endl;
}
