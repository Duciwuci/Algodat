//
// Created by Viet Duc Mai on 08.11.18.
//

#include "CursorList.h"

template <class T> bool List<T>::empty() const {
    return this->root == nullptr;
}

template <class T> int List<T>::size() const {
    int size = 0;
    return size;
}

template <class T> T& List<T>::front() const {
    return this->root;
}

template <class T> void List<T>::push_front(const T &) {
} // add a new value to the front of a list

template <class T> void List<T>::pop_front() {
}

template <class T> iterator List<T>::begin() const {
}

template <class T> iterator List<T>::end() const {
}

template <class T> iterator List<T>::insert(iterator itr, const T& value) {
} // insert before itr

template <class T> iterator List<T>::erase(iterator start, iterator stop) {
} // stop exclusive

template <class T> iterator List<T>::erase(iterator itr) {
} // return ++itr


