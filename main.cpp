
/**
 * ЗАДАЧА: Модернизируйте модель чата из задания 15.4.2 так,
 * чтобы логин и хеш от пароля теперь хранились в хеш-таблице.
 * То есть логин является ключом, хеш — значением, а вместе они составляются пару.
 * Хеш-функцию для хеш-таблицы составьте методом умножения.
 * Хеш-таблицу реализуйте методом квадратичного пробирования.
**/
#include "sha1.h"
#include "string.h"
#include "chat.h"
#include <iostream>

int main() {
    Chat chat;
    std::cout << " * Registration * " << std::endl;
    std::cout << "Username: ";
    userName user;
    std::cin >> user;
    std::cout << "Password: ";
    char pass[10];
    std::cin >> pass;
    int size = strlen(pass);
    chat.reg(user,pass,size);

    std::cout << "-----------------------------------------" << std::endl;

    std::cout << " * Login * : " << std::endl;
    std::cout << "Username: ";
    userName user2;
    std::cin >> user2;
    std::cout << "Password: ";
    char pass2[10];
    std::cin >> pass2;
    int size2 = strlen(pass2);
    chat.login(user2,pass2,size2);
    return 0;
}
