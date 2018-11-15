//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORITERATOR_H
#define ALGODAT1_FISCHER_CURSORITERATOR_H

#include "CursorList.h"


template <class T, int N> class CursorIterator {

    struct link {
        T element;
        int next;
        int previous;
    };
    link mainElement;
    typedef T value_type;
    CursorList<value_type , N> mainList;
    typedef CursorIterator<T, N> iterator;
public:
    CursorIterator(CursorList<value_type , N>* list, link* cl) {
        this->mainElement = *cl;
        this->mainList = list;
    } ;
    T& operator *() {

    };
    iterator& operator = (const iterator& rhs) {
    };
    bool operator != (const iterator& rhs) const {
        return this->mainElement.element != rhs.mainElement.element ? true : false;
    };
    bool operator == (const iterator& rhs) const {
        return this->mainElement.element == rhs.mainElement.element ? true : false;
    };
    iterator& operator ++() {
        
    };
    iterator operator ++(int) {

    }; // postfix operator, dummy parameter
};


#endif //ALGODAT1_FISCHER_CURSORITERATOR_H
