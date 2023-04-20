#include <iostream>
#include <Windows.h>

void count_sort(int* arr, int size)
{
    const int min = 10;//Минимальное известное число
    const int max = 24;//Максимально известное число
    const int k = (max - min) + 1; //Размер массива для посчета
    int arrT[k] = {};//Массив куда складываются посчеты 
    int total = 0;

    for (int i = 0; i < size; i++)//Делам посчет и вносим данные в массив посчетов
    {
        int help = arr[i] - min;
        arrT[help] += 1;
    }
    //for (int i = 0; i < k; i++) {
    //    //total += arrT[i];
    //    std::cout << i << " index has " << (arrT[i]) << " num = " << (i + min) << std::endl;
    //}

    //std::cout << sizeof(arrT)/sizeof(arrT[0]) << std::endl;
    //std::cout << arrT[i] << std::endl;

    for (int i = 0; i < k; i++)//Переносим данные из массива с подсчетом в сортировочный массив
    {
        if (arrT[i] == 0)//Если внутри ноль, то такого числа нет 
        {
            continue;
        }
        int h = arrT[i];//Число которое хранит количество повторяющихся чисел
        while (h > 0)//Цикл который растанавливает в сортировочном массиве числа по порядку
        {
            arr[total] = (i + min);
            h--;
            total++;
        }

    }
    //std::cout << "Total " << total << std::endl;
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

    int arrA[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arrB[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arrC[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

    int sizeA = sizeof(arrA) / sizeof(arrA[0]);//30
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);//40
    int sizeC = sizeof(arrC) / sizeof(arrC[0]);//45

    std::cout << "Исходный массив А= ";
    print_arrey(arrA, sizeA);
    count_sort(arrA, sizeA);
    std::cout << "Отсортированный массив А= ";
    print_arrey(arrA, sizeA);
    std::cout << std::endl;

    std::cout << "Исходный массив В= ";
    print_arrey(arrB, sizeB);
    count_sort(arrB, sizeB);
    std::cout << "Отсортированный массив В= ";
    print_arrey(arrB, sizeB);
    std::cout << std::endl;

    std::cout << "Исходный массив С= ";
    print_arrey(arrC, sizeC);
    count_sort(arrC, sizeC);
    std::cout << "Отсортированный массив С= ";
    print_arrey(arrC, sizeC);
}