//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include <iostream>

template <class T,  int N> class CursorList {

    struct link {
        T element;
        int previous;
        int next;
    };

    class CursorIterator {

       /* struct link {
            T element;
            int next;
            int previous;
        };*/
    public:
        link mainElement;
        typedef T value_type;
        typedef CursorList<T, N> list_type;
        list_type* mainList;
        typedef CursorIterator iterator;

        CursorIterator(list_type* list, link *cl) {
            this->mainElement = *cl;
            this->mainList = list;
        } ;
        T& operator *() {
            return &mainElement;
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
            return *this;
        }; // postfix operator, dummy parameter

    private:
        iterator& next() {
            //TODO: check implementation
            // if mainElement.next == -1 point to the first element, else take the next one
            if (this->mainElement.next == -1) {
                this->mainElement = mainList->list[mainList->start_list];
            } else {
                this->mainElement = mainList->list[this->mainElement.next];
            }
        }
    };

    int start_list = 0;
    int start_free = 0;
    int end_list = 0;
    link list[N];

public:
    typedef T value_type;

    typedef CursorIterator iterator;

    CursorList() {
        // initialize the "Free Place List".
        // at the Beginning the list is empty, so the "Free Place List" is the whole list
        for (int i = 0; i < N ; i++) {
            list[i].next = i == N - 1 ? -1 : i + 1;
            list[i].previous = i - 1;
        }
    }

    bool empty() const {
        return start_list == start_free;
    };

    int size() const {
        return N;
    };

    T& front() const {
        /*if(this->empty()) {
            return -1;
        }*/
        return list[start_list].element;
    };

    void push_front(const T &input) {
        if(empty()) {
            this->list[0].element = input;
            this->list[0].previous = -1;
            this->list[0].next = -1;
            start_list = 0;
            end_list = 0;
        }  else if (start_free >= 0) {
            this->list[start_free].element = input;
            this->list[start_free].previous = -1;
            this->list[start_free].next = start_list;
            this->list[start_list].previous = start_free;
            start_list = start_free;
        } else {
            int previous = this->list[this->end_list].previous;
            this->list[end_list].element = input;
            this->list[end_list].previous = -1;
            this->list[end_list].next = start_list;
            this->list[start_list].previous = end_list;
            start_list = end_list;
            end_list = previous;
        }
        if (start_free != -1 ) start_free = this->list[start_free].next;
    };

    void pop_front() {
        if(empty()) {
            return;
        }
        int* next = &this->list[start_list].next;
        this->list[*next].previous = -1;
        this->list[start_free].previous = -1;
        this->list[start_free].next = -1;
        // TODO: Irgendeine Abfrage von dir Duc...

        // buffer index of start_list to add it to the Free Place List
        // after start_list has changed to its new index
        int index = start_list;
        start_list = *next == -1 ? 0 : *next;

        this->addIndexToFreePlaceList(index);
    };

    iterator begin() const {
        return iterator(&this, &(this->list[start_list]));
    };

    iterator end() const {
        return iterator(&this, &(this->list[end_list]));
    };

    iterator insert(iterator itr, const T& value) {
        if(empty()) {
            this->list[0].element = *value;
        } else if (start_free == -1) {
            //TODO: was passiert wenn es keinen leeren Platz gibt?
        } else {
            //TODO: check impoementation
            this->list[start_free].element = *value;
            this->list[start_free].next = this->list[itr.mainElement.previous].next;
            this->list[start_free].previous = itr.mainElement.previous;

            this->list[this->list[start_free].previous].next = start_free;
            itr.mainElement.element = this->list[start_free].element;
            itr.mainElement.previous = this->list[start_free].previous;
            itr.mainElement.next = this->list[start_free].next;
        }
        if (start_free != -1 ) start_free = this->list[start_free].next;
        return itr;
    }; // insert before itr

    iterator erase(iterator start, iterator stop) {
        T& startElement = start.operator*();
        T& endElement = stop.operator*();

        int first = startElement->previous;
        int last = endElement->next;

        int firstFree = list[first].next;
        int lastFree = list[last].previous;

        list[first].next = last;
        list[last].previous = first;
        list[start_free].previous = lastFree;
        start_free = firstFree;

        return ++start;
    }; // stop exclusive

    iterator erase(iterator itr) {
        T& element = itr.operator*();
        int index = list[element->previous].next;

        if (element->previous != -1) list[element->previous].next = element->next;
        if (element->next != -1) list[element->next].previous = element->previous;

        this->addIndexToFreePlaceList(index);

        return ++itr;
    }; // return ++itr

private:
    void addIndexToFreePlaceList(int index) {
        if (start_free == -1) {
            start_free = index;
            list[start_free].next = -1;
            return;
        }
        list[start_free].previous = index;
        list[index].next = start_free;
        start_free = index;
    }
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
