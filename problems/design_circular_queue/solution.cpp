class MyCircularQueue {
    vector<int> arr;
    int i = 0;
    int j = 0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr.resize(k + 1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()) {
            j = (j+1) % arr.size();
            arr[j%arr.size()] = value;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()) {
             i = (i+1) % arr.size();
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return !isEmpty() ? arr[(i+1) % arr.size()] : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return !isEmpty() ? arr[j] : -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return i == j;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((j + 1) % arr.size()) == i;
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