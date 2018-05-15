//
//  main.cpp
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/28/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "PathDepOption.h"
#include "GmtrAsianCall.h"

using namespace std;

int main()
{
//        Assignment 1:
    double S0=106.0, r=0.058, sigma=0.46;
    double T=9.0/12.0, K=100.0;
    cout << setiosflags(ios::fixed) << setprecision(4);
    BSModel Model(S0,r,sigma);

    EurCall CallOption(T,K);
    EurPut PutOption(T,K);
    long N1=30000;
    cout << "HW1:" << endl
    << "Eur Call Price = "
    << CallOption.PriceByMC(Model,N1,0) << endl;

    cout << "Eur Put Price = "
    << PutOption.PriceByMC(Model,N1,0) << endl << endl;
    
    //    Assignment 2:
    double S02=100., r2=0.03, sigma2=0.2;
    BSModel Model2(S02,r2,sigma2);

    double T2=1.0/12.0, K2=100.0;
    int m2=30;
    ArthmAsianCall Option(T2,K2,m2);

    long N2=30000;
    double epsilon=0.001;
    cout << setiosflags(ios::fixed) << setprecision(9);
    
    Option.PriceByMC(Model2,N2,epsilon);
    cout << "HW2:" << endl
    << "Asian Call Price = " << Option.Price << endl
    << "   Pricing Error = " << Option.PricingError << endl
    << "           delta = " << Option.delta << endl
    << "           gamma = " << Option.gamma << endl << endl;
    
    //    Assignment 3:
    double S03=100.0, r3=0.03, sigma3=0.2;
    BSModel Model3(S03,r3,sigma3);
    
    double T3 =1.0/12.0, K3=100.0;
    int m3=30;
    
    ArthmAsianCall Option3(T3,K3,m3);
    GmtrAsianCall  CVOption(T3,K3,m3);
    
    long N3=30000;
    double epsilon3 =0.001;
    Option3.PriceByVarRedMC(Model3,N3,CVOption,epsilon3);
    cout << "HW3:" << endl
    << "Arithmetic call price = " << Option3.Price << endl
    << "Error = " << Option3.PricingError << endl
    << "delta = " << Option3.delta << endl << endl;
    
    Option3.PriceByMC(Model3,N3,epsilon3);
    cout << "Price by direct MC = " << Option3.Price << endl
    << "Error = " << Option3.PricingError << endl
    << "delta = " << Option3.delta << endl;

    return 0;
}

/*
 HW1:
 Eur Call Price = 21.8119
 Eur Put Price = 11.2094
 
 HW2:
 Asian Call Price = 1.420299784
 Pricing Error = 0.012060697
 delta = 0.524591854
 gamma = 0.118968812
 
 HW3:
 Arithmetic call price = 1.426032129
 Error = 0.000137131
 delta = 0.502915658
 
 Price by direct MC = 1.419721241
 Error = 0.012037717
 delta = 0.525020375
 */
