#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    uint* a = sha1(_pass, sizeof(_pass[0]) - 1 );
    data[data_count++] = AuthData(_login, a);
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    for (int i =0; i < SIZE; i++) {
        if(strcmp( data[i].login, _login ) == 0) {
            uint* a = sha1(_pass, sizeof(_pass[0]) - 1);
            if (a == data[i].pass_sha1_hash) {
                return true;
            }
        }
    }
    return false;
}