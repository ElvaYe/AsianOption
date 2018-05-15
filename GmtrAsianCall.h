//
//  GmtrAsianCall.h
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/29/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#ifndef GmtrAsianCall_h
#define GmtrAsianCall_h
#include "PathDepOption.h"
#include "EurCall.h"

class GmtrAsianCall: public PathDepOption
{
public:
    double K;
    GmtrAsianCall(double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double Payoff(SamplePath& S);
    double PriceByBSFormula(BSModel Model);
    double BSdelta(BSModel Model);
};

#endif
