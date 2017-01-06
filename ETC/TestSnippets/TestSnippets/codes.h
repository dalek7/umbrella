//
//  codes.h
//  TestSnippets
//
//  Created by Seung-Chan Kim on 1/6/17.
//  At a cafè at Mangpo
//  Copyright (c) 2017 Seung-Chan Kim. All rights reserved.
//

#ifndef TestSnippets_codes_h
#define TestSnippets_codes_h

// Codes for gaussRand taken from g2o project !!
/**
 * sample a number from a uniform distribution
 */
static double uniformRand(double lowerBndr, double upperBndr)
{
    return lowerBndr + ((double) std::rand() / (RAND_MAX + 1.0)) * (upperBndr - lowerBndr);
}

/**
 * Gaussian random with a mean and standard deviation. Uses the
 * Polar method of Marsaglia.
 */
#include <cstdlib>
#include <cmath>

static double gaussRand(double mean, double sigma)
{
    double x, y, r2;
    do {
        x = -1.0 + 2.0 * uniformRand(0.0, 1.0);
        y = -1.0 + 2.0 * uniformRand(0.0, 1.0);
        r2 = x * x + y * y;
    } while (r2 > 1.0 || r2 == 0.0);
    return mean + sigma * y * std::sqrt(-2.0 * log(r2) / r2);
}



#endif
