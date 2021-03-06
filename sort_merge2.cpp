#include <iostream>
#include <stdio.h>

//функция, сливающая массивы
void Merge(int Array[], int first, int last, int n) {
    int middle, start, final;
    int temp [n];
    middle = (first + last) / 2; //вычисление среднего элемента, чтобы поделить на 2 части
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (int j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (Array[start] < Array[final]))) {
            temp[j] = Array[start];
            start++;
        } 
        else {
            temp[j] = Array[final];
            final++;
        }
//возвращение результата в список
    for (int j = first; j <= last; j++)
    Array[j] = temp[j];
};
//рекурсивная функция сортировки
void MergeSort(int Array[] , int first,int last, int n) {
    if (first < last) {
    MergeSort(Array, first, (first + last) / 2, n); //сортировка левой части
    MergeSort(Array, (first + last) / 2 + 1, last, n); //сортировка правой части
    Merge(Array, first, last, n); //слияние двух частей
    }
}
//главная функция

int main() {
int n;
std:: cin >> n;
    
int Array[n];
for (int i = 0; i <= n-1; i++){
    std::cin >> Array[i] ;    
}

MergeSort(Array, 0, n-1, n); //вызов сортирующей функции
//вывод упорядоченного массива по возрастанию
for (int i = 0; i <= n-1; i++){
    std::cout << Array[i] << " " ;    
}
return 0;
}