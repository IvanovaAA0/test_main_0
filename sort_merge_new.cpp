#include <iostream>
#include <stdio.h>


//функция, сливающая массивы
void Merge(int p_array[], int first, int last, int leght) {
	int middle, start, final;
	int * temp = new int[leght];
	middle = (first + last) / 2; //вычисление среднего элемента, чтобы поделить на 2 части
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (int j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (p_array[start] < p_array[final]))) {
			temp[j] = p_array[start];
			start++;
		}
		else {
			temp[j] = p_array[final];
			final++;
		}
	//возвращение результата в список
	for (int j = first; j <= last; j++)
		p_array[j] = temp[j];
	delete[] temp;
};
//рекурсивная функция сортировки
void MergeSort(int p_array[], int first, int last, int leght) {
	if (first < last) {
		MergeSort(p_array, first, (first + last) / 2, leght); //сортировка левой части
		MergeSort(p_array, (first + last) / 2 + 1, last, leght); //сортировка правой части
		Merge(p_array, first, last, leght); //слияние двух частей
	}
}
//главная функция

int main() {
	static int n;
	std::cin >> n;

	int *p_array = new int[n];
	int leght = n;
	for (int i = 0; i <= n - 1; i++) {
		std::cin >> p_array[i];
	}

	MergeSort(p_array, 0, n - 1, leght); //вызов сортирующей функции
	//вывод упорядоченного массива по возрастанию
	for (int i = 0; i <= n - 1; i++) {
		std::cout << p_array[i] << " ";
	}
	delete[] p_array;
	return 0;
}