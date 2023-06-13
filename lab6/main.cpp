#include "HashTable.h"

int main() {
    HashTable HashTable;

    HashTable.insert(1, 10);
    HashTable.insert(2, 20);
    HashTable.insert(3, 30);
    HashTable.insert(4, 40);
    HashTable.insert(5, 50);

    cout << "Size: " << HashTable.size() << endl;

    // Виведення через ітератор
    cout << "Content of HashTable:" << endl;
    for (auto kv : HashTable) {
        cout << "Key: " << kv.first << " => " << kv.second << endl;
    }

    // Отримання по ключу
    cout << "Key 3 value: " << HashTable.get(3) << endl;

    // Видалення
    HashTable.remove(3);
    cout << "Size after remove: " << HashTable.size() << endl;

    // Виведення після видалення
    cout << "After remove:" << endl;
    for (auto kv : HashTable) {
        cout << kv.first << " => " << kv.second << endl;
    }

    // Очищення
    HashTable.clear();
    cout << "Size after clear: " << HashTable.size() << endl;

    return 0;
}
