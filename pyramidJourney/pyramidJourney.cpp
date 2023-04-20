#include <iostream>
#include <string>


void move_through_pyramid(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++) //Выводим данные из массива на консоль
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::string userAns = "exit";//Переменная для отслеживания команды пользователя
    int pyrStr = 1;//Номер начального уровня в пирамиде после корневого
    int num = 0;//Номер индекса в массиве
    std::string place = "";//Переменная для обозначения правого или левого ребенка

    int* level = new int[SIZE];//Создаем массив для храния уровня элемента в пирамиде
    level[0] = 0;//Корневой элемент ставим на 0 уровень
    int numPyrElements = 2;//Переменная для ослеживания количества элементов на определенном уровне
    //Заполняем массив таким образом, чтобы индексы элементов массива совпадали с уровнем элементов в пирамиде
    for (int i = 1; i < SIZE; i++)
    {
        if (numPyrElements >= i)
        {
            level[i] = pyrStr;

        }
        else {

            numPyrElements = numPyrElements + numPyrElements * 2;
            pyrStr++;
            level[i] = pyrStr;
        }
    }

    std::cout << "Пирамида: " << std::endl;//Начало вывода пирамиды на консоль

    while (((num * 2 + 1) < SIZE) || ((num * 2 + 2) < SIZE))
    {
        if (num == 0) {

            std::cout << level[num] << " root " << arr[num] << std::endl;
            if ((num * 2 + 1) < SIZE) {

                std::cout << level[num * 2 + 1] << " left(" << arr[num] << ")" << " " << arr[2 * num + 1] << std::endl;
            }
            if ((num * 2 + 2) < SIZE) {

                std::cout << level[num * 2 + 2] << " right(" << arr[num] << ")" << " " << arr[2 * num + 2] << std::endl;
            }
            num++;

        }
        else {


            if ((num * 2 + 1) < SIZE) {
                std::cout << level[num * 2 + 1] << " left(" << arr[num] << ")" << " " << arr[num * 2 + 1] << std::endl;
               
            }
            if ((num * 2 + 2) < SIZE) {
                std::cout << level[num * 2 + 2] << " right(" << arr[num] << ")" << " " << arr[num * 2 + 2] << std::endl;
                
            }
            num++;
        }
    }
    std::cout << std::endl;
    num = 0;
    //Запуск цикла путешествия по элементам пирамиды  
    do {        
        if (num == 0)//Проверка если пользователь находится в корне пирамиды
        {
            std::cout << "Вы находитесь здесь: " << level[num] <<" root " << arr[num] << std::endl;
        }
        else {//Если индекс массива пирамиды не равен 0

            if (num % 2 == 0) {//Проверка на правого потомка
                place = "right";
            }
            else {//Проверка на левого потомка
                place = "left";
            }
            //Вывод на экран элемента в пирамиде
            std::cout << "Вы находитесь здесь: " << level[num] << " " << place << "(" << arr[(num - 1) / 2] << ") " << arr[num] << std::endl;
        }

        std::cout << "Введите команду: ";
        std::cin >> userAns;//Принимаем команду от пользователя

        if (userAns == "left")
        {
            int move = num * 2 + 1;
            if (move < SIZE)//Проверка на наличие элементов в пирамиде
            {
                std::cout << "Ok" << std::endl;
                num = move;

            }
            else {
                std::cout << "Ошибка! Отсутствует левый потомок " << std::endl;
            }

        }
        else if (userAns == "right")
        {
            int move = num * 2 + 2;
            if (move < SIZE)//Проверка на наличие элементов в пирамиде
            {
                std::cout << "Ok" << std::endl;
                num = move;

            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок " << std::endl;
            }

        }
        else if (userAns == "up")
        {
            int move = num - 1;
            if (move >= 0)//Проверка на наличие элементов в пирамиде
            {
                std::cout << "Ok" << std::endl;
                num = (num - 1) / 2;

            }
            else {

                std::cout << "Ошибка! Отсутствует родитель " << std::endl;
            }

        }
        else if (userAns == "exit")
        {
            std::cout << "Спасибо, до свидания!" << std::endl;
            
        }
        else
        {
            std::cout << "Ошибка, нет такой команды, попробуйте еще раз " << std::endl;
        }

    } while (userAns != "exit");

    delete[] level; //Очищаем динамическую память

}

int main() {
    setlocale(LC_ALL, "Russian");

    int arrA[] = { 1, 3, 6, 5, 9, 8 };
    //int arrB[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arrC[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    int sizeA = sizeof(arrA) / sizeof(arrA[0]);//Размер массива А
    //int sizeB = sizeof(arrB) / sizeof(arrB[0]);//Размер массива В
    //int sizeC = sizeof(arrC) / sizeof(arrC[0]);//Размер массива С

    std::cout << "Исходный массив ";
    move_through_pyramid(arrA, sizeA);
}
