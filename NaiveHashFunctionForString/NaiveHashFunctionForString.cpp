#include <iostream>
#include <string>

int simple_string_hash(std::string s)//метод возвращает сумму хеша строки
{
    int hash = 0;//Число которое будет аккамулировать цифровые значения символов

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        hash += c;
    }
    return hash;
}
int main() {

    setlocale(LC_ALL, "Russian");

    std::string str = "";//Переменная для получения строки от пользователя

    do {//Цикл начала работы программы
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
    } while (str != "exit");

}