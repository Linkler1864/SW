#include <iostream>
using namespace std;

int* Array_create(int _size)
{
	int* a = new int[_size];
	srand(time(0));
	for (int i = 0;i < _size;i++)
		a[i] = rand() % 21 - 10;
	return(a);
}

void Array_print(int* a, int _size)
{
	for (int i = 0;i < _size;i++)
		cout << a[i] << ' ';
	cout << endl;
}

int Element_number(int* a, int _size, int el)
{
	int i = 0, num = -1;
	while (i < _size)
	{
		if (el == a[i])
		{
			num = i;
			i = _size;
		}
		else i++;
	}
	return(num);
}

int Max_raw(int* a, int s)
{
	int max = 1, k = 1;
	for (int i = 1;i < s;i++)
	{
		if (a[i] == a[i - 1])
		{
			k++;
		}
		else
		{
			if (k > max)
				max = k;
			k = 1;
		}
	}
	return(max);
}

void Element_position()
{
	int size, * array, element;
	cout << "Enter size of array" << endl;
	cin >> size;
	array = Array_create(size);
	Array_print(array, size);
	cout << "Enter the element" << endl;
	cin >> element;
	cout << Element_number(array, size, element) << endl;
	delete[]array;
}

void Numbers_search()
{
	int size, * array, flag = 0;
	cout << "Enter size of array" << endl;
	cin >> size;
	array = Array_create(size);
	Array_print(array, size);
	if (size > 2)
		for (int i = 2;i < size;i++)
		{
			if (array[i] < array[i - 2] - array[i - 1])
			{
				cout << array[i] << ' ';
				flag = 1;
			}
		}
	else cout << "No such numbers" << endl;
	if (flag == 0)
		cout << "No such numbers" << endl;
	delete[]array;
}

void Max_subsequence()
{
	int size;
	cout << "Enter size of array" << endl;
	cin >> size;
	int* array = new int[size];
	for (int i = 0;i < size;i++)
	{
		cout << "a[" << i << "] = ";
		cin >> array[i];
	}
	Array_print(array, size);
	cout << Max_raw(array, size) << endl;
	delete[]array;
}

int main()
{
	int task_number;
	cout << "Enter task number" << endl;
	cin >> task_number;
	switch (task_number)
	{
	case 1:
		Element_position();
		break;
	case 2:
		Numbers_search();
		break;
	case 3:
		Max_subsequence();
		break;
	}
}