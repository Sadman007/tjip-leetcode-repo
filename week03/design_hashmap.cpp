// TC: O(1) per query on avg
// MC: O(C) in total, where C = capacity

class Node {
  public:
    int key, value;
    Node* next;
    Node(int k, int v, Node* nxt) {
        key = k;
        value = v;
        next = nxt;
    }
};

class MyHashMap {
public:
    const static int CAPACITY = 19991;
    Node* data[CAPACITY] = {};
    
    MyHashMap() {
        
    }
    
    int getHash(int key) {
        return key % CAPACITY;
    }
    
    void put(int key, int value) {
        remove(key);
        int h = getHash(key);
        Node* node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = getHash(key);
        Node* node = data[h];
        while(node) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = getHash(key);
        Node* node = data[h];
        if (node == nullptr) {
            return;
        }
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        }
        else {
            while(node && node->next) {
                if (node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    delete temp;
                }
                node = node->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

