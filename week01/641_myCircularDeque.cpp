// ----------------------------- leetcode 641 设计循环双端队列 ----------------------

class MyCircularDeque {
public:
    int *fifo;
    int head, tail;
    int length;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
         fifo = new int[k+1];
         head = 0;
         tail = 0;
         length = k+1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if  (isFull() == true) {
            return false;
        }

        head = (head+length-1)%length;
        fifo[head] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if  (isFull() == true) {
            return false;
        }

        fifo[tail] = value;
        tail = (tail+1) % length;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if  (isEmpty() == true) {
            return false;
        }

        head = (head+1) % length;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if  (isEmpty() == true) {
            return false;
        }

        tail = (tail+length-1) % length;

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        int res;

        if  (isEmpty() == true) {
            return -1;
        }

        res = fifo[head];

        return res;

    }
    
    /** Get the last item from the deque. */
    int getRear() {

        int res;

        if  (isEmpty() == true) {
            return -1;
        }

        res = fifo[(tail+length-1) % length];

        return res;

    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {

        if (head == tail) {
            return true;
        }

        return false;

    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {

        if ((tail+1)%length == head) {
            return true;
        }

        return false;

    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */