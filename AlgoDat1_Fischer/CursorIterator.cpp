//
// Created by Viet Duc Mai on 08.11.18.
//

#include "CursorIterator.h"

template <class T>
T& CursorIterator<T>::operator *() {};

template <class T>
CursorIterator<T>& CursorIterator<T>::operator = (const CursorIterator<T>& rhs) {};

template <class T>
bool CursorIterator<T>::operator != (const CursorIterator<T>& rhs) const {};

template <class T>
bool CursorIterator<T>::operator == (const CursorIterator<T>& rhs) const {} ;

template <class T>
CursorIterator<T>& CursorIterator<T>::operator ++() {};

template <class T>
CursorIterator<T> CursorIterator<T>::operator ++(int) {}; // postfix operator, dummy parameter