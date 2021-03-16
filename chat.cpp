#include "chat.h"
#include "iostream"
#include "string.h"
#include "hash_table.h"

Chat::Chat() {}

void Chat::reg(userName _login, char _pass[], int pass_len) {
    uint* new_hash = sha1(_pass, pass_len ); // вычисляем хэш пароля
    data.add(_login, new_hash); // записываем пару в хэш таблицу
    std::cout << "Registration successfull" << std::endl;
}
bool Chat::login(userName _login, char _pass[],int pass_len) {

    uint* new_hash = sha1(_pass, pass_len); // вычисляем хэш пароля
    uint* loghash = data.find(_login);
    if (!loghash) {
        std::cout << "Login not found" << std::endl;
        return false;
    }
    if (*loghash == *new_hash) {
        std::cout << "Login!" << std::endl;
        return true;
    } 

    std::cout << "Invalid password" << std::endl;
    return false;
}
