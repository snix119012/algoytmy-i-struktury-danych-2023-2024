#include <iostream>
#include <vector>

using namespace std;
template <class T>
class ListaSinglyStack {
public:
    struct cell {
        T element;
        cell* next;
    };

protected:
    cell* header;

public:
    ListaSinglyStack () : header(nullptr) {}
    ~ListaSinglyStack () {
        while (header) {
            cell* temp = header;
            header = header->next;
            Delete(temp);
        }
    }
    void push(T x)
    {
        Insert(x, nullptr);
    }
    T pop()
    {
        if (header == nullptr) {
            return  0;
        }
        T topEl = header->element;
        cell* temp = header;
        header = header->next;
        Delete(temp);
        return topEl;
    }
    T top() {
        if (header == nullptr) {
            return 0;
        }
        return header->element;
    }
    void makenull() {
        while (header) {
            cell* temp = header;
            header = header->next;
            Delete(temp);
        }
    }
    bool empty() {
        return (header == nullptr);
    }
    bool Delete(cell* p) {
        if (p == nullptr || p->next == nullptr) {
            return false;
        }
        cell* temp = p->next;
        p->element = temp->element;
        p->next = temp->next;
        return true;
    }
    void Insert(T x, cell* p) {
        cell* newC = new cell{ x, nullptr };
        if (p == nullptr) {
            newC->next = header;
            header = newC;
        } else {
            newC->next = p->next;
            p->next = newC;
        }
    }
    void print() {
        cell* current = header;
        while (current != nullptr) {
            cout << current->element << " ";
            current = current->next;
        }
        cout<<endl;
        if(empty())
        {
            cout<< "Stack is empty"<<endl;
        }
    }

};
template <class T>
class StackArray {
private:
    static const int size = 10;
    vector<T> arr;
    int top;

public:

    StackArray() : top(-1), arr(size) {}
    bool Delete(int p) {
        if (p < 0 || p > top) {
            return false;
        }
        for (int i = p; i < top; i++) {
            arr[i] = arr[i + 1];
        }
        top--;
        return true;
    }
    bool push2(T x) {
        if (top == size - 1) {
            return false;
        }
        arr[++top] = x;
        return true;
    }

    T pop2() {
        if (empty2()) {
            return 0;
        }
        return arr[top--];
    }

    T top2() const {
        if (empty2()) {
            return 0;
        }
        return arr[top];
    }

    void makenull2() {
        top = -1;
    }

    bool empty2() const {
        return (top == -1);
    }
    void print2() const {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    cout<<"Stack using a pointer list implementation: "<<endl;
    ListaSinglyStack <double> stack;
    stack.push(11.1);
    stack.push(22.2);
    stack.push(33.3);
    cout << "Top element: " << stack.top() << endl;
    stack.print();
    cout << "Pop element: " << stack.pop() << endl;
    stack.print();
    cout << "Using makenull: ";
    stack.makenull();
    stack.print();
    cout<<"Stack using an array implementation: "<<endl;
    StackArray <int> stack2;
    stack2.push2(11);
    stack2.push2(22);
    stack2.push2(33);
    cout << "Top element: " << stack2.top2() << endl;
    stack2.print2();
    cout << "Pop element: " << stack2.pop2() << endl;
    stack2.print2();
    cout << "Using makenull: ";
    stack.makenull();
    if(stack2.empty2()==1)
    {
        cout<<"Stack is empty";
    }
    else
        cout<<"Stack is not empty";

    return 0;
}
