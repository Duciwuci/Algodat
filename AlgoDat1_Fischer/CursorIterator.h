//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORITERATOR_H
#define ALGODAT1_FISCHER_CURSORITERATOR_H

#include "CursorList.h"


template <class T> class CursorIterator {

    struct link {
        T element;
        int next;
        int previous;
    }
    typedef CursorIterator<T> iterator;
public:
    CursorIterator(CursorList<T, N>* list, CursorList<T, N>::link* cl);
    T& operator *();
    iterator& operator = (const iterator& rhs);
    bool operator != (const iterator& rhs) const;
    bool operator == (const iterator& rhs) const;
    iterator& operator ++();
    iterator operator ++(int); // postfix operator, dummy parameter
};


#endif //ALGODAT1_FISCHER_CURSORITERATOR_H
