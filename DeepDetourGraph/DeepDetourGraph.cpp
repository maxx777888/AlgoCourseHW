//Глубокий проход по графу
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
        //Создаем массив для сохранения вершин где уже был проход, изначально все нули.
        int* visArr = new int[arr_size](); 

        //Начало прохода в глубину по массиву
        int v = 0;//Индекс куда будут складываться номер вершины, которую уже посетили 
        bool finished = true;//Переменная которая будет отслеживать, посещаемость вершины
        std::cout << "Порядок обхода вершин: ";
        do 
        {

            visArr[v] = 1;//Сразу присваиваем ячейке, которая равна вершине, что проход состоялся
            std::cout << v + 1 << " ";//Выводим на консоль номер вершины
            finished = true;

            for (int i = 0; i < arr_size; i++) //Проход по строке массива
            {
                if (fArr[v][i] == 1)//Нашли смежную вершину
                {
                    if (visArr[i] == 1)//Проверяем если эта вершина уже посещалась
                    {
                        continue;//Если да идем дальше по проходу

                    } else {//Если еще вершина не посещалась

                        v = i;//Присваиваем индексу номер вершину куда надо пойти с проходом
                        finished = false;//Еще есть куда переходить
                        break;//Выходим из прохода. 
                    }
                }  
            }
        } while (!finished);

        std::cout << std::endl;
        //Вывод на экран значений массива
        /*for (int i = 0; i < arr_size; i++)
        {
            for (int j = 0; j < arr_size; j++)
            {
                std::cout << fArr[i][j] << " ";
            }
            std::cout << std::endl;
        }*/

        delete[] visArr;//Очищаем динамическую память
        delete2dArr(fArr, arr_size);//Очищаем динамическую память

    }
    else //Предупреждение на случай, если файл input.txt отсутствует
    {
        std::cout << "file input.txt not found!!! Файл input.txt не найден!!!" << std::endl;
    }

    return 0;
}




