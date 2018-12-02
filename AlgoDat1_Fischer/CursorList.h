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
        CursorList<T, N> *mainList;
        typedef CursorIterator iterator;

        CursorIterator(CursorList<T, N> *list) {
            this->mainList = list;
            iteratorIndex = list->start_list;
        } ;
        T& operator *() {
            return mainList->list[iteratorIndex].element;
        };

        iterator& operator = (const iterator& rhs) {
            this->mainList = rhs.mainList;
            this->iteratorIndex = rhs.iteratorIndex;
            return *this;
        };

        bool operator != (iterator& rhs) {
            return this->operator*() != rhs.operator*();
        };
        bool operator == (iterator& rhs) {
            return this->operator*() == rhs.operator*();
        };
        iterator& operator ++() {
            this->iteratorIndex = getIteratorNextIndex();
            return *this;
        };
        iterator operator ++(int value) {
            for(int i = 0; i < value; i++) {
                if (iteratorIndex == -1) return *this;
                iteratorIndex = getIteratorNextIndex();
            }
            return *this;
        }; // postfix operator, dummy parameter

        int getIteratorIndex() {
            return iteratorIndex;
        }

        int getIteratorNextIndex() {
            return this->mainList->list[iteratorIndex].next;
        }

        int getIteratorPreviousIndex() {
            return this->mainList->list[iteratorIndex].previous;
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
        return CursorIterator(this);
    };

    iterator end() {
        CursorIterator result = CursorIterator(this);
        while (result.getIteratorNextIndex() != -1) {
            result++;
        }
        return result;
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
            int prevElem = itr.getIteratorPreviousIndex();

            int mainElement = itr.getIteratorIndex();
            list[start_free].next = mainElement;
            list[start_free].previous = prevElem;
            list[mainElement].previous = start_free;
            if (prevElem == -1) {
                start_list = start_free;
            } else {
                list[prevElem].next = start_free;
            }
        }
        start_free = new_Start_free;
        return CursorIterator(this);
    }; // insert before itr

    iterator erase(iterator start, iterator stop) {

        // start.previous and stop.next will be linked.
        int first = start.getIteratorPreviousIndex();
        int last = stop.getIteratorNextIndex();

        // the Deleted ones will be added to the free list
        int firstFree = start.getIteratorIndex();
        int lastFree = stop.getIteratorIndex();

        list[first].next = last;
        list[last].previous = first;
        list[start_free].previous = lastFree;
        start_free = firstFree;

        if (first < 0) start_list = last;

        return ++start;
    }; // stop exclusive

    iterator erase(iterator itr) {
        int index = itr.getIteratorIndex();

        int prev = itr.getIteratorPreviousIndex();
        int next = itr.getIteratorNextIndex();
        if (prev != -1) list[prev].next = next;
        if (next != -1) list[next].previous = prev;

        if (prev == -1) start_list = prev;

        this->addIndexToFreePlaceList(index);

        return ++itr;
    }; // return ++itr
};

#endif //ALGODAT1_FISCHER_CURSORLIST_H
