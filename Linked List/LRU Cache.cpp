struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this -> key = key;
        this -> value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    int currSize;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> prev = NULL;
        head -> next = tail;
        tail -> prev = head;
        tail -> next = NULL;
        this -> capacity = capacity;
        currSize = 0;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

            Node* prev = node -> prev;
            Node* next = node -> next;

            prev -> next = next;
            next -> prev = prev;

            node -> prev = head;
            node -> next = head -> next;
            head -> next -> prev = node;
            head -> next = node;
            return node -> value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node -> value = value;

            Node* prev = node -> prev;
            Node* next = node -> next;

            prev -> next = next;
            next -> prev = prev;

            node -> prev = head;
            node -> next = head -> next;
            head -> next -> prev = node;
            head -> next = node;
        }
        else {
            if(currSize == capacity) {
                Node* lruNode = tail -> prev;
                cout<<lruNode -> key<<endl;
                
                Node* prev = lruNode -> prev;
                Node* next = lruNode -> next;
                
                prev -> next = next;
                next -> prev = prev;

                mp.erase(lruNode -> key);

                delete lruNode;
                currSize--;
            }
            
            Node* newNode = new Node(key, value);
            mp[key] = newNode;

            newNode -> prev = head;
            newNode -> next = head -> next;

            head -> next -> prev = newNode;
            head -> next = newNode;

            currSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */