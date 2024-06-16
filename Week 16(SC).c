#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct HashTable {
    struct Node* array[SIZE];
};

struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; i++) {
        hashTable->array[i] = NULL;
    }
    return hashTable;
}

int hash(int key) {
    return key % SIZE;
}

void chaining(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);
    struct Node* newNode = createNode(key, value);
    if (hashTable->array[index] == NULL) {
        hashTable->array[index] = newNode;
    } else {
        struct Node* temp = hashTable->array[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct HashTable* hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = hashTable->array[i];
        while (temp != NULL) {
            printf("(%d, %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct HashTable* hashTable_chaining = createHashTable();
    
    chaining(hashTable_chaining, 10, 20);
    chaining(hashTable_chaining, 21, 30);
    chaining(hashTable_chaining, 22, 40);
    chaining(hashTable_chaining, 23, 50);
    chaining(hashTable_chaining, 33, 60);
    
    printf("Hash Table with Chaining:\n");
    display(hashTable_chaining);
    
    return 0;
}
