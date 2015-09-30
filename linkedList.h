//
// Created by gabriel on 9/15/15.
//

#ifndef LISTS_LINKEDLIST_H
#define LISTS_LINKEDLIST_H

namespace linked {

    struct List {
        int data;
        List *tail;
    };

    /**
     * Add element to list
     */
    void add(List *&list, int data);

    /**
     * remove the element at position pos
     */
    void remove(List *&list, int pos);

    /**
     * join to lists
     *
     * if listA == listB the program stop
     *
     *
     */
    void join(List *&listA, List *&listB, bool neatly = false, bool orderedListB = false);

    /**
     *
     */
    void orderJoin(List *&listA, List *&listB, bool orderedListB = false);

    void print(List *list);
}


#endif //LISTS_LINKEDLIST_H
