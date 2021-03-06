#include <stdio.h>

#define n 8
int A[n]={9, 6, 89, 1, 12, 4, 5, 32};

//функция, сливающая массивы
void Merge(int A[], int first, int last) {
int middle, start, final;
int temp [8];
middle = (first + last) / 2; //вычисление среднего элемента, чтобы поделить на 2 части
start = first; //начало левой части
final = middle + 1; //начало правой части
for (int j = first; j <= last; j++) //выполнять от начала до конца
if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
temp[j] = A[start];
start++;
} 
else {
temp[j] = A[final];
final++;
}
//возвращение результата в список
for (int j = first; j <= last; j++)
A[j] = temp[j];

};
//рекурсивная функция сортировки
void MergeSort(int A[] , int first,int last) {
if (first < last) {
MergeSort(A, first, (first + last) / 2); //сортировка левой части
MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
Merge(A, first, last); //слияние двух частей
}
}
//главная функция
int main() {

MergeSort(A, 0, n-1); //вызов сортирующей функции
//вывод упорядоченного массива по возрастанию
for (int i = 0; i <= n-1; i++){
printf(" %u ", A[i], " ") ;
}
return 0;
}