//
//  SpaceVoyage.hpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#ifndef SpaceVoyage_hpp
#define SpaceVoyage_hpp

#include <iostream>
#include <iomanip>
#include <vector>

#include "Supplies.hpp"
#include "Spaceship.hpp"
#include "BlasterBolts.hpp"
#include "Medicine.hpp"
#include "Fuel.hpp"
#include "Parts.hpp"

#include "Crew.hpp"
#include "Navigator.hpp"
#include "Mechanic.hpp"
#include "Doctor.hpp"
#include "Investor.hpp"
#include "Scientist.hpp"

class SpaceVoyage
{
public:
    
    // constructor
    SpaceVoyage();
    
    SpaceVoyage( int difficulty );
    
    // destructor
    ~SpaceVoyage();
    
    void startGame( void );
    
private:
    
    void initializeVoyage( int difficulty );
    
    void gatherSupplies( void );
    void gatherCrew( void );

    void newIteration();
    
    void printStatus(int itrs);

    
    void checkPlanet();
    void pitstop();
    void huntSpaceBuffalo();
    void applyMedicine();
    void eat();
    void repairShip();
    void continueMoving();
    bool checkWin();
    bool checkAlive();
    
    int generateRandom(int min, int max);
    
    double budget;
    double defaultBudget{500.0};
    
    int numSupplies{5};
    int numCrew{5};
    
    // supplies
    Spaceship spaceship;
    BlasterBolts blasterbolts;
    Medicine medicine;
    Fuel fuel;
    Parts parts;
    
    std::vector<Supplies*> suppliesVector;
    
    // crew
    Navigator navigator;
    Mechanic mechanic;
    Doctor doctor;
    Investor investor;
    Scientist scientist; 
    std::vector<Crew*> crewVector;
    
    double totalDistance{6000.0};
    double distanceTraveled{0.0};
    double numberOfCities{6};
    double distanceBetweenCities;
    
    // vitals
    double currentHealth{100.0};
    double currentHunger{100.0};
    double currentShipDamage{100.0};
    bool shipDown{0};
    
    // extra inventory
    double currentFoodLevel{0.0};
    double currentSaleMaterial{0.0};


};

#endif /* SpaceVoyage_hpp */
