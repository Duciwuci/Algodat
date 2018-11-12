//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include "CursorIterator.h"

template <class T,  int N> class CursorList {

    struct link {
        T element;
        int previous;
        int next;
    };

    link list[N];

public:
    typedef T value_type;
    typedef CursorIterator<T> iterator;
    bool empty() const;
    int size() const;
    T& front() const;
    void push_front(const T &); // add a new value to the front of a list
    void pop_front();
    iterator begin() const;
    iterator end() const;
    iterator insert(iterator itr, const T& value); // insert before itr
    iterator erase(iterator start, iterator stop); // stop exclusive
    iterator erase(iterator itr); // return ++itr

private:
    int getFree();
    int getLast();
    int getFront();
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
