//
//  GeotrAsianCall.cpp
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/29/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#include <cmath>
#include "GmtrAsianCall.h"
double GmtrAsianCall::Payoff(SamplePath& S)
{
    double Prod=1.0;
    for (int i=0; i<m; i++)
    {
        Prod=Prod*S[i];
    }
    if (pow(Prod,1.0/m)<K) return 0.0;
    return pow(Prod,1.0/m)-K;
}

double GmtrAsianCall::PriceByBSFormula(BSModel Model)
{
    double a = exp(-Model.r*T)*Model.S0*exp((m+1.0)*T/(2.0*m)*(Model.r+Model.sigma*Model.sigma
                                                               *((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
    double b = Model.sigma*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
    BSEurCall G(T, K);
    Price = G.PriceByBSFormula(a,b,Model.r);
    return Price;
}

double GmtrAsianCall::BSdelta(BSModel Model)
{
    double a = exp(-Model.r*T)*Model.S0*exp((m+1.0)*T/(2.0*m)*(Model.r+Model.sigma*Model.sigma
                                                               *((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
    double b = Model.sigma*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
    BSEurCall G(T, K);
    double d = (log(a/K)+(Model.r+pow(b,2)/2)*T)/b*sqrt(T);
    delta = G.N(d)*a/Model.S0;
    return delta;
}


