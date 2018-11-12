//
// Created by Viet Duc Mai on 08.11.18.
//

#include "CursorList.h"

template <class T, int N> bool CursorList<T, N>::empty() const {
    return this->list[0] == nullptr;
}

template <class T, int N> int CursorList<T, N>::size() const {
    return this->list->size;
}

template <class T, int N> T& CursorList<T, N>::front() const {
    return this->empty() ? nullptr : this->list[0];
}

template <class T, int N> void CursorList<T, N>::push_front(const T &newVariable) {
    if(this->empty()) {
        this->list[0]->element = newVariable;
        list[0]->next = nullptr;
        list[0]->previous = nullptr;
    } else {
       
    }
} // add a new value to the front of a list

template <class T, int N> void CursorList<T, N>::pop_front() {
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


