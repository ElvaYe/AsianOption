//
//  BSModel01.cpp
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/28/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#include "BSModel01.h"
#include <cmath>
const double pi=4.0*atan(1.0);

double Gauss()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

void BSModel::GenerateSamplePath (double T, int m, SamplePath& S)
{
    double St = S0;
    for(int k=0; k<m; k++)
    {
        S[k]= St*exp((r-sigma*sigma*0.5)*(T/m)
                     +sigma*sqrt(T/m)*Gauss());
        St=S[k];
    }
}
