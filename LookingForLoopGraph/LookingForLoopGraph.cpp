//Поиск цикла в графе
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
        
       
        int v = 0;//Индекс куда будут складываться номер вершины, которую уже посетили 
        bool is_loop = false;//Флаг, который отвлеживает наличие цикла
        int vertex = 0;//Начало поиска с первой вершины
        //Начало поиска цикла
        while (vertex < arr_size && is_loop == false) 
        {
            //Создаем массив для отслеживания цепочки вершин в цикле, изначально берем самое максимальное число элементов в цикле.
            int* visArr = new int[arr_size]();
            visArr[v] = 1;//На вершину откуда начинается отчет помечаем как пройденую
            int gLoop = vertex;//Перенная которая будет началом и конецом цикла, если есть цикл
            //Переменная для записи кол-во цепочек вершин в потенциальном цикле, минимум две, чтобы в цикл включал минимум три вершины
            int count = 0;
            int i = 0;//Переменная для прохода в цикле for
            for (; i < arr_size;)
            {
                if (fArr[v][i] == 1) //Проверка на смежную вершину
                {
                    if (visArr[i] == 1) {//Проверка на посещение в прошлом
                        if (count >= 2 && i == gLoop)//Проверка на кол-во цепочек в цикле и что цикл пришел в начальную вершину
                        {
                            is_loop = true;//Ставим флаг на правда
                            break;//Выходим из цикла For
                        }
                        i++;//Идем дальше по циклe For
                        continue;

                    } else {//Если это новая вершина, до этого еще не входящая в цикл

                        visArr[i] = 1;//Отмечаем ее в массиве посещений
                        v = i;//Переходим на индекс этой вершины
                        i = 0;//Обнуляем i, для начало прохода по циклу For
                        count++;//Увеличиваем счетчик цепочек в потенциальном цикле
                        continue;
                    }   
                    
                }
                i++;//Идем дальше по циклу For
            }
            vertex++;//Начнем поиск со следующей вершины 
            v = vertex;
            delete[] visArr;//Очищаем динамическую память
        }
            
        std::cout << (is_loop ? "В графе есть цикл!" : "В графе нет циклов") << std::endl;
        //std::cout << std::endl;
        //Вывод на экран значений массива
        /*for (int i = 0; i < arr_size; i++)
        {
            for (int j = 0; j < arr_size; j++)
            {
                std::cout << fArr[i][j] << " ";
            }
            std::cout << std::endl;
        }*/

        
        delete2dArr(fArr, arr_size);//Очищаем динамическую память

    }
    else //Предупреждение на случай, если файл input.txt отсутствует
    {
        std::cout << "file input.txt not found!!! Файл input.txt не найден!!!" << std::endl;
    }

    return 0;
}




