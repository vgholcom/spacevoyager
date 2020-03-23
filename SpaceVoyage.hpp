// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// SpaceVoyage.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

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
    
    // constructor with input
    SpaceVoyage( int difficulty );
    
    // destructor
    ~SpaceVoyage();
    
    // start game
    void startGame( void );
    
private:
    
    /*****************
     *
     *   functions
     *
     *****************/
    
    // initialize game and game variables
    void initializeVoyage( int difficulty );
    
    // gather initial supplies for jouney
    void gatherSupplies( void );
    
    // buy more supplies
    void buyMoreSupplies( void );
    
    // gather crew for jouney
    void gatherCrew( void );

    // operations to run at the begining of each iteration
    void newIteration( void );
    
    // print current game status
    void printStatus(int itrs);
    
    // continue jouney
    void continueMoving( void );

    // check if reached a planet to stop at
    void checkPlanet( void );
    
    // check if traveled through an asteroid belt
    void asteroidBelt( void );
    
    // take a rest
    void pitstop( void );
    
    // hunt for food
    void huntSpaceBuffalo( void );
    
    // heal / apply medicine
    void applyMedicine( void );
    
    // eat
    void eat( void );
    
    // repair damaged ship
    void repairShip( void );
    
    // check if win condition is met
    bool checkWin( void );
    
    // check if user is still alive
    bool checkAlive( void );
    
    // generate a random number between min and max
    double generateRandom(int min, int max);
    
    // generate a random number beween 0 and 1
    double generateRandomZeroOne( void );
    
    
    /*****************
     *
     *   variables
     *
     *****************/

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
    
    // budget
    double defaultBudget{500.0};
    double budget;
    
    // travel information
    double totalDistance{6000.0};
    double distanceTraveled{0.0};
    double numberOfPlanets{6};
    double distanceBetweenPlanets;
    int planetsPast{0};
    double distanceFromLastPlanet{0.0};
    
    // vitals
    double currentHealth{100.0};
    double currentHunger{100.0};
    double currentShipDamage{0.0};
    bool shipDown{0};
    
    // extra inventory
    double currentFoodLevel{0.0};
    double currentSaleMaterial{0.0};

};

#endif /* SpaceVoyage_hpp */
