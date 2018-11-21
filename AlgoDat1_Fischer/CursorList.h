//
// Created by Viet Duc Mai on 08.11.18.
//

#ifndef ALGODAT1_FISCHER_CURSORLIST_H
#define ALGODAT1_FISCHER_CURSORLIST_H

#include <iostream>

template<typename T>
struct link {
    T element;
    int previous;
    int next;
};

// Aufgabe 4
template<typename Iterator, typename T>
Iterator find(Iterator start, Iterator stop, const T& value) {
    for (link<T> element : start->mainList) {
        if(element->element == *value) {
            return start;
        } else {
            start->next;
        }
    }
    return stop;
};

template <class T,  int N> class CursorList {

    int start_list = -1;
    int start_free = 0;
    int end_list = 0;
    link<T> list[N];

private:
    void addIndexToFreePlaceList(int index) {
        if (start_free < 0) {
            start_free = index;
            list[start_free].next = -1;
            return;
        }
        list[start_free].previous = index;
        list[index].next = start_free;
        start_free = index;
    }

public:
    class CursorIterator {

        int iteratorIndex;

    public:
        link<T> mainElement;
        CursorList<T, N> *mainList;
        typedef CursorIterator iterator;

        CursorIterator(CursorList<T, N> *list, link<T> *cl) {
            this->mainElement = *cl;
            this->mainList = list;
            iteratorIndex = cl->next > 0 ? list->start_list : list->end_list;
        } ;
        T& operator *() {
            return mainElement.element;
        };

        iterator& operator = (const iterator& rhs) {
            this->mainElement = *rhs.mainElement;
        };

        bool operator != (const iterator& rhs) const {
            return this->mainElement.element != rhs.mainElement.element ? true : false;
        };
        bool operator == (const iterator& rhs) const {
            return this->mainElement.element == rhs.mainElement.element ? true : false;
        };
        iterator& operator ++() {
            this->next();
            return *this;
        };
        iterator operator ++(int value) {
            for(int i = 0; i < value; i++) {
                this->next();
            }
            return *this;
        }; // postfix operator, dummy parameter

        int getIteratorIndex() {
            return iteratorIndex;
        }



    private:
        void next() {
            // if mainElement.next == -1 point to the first element, else take the next one
            if (this->mainElement.next < 0) {
                if (!this->mainList->empty()) {
                    this->mainElement = mainList->list[mainList->start_list];
                }
                iteratorIndex = mainList->start_list;
            } else {
                int next = mainElement.next;
                this->mainElement = mainList->list[next];
                iteratorIndex = mainElement.next;
            }
        }
    };

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
        return start_list == -1;
    };

    int size() const {
        return N;
    };

    T& front() {
        // Das ist leider wichtig, damit wir keine ArrayExceptions bekommen
        if(this->empty()) {
            return list[0].element;
        }
        return list[start_list].element;
    };

    void push_front(const T &input) {
        int new_start_free = -1;
        if(empty()) {
            new_start_free = list[0].next;
            this->list[0].element = input;
            this->list[0].previous = -1;
            this->list[0].next = -1;
            start_list = 0;
            end_list = 0;
        }  else if (start_free >= 0) {
            new_start_free = list[start_free].next;
            this->list[start_free].element = input;
            this->list[start_free].previous = -1;
            this->list[start_free].next = start_list;
            this->list[start_list].previous = start_free;
            start_list = start_free;
        } else {
            // else is start_free == -1 --> no Place. So just replace the start_list element;
            list[start_list].element = input;
        }
        start_free = new_start_free;
    };

    void pop_front() {
        if(empty()) {
            return;
        }
        int next = list[start_list].next;
        list[next].previous = -1;
        // buffer index of start_list to add it to the Free Place List
        // after start_list has changed to its new index
        int index = start_list;
        start_list = next < 0 ? 0 : next;
        this->addIndexToFreePlaceList(index);
    };

    iterator begin() {
        return CursorIterator(this, &(this->list[start_list]));
    };

    iterator end() {
        return CursorIterator(this, &(this->list[end_list]));
    };

    iterator insert(iterator itr, const T& value) {
        int new_Start_free = start_free != -1 ? list[start_free].next : -1;
        if(empty()) {
            this->list[0].element = value;
        } else {
            if (start_free < 0) {
                start_free = end_list;
            }
            list[start_free].element = value;
            // TODO: Raphi: ich hab dem CursorIterator jetzt einen Index gegeben, hier kannst du ihn abfragen.
            // Die Implementierung geht nicht wenn es die liste nur 2 elemente groß ist und ist mega ugly
            int prevElem = itr.mainElement.previous;

            // ist so hässlich, weil ich den index des Mainelements nicht habe...
            int mainElement = list[itr.mainElement.next].previous;
            list[start_free].next = list[itr.mainElement.next].previous;
            list[start_free].previous = prevElem;
            list[mainElement].previous = start_free;
            if (prevElem == -1) {
                start_list = start_free;
            } else {
                list[prevElem].next = start_free;
            }

            itr.mainElement = list[start_free];
        }
        start_free = new_Start_free;
        return itr;
    }; // insert before itr

    iterator erase(iterator start, iterator stop) {
        link<T> startElement = start.mainElement;
        link<T> endElement = stop.mainElement;

        int first = startElement.previous;
        int last = endElement.next;

        int firstFree = list[first].next;
        int lastFree = list[last].previous;

        list[first].next = last;
        list[last].previous = first;
        list[start_free].previous = lastFree;
        start_free = firstFree;

        if (first < 0) start_list = last;

        return ++start;
    }; // stop exclusive

    iterator erase(iterator itr) {
        link<T> element = itr.mainElement;
        int index = list[element.previous].next;

        if (element.previous != -1) list[element.previous].next = element.next;
        if (element.next != -1) list[element.next].previous = element.previous;

        if (element.previous == -1) start_list = element.previous;

        this->addIndexToFreePlaceList(index);

        return ++itr;
    }; // return ++itr

};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
