﻿//Широкий проход по графу
#include <iostream>
#include <fstream>

//Функция создает двумерные массивы. 
int** create2arr(const int ROWS, const int COLUMNS)
{
    int** arr2d = new int* [ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        arr2d[i] = new int[COLUMNS];
    }
    return arr2d;
}

//Функция очищает динамическую память, удаляя двумерный массив. 
void delete2dArr(int** arr2d, const int ROWS)//Функция стерает двумерный массив
{
    for (int i = 0; i < ROWS; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;
    arr2d = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream f_in("input.txt");

    if (f_in.is_open()) //Проверка на наличие файла in.txt
    {
        //Создаем двумерный пустой массив 
        int arr_size;//Переменная будет хранить размер массива
        f_in >> arr_size;
        int** fArr = create2arr(arr_size, arr_size);//Двумерный массив

        //Считывание и запись массива графа
        for (int i = 0; i < arr_size; i++)
        {
            for (int j = 0; j < arr_size; j++)
            {
                f_in >> fArr[i][j];
            }
        }
        int userAns = 0;//Переменная для отслеживания номера вершины, которую выберет пользователь
        bool goodNum = true;//Переменная отслеживает правильность номера вершины, введенного пользователем
        do {
            std::cout << "В графе "<< arr_size <<" вершин.Введите номер вершины, с которой начнётся обход: ";
            std::cin >> userAns;
            if (userAns > arr_size || userAns < 1) 
            {
                goodNum = false;
                std::cout << "Новер вершины не верный. Попробуйте еще раз! " << std::endl;
            }
            else {
                goodNum = true;
            }

        } while (!goodNum);

        //Создаем массив для сохранения вершин где уже был проход, изначально все нули.
        int* visArr = new int[arr_size]();

        //Начало прохода в ширину по массиву
        int v = (userAns - 1);//Индекс куда будут складываться номер вершины, которую уже посетили
        visArr[v] = 1;//Заносим выбор пользователя по индексу в массив где уже был проход
        int countStr = 0;//Счетчик который будет отслеживать количество смежных вершин
        bool stopDetour = false;//Переменная нужна для выхода из цикла
        std::cout << "Порядок обхода вершин: ";
        std::cout << userAns << " ";//Выводим на консоль первый номер вершины в обходе

        do{
            countStr = 0;//Технический счетчик
            for (int i = 0; i < arr_size; i++) //Подсчитаем сколько смежных вершин 
            {
                if (fArr[v][i] == 1) 
                {
                    countStr++;
                }
            }
            //Создадим массив куда отправятся все смежные вершины, которые будут по факту зараженными
            int* infArr = new int[countStr];
            countStr = 0;//Теперь будем использовать как индекс массива зараженных вершин

            for (int i = 0; i < arr_size; i++)//Проходимся по вершине и заражаем все смежные вершины
            {
                if (fArr[v][i] == 1)//Проверка на смежную вершину
                {
                    if (visArr[i] != 1) {//Проверка, что вершина еще не заражена

                        infArr[countStr] = i;//Отмечаем вершину в массиве зараженных
                        countStr++;//Увеличиваем счетчик зараженных вершин
                        visArr[i] = 1;//Отмечаем вершину в массиве посещенных
                        std::cout << i + 1 << " ";
                    }
                    
                }
            }
            bool first = true;//Переменная будет использоваться для отлова первой вершины на заражение
            for (int i = 0; i < countStr; i++)//Начинаем проход по массиву смежных вершин
            {
                int h = infArr[i];//Индекс зараженной переменной будет использовать для поиска смежных вершин

                for (int j = 0; j < arr_size; j++)//Запускаем проход 
                {
                    if (fArr[h][j] == 1)//Нашли смежную вершину
                    {
                        if (visArr[j] != 1)//Проверяем в массиве уже посещенных вершин
                        {
                            if (first) {//Проверка на самую первую вершину 
                                v = j; //Делаем переход на новую вершину
                                first = false;//Меняем флаг, что нашли первую вершину
                            }
                            visArr[j] = 1;//Отмечаем вершину в массиве посещенных
                            std::cout << j + 1 << " ";                            
                        }
                    }
                }
                
            }


            delete[] infArr;//Очищаем динамическую память

            if (countStr == 0) {//Проверка, на отсутствие зараженных вершин
                stopDetour = true;//Меняем флаг и выходим из цикла
            }

        } while (!stopDetour);
        

        std::cout << std::endl;
        

        delete[] visArr;//Очищаем динамическую память
        delete2dArr(fArr, arr_size);//Очищаем динамическую память

    }
    else //Предупреждение на случай, если файл input.txt отсутствует
    {
        std::cout << "file input.txt not found!!! Файл input.txt не найден!!!" << std::endl;
    }

    return 0;
}




                