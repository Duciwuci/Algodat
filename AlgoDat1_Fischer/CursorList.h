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

    int start_list = 0;
    int start_free = 0;
    int end_list = 0;
    link list[N];

public:

    typedef T value_type;

    typedef CursorIterator<T> iterator;

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
            start_free = start_free++ < N  ? start_free++ : -1;
        }  else if (this->getFree() >= 0) {
            this->list[this->getFree()].element = input;
            this->list[this->getFree()].previous = -1;
            this->list[this->getFree()].next = this->getFront();
            this->list[start_list].previous = getFree();
            end_list = getFront();
            start_list = getFree();
            start_free = start_free++ < N  ? start_free++ : -1;
        } else {
            int previous = this->list[this->getLast()].previous;
            this->list[this->getLast()].element = input;
            this->list[this->getLast()].previous = -1;
            this->list[this->getLast()].next = this->getFront();
            this->list[start_list].previous = getLast();
            start_list = end_list;
            end_list = previous;
        }
    };

    void pop_front() {
        if(empty()) {
            return;
        }
        int next = this->list[start_list].next;
        this-list[this->list[start_list].next].previous = -1;
        this->list[start_list].element = -1;
        this->list[start_list].previous = -1;
        this->list[start_list].next = -1;
        start_free = start_list;
        start_list = next;
    };

    iterator begin() const {
    };

    iterator end() const {
    };

    iterator insert(iterator itr, const T& value); // insert before itr

    iterator erase(iterator start, iterator stop); // stop exclusive

    iterator erase(iterator itr); // return ++itr

private:
    int getFree() {
        return start_free;
    }

    int getLast() {
        return end_list;
    }

    int getFront() {
        return start_list;
    }
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
