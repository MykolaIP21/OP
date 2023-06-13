#ifndef LAB6_HASHTABLE_H
#define LAB6_HASHTABLE_H

#include "Node.h"
#include <iostream>

using namespace std;

#define TABLE_SIZE 20

class HashTable {
    class Node {
    public:
        int key;
        int value;
        Node* next;

        Node(int key, int value) : key(key), value(value), next(nullptr) {}
    };

    Node* table[TABLE_SIZE]{};

public:
    using KeyVal = pair<int, int>;
    class Iterator {
        Node* node;
        Node** table;
        int index;
    public:
        explicit Iterator(Node** table, int index = 0) : table(table), index(index) {
            node = table[index];
            moveToNextNode();
        }

        void moveToNextNode() {
            while (node == nullptr && index < TABLE_SIZE) {
                node = table[++index];
            }
        }

        KeyVal operator*() {
            return KeyVal{node->key, node->value};
        }

        Iterator& operator++() {
            node = node->next;
            moveToNextNode();
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return node != other.node || index != other.index;
        }
    };

    HashTable() {
        for(int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        clear();
    }

    static int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    int size() const {
        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (Node* node = table[i]; node != nullptr; node = node->next) {
                count++;
            }
        }
        return count;
    }

    void clear() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* node = table[i];
            while (node != nullptr) {
                Node* toDelete = node;
                node = node->next;
                delete toDelete;
            }
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int get(int key) {
        int index = hashFunction(key);
        Node* node = table[index];
        while(node) {
            if(node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node *node = table[index];
        Node *prevNode = nullptr;
        while (node) {
            if (node->key == key) {
                if (prevNode) {
                    prevNode->next = node->next;
                } else {
                    table[index] = node->next;
                }
                delete node;
                return;
            }
            prevNode = node;
            node = node->next;
        }
        cout << "Not element by key "<< key << endl;
    }

    Iterator begin() {
        return Iterator(table, 0);
    }

    Iterator end() {
        return Iterator(table, TABLE_SIZE);
    }
};

#endif //LAB6_HASHTABLE_H
