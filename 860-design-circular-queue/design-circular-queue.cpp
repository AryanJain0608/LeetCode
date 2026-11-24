
class MyCircularQueue {
public:
    vector<int> arr;
    int front, rear, count, capacity;

    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        count = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
