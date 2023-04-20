#include <iostream>

void print_pyramid(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++) //Выводим массив на консоль
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Пирамида: " << std::endl;//Начало вывода пирамиды на консоль

    int str = 0;//Номер уровня в пирамиде
    int num = 0;//Номер индекса в массиве
    int h = 0; //Кол-во установленных элементов из массива в пирамиду
    int level = 4;//Перенная будет хранить сколько элементов установлено на определенном уровне пирамиды
    while (((num * 2 + 1) < SIZE) || ((num * 2 + 2) < SIZE))
    {
        if (num == 0) {

            std::cout << str << " root " << arr[num] << std::endl;
            str++;
            if ((num * 2 + 1) < SIZE) {

                std::cout << str << " left(" << arr[num] << ")" << " " << arr[2 * num + 1] << std::endl;
            }
            if ((num * 2 + 2) < SIZE) {

                std::cout << str << " right(" << arr[num] << ")" << " " << arr[2 * num + 2] << std::endl;
            }
            num++;
            str++;
            
        }
        else {
 
            if (level <= h) {
                str++;
                level *= 2;
                h = 0;
            }

            if ((num * 2 + 1) < SIZE) {
                std::cout << str << " left(" << arr[num] << ")" << " " << arr[num * 2 + 1] << std::endl;
                h++;
            }
            if ((num * 2 + 2) < SIZE) {
                std::cout << str << " right(" << arr[num] << ")" << " " << arr[num * 2 + 2] << std::endl;
                h++;
            }
            num++;
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int arrA[] = { 1, 3, 6, 5, 9, 8 };
    int arrB[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arrC[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    int sizeA = sizeof(arrA) / sizeof(arrA[0]);//Размер массива А
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);//Размер массива В
    int sizeC = sizeof(arrC) / sizeof(arrC[0]);//Размер массива С

    std::cout << "Исходный массив А: ";
    print_pyramid(arrA, sizeA);

    std::cout << "Исходный массив B: ";
    print_pyramid(arrB, sizeB);

    std::cout << "Исходный массив C: ";
    print_pyramid(arrC, sizeC);
}
