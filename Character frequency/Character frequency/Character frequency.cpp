/*

# Задача 1. Частота символов

### Описание
Нужно посчитать, сколько раз каждый символ встречается в заданном тексте, и отсортировать по убыванию частоты.

---

### Пример правильной работы программы
```
[IN]: Hello world!!
[OUT]:
l: 3
o: 2
!: 2
 : 1
H: 1
e: 1
d: 1
w: 1
r: 1
```

*/

#include <iostream>
#include <string>
#include <set>
#include <windows.h>

class myClass
{
public:
    char simbol;
    int counter;
    myClass(char sim, int count)
    {
        this->counter = count;
        this->simbol = sim;
    }
    bool operator<(const myClass& aOther) const {
        return counter  > aOther.counter;
    }
};
std::multiset<char> inString()
{
    std::multiset<char> newString;
    std::string STR;
    std::cout << "Введите строку: ";
    _flushall(); //Очистить буферы
    getline(std::cin, STR);
    for (const auto& elem : STR) 
        newString.insert(elem);    
    return newString;
}

void result(std::multiset<char> inString)
{
    std::set<char> uniChar;
    std::multiset<myClass> resultic;
    for (const auto& elem : inString) 
        uniChar.insert(elem);
    
    for (const auto& elem : uniChar)
    {
        myClass A(elem, inString.count(elem));

        resultic.insert(A);
    }
    std::cout << "Введенной строке есть следующие элементы: " << std::endl;
    for (const auto& elem : resultic)
    {
        std::cout << "\"" << elem.simbol << "\" - " << elem.counter << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::multiset<char> userString=inString();
    result(userString);
}

