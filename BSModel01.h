//
//  BSModel01.h
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/28/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#ifndef BSModel01_h
#define BSModel01_h
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<double> SamplePath;

class BSModel
{
public:
    double S0, r, sigma;
    BSModel(double S0_, double r_, double sigma_)
    {S0 = S0_; r = r_; sigma = sigma_; srand(time(NULL));}
    void GenerateSamplePath(double T,int m,SamplePath& S);
};

#endif
