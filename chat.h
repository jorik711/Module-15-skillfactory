#pragma once

#include "sha1.h"
#include "string.h"
#include "hash_table.h"

#define SIZE 10
#define LOGINLENGTH 10

class Chat {
    public:
        Chat();
        void reg(userName _login, char _pass[], int pass_len);
        bool login(userName _login, char _pass[], int pass_len);

    private:
        HashTable data;
};
