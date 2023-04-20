#include <iostream>
#include <Windows.h>

void sort_arr(int* arr, int left, int right)
{
    if (left > right) return;//Выход из рекурсии, когда левый и правый индекс встретятся
    int pivot_num = arr[(left + right) / 2];//Число - pivot, на которое мы будет равняться в сортировке
    int first_border = left;//Левая сторона, отсюда пойдут все числа меньше pivot
    int end_border = right;//Правая сторона, отсюда пойдут все числа больше pivot
    while (first_border <= end_border)
    {
        while (arr[first_border] < pivot_num) { first_border++; }//Если pivot меньше идем дальше направо
        while (arr[end_border] > pivot_num) { end_border--; }//Если pivot ,больше идем дальше налево
        if (first_border <= end_border)//Если pivot меньше чем должен быть с правой стороны или больше чем с левой  
        {//Меняем местами числа и двигаемся дальше по индексам на встречу друг другу
            int temp = arr[first_border];
            arr[first_border] = arr[end_border];
            arr[end_border] = temp;
            first_border++;
            end_border--;
        }
    }
    sort_arr(arr, left, end_border);//Запускаем сортировку стороны которая меньше pivot
    sort_arr(arr, first_border, right);//Запускаем сортировку стороны которая ,больше pivot
}
void quick_sort(int* arr, int size)
{
    int left = 0;
    int right = size - 1;
    sort_arr(arr, left, right);
}

void print_arrey(int* arr, int size)//Метод выводит на экран данные из массива
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    //Необходимые настройки консоли, для правильной работы с русским языком.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int arrA[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arrB[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arrC[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int sizeA = sizeof(arrA) / sizeof(arrA[0]);//Размер массива А
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);//Размер массива В
    int sizeC = sizeof(arrC) / sizeof(arrC[0]);//Размер массива С

    std::cout << "Исходный массив А: ";
    print_arrey(arrA, sizeA);
    quick_sort(arrA, sizeA);
    std::cout << "Отсортированный массив А: ";
    print_arrey(arrA, sizeA);
    std::cout << std::endl;

    std::cout << "Исходный массив В: ";
    print_arrey(arrB, sizeB);
    quick_sort(arrB, sizeB);
    std::cout << "Отсортированный массив В: ";
    print_arrey(arrB, sizeB);
    std::cout << std::endl;

    std::cout << "Исходный массив С: ";
    print_arrey(arrC, sizeC);
    quick_sort(arrC, sizeC);
    std::cout << "Отсортированный массив С: ";
    print_arrey(arrC, sizeC);

}
