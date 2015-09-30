//
// Created by gabriel on 9/15/15.
//

#include <malloc.h>
#include <iostream>
#include "arrayList.h"

using namespace array;

int search_index(List *&list, int element, int offset = 0);

void reallocateMemoryIfNecessary(List *&list, int newSize);

int forceOrderedAddition(List *&list, int data, int offset = 0);

void addAll(List *&listA, List *&listB, bool ordered, bool orderedListB);

/**
 * Adiciona um elemento em uma lista ordenada, mantendo-a ordenada
 */
void array::add(List *&list, int element) {
    if (!list) {
        list = new List;
        list->data = new int;
        list->allocationBlockSize = 1;
        list->size = 0;
    }
    reallocateMemoryIfNecessary(list, list->size + 1);
    forceOrderedAddition(list, element);
}

/**
 * Remove o elemento da lista na posição indicada
 */
void array::remove(List *&list, int pos) {
    if (!list || pos < 0) return;
    if (pos < list->size) {
        int *data = list->data;
        for (int i = pos; i < list->size; ++i) {
            data[i] = data[i + 1];
        }
        list->size--;
    }
}

/**
 * Adiciona todos os elementos da lista B na lista A, mantendo-a ordenada
 */
void array::orderJoin(List *&listA, List *&listB, bool orderedListB) {
    join(listA, listB, true, orderedListB);
}

/**
 * Adiciona todos os elementos de listB à listA, se neatly for true a lista A se manterá ordenada
 */
void array::join(List *&listA, List *&listB, bool neatly, bool orderedListB) {
    if (!listB) {
        return;
    }

    if (!listA) {
        listA = listB;
        return;
    }
    reallocateMemoryIfNecessary(listA, listA->size + listB->size);
    addAll(listA, listB, neatly, orderedListB);
}

void array::print(List *list) {
    std::cout << "[";
    if (list) {
        std::cout << list->data[0];
        for (int i = 1; i < list->size; ++i) {
            std::cout << ", " << list->data[i];
        }
    }
    std::cout << "]" << std::endl;
}

int search_index(List *&list, int element, int offset) {
    int *data = list->data + offset;
    int size = list->size - offset;
    int remain_elements = size;

    while (remain_elements > 0) {
        int *midddle = data + remain_elements / 2;
        if (*midddle == element) {
            return offset + remain_elements / 2;
        }

        if (element < *midddle) {
            remain_elements /= 2;
            continue;
        }

        data = midddle + 1;
        offset += remain_elements / 2 + 1;
        remain_elements = remain_elements - remain_elements / 2 - 1;

    }

    return offset;
}

void reallocateMemoryIfNecessary(List *&list, int newSize) {
    while (list->allocationBlockSize < newSize) {
        list->allocationBlockSize *= 2;
        list->data = (int *) realloc(list->data, list->allocationBlockSize * sizeof(int));
    }
}

int forceOrderedAddition(List *&list, int data, int offset) {
    int index = search_index(list, data, offset);
    for (int i = list->size; i > index; --i) {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = data;
    list->size++;
    return index;
}

void addAll(List *&listA, List *&listB, bool ordered, bool orderedListB) {
    int *dataB = listB->data;
    int offset = 0;
    for (int i = 0; i < listB->size; ++i) {
        if (ordered) {
            offset = forceOrderedAddition(listA, *(dataB), orderedListB ? offset : 0);
        } else {
            listA->data[listA->size++] = *dataB;
        }
        dataB++;
    }
}
