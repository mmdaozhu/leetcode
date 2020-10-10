#include <cassert>
#include <iostream>

/*
解体思路：
    设计循环双端队列最关键的是判空和判满的条件。
    判空：front == rear;
    判满：(rear + 1) % size == front;
*/

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        deque = new int[k + 1];
        size = k + 1;
        rear = front = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + size) % size;
        deque[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        deque[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + size) % size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return deque[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return deque[(rear - 1 + size) % size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() { return front == rear; }

    /** Checks whether the circular deque is full or not. */
    bool isFull() { return ((rear + 1) % size) == front; }

private:
    int* deque;
    int size;
    int front;
    int rear;
};

int main() {
    MyCircularDeque circularDeque(3);               // set the size to be 3
    assert(circularDeque.insertLast(1) == true);    // return true
    assert(circularDeque.insertLast(2) == true);    // return true
    assert(circularDeque.insertFront(3) == true);   // return true
    assert(circularDeque.insertFront(4) == false);  // return false, the queue is full
    assert(circularDeque.getRear() == 2);           // return 2
    assert(circularDeque.isFull() == true);         // return true
    assert(circularDeque.deleteLast() == true);     // return true
    assert(circularDeque.insertFront(4) == true);   // return true
    assert(circularDeque.getFront() == 4);          // return 4
    return 0;
}