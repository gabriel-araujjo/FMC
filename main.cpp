#include "linkedList.h"
#include "arrayList.h"

int main() {
    array::List *arrayList = nullptr;
    array::List *otherList = nullptr;

    for (int i = 0; i < 20; i += 2) {
        array::add(arrayList, i);
        array::add(otherList, i + 1);
    }

    array::orderJoin(arrayList, otherList, true);

    array::print(arrayList);
    array::print(otherList);

    linked::List *linkedList = nullptr;
    linked::List *otherLinkedList = nullptr;

    for (int i = 0; i < 4; i += 2) {
        linked::add(linkedList, i);
    }
    for (int j = 0; j < 8; j += 4) {
        linked::add(otherLinkedList, j + 1);
    }

    linked::print(linkedList);
    linked::print(otherLinkedList);

    linked::orderJoin(linkedList, otherLinkedList);
    linked::orderJoin(linkedList, otherLinkedList);


    linked::print(linkedList);
    linked::print(otherLinkedList);

    linked::join(linkedList, otherLinkedList);

    linked::print(linkedList);
    linked::print(otherLinkedList);
    return 0;
}