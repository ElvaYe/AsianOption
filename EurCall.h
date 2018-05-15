//
//  EurCall.h
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/29/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#ifndef EurCall_h
#define EurCall_h

class BSEurCall
{
public:
    double T,K;
    BSEurCall(double T_, double K_) {T=T_; K=K_;}
    double N(double x);
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
};

#endif /* EurCall_h */

