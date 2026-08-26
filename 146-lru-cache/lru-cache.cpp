class Node{
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k,int v){
        key =k;
        value =v;

        prev=NULL;
        next=NULL;
    }
    
};
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,1);  
        tail = new Node(-1,1);

        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node* node){
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insert(Node* node){
        node->next = head->next;
        node ->prev = head;
        head->next->prev =node;
        head->next =node;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        remove(node);
        insert(node);
        return(node->value);
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            remove(existing);
            mp.erase(key);
        }
        if(mp.size() == cap){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
        }
        Node* newnode= new Node(key, value);
        insert(newnode);
        mp[key] =newnode;
    }
};
