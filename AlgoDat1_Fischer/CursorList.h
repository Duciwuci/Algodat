//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include "CursorIterator.h"
#include <iostream>

template <class T,  int N> class CursorList {

    struct link {
        T element;
        int previous;
        int next;
    };

    int start_list = 0;
    int start_free = 0;
    int end_list = 0;
    link list[N];

public:

    typedef T value_type;

    typedef CursorIterator<T, N> iterator;

    bool empty() const {
        return start_list == start_free;
    };

    int size() const {
        return N;
    };

    T& front() const {
        if(this->empty()) {
            return -1;
        }
        return this->list[start_free];
    };

    void push_front(const T &input) {
        if(empty()) {
            this->list[0].element = input;
            this->list[0].previous = -1;
            this->list[0].next = -1;
            start_list = 0;
            end_list = 0;
            start_free = start_free++;
        }  else if (start_free >= 0) {
            this->list[start_free].element = input;
            this->list[start_free].previous = -1;
            this->list[start_free].next = start_list;
            this->list[start_list].previous = start_free;
            end_list = start_list;
            start_list = start_free;
            start_free = start_free++ < N  ? start_free++ : -1;
        } else {
            int previous = this->list[this->end_list].previous;
            this->list[end_list].element = input;
            this->list[end_list].previous = -1;
            this->list[end_list].next = start_list;
            this->list[start_list].previous = end_list;
            start_list = end_list;
            end_list = previous;
        }
    };

    void pop_front() {
        if(empty()) {
            return;
        }
        int* next = &this->list[start_list].next;
        this->list[*next].previous = -1;
        this->list[start_free].previous = -1;
        this->list[start_free].next = -1;
        start_free = start_list;
        start_list = *next == -1 ? 0 : *next;
    };

    iterator begin() const {
        return iterator(this, front());
    };

    iterator end() const {
    };

    iterator insert(iterator itr, const T& value); // insert before itr

    iterator erase(iterator start, iterator stop); // stop exclusive

    iterator erase(iterator itr); // return ++itr
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
