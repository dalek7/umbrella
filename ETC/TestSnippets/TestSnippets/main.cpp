//
//  main.cpp
//  TestSnippets
//
//  Created by Seung-Chan Kim on 1/6/17.
//  At a cafè at Mangpo
//  Copyright (c) 2017 Seung-Chan Kim. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include "codes.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<double> vdbg;
    FILE *fp = fopen("out_samplertest.txt", "w");
    for(int i=0; i<1000; i++)
    {
        double v = gaussRand(0, 1);
        fprintf(fp, "%f\n", v);
        cout << v << endl;
        
    }
    fclose(fp);
    std::cout << "Hello, World!\n";
    return 0;
}
