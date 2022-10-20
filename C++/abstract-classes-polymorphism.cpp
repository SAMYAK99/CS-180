class LRUCache: public Cache {
    public:
        LRUCache(int cap) {capacity = cap;}
        void set(int key, int val) {
            map<int, Node*>::iterator it = mp.find(key);
            if(it == mp.end()) {
                // not in the cache
                Node* newNode = new Node(key, val);
                mp.emplace(key, newNode);
                if(mp.size() == 1) {
                    head = newNode;
                    tail = newNode;
                } else {
                    head->prev = newNode;
                    newNode->next = head;
                    head = newNode;
                    if(mp.size() > capacity) {
                        Node* last = tail;
                        tail = last->prev;
                        mp.erase(last->key);
                        tail->next = nullptr;
                        delete last;
                    }   
                }
            } else {
                // cache hit
                Node* node = it->second;
                node->value = val;
                if(mp.size() != 1) {
                    if(node->prev != nullptr) {
                        node->prev->next = node->next;
                        head->prev = node;
                        node->prev = nullptr;
                        head = node;
                    }
                    
                }
            }
        }
        
        int get(int key) {
            map<int, Node*>::iterator it = mp.find(key);
            return (it == mp.end() ? -1 : it->second->value);
        }
    
    private:
        int capacity;
};
