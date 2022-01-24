#ifndef CYCLE_DETECTION
#define CYCLE_DETECTION
#include <functional>
#include <utility>
#include <iostream>

namespace aac {

/**
 * Brent's cycle-finding algorithm
 * Based on Floyd's hare and tortoise algorithm
 * with some improvements
 * Works with a sequence defined as follow : a_(n+1) = f(a_n)
 * @param f : function defined on a finite Set of cardinal n
 * @param a0 : the first term of the sequence
 * @return a pair of int where the key is the length of the
 * cycle and the value is the number of elements outside it
 */ 
template <typename T>
std::pair<int, int> brent(std::function<T(T)>& f, T a0)
{
    int pow = 1;
    int lambda = 1;
    int mu = 0;
    T tortoise = a0;
    T hare = f(a0);

    while (hare != tortoise) {
        if (pow == lambda) {
            tortoise = hare;
            pow *= 2;
            lambda = 0;
        }

        hare = f(hare);
        lambda++;
    }

    /* Now we search for the index of the first repetition */
    tortoise = a0;
    hare = a0;

    for (int i = 0; i < lambda; i++) {
        hare = f(hare);
    }

    /* distance between hare and tortoise is now lambda */

    /* Now we search for the length of the cycle mu */
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    
    return std::pair<int, int>(lambda, mu);
}

} // aac

#endif