//
//  Supplies.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef Supplies_hpp
#define Supplies_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string> // C++ standard string class

class Supplies {
public:
    Supplies();
    virtual ~Supplies( void ) = default; // compiler generates virtual destructor
    
    virtual void getInfo( void ) = 0; // pure virtual
    
    void buySupply(int number);
    
    virtual double getSupplyPrice( void ) = 0;

    virtual void printItemName( void ) = 0;
    virtual void purchaseIntro( void ) = 0;
    
    double checkQuantity( void );
    void changeQuantity(double amount);

    virtual void printQuantity( void );
    
private:

    double supplyQuantity{0};
    

};


#endif /* Supplies_hpp */
