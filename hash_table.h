#pragma once

#include <string.h>

#define NAMELENGTH 10  // Зафикcируем длину имени

typedef char userName[NAMELENGTH]; // тип имя пользователя

class HashTable { // хэш таблица
    public:
    
        HashTable();
        ~HashTable();
        void add(userName user_name, int hash);  
        void del(userName user_name);
        int find(userName user_name);               
         
    private:
    
        enum enPairStatus {
            free,
            engaged,
            deleted
        };
    
        struct Pair { // пара ключ-значение
            
            Pair(): 
                user_name(""), 
                hash_pass(-1),
                status(enPairStatus::free)
            {}
            Pair(userName u_name, int hash): 
                hash_pass(hash),
                status(enPairStatus::engaged) {
                memcpy(user_name, u_name, NAMELENGTH);
            }
            Pair& operator = (const Pair& other) {
                hash_pass =  other.hash_pass;
                memcpy(user_name, other.user_name, NAMELENGTH);
                status = other.status;
                
                return *this;
            }
            
            bool operator == (const Pair& other) {
                return  status == other.status &&
                        (status != enPairStatus::engaged || (hash_pass == other.hash_pass && !strcmp(user_name, other.user_name)));
            }
            
            
            userName user_name;
            int hash_pass;
            
            enPairStatus status;
        };
    
        int hash_func(userName user_name, int offset);
        
        Pair* array;
        int mem_size;
        int count;
};