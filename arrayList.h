//
// Created by gabriel on 9/15/15.
//

#ifndef LISTS_ARRAYLIST_H
#define LISTS_ARRAYLIST_H

namespace array {

    struct List {
        int *data;
        int size;
        unsigned int allocationBlockSize;
    };

    void add(List *&list, int element);

    void remove(List *&list, int pos);

    void join(List *&listA, List *&listB, bool neatly = false, bool orderedListB = false);

    void orderJoin(List *&listA, List *&listB, bool orderedListB = false);

    void print(List *list);
}

#endif //LISTS_ARRAYLIST_H
