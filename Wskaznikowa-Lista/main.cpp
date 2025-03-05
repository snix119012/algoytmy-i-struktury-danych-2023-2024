#include <iostream>
using namespace std;
template <class T>
class ListaSingly {
public:
    struct cell {
        T element;
        cell* next;
    };

protected:
    cell* header;

public:
    ListaSingly() : header(nullptr) {}
    ~ListaSingly() {
        while (header) {
            cell* temp = header;
            header = header->next;
            Delete(temp);
        }
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
    int Retrieve(cell* p) {
        if (p == nullptr) {
            return false;
        }
        return p->element;
    }

    cell* Locate(T x) {
        cell* c1 = header;
        while (c1) {
            if (c1->element == x) {
                return c1;
            }
            c1 = c1->next;
        }

        return nullptr;
    }
    cell* First() {
        return header;
    }

    cell* Next(cell* p) {
        if (p == nullptr) {
            return nullptr;
        }
        return p->next;
    }
    cell* Previous(cell *p)
    {
        if(p == header || p == nullptr)
        {
            return nullptr;
        }
        cell* c1 =header;
        while (c1->next !=p && c1 != nullptr)
        {
            c1 = c1->next;
        }
        return c1;
    }
    cell* Last()
    {
        if(header== nullptr)
        {
            return nullptr;
        }
        cell* c1=header;
        while(c1->next != nullptr)
        {
            c1 = c1->next;
        }
        return c1;
    }
    void print() {
        cell* current = header;
        while (current != nullptr) {
            cout << current->element << " ";
            current = current->next;
        }
    }

};
template <class T>
class ListaDoubly {
public:
    struct cell {
        T element;
        cell* next;
        cell* pre;
    };

protected:
    cell* header;

public:
    ListaDoubly() : header(nullptr) {}
    ~ListaDoubly() {
        while (header) {
            cell* temp = header;
            header = header->next;
            Delete(temp);
        }
    }
    bool Delete(cell* p) {
        if (p == nullptr) {
            return false;
        }
        if (p->pre) {
            p->pre->next = p->next;
        } else {
            header = p->next;
        }
        if (p->next) {
            p->next->pre = p->pre;
        }
        delete p;
        return true;
    }
    void Insert(T x, cell* p) {
        cell* newC = new cell{ x, nullptr, nullptr };
        if (p == nullptr) {
            newC->next = header;
            if (header) {
                header->pre = newC;
            }
            header = newC;
        } else {
            newC->next = p->next;
            newC->pre = p;
            if (p->next) {
                p->next->pre = newC;
            }
            p->next = newC;
        }
    }
    int Retrieve(cell* p) {
        if (p == nullptr) {
            return false;
        }
        return p->element;
    }

    cell* Locate(T x) {
        cell* c1 = header;
        while (c1) {
            if (c1->element == x) {
                return c1;
            }
            c1 = c1->next;
        }

        return nullptr;
    }
    cell* First() {
        return header;
    }

    cell* Next(cell* p) {
        if (p == nullptr) {
            return nullptr;
        }
        return p->next;
    }
    cell* Previous(cell *p)
    {
        if (p == header || p == nullptr) {
            return nullptr;
        }
        return p->pre;
    }
    cell* Last()
    {
        if(header== nullptr)
        {
            return nullptr;
        }
        cell* c1=header;
        while(c1->next != nullptr)
        {
            c1 = c1->next;
        }
        return c1;
    }
    void print() {
        cell* current = header;
        while (current != nullptr) {
            cout << current->element << " ";
            current = current->next;
        }
    }

};


int main() {
    ListaSingly<int> myList;
    ListaDoubly<double> myList2;
    myList.Insert(1, nullptr);
    myList.Insert(2, myList.First());
    myList.Insert(3, myList.First()->next);
    cout << "Singly linked lists:" << endl;
    cout <<  "Printing list with function print: ";
    myList.print();
    cout<< endl;
    cout << "Delete element with function Delete(): ";
    ListaSingly<int>::cell* element2 = myList.First()->next;
    myList.Delete(element2);
    myList.print();
    cout << endl;
    //second one
    myList2.Insert(11.11, nullptr);
    myList2.Insert(12.12, myList2.First());
    myList2.Insert(13.13, myList2.First()->next);
    cout << "Doubly linked list:" << endl;
    cout << "Printing list with function print: ";
    myList2.print();
    cout << endl;
    cout << "Delete element with function Delete(): ";
    ListaDoubly<double>::cell* element11 = myList2.First();
    myList2.Delete(element11);
    myList2.print();
    cout << endl;
    return 0;
}
