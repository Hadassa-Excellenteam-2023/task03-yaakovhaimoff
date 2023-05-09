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
};

