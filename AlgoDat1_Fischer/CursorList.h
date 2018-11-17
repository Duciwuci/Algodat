//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include <iostream>

template <class T,  int N> class CursorList {

    class CursorIterator {

        struct link {
            T element;
            int next;
            int previous;
        };
    public:
        link mainElement;
        typedef T value_type;
        typedef CursorList<T, N> list_type;
        list_type mainList;
        typedef CursorIterator iterator;

        CursorIterator(list_type* list, link cl) {
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
            return this->next();
        };
        iterator operator ++(int value) {
            for(int i = 0; i < value; i++) {
                this->next();
            }
            return this;
        }; // postfix operator, dummy parameter

    private:
        iterator& next() {
            //TODO: implement
        }
    };

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

    typedef CursorIterator iterator;

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
            //TODO: Abfrage,start_list darf nur start_free sein, wenn start_free < start_list
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
        return iterator(&this, &(this->list[start_list]));
    };

    iterator end() const {
        return iterator(this, this->list[end_list]);
    };

    iterator insert(iterator itr, const T& value) {
        if(empty()) {
            this->list[0].element = *value;
        } else {
            //TODO: logic
            this->list[start_free].element = *value;
            this->list[start_free].previous = ;
            this->list[start_free].next = ;
            this->list[this->list[start_free].previous].next = ;
            itr.mainElement.element = this->list[start_free].element;
            itr.mainElement.previous = this->list[start_free].previous;
            itr.mainElement.next = this->list[start_free].next;
        }
        return itr;
    }; // insert before itr

    iterator erase(iterator start, iterator stop) {
        // TODO: What is this?
    }; // stop exclusive

    iterator erase(iterator itr) {
        // TODO: implement.
    }; // return ++itr
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
