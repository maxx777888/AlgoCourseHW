#include <iostream>
#include <string>
#include <math.h>

long real_string_hash(std::string s, int p, int n)//метод возвращает сумму хеша строки
{
    long hash = 0;//Число которое будет аккамулировать цифровые значения символов

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (i == 0) 
        {
            //Если это первый символ в строке, то просто добавляем его значение в хеш
            hash = static_cast<int>(c);
        }
        else {
            //Если это не первый символ в строке, умножаем его на число Р в степени индекса символа в строке
            hash += static_cast<int>(c) * static_cast<long>(pow(p, i));   
        }
        
    }
    hash = hash % n;//Получаем остаток по модулю n
    return hash;
}
int main() {

    setlocale(LC_ALL, "Russian");

    int p = 0;
    int n = 0;
    std::string str = "";//Переменная для получения строки от пользователя
    bool prime = true;//Переменная для проверки, что число Р является простым числом
    do {//Запуск цикла для получения простого числа Р
        prime = true;
        std::cout << "Введите p: ";
        std::cin >> p;
        for (int i = 2; i <= sqrt(p); i++)
        {
            if (p % i == 0)
            {
                prime = false;
                std::cout << "Число р должно быть простое " << std::endl;
                break;
            }
        }
    } while (!prime);
    

    std::cout << "Введите n: ";
    std::cin >> n;

    do
    {//Цикл начала работы программы
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " <<
            real_string_hash(str, p, n) << std::endl;
    } while (str != "exit");

}