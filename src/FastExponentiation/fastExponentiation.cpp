#include <iostream>
#include <FastExponentiation/fastExponentiation.hpp>

namespace aac {

    /**
     * @param x the number to be elevated to
     * @param pow the power to elevate x to
     */ 
    double fastExponentiation(int x, int pow)
    {
        double res = 1.0;
        bool flag = false;

        /* if pow is negative, we make it positive. We also set a flag*/
        /* to true to return the inverse of the calculated result    */
        if(pow < 0) {
            flag = true;
            pow = -pow;
        }
        
        while (pow)
        {
            /* pow is odd, we multiply the result by x and decrease pow by one */
            if (pow & 1)
            {
                res *= x;
                pow--;
            }
            /* pow is even, we set x to x squared and divide pow by 2 */
            else
            {
                x *= x;
                pow >>= 1;
            }
        }

        if(flag) {
            res = 1/res;
        }

        return res;
    }
} //aac