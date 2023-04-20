//Вывод орграфа на консоль
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

        //Начало вывода орграфа на консоль
        std::cout << "Текстовый вид орграфа: " << std::endl;
        for (int i = 0; i < arr_size; i++) //Пройдемся циклом по всем вершинам орграфа
        {
            std::cout << (i + 1) << ": ";
            bool hasnt = true;//Переменная будет ослеживать, если у вершины отсутствуют дуги
            for (int j = 0; j < arr_size; j++) 
            {
                if (fArr[i][j] == 1) //Нашли переход
                {
                    std::cout << (j + 1) << " ";
                    hasnt = false;//Поменяли флаг
                }
            }
            if (hasnt == true) //Если нет смежных вершин
            {
                std::cout << "нет ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
        delete2dArr(fArr, arr_size);//Очищаем динамическую память

    }
    else //Предупреждение на случай, если файл input.txt отсутствует
    {
        std::cout << "file input.txt not found!!! Файл input.txt не найден!!!" << std::endl;
    }

    return 0;
}




