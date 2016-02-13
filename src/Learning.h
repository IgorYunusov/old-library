/***

    RollRat Software Project.
    Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
    Learning.h

Purpose:

    RollRat Library

Author:

    12-30-2015:   HyunJun Jeong, Creation

***/

#ifndef _LEARNING_9bf1541fdf7efd41b7b39543fd870ac4_
#define _LEARNING_9bf1541fdf7efd41b7b39543fd870ac4_

#include <random>
#include <memory.h>

namespace Utility {

    template<size_t len>
    class Hopfield
    {
        int64_t map[len][len] = { 0, };

    public:

        Hopfield() { memset(map, 0, len*len*sizeof(int64_t)); }

        void AddPattern(int64_t pat[len])
        {
            for (int i = 0; i < len; i++)
                for (int j = 0; j < len; j++)
                    if ( i != j )
                    {
                        map[i][j] += pat[i] * pat[j];
                    }
        }

        int64_t* Transfer(int64_t pat[len])
        {
            int64_t ret[len];
            
            for (int i = 0; i < len; i++)
            {
                int64_t weight=0;
                for (int j = 0; j < len; j++)
                {
                    weight += pat[j]*map[i][j];
                }
                ret[i] = HardLimiter(weight);
            }

            return ret;
        }

    protected:

        inline int64_t HardLimiter(int64_t v)
        {
            if ( v >= 0 ) return 1;
            return -1;
        }

    };

    typedef Hopfield<5> NHopfield;

}

#endif