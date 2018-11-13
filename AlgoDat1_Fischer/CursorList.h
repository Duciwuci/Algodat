//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include "CursorIterator.h"

template <class T,  int N> class CursorList {

    struct link {
        T* element;
        int previous;
        int next;
    };

    link list[N];

public:
    CursorList() {
        for(int i = 0; i < N - 1; i++) {
            this->list[i].element = nullptr;
            this->list[i].previous = -1;
            this->list[i].next = -1;
        }
    };

    typedef T value_type;

    typedef CursorIterator<T> iterator;

    bool empty() const {
        for(int i = 0; i < N - 1; i++) {
            if(this->list[i].element != nullptr) {
                return false;
            }
        }
        return true;
    };

    int size() const {
        return N;
    };

    T& front() const {
        if(this->empty()) {
            return nullptr;
        }
        for(int i = 0; i < N - 1; i++) {
            if(list[i].element != nullptr && list[i].previous == nullptr && list[i].next != nullptr) {
                return list[i].element;
            }
        }
    };

    void push_front(const T &newVariable) {
        if(empty()) {
            this->list[0].element = newVariable;
            this->list[0].previous = nullptr;
            this->list[0].next = nullptr;
        }  else if (this->getFree() >= 0) {
            this->list[this->getFree()].element = newVariable;
            this->list[this->getFree()].previous = nullptr;
            this->list[this->getFree()].next = this->getFront();
        } else {
            this->list[this->getLast()].element = newVariable;
            this->list[this->getLast()].previous = nullptr;
            this->list[this->getLast()].next = this->getFront();
        }
    }; // add a new value to the front of a list

    void pop_front() {
        if(empty()) {
            return;
        }  else {
            this->list[this->getFront()].element = nullptr;
            this->list[this->getFront()].previous = nullptr;
            this->list[this->getFront()].next = nullptr;
        }
    };

    iterator begin() const {
        return !empty() ? iterator(this, getFront()) : iterator(this, 0);
    };

    iterator end() const {
        return !empty() ? iterator(this, getLast()) : iterator(this, 0);
    };

    iterator insert(iterator itr, const T& value); // insert before itr

    iterator erase(iterator start, iterator stop); // stop exclusive

    iterator erase(iterator itr); // return ++itr

private:
    int getFree() {
        for(int i = 0; i < sizeof(this->list) - 1; i++) {
            if(list[i].element == nullptr) {
                return i;
            }
        }
        return -1;
    }

    int getLast() {
        for(int i = 0; i < sizeof(this->list) - 1; i++) {
            if(list[i].element != nullptr && list[i].previous != nullptr && list[i].next == nullptr) {
                return i;
            }
        }
        return -1;
    }

    int getFront() {
        for(int i = 0; i < sizeof(this->list) - 1; i++) {
            if(list[i].element != nullptr && list[i].previous == nullptr && list[i].next != nullptr) {
                return i;
            }
        }
        return -1;
    }
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
