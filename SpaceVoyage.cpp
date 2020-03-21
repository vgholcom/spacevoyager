//
//  SpaceVoyage.cpp
//  SpaceVoyage
//
//  Created by Tori Tenney on 3/10/20.
//  Copyright © 2020 Tori Tenney. All rights reserved.
//

#include "SpaceVoyage.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

SpaceVoyage::SpaceVoyage()
{
    // default difficulty
    int defaultDifficulty{2};
    initializeVoyage( defaultDifficulty );
    
}


// constructor
SpaceVoyage::SpaceVoyage( int difficulty )
{
    initializeVoyage( difficulty );
}


// destructor
SpaceVoyage::~SpaceVoyage()
{
}


void SpaceVoyage::initializeVoyage( int difficulty )
{
    // for random...
    std::srand(std::time(0));

    // initialize budget
    if ( difficulty == 1 ) // easy
    {
        budget = 1000.0;
    } else if ( difficulty == 2 ) // medium
    {
        budget = 500.0;
    } else if ( difficulty == 3 ) // hard
    {
        budget = 250.0;
    } else {
        std::cout << "Error: Invalid difficulty entered." << std::endl;
        return;
    }

    // initialize avaliable supplies
    suppliesVector.push_back(&spaceship);
    suppliesVector.push_back(&blasterbolts);
    suppliesVector.push_back(&medicine);
    suppliesVector.push_back(&fuel);
    suppliesVector.push_back(&parts);

    // initialize avaliable crew
    crewVector.push_back(&navigator);
    crewVector.push_back(&mechanic);
    crewVector.push_back(&doctor);
    crewVector.push_back(&investor);
    crewVector.push_back(&scientist);
    
    // calculate the distance between cities
    distanceBetweenCities = totalDistance / numberOfCities;
}


void SpaceVoyage::startGame( void )
{
    bool game{1};
    int itrs{0};
    int userResponse;

    // begin the game
    std::cout << "Welcome to the game. Your goal is to make it across the galaxy. Let's begin." << std::endl;

    // gather supplies
    gatherSupplies();
    
    // gather team, choose 3
    gatherCrew();
    
    // start jouney
    while ( game ) // while not game over
    {

        // print status
        printStatus(itrs);
        
        // iteration
        newIteration();
        
        // choose to move or rest
        std::cout << "Would you like to continue on your jouney or take a pit stop here? 0 for rest, 1 for continue." << std::endl;
        std::cin >> userResponse;
        bool valid = 0;
        
        // while user response is invalid
        while (valid == 0)
        {
            valid = 0;
            if ( userResponse == 0 )
            {
                // user chose to rest
                pitstop();
                
            } else if ( userResponse == 1 ) {
                
                // user chose to keep moving
                if (!shipDown) { continueMoving(); }
                
            } else {
                
                // invalid user entry
                std::cout << "Error: Invalid response entered. Try again. 0 to rest, 1 to continue on the jouney." << std::endl;
                valid = 1;
            }
        }
        
        // check if game continues
        game = checkAlive() || checkWin();
        
        // increase iteration
        itrs++;
    }
    
    return;
}

void SpaceVoyage::gatherSupplies( void )
{
    int number{0};
    
    // print descriptions
    std::cout << std::fixed << std::setprecision(2) << "You have $" << budget << " to spend, lets gather supplies for your journey. Avaliable supplies include: " << std::endl;
    
    // polymorphically process each element in vector employees
    for (Supplies* supplyPtr : suppliesVector) {
        supplyPtr->getInfo(); // output supply
    }

    // set supply amounts
    std::cout << "Now it's time to buy your supplies." << std::endl;
    
    for (Supplies* supplyPtr : suppliesVector) {
        // print item name and cost
        supplyPtr->purchaseIntro();
        
        // get number from user
        std::cin >> number;
        
        // add +N to supplyQuantity
        supplyPtr->buySupply( number );
        
        // calculate spent
        double spent = number * supplyPtr->getSupplyPrice();
        
        // reduce from budget
        budget = budget - spent;
        
        // print updated budget
        std::cout << "You have $" << budget << " left to spend." <<std::endl;
    }
}

void SpaceVoyage::gatherCrew( void )
{
    bool choice;
    int crewCount = 0;
    int maxCrew = 3;
    
    // print crew descriptions
    std::cout << std::fixed << std::setprecision(2) << "You can choose three crew members to join you on your journey. Avaliable crew includes: " << std::endl;
    
    // polymorphically process each element in vector employees
    for (Crew* crewPtr : crewVector) {
        crewPtr->getInfo(); // output supply
    }

    std::cout << "Now its time to choose your crew." << std::endl;
    while ( crewCount < (maxCrew - 1) )
    {
        for (Crew* crewPtr : crewVector) {
            if ( !crewPtr->isPresent() )
            {
                crewPtr->chooseIntro(); // output supply
                std::cin >> choice;
                crewPtr->setPresent(choice);
                
                crewCount = crewCount + choice;
                std::cout << "You have " << maxCrew - crewCount << " crew members left to choose." << std::endl;
            }
        }
    }
}


void SpaceVoyage::printStatus(int itrs)
{
    std::cout << "It's been " << itrs << " days." <<std::endl;
    std::cout << "You have traveled " << distanceTraveled << " lightyears out of " << totalDistance << ". You are " << (distanceTraveled / totalDistance) * 100.0 << "% completed with your jouney. " << std::endl;
    std::cout << "Your health is currently at " << currentHealth << "% and your hunger is at " << currentHunger << "%. " << std::endl;
    std::cout << "You have $" << std::fixed << std::setprecision(2) << budget << "." << std::endl;
    std::cout << "Your crew consists of: ";
    for (Crew* crewPtr : crewVector) {
        if ( crewPtr->isPresent() )
        {
            crewPtr->printCrewName();
        }
    }
    std::cout << "Your inventory consists of:\nItem:\t\tQuantity:" << std::endl;
    for (Supplies* supplyPtr : suppliesVector) {
        supplyPtr->printItemName();
        supplyPtr->printQuantity();
    }
}


void SpaceVoyage::newIteration()
{
    // decrease health by 0 - 5 %
    currentHealth = currentHunger - generateRandom(0, 5);
    
    // decrease hunger by 2 - 7 %
    currentHunger = currentHunger - generateRandom(2, 7);
    
    // decrease ship damage.. proportional to ship cost
    currentShipDamage = currentShipDamage - generateRandom(0, (1/spaceship.checkQuantity())*100);
    
    // check ship damage
    if ( currentShipDamage < 0.0 )
    {
        std::cout << "Your ship is too damaged to continue on, you must fix it to continue." << std::endl;
        shipDown = 1; 
    }
}


void SpaceVoyage::checkPlanet()
{
    // if at 1/6 planets
    //      can buy / sell
    // check if we're near a planet
}


void SpaceVoyage::pitstop()
{
    int userResponse;
    bool valid = 0;
    
    // while user response is invalid
    while (valid == 0)
    {
        // set user response to valid
        valid = 1;
        
        // prompt user
        std::cout << "You are now resting. Would you like to:\n 1. Hunt for space buffalo. \n2. Use medicine to heal. \n3. Eat \n4. Repair the ship." << std::endl;
        
        // read user response
        std::cin >> userResponse;
        
        if ( userResponse == 1 )
        {
            // hunt
            huntSpaceBuffalo();
            
        } else if ( userResponse == 2 ){
            
            // heal
            applyMedicine();
            
        } else if ( userResponse == 3 ){
            
            // eat
            eat();
            
        } else if ( userResponse == 4 ){
            
            // repair
            repairShip();

        } else {
            
            // invalid, repeat
            std::cout << "Invalid response. Choose again." << std::endl;
            valid = 0;
            
        }
    }

}

void SpaceVoyage::huntSpaceBuffalo()
{
    // hunt:
    bool keepTrying = 1;
    int killProbability = 75;
    
    //    decrease ammo
    if ( blasterbolts.checkQuantity() > 0 )
    {
        while ( keepTrying && blasterbolts.checkQuantity() > 0 )
        {
            blasterbolts.changeQuantity(-1);
            bool gotIt = (rand() % 100) < killProbability;
            if ( gotIt )
            {
                currentFoodLevel = currentFoodLevel + generateRandom(1, 5);
                currentSaleMaterial = currentSaleMaterial + generateRandom(0, 3);
            } else {
                std::cout << "Sorry, you missed. ";
            }
            std::cout << "Would you like to try again? 1 to try again, else 0." << std::endl;
            std::cin >> keepTrying;
        }
    } else {
        std::cout << "You dont have enough blaster bolts to do that." << std::endl;
    }
    
    //    increase food
}


void SpaceVoyage::applyMedicine()
{
    // rest:
    //    improve health
}


void SpaceVoyage::eat()
{
    // decrease food
    double foodInTake{1.0};
    currentFoodLevel = currentFoodLevel - foodInTake;
    
    // increase hunger
    currentHealth = std::max(100.0, currentHunger + generateRandom(1, 5));
}


void SpaceVoyage::repairShip()
{
    // check for parts
    // check for mechanic
    // decrease damage
    if (shipDown && currentShipDamage > 0)
    {
        shipDown = 0;
    }
}


void SpaceVoyage::continueMoving()
{
    double distanceDelta{100.0};
    
    // degrade fuel
    
    
    // increase progress
    distanceTraveled+=distanceDelta;
    
    // moving:
    // degrade fuel
    // calculate if we've broken down
    // if in astroid belt:
    //      can damage ship
    //      can get minerals
}


bool SpaceVoyage::checkAlive()
{
    bool status{1};
    if ( currentHealth <= 0.0 || currentHunger <= 0.0 )
    {
        
        std::cout << "You have died due to poor health. Game Over." << std::endl;
        status = 0;
        
    }
    
    return status;
}


bool SpaceVoyage::checkWin()
{
    bool status{1};
    // win if traveled distance >= total distance
    if ( distanceTraveled >= totalDistance )
    {
        
        std::cout << "Congrats, you have reached the destination planet!" << std::endl;
        status = 0;
        return 0;
        
    }
    return status;
}

int SpaceVoyage::generateRandom(int min, int max)
{
    return rand()%(max-min + 1) + min;
}
