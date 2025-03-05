#include <iostream>
using namespace std;
template <class T>
class Queue {
public:
    struct cell {
        T element;
        cell* next;
    };
protected:
    cell* header;
public:
     Queue() : header(nullptr) {}
    ~Queue() {
        while (header) {
            cell* temp = header;
            header = header->next;
            Delete(temp);
        }
    }
    bool empty(){
         return header== nullptr;
    };
    void put(T x) {
        cell* newC = new cell{ x, nullptr };
        if (header == nullptr) {
            header = newC;
        } else {
            cell* last = header;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = newC;
        }
    }
    void makenull(){
            while (header) {
                cell *temp = header;
                header = header->next;
                Delete(temp);
            }
    };
    T front() {
        return header->element;
    }
    T get(){
        T first = header->element;
        cell* temp = header;
        header = header->next;
        Delete(temp);
        return first;

    };
    bool Delete(cell* p) {
        if (p == nullptr || p->next == nullptr) {
            return false;
        }
        cell* temp = p->next;
        p->element = temp->element;
        p->next = temp->next;
        return true;
    }
};
const int size = 10;
template <typename T>
class CircularQueue {
private:
    const int MAX_SIZE = size;
    T arr[size];
    int fr, rear, currSize;
public:
    CircularQueue() : fr(-1), rear(-1), currSize(0) {}
    ~CircularQueue() {
        makenull();
    }
    bool empty() const {
        return currSize == 0;
    }
    bool full() const {
        return currSize == MAX_SIZE;
    }
    bool put(T element) {
        if (full()) {
            cout << "Queue is full";
            return false;
        } else {
            if (empty()) {
                fr = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = element;
            currSize++;
            return true;
        }
    }
    T get() {
        if (empty()) {
            cout << "Queue is empty";
            return T();
        } else {
            T element = arr[fr];
            if (fr == rear) {
                fr = -1;
                rear = -1;
            } else {
                fr = (fr + 1) % MAX_SIZE;
            }
            currSize--;
            return element;
        }
    }
    T front() {
        if (empty()) {
            cout << "Queue is empty";
            return T();
        } else {
            return arr[fr];
        }
    }
    void makenull() {
        fr = -1;
        rear = -1;
        currSize=0;
    }
};
int main() {
    Queue<int> myQueue;
    myQueue.put(10);
    myQueue.put(20);
    myQueue.put(30);
    cout << "QUEUE" <<endl;
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Get element: " << myQueue.get() << endl;
    if (myQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    myQueue.makenull();
    if (myQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    cout << "QUEUE CIRCULAR" <<endl;
    CircularQueue<int> myQueue2;
    const int size = 5;
    for (int i = 1; i <= size; ++i) {
        myQueue2.put(i*11);
    }
    cout << "Front element: " << myQueue2.front() << endl;
    cout << "Get element: " << myQueue2.get() << endl;
    if (myQueue2.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    myQueue2.makenull();
    if (myQueue2.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    return 0;
}
