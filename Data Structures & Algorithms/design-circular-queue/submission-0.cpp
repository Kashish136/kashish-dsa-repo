class MyCircularQueue {

    int*temp;
    int front ;
    int rear ;
    int maxsize;
    int currentsize;


public:
    MyCircularQueue(int k) {
        temp = new int[k];
        start = -1;
        end = -1;
        maxsize = k;
        currentsize = 0;
    }
    
    bool enQueue(int value) {
        
        if(currentsize == maxsize){
            return false;
        }

        if(end == -1){
            start = 0;
            end = 0;
        }

        else{
            end = (end+1)%maxsize;

        }
        temp[end] = value;
        currentsize++;
    }
    
    bool deQueue() {
        
        if(start == -1){
            return false ;
        }

        int element = temp[start];
        if(currentsize == 1){
            start = -1;
            end = -1;
        }

        else{
            start = (start+1)%maxsize;
        }

        currentsize--;
        return true ;
    }
    
    int Front() {
        
        if(start == -1){
            return -1;
        }

        int value = temp[start];
        
        return value;
    }
    
    int Rear() {
        
        if(start == -1){
            return -1;
        }

        int value = temp[end];
        return value;
    }
    
    bool isEmpty() {
        
        return (currentsize == 0) ? 1 : 0;
    }
    
    bool isFull() {
        
        return currentsize == maxsize ;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */