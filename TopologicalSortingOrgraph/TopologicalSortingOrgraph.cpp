//Топологическая сортировка орграфа
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
        //Начало прохода в глубину по массиву
        int* topSort = new int[arr_size]();//Массив куда будут заноситься вершины в топологическом порядке
        int* visSort = new int[arr_size]();//Массив для отслеживания вершин, которые уже отсортированы
        int count = 0;//Техническая переменная для отслеживания прохода по всем вершинам
        
        int vertex = 0;//Индекс куда будут складываться номер вершины, которую уже посетили 
        
        
        while (count < arr_size)
        {
            
            for (int i = 0; i < arr_size; i++)//Цикл для поиска вершин, в которых отсутсвуют входящие дуги
            {
                bool startPoint = true;
                for (int j = 0; j < arr_size; j++)
                {
                    if (fArr[j][i] == 1)
                    {
                        startPoint = false;
                        continue;
                    }
                }
                
                
                if (startPoint)
                {
                    if (visSort[i] == 1) {
                        continue;
                    }
                    else {
                        vertex = i;//Нашли начальную вершину для входа
                    }
                    
                }
            }
            int v = vertex;
            bool finished;//Переменная которая будет отслеживать, посещаемость вершины

            do
            {

                finished = true;

                for (int i = 0; i < arr_size; i++) //Проход по строке массива
                {
                    if (fArr[v][i] == 1)//Нашли смежную вершину
                    {
                        if ( visSort[i] == 1)//Проверяем если эта вершина уже посещалась
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
            

                topSort[(arr_size - 1) - count] = v;//Вставляем вершину в массив сортировки
                if (v < arr_size) visSort[v] = 1;//Помечаем вершину, как отсортированную
                count++;//Увеличиваем счетчик отсортированных вершин
        
            
        }
        std::cout << "Топологический порядок вершин: ";
        for (int i = 0; i < arr_size; i++)//Выводим порядок вершина на консоль
        {
            std::cout << (topSort[i] + 1) << " ";
        }

        std::cout << std::endl;
     
        delete[] visSort;//Очищаем динамическую память
        delete[] topSort;//Очищаем динамическую память
        delete2dArr(fArr, arr_size);//Очищаем динамическую память

    }
    else //Предупреждение на случай, если файл input.txt отсутствует
    {
        std::cout << "file input.txt not found!!! Файл input.txt не найден!!!" << std::endl;
    }

    return 0;
}




