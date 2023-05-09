#pragma once

#include <iostream>
#include <list>
#include <exception>

template<class T>
class PriorityQueue {

public:
    void push(const T &t);

    T poll();

private:
    struct {
        T operator()(T a, T b) const {
            return a - b;
        }
    } m_comp;

    std::list<T> m_pq;
};

template<class T>
void PriorityQueue<T>::push(const T &t) {
    auto i = m_pq.begin();
    while (i != m_pq.end() && m_comp(*i, t) < 0) i++;
    m_pq.insert(i, t);
}

template<class T>
T PriorityQueue<T>::poll() {
    if (m_pq.empty()) {
        throw std::out_of_range("PriorityQueue is empty !");
    }
    T t = m_pq.front();
    m_pq.pop_front();
    return t;
}
