#include <iostream>

void merge(int* arr, int begin, int end, const int size)
{
    int* t_arr = new int [size] {0};//Создаем пустой технический массив 
    int i = begin; //Переменная для прохождения по массиву с начала
    int t = 0; //Техническая переменная 
    int mid = begin + (end - begin) / 2; //Находим середину массива
    int j = mid + 1; //Переменная для прохождения по массиву с середины
    
    //Пока есть куда идти по массиву с начала до середины и с середины до конца, цикл будет 
    //идти пока эти два условия совпадают
    while (i <= mid && j <= end)
    {

        if (arr[i] <= arr[j])//Если ячейка с начала меньше или равна ячейке с середины, заносим в тех. массив
        {
            t_arr[t] = arr[i];
            i++;
        }
        else {//Если ячейка с середины меньше чем ячейка с начала, заносим в тех. массив
            t_arr[t] = arr[j];
            j++;
        }
        t++;//Увеличиваем техническую переменную
    }

    while (i <= mid)//Если остались еще ячейки с начала, добавляем их в тех. массив
    {
        t_arr[t] = arr[i];
        i++;
        t++;

    }

    while (j <= end)//Если остались еще ячейки с середины, добавляем их в тех. массив
    {
        t_arr[t] = arr[j];
        j++;
        t++;
    }

    for (i = 0; i < t; i++) //Переносим данные из тех. массива в основной. 
    {
        arr[begin + i] = t_arr[i];
    }
        
    delete[] t_arr;//Очищаем динамическую память. 
}

void mergeSort(int* arr, int left, int right, const int size)
{
    if (left < right)
    {
        if (right - left == 1)
        {
            if (arr[right] < arr[left])
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        } else {
            mergeSort(arr, left, left + (right - left) / 2, size);
            mergeSort(arr, left + (right - left) / 2 + 1, right, size);
            merge(arr, left, right, size);
        }
    }
}

void merge_sort(int* arr, const int size)
{
    int left = 0;
    int right = size - 1;
    mergeSort(arr, left, right, size);
}

void print_arrey(int* arr, int size)//Метод выводит на экран данные из массива
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int arrA[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arrB[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arrC[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    const int sizeA = sizeof(arrA) / sizeof(arrA[0]);//Размер массива А
    const int sizeB = sizeof(arrB) / sizeof(arrB[0]);//Размер массива В
    const int sizeC = sizeof(arrC) / sizeof(arrC[0]);//Размер массива С

    std::cout << "Исходный массив А: ";
    print_arrey(arrA, sizeA);
    merge_sort(arrA, sizeA);
    std::cout << "Отсортированный массив А: ";
    print_arrey(arrA, sizeA);
    std::cout << std::endl;

    std::cout << "Исходный массив В: ";
    print_arrey(arrB, sizeB);
    merge_sort(arrB, sizeB);
    std::cout << "Отсортированный массив В: ";
    print_arrey(arrB, sizeB);
    std::cout << std::endl;

    std::cout << "Исходный массив С: ";
    print_arrey(arrC, sizeC);
    merge_sort(arrC, sizeC);
    std::cout << "Отсортированный массив С: ";
    print_arrey(arrC, sizeC);
}
