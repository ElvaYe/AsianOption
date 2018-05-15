//
//  BinModel02.h
//  Elva_Ye_HW9
//
//  Created by Congqing Ye on 3/28/18.
//  Copyright © 2018 Congqing Ye. All rights reserved.
//

#ifndef BinModel02_h
#define BinModel02_h
class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;
public:
    //computing risk-neutral probability
    double RiskNeutProb();
    //computing the stock price at node n,i
    double S(int n, int i);
    //inputting, displaying and checking model data
    int GetInputData();
    double GetS0() {return S0;}
    double GetU() {return U;}
    double GetD() {return D;}
    double GetR();
    
};

#endif /* BinModel02_h */
