#include <iostream>
using namespace std;
const int MIN = -10000000;
const int size = 10;
class ArrayList {
private:
    int arr[size];
    int last;
public:
    ArrayList() {
        last = -1;
    }
    int First()
    {
        if(last>-1)
            return 0;
        else
            return -1;
    }
    int END()
    {
        return last + 1;
    }
    int Next(int p)
    {
        if(p>last)
        {
            return -1;
        }
        else
        {
            return p+1;
        }
    }
    int Previous(int p)
    {
        if(p<0)
        {
            return -1;
        }
        else
        {
            return p-1;
        }
    }

    bool Insert(int x, int p) {
        if (p < 0 || p > last + 1 || last == size-1) {
            return false;
        }
        for (int i = last; i >= p; i--) {
            arr[i+1] = arr[i];
        }
        arr[p] = x;
        last++;
        return true;
    }
    bool Delete(int p) {
        if (p < 0 || p > last) {
            return false;
        }
        for (int i = p; i < last; i++) {
            arr[i] = arr[i + 1];
        }
        last--;
        return true;
    }
    int Locate(int x) {
        for (int i = 0; i <= last; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return END()+1;
    }

    int Retrieve(int p) {
        if (p < 0 || p > last) {
            return MIN;
        }
        return arr[p];
    }
    void DeleteD() {
        for (int i = 0; i <= last; i++) {
            for (int j = i + 1; j <= last; j++) {
                if (arr[i] == arr[j]) {
                    Delete(j);
                    j--;
                }
            }
        }
    }

};
int main() {
    ArrayList arrList;
    arrList.Insert(11, 0);
    arrList.Insert(22, 1);
    arrList.Insert(33, 2);
    arrList.Insert(11, 3);
    arrList.Insert(44, 4);
    cout << "Print list with function Retrive(p): ";
    for (int i = 0 ; i < arrList.END(); i++) {
        cout << arrList.Retrieve(i) << " ";
    }
    cout << endl;
    cout << "Deleting from list with function Delete(p): ";
    arrList.Delete(4);
    for (int i = 0; i < arrList.END(); i++) {
        cout << arrList.Retrieve(i) << " ";
    }
    cout << endl;
    arrList.DeleteD();
    cout << "Deleting duplicates from list with function DeleteD): ";
    for (int i = 0; i <= arrList.END(); i++) {
        int v = arrList.Retrieve(i);
        if (v != MIN) {
            cout << v << " ";
        }
    }
    cout << endl;
    cout << "Return position of element 11 with function Locate(x): " << arrList.Locate(11) << endl;
    return 0;
}
