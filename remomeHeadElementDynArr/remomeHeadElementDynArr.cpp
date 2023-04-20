#include <iostream>
#include <string>
#include <Windows.h>


void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++)//Выводим данные массива на экран
    {
        if (i < logical_size) //Проверка на текущего индекса с логическим размером
        {
            std::cout << arr[i] << " ";//Если индекс меньше выводим данные

        }
        else {

            std::cout << "_" << " ";//Если индекс больше или равно то выводим количество запасных элементов массива
        }

    }
    std::cout << std::endl;
}

void remove_dynamic_array_head(int*& arr, int& log_size, int& act_size)
{
    while (true)
    {
        std::string userAnswer = "нет";
        std::cout << "Удалить первый элемент? " << std::endl;
        std::cin >> userAnswer;

        if (userAnswer == "да")
        {
          if (act_size == 0)//Проверка на наличие элементов в массиве
          {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания! " << std::endl;
            return;//Выход
          }

          log_size--;//Уменьшаем логический размер на единицу
          if ((log_size > (act_size / 3)))
          {
            int* newArr = new int[act_size];//Создаем новый технический массив
            for (int i = 1; i <= act_size; i++)//Переносим информацию из основного массива в технический
            {
              newArr[i - 1] = arr[i];//На первое место в технический массив ставим второй элемент из основного массива
            }
            delete[] arr;//Очищаем старый массив  
            arr = newArr;//Меняем указатели с технического на основной.
            print_dynamic_array(arr, log_size, act_size);

          }
          else if (act_size == 1) 
          {
            log_size = 0;
            print_dynamic_array(arr, log_size, act_size);
            act_size = 0;

          } else {

            act_size /= 3;//Уменьшаем фактический размер поделив на 3
            int* newArr = new int[act_size];//Создаем новый технический массив
                    
            for (int i = 1; i <= act_size; i++)//Переносим информацию из основного массива в технический
            {
              newArr[i - 1] = arr[i];//На первое место в технический массив ставим второй элемент из основного массива
            }
            delete[] arr;//Очищаем старый массив  
            arr = newArr;//Меняем указатели с технического на основной.
            print_dynamic_array(arr, log_size, act_size);

          }
        } else {

            std::cout << "Спасибо! Ваш динамический массив: ";
            for (int i = 0; i < act_size; i++)//Выводим данные массива на экран
            {
               if (i < log_size) //Проверка на текущего индекса с логическим размером
               {
                 std::cout << arr[i] << " ";//Если индекс меньше выводим данные        
               } else {

                 std::cout << "_" << " ";//Если индекс больше или равно то выводим количество запасных элементов массива
               }

            }
            std::cout << std::endl;
            return;
        }

    }
}

int main()
{
    //Необходимые настройки консоли, для правильной работы с русским языком.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int act_size, log_size;//Переменные где будет храниться фактический и логический размер массива
    do {//Делаем проверку, чтобы логический размер не превышал фактический
        std::cout << "Введите фактичеcкий размер массива: " << std::endl;
        std::cin >> act_size;
        std::cout << "Введите логический размер массива: " << std::endl;
        std::cin >> log_size;
        if (log_size > act_size) {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический! " << std::endl;
            std::cout << std::endl;
        }
    } while (log_size > act_size);


    int* arr = new int[act_size](); //Создаем новый динамический массив
    for (int i = 0; i < log_size; i++)//Заполняем массив данными от пользователя. 
    {
        int input;
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> input;
        arr[i] = input;
    }

    print_dynamic_array(arr, log_size, act_size);
    remove_dynamic_array_head(arr, log_size, act_size);

    delete[] arr; //Очищаем динамическую память
}
