class LRUCache {
public:
   

    class Node{


    public:
        Node*next;
        Node*prev;
        int key;
        int value;

        Node(int _key , int _value){
             
            key = _key;
            value = _value;
        }
    };

    Node*head;
    Node*tail;
    int capacity;
    unordered_map<int , Node*>mpp;


    void insert(Node*node){

       if(head == nullptr){
          node = head;
          node = tail;
          node->next = nullptr;
          node->prev = nullptr;

          return;
        }

        else{

            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;

        }
    }

    // Deletes any node
    void deleteNode(Node* node) {
        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;

        if (node == head)
            head = node->next;

        if (node == tail)
            tail = node->prev;


            node->next = NULL;
            node->prev = NULL ;
    }




    LRUCache(int capacity) {
        this->capacity = capacity;
        unordered_map<int , Node*>mpp;
        head = tail = nullptr;
    }
    
    int get(int key) {
        
        if(mpp.find(key) != mpp.end()){

            Node*node = mpp[key];
            delete(node);
            insert(node);
        }

        return node->value;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()){
            Node*node = mpp[key];
            node->value = value;
            delete(node);
            insert(node);
        }

        else{

            if(mpp.size() == capacity){
                mpp.erase(tail->key);
                delete(tail);
            }

            
            Node* newNode = new Node(key, value);
            insert(newNode);
            mpp[key] = newNode;
        }
    }
};
