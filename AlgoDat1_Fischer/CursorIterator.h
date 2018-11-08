//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORITERATOR_H
#define ALGODAT1_FISCHER_CURSORITERATOR_H


template <class T> class ListIterator {
    typedef ListIterator<T> iterator;4
public:
    T& operator *();
    iterator& operator = (const iterator& rhs);
    bool operator != (const iterator& rhs) const;
    bool operator == (const iterator& rhs) const;
    iterator& operator ++();
    iterator operator ++(int); // postfix operator, dummy parameter
};


#endif //ALGODAT1_FISCHER_CURSORITERATOR_H
