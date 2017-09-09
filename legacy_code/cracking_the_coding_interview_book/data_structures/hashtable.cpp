#include <iostream>
#define HASHSIZE 997

using namespace std;

class Node {
    public:
        int key;
        int data;
        Node* next;

        Node(int key, int data) {
            this->key = key;
            this->data = data;
            this->next = NULL;
        }

};

class LinkedList {
    public:
        Node* root;

        void insert(int key, int data) {
            if (root == NULL) {
                root = new Node(key, data);
            } else {
                Node* aux = root;
                root = new Node(key, data);
                root->next = aux;
            }
        }

        Node* find(int key) {
            if (root == NULL)
                return NULL;
            Node* current = root;
            while (current != NULL) {
                if (current->key == key)
                    return current;
                current = current->next;
            }
            return NULL;
        }

};

class HashTable {
    private:
        LinkedList** container = new LinkedList*[HASHSIZE];

        int hash_function(int key) {
            return key % HASHSIZE;
        }

    public:

        void set(int key, int data) {
            int hash_key = hash_function(key);
            if (container[hash_key] == NULL) {
                container[hash_key] = new LinkedList();
            } else {
                cout << "Colition!" << endl;
            }
            container[hash_key]->insert(key, data);
        }

        int get(int key) {
            int hash_key = hash_function(key);
            if (container[hash_key] == NULL)
                return -1;
            Node* element = container[hash_key]->find(key);
            if (element != NULL)
                return element->data;
            return -1;
        }

};

void read(HashTable* ht, int key) {
    cout << "Reading " << key << ": " << ht->get(key) << endl;
    cout << endl;
}

void insert(HashTable* ht, int key, int data) {
    cout << "Setting " << key << ": " << data << endl;
    ht->set(key, data);
    read(ht, key);
}

int main() {
    HashTable ht;
    read(&ht, 1);
    insert(&ht, 1, 10);
    insert(&ht, 998, 17);
    read(&ht, 2);
    insert(&ht, 2, 15);
}
