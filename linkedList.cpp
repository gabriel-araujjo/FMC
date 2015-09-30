//
// Created by gabriel on 9/15/15.
//

#include <iostream>
#include "linkedList.h"

using namespace linked;

List* addNode(List *&list, List *&item);

bool conflictLists(List *listA, List *listB);

void linked::add(List *&list, int data) {

    List *item = new List;
    item->data = data;

    if (!list) {
        list = item;
        item->tail = nullptr;
        return;
    }

    addNode(list, item);
}

void linked::print(List *list) {
    List *i = list;
    std::cout << "[";
    if (i) {
        std::cout << i->data;
        i = i->tail;
        if (i == list) {
            std::cout << ", ⟲]" << std::endl;
            return;
        }
    }
    while (i) {
        std::cout << ", " << i->data;
        i = i->tail;
        if (i == list) {
            std::cout << ", ⟲";
            break;
        }
    }
    std::cout << "]" << std::endl;
}

void ::linked::remove(List *&list, int pos) {
    if (!list || pos < 0) return;


    List *item = list;

    if (pos == 0) {
        list = item->tail;
        delete item;
        return;
    }

    int i = 0;
    while (item && i < pos - 1) {
        item = item->tail;
        i++;
    }

    if (item) {
        List *deletedItem = item->tail;
        List *nextItem = deletedItem->tail;

        item->tail = nextItem;

        delete deletedItem;
    }

}

void ::linked::orderJoin(List *&listA, List *&listB, bool orderedListB) {
    linked::join(listA, listB, true, orderedListB);
}

void ::linked::join(List *&listA, List *&listB, bool neatly, bool orderedListB) {
    if (!listA) {
        listA = listB;
        return;
    }

    if (!listB) {
        return;
    }

    if (conflictLists(listA, listB)) return;

    List *itemA = listA, *itemB = listB;
    if (!neatly) {
        while (itemA && itemA->tail && (itemA->tail != listA)) {
            itemA = itemA->tail;
        }
        if (itemA) {
            if (itemA->tail) {
                while (itemB && itemB->tail && (itemB->tail != listB)) {
                    itemB = itemB->tail;
                }
                if (itemB) {
                    itemA->tail = listB;
                    itemB->tail = listA;
                }
            } else {
                itemA->tail = listB;
            }
        }
        return;
    }

    itemA = listA, itemB = listB;

    do {
        List *newPosition = addNode(itemA, itemB);

        if (orderedListB) {
            itemA = newPosition;
        }
    } while (itemB && itemB != listB);
}

List* addNode(List *&list, List *&item) {
    List *head = list, *aux = item;

    item = item->tail;

    int data = aux->data;
    if (head->data > data) {
        aux->tail = head;
        list = aux;
    } else {
        while (head->tail && head->tail->data < data && head->tail != list) {
            head = head->tail;
        }
        aux->tail = head->tail;
        head->tail = aux;
    }
    return aux;
}

bool conflictLists(List *listA, List *listB) {
    if (!(listA && listB)) return false;
    List *initListA = listA;
    List *initListB = listB;
    bool endA = false;
    bool endB = false;
    listA = listA->tail;
    listB = listB->tail;
    do {

        if (listA && (listA == listB)) {
            return true;
        } else if (endA && endB) {
            return false;
        }

        if (listA && (listA != initListA) && listA->tail) {
            listA = listA->tail;
        } else {
            endA = true;
        }

        if (listB && (listB != initListB) && listB->tail) {
            listB = listB->tail;
        } else {
            endB = true;
        }
    } while ((listA || listB) && !(listA == initListA && listB == initListB));
    return false;
}
