//
//  PathDepOption.h
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/28/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#ifndef PathDepOption_h
#define PathDepOption_h
#include "BSModel01.h"
//#include "BinModel02.h"

class PathDepOption
{
public:
    double T, Price, PricingError, delta, gamma;
    int m;
    virtual double Payoff(SamplePath& S)=0;
    double PriceByMC(BSModel Model, long N, double epsilon);
    double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon);
    virtual double PriceByBSFormula(BSModel Model){return 0.0;}
    virtual double BSdelta(BSModel Model) {return 0.0;}
};

class DifferenceOfOptions: public PathDepOption
{
public:
    PathDepOption* Ptr1;
    PathDepOption* Ptr2;
    DifferenceOfOptions(double T_, int m_,PathDepOption* Ptr1_,PathDepOption* Ptr2_)
    {T=T_; m=m_; Ptr1=Ptr1_; Ptr2=Ptr2_;}
    double Payoff(SamplePath& S)
    {return Ptr1->Payoff(S)-Ptr2->Payoff(S);}
};

class ArthmAsianCall: public PathDepOption
{
public:
    double K;
    ArthmAsianCall (double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double Payoff(SamplePath& S);
};

class EurCall: public PathDepOption
{
public:
    double K;
    EurCall(double T_, int K_)
    {T=T_; K=K_; m=1;}
    double Payoff(SamplePath& S);
};

class EurPut: public PathDepOption
{
public:
    double K;
    EurPut(double T_, int K_)
    {T=T_; K=K_; m=1;}
    double Payoff(SamplePath& S);
};
#endif /* PathDepOption_h */
