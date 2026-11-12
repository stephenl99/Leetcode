class MyCircularQueue {
public:
    vector<int> slots;
    int head;
    int tail;
    int capacity;
    MyCircularQueue(int k) {
        slots.resize(k);
        capacity = k;
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        slots[tail % capacity] = value;
        tail++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return slots[head % capacity];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return slots[(tail - 1) % capacity];
    }
    
    bool isEmpty() {
        return (tail == head);
    }
    
    bool isFull() {
        return (tail - head == capacity);
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