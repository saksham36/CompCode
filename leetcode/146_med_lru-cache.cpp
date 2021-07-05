class LRUCache {
public:
    struct Node{
        int key;
        int value; 
        Node* prev; 
        Node* next; 
        
        Node(int k, int val){
            this->key = k;
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    unordered_map<int, Node*> map; // value is address in doubly linked list
	int capacity, count; 
	Node *head, *tail; 
    LRUCache(int cap) {
        head = new Node(0, 0); 
		tail = new Node(0, 0); 
		head->next = tail; 
		tail->prev = head; 
		head->prev = NULL; 
		tail->next = NULL; 
		count = 0; 
        capacity = cap;
    }
    void deleteNode(Node* node){
        // cout<<"Delete: "<<node->value<<endl;
        node->prev->next = node->next;
        node->next->prev = node->prev;   
    }
    void addToHead(Node* node){
        node->next = head->next; 
		node->next->prev = node; 
		node->prev = head; 
		head->next = node; 
        
    }
    int get(int key) {
        if(map.count(key)){
            Node* node = map[key];
            deleteNode(node);
            addToHead(node);
            return node->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        // cout<<"Put: "<<key<< " "<<value<<endl;
        // cout<<"Check: "<<(map[key] == NULL)<<endl;
        // cout<<"Check1: "<<(map.count(key))<<endl;
        if(map.count(key)){
            // cout<<"already in map"<<endl;
            Node* node = map[key];
            node->value = value;
            node->key = key;
            deleteNode(node);
            addToHead(node);
        }
        else{
            // cout<<"Making new node"<<endl;
            Node* node = new Node(key, value);
            map[key] = node;
            // cout<<"Count: "<<count<<" capacity: "<<capacity<<endl;
            if(count < capacity){
                // cout<<"Less than capacity"<<endl;
                count++;
                addToHead(node);
            }
            else{
                map.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

