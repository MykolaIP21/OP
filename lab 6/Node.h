#ifndef LAB6_NODE_H
#define LAB6_NODE_H

class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};


#endif //LAB6_NODE_H
