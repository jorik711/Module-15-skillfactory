#include "hash_table.h"
#include <iostream>
#include <string.h>

HashTable::HashTable() {
    count = 0;
    mem_size = 100000;
    array = new Pair [mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}
void HashTable::add(userName us_name, uint *hash) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(us_name, i);
        if(array[index].status == enPairStatus::free) { 
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }
    if(i >= mem_size) return; // все перебрали, нет места
    
    // кладем в свободную ячейку пару
    array[index] = Pair(us_name, hash);
    count++;
}
int HashTable::hash_func(userName us_name, int offset) {
    //const double A = 0.7;
    // вычисляем индекс
    int sum = 0;
    size_t i = 0;
    for(; i < strlen(us_name); i++) {
        sum += us_name[i];
    }
    // квадратичные пробы
    return (sum % mem_size + offset*offset) % mem_size; 
    //return (mem_size*(A*sum - int(A*sum)) + offset * offset); 
}

void HashTable::del(userName us_name) {
    for(int i = 0;i < mem_size; i++) {
        int index = hash_func(us_name, i);
        if( array[index].status == enPairStatus::engaged && !strcmp(array[index].user_name, us_name) ) { 
		    array[index].status = enPairStatus::deleted;
		    count--;
		    return;
        } else if(array[index].status == enPairStatus::free) {
            return;
        }
    }
}
uint *HashTable::find(userName us_name) {
     for(int i = 0;i < mem_size; i++) {
        int index = hash_func(us_name, i);
        if( array[index].status == enPairStatus::engaged && 
         !strcmp(array[index].user_name, us_name) ) { 
            return array[index].hash_pass;
        } else if(array[index].status == enPairStatus::free) {
            return nullptr;
        }
     }
     return nullptr;
}
