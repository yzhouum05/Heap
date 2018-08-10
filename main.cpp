#include <iostream>
#include "heap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    MinIntHeap* heap = new MinIntHeap(), * heap2;
    int size, item, size2;
    cout << "Let's create a min heap.\n Size:";
    cin >> size;
    cout << "Items (integers):";
    for (int i = 0; i < size; i++) {
        cin >> item;
        heap->add(item);
    }
    cout << "Peek: " << heap->peek() << endl;
    cout << "Poll: " << heap->poll() << endl;
    cout << "Peek again: " << heap->peek() << endl;
    cout << "Create a new heap from the exisitng heap.\n";
    heap2 = new MinIntHeap(*heap);
    size2 = heap2->get_size();
    cout << "New heap: \n";
    for (int i = 1; i < size2; i++) {
        cout << "Poll: " << heap2->poll() << endl;
    }
    size = heap->get_size();
    cout << "First heap size: " << size;
    for (int i = 1; i < size; i++) {
        cout << "Poll: " << heap->poll() << endl;
    }
    cin.get();
    return 0;
}
