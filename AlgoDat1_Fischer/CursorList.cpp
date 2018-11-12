//
// Created by Viet Duc Mai on 08.11.18.
//

#include "CursorList.h"

template <class T, int N> bool CursorList<T, N>::empty() const {
    for(int i = 0; i < sizeof(this->list) - 1; i++) {
        if(list[i].element != nullptr) {
            return false;
        }
    }
    return true;
}

template <class T, int N> int CursorList<T, N>::size() const {
    return sizeof(this->list);
}

template <class T, int N> T& CursorList<T, N>::front() const {
    if(this->empty()) {
        return nullptr;
    }
    for(int i = 0; i < sizeof(this->list) - 1; i++) {
        if(list[i].element != nullptr && list[i].previous == nullptr && list[i].next != nullptr) {
            return list[i].element;
        }
    }
}

template <class T, int N> void CursorList<T, N>::push_front(const T &newVariable) {
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
}

template <class T, int N> void CursorList<T, N>::pop_front() {
    if(empty()) {
        return;
    }  else {
        this->list[this->getFront()].element = nullptr;
        this->list[this->getFront()].previous = nullptr;
        this->list[this->getFront()].next = nullptr;
    }
}

template <class T, int N> CursorIterator<T> CursorList<T, N>::begin() const {
}

template <class T, int N> CursorIterator<T> CursorList<T, N>::end() const {
}

template <class T, int N> CursorIterator<T> CursorList<T, N>::insert(iterator itr, const T& value) {
} // insert before itr

template <class T, int N> CursorIterator<T> CursorList<T, N>::erase(iterator start, iterator stop) {
} // stop exclusive

template <class T, int N> CursorIterator<T> CursorList<T, N>::erase(iterator itr) {
} // return ++itr

template <class T, int N> int CursorList<T, N>::getFree() {
    for(int i = 0; i < sizeof(this->list) - 1; i++) {
        if(list[i].element == nullptr) {
            return i;
        }
    }
    return -1;
}

template <class T, int N> int CursorList<T, N>::getLast() {
    for(int i = 0; i < sizeof(this->list) - 1; i++) {
        if(list[i].element != nullptr && list[i].previous != nullptr && list[i].next == nullptr) {
            return i;
        }
    }
    return -1;
}

template <class T, int N> int CursorList<T, N>::getFront() {
    for(int i = 0; i < sizeof(this->list) - 1; i++) {
        if(list[i].element != nullptr && list[i].previous == nullptr && list[i].next != nullptr) {
            return i;
        }
    }
    return -1;
}

