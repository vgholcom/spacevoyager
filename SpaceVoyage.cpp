// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// SpaceVoyage.cpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#include "SpaceVoyage.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

// constructor
SpaceVoyage::SpaceVoyage()
{
    
    // default difficulty
    int defaultDifficulty{2};
    
    // initialize with default difficulty
    initializeVoyage( defaultDifficulty );
    
}


// constructor
SpaceVoyage::SpaceVoyage( int difficulty )
{
    
    // initialize
    initializeVoyage( difficulty );
    
}


// destructor
SpaceVoyage::~SpaceVoyage()
{
}


// initialize voyage
void SpaceVoyage::initializeVoyage( int difficulty )
{
    
    // set seed for random...
    std::srand(std::time(0));

    // set a loop variable
    bool valid = 0;
    
    // while user input is valid
    while (valid == 0)
    {
        valid = 1;
    
        // initialize budget based on difficulty
        if ( difficulty == 1 )
        {
            // easy
            budget = 1000.0;
        } else if ( difficulty == 2 )
        {
            // medium
            budget = 500.0;
        } else if ( difficulty == 3 )
        {
            // hard
            budget = 250.0;
        } else {
            
            // invalid entry, prompt user again
            std::cout << "Error: Invalid difficulty entered. Try again. Choose a difficulty. 1. easy\n2. medium\n3. hard" << std::endl;
            std::cin >> difficulty;
            valid = 0;
        }
    }

    // add available supplies to vector
    suppliesVector.push_back(&spaceship);
    suppliesVector.push_back(&blasterbolts);
    suppliesVector.push_back(&medicine);
    suppliesVector.push_back(&fuel);
    suppliesVector.push_back(&parts);

    // add avaliable crew to vector
    crewVector.push_back(&navigator);
    crewVector.push_back(&mechanic);
    crewVector.push_back(&doctor);
    crewVector.push_back(&investor);
    crewVector.push_back(&scientist);
    
    // calculate the distance between cities
    distanceBetweenPlanets = totalDistance / numberOfPlanets;
    
}


// start game
void SpaceVoyage::startGame( void )
{
    
    // variables
    bool game{1};           // game loop
    int itrs{0};            // iteration counter
    int userResponse{0};   // user response
    bool valid = 0;         // valid response loop
    
    // output intro to user
    std::cout << "Welcome to the game. Your goal is to make it across the galaxy. Let's begin." << std::endl;

    // gather supplies
    gatherSupplies();
    
    // gather team
    gatherCrew();
    
    // start jouney
    // while not game over
    while ( game )
    {
        // print status
        printStatus( itrs );
        
        // new iteration housekeeping
        newIteration();
        
        // while user response is invalid
        valid = 0;
        while (valid == 0)
        {
            // choose to move or rest
            std::cout << "Would you like to continue on your jouney or take a pit stop here? 0 for rest, 1 for continue." << std::endl;
            std::cin >> userResponse;
            valid = 1;
            
            // loop through responses
            if ( userResponse == 0 )
            {
                // user chose to rest
                pitstop();
                
            } else if ( userResponse == 1 ) {
                
                // user chose to keep moving, make sure the ship isn't broken
                if (!shipDown) { continueMoving(); }
                
            } else {
                
                // invalid user entry, try again
                std::cout << "Error: Invalid response entered. Try again." << std::endl;
                valid = 0;
            }
        }
        
        // check if game continues
        game = checkAlive() && checkWin();
        
        // increase iteration
        itrs++;
    }
}


// gather initial supplies
void SpaceVoyage::gatherSupplies( void )
{
    
    // init vars
    int number{0};      // user input
    double spent{0.0};  // amount spent
    
    // print descriptions
    std::cout << std::fixed << std::setprecision(2) << "You have $" << budget << " to spend, lets gather supplies for your journey. Avaliable supplies include: " << std::endl;
    
    // polymorphically process each element in vector to show supply info
    for (Supplies* supplyPtr : suppliesVector)
    {
        // output supply info
        supplyPtr->getInfo();
    }

    // loop through supplies, get amounts from user
    std::cout << "Now it's time to buy your supplies." << std::endl;
    for (Supplies* supplyPtr : suppliesVector) {
        
        // if budget is greater than 0
        if ( budget > 0.0 )
        {
            // print item name and cost
            supplyPtr->purchaseIntro();
        
            // get quanity from user
            std::cin >> number;
            
            // calcluate amount to be spent
            spent = number * supplyPtr->getSupplyPrice();
            
            // check if user can afford
            if ( budget - spent >= 0 )
            {
                // add +N to supplyQuantity
                supplyPtr->buySupply( number );
            
                // reduce from budget
                budget = budget - spent;
            
            } else {
                // not enough money
                std::cout << "You do not have enough money to buy this supply." << std::endl;
            }
        
            // print updated budget
            std::cout << "You have $" << budget << " left to spend." <<std::endl;
            
        } else {
            
            // user doesn't have enough money to buy any more supplies
            std::cout << "You have spent all of your money." << std::endl;
            
        }
    }
}


// gather initial supplies
void SpaceVoyage::buyMoreSupplies( void )
{
    
    // init vars
    int number{0};      // user input
    double spent{0.0};  // amount spent
    
    // print descriptions
    std::cout << std::fixed << std::setprecision(2) << "You have $" << budget << " to spend on supplies. Avaliable supplies include: " << std::endl;
    
    // polymorphically process each element in vector to show supply info
    for (Supplies* supplyPtr : suppliesVector)
    {
        // if not spaceship
        if (!supplyPtr->checkIfSpaceship())
        {
            // output supply info
            supplyPtr->getInfo();
        }
    }
    
    // loop through supplies, get amounts from user
    std::cout << "Now it's time to buy your supplies." << std::endl;
    for (Supplies* supplyPtr : suppliesVector) {
        
        // if budget is greater than 0 and not spaceship
        if ( budget > 0.0 && !supplyPtr->checkIfSpaceship())
        {
            // print item name and cost
            supplyPtr->purchaseIntro();
            
            // get quanity from user
            std::cin >> number;
            
            // calcluate amount to be spent
            spent = number * supplyPtr->getSupplyPrice();
            
            // check if user can afford
            if ( budget - spent >= 0 )
            {
                // add +N to supplyQuantity
                supplyPtr->changeQuantity( number );
                
                // reduce from budget
                budget = budget - spent;
                
            } else {
                // not enough money
                std::cout << "You do not have enough money to buy this supply." << std::endl;
            }
            
            // print updated budget
            std::cout << "You have $" << budget << " left to spend." <<std::endl;
            
        } else if (budget <= 0.0) {
            
            // user doesn't have enough money to buy any more supplies
            std::cout << "You have spent all of your money." << std::endl;
            
        }
    }
}


// gather crew
void SpaceVoyage::gatherCrew( void )
{

    // init vars
    bool choice;        // user input
    int crewCount{0};   // current number of crew members
    int maxCrew{3};     // maximum number of crew members
    
    // print crew descriptions
    std::cout << std::fixed << std::setprecision(2) << "\nYou can choose three crew members to join you on your journey. Avaliable crew includes: " << std::endl;
    
    // polymorphically process each element in vector to output crew info
    for (Crew* crewPtr : crewVector)
    {
        // crew information
        crewPtr->getInfo();
    }
    
    // choose crew members while not at maximum
    std::cout << "Now its time to choose your crew: (1 for yes, 0 for no)." << std::endl;
    while ( crewCount < (maxCrew - 1) )
    {
        // for each crew member
        for (Crew* crewPtr : crewVector) {
            
            // if member hasn't been chosen already
            if ( !crewPtr->isPresent() && crewCount < 3)
            {
                // get user choise, 0 or 1
                crewPtr->chooseIntro();
                std::cin >> choice;
                
                // set member variable to 0 or 1
                crewPtr->setPresent((bool)choice);
                
                // increment crew count
                crewCount = crewCount + choice;
                
                // notify user of number left
                std::cout << "You have " << maxCrew - crewCount << " crew members left to choose." << std::endl;
            }
        }
    }
    
    std::cout << "Your crew has been chosen. Let's begin the jouney" << std::endl;
    
}


// print status
void SpaceVoyage::printStatus( int itrs )
{
    
    std::cout << "It's been " << itrs << " days. You have traveled " << distanceTraveled << " lightyears out of " << totalDistance << ". You are " << (distanceTraveled / totalDistance) * 100.0 << "% completed with your jouney. " << std::endl;
    std::cout << "Your health is currently at " << currentHealth << "%, your hunger is at " << currentHunger << "%, and the current spaceship damage is " << currentShipDamage << "%." << std::endl;
    std::cout << "You have $" << std::fixed << std::setprecision(2) << budget << "." << std::endl;
    std::cout << "Your crew consists of: ";
    
    // print crew
    for (Crew* crewPtr : crewVector)
    {
        if ( crewPtr->isPresent() )
        {
            crewPtr->printCrewName();
        }
    }
    std::cout << std::endl;
    
    // print supplies
    std::cout << "Your supply inventory consists of:\nItem:\t\tQuantity:" << std::endl;
    for (Supplies* supplyPtr : suppliesVector)
    {
        supplyPtr->printItemName();
        supplyPtr->printQuantity();
    }

    // other items
    std::cout << "Additionally, you have: " << std::endl;
    std::cout << "Food\t\t\t\t" << currentFoodLevel << std::endl;
    std::cout << "Material\t\t\t" << currentSaleMaterial << std::endl;

}


// run at each iteration
void SpaceVoyage::newIteration( void )
{

    // variables
    int healthDecreaseLowerBound{0};    // decrease health by 0 - 5 %
    int healthDecreaseUpperBound{5};
    int hungerDecreaseLowerBound{2};    // decrease hunger by 2 - 7 %
    int hungerDecreaseUpperBound{7};
    
    // if doctor is on crew, lower probability of getting sick
    if ( doctor.isPresent() )
    {
        // decrease lower & upper bounds by advantage
        healthDecreaseLowerBound = healthDecreaseLowerBound / doctor.getAdvantage();
        healthDecreaseUpperBound = healthDecreaseUpperBound / doctor.getAdvantage();
    }
    
    // update current health
    currentHealth = std::max(0.0, currentHealth - generateRandom(healthDecreaseLowerBound, healthDecreaseUpperBound));

    // update current hunger
    currentHunger = std::max(0.0, currentHunger - generateRandom(hungerDecreaseLowerBound, hungerDecreaseUpperBound));
    
    // decrease ship damage.. proportional to ship cost
    currentShipDamage = std::max(0.0, currentShipDamage +  generateRandom(0, (1/spaceship.checkQuantity())*100));
    
    // check ship damage
    if ( currentShipDamage >= 100.0 )
    {

        // ship is too damaged to continue
        std::cout << "Your ship is too damaged to continue on, you must fix it to continue." << std::endl;
        shipDown = 1;

    }
}


// rest
void SpaceVoyage::pitstop( void )
{

    // variables
    int userResponse;   // user response
    bool valid{0};     // valid response loop
    
    // while user response is invalid
    while (valid == 0)
    {
        // set user response to valid
        valid = 1;
        
        // prompt user
        std::cout << "You are now resting. Would you like to:\n1. Hunt for space buffalo. \n2. Use medicine to heal. \n3. Eat \n4. Repair the ship." << std::endl;
        
        // read user response
        std::cin >> userResponse;
        
        // loop through response
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


// hunt for space buffalo
void SpaceVoyage::huntSpaceBuffalo( void )
{

    // variables
    bool keepTrying{1};        // user input to keep hunting
    int killProbability{75};   // default success rate
    bool gotIt{0};             // if succeeded
    
    //  if there is enough ammo, continue
    if ( blasterbolts.checkQuantity() > 0 )
    {
        // user wants to keep trying, and there's enough ammo
        while ( keepTrying && blasterbolts.checkQuantity() > 0 )
        {
            // decrease blaster bolts
            blasterbolts.changeQuantity(-1);
            
            // check if success
            gotIt = (rand() % 100) < killProbability;
            
            // if success
            if ( gotIt )
            {
                
                // increase food and material
                std::cout << "You got him. ";
                currentFoodLevel = currentFoodLevel + generateRandom(1, 5);
                currentSaleMaterial = currentSaleMaterial + generateRandom(0, 3);
                
            } else {
                
                // missed space buffalo
                std::cout << "Sorry, you missed. ";
                
            }
            
            // print information for user
            std::cout << "You currently have " << currentFoodLevel << " food, and " << currentSaleMaterial << " material to sell. There are " << blasterbolts.checkQuantity() << " blaster bolts left. ";
            
            // if enough blaster bolts, prompt to try again
            if ( blasterbolts.checkQuantity() >= 0 )
            {
                
                // get user input
                std::cout << "Would you like to try again? 1 to try again, else 0." << std::endl;
                std::cin >> keepTrying;
            } else {
                
                // not enough blaster bolts, user must stop
                keepTrying = 0;
                
            }
        }
        
        // if not enough blaster bolts
        if ( blasterbolts.checkQuantity() <= 0 )
        {
            
            // alert user not enough to hunt
            std::cout << "You dont have enough blaster bolts to continue hunting." << std::endl;
            
        }
    } else {
        
        // alert user not enough to hunt
        std::cout << "You dont have enough blaster bolts to do that." << std::endl;
        
    }
}


// apply medicine
void SpaceVoyage::applyMedicine( void )
{

    // variables
    int healthIncreaseLowerBound{1};    // lower bound
    int healthIncreaseUpperBound{6};    // upper bound
    
    // if doctor is on crew, medicine is more effective
    if ( doctor.isPresent() )
    {
        
        // increase lower and upper bound
        healthIncreaseLowerBound = healthIncreaseLowerBound * doctor.getAdvantage();
        healthIncreaseUpperBound = healthIncreaseUpperBound * doctor.getAdvantage();
        
    }
    
    // apply medicine if avaliable
    if ( medicine.checkQuantity() > 0 )
    {
        
        // increase health with medicine
        currentHealth = std::max(100.0, currentHealth + generateRandom(healthIncreaseLowerBound, healthIncreaseUpperBound));
        
        // decrease medicine
        medicine.changeQuantity(-1.0);

    } else {
        
        // not enough medicine
        std::cout << "You do not have enough medicine to heal yourself." << std::endl;

    }
}


// eat
void SpaceVoyage::eat( void )
{
    
    // variables
    double foodInTake{1.0};     // food amount
    int hungerLowerBound{1};    // lower bound
    int hungerUpperBound{5};    // upper bound
    
    // check user food quantity
    if (currentFoodLevel > 0)
    {
        
        // decrease food
        currentFoodLevel = currentFoodLevel - foodInTake;
        
        // increase hunger
        currentHunger = std::max(100.0, currentHunger + generateRandom(hungerLowerBound, hungerUpperBound));
        
    } else {
        
        // user doesnt have food
        std::cout << "You don't have any food. Try hunting." << std::endl;
        
    }
}


// repair ship
void SpaceVoyage::repairShip( void )
{
    
    // variables
    int damageIncreaseLowerBound{1};    // lower bound
    int damageIncreaseUpperBound{6};    // upper bound
    
    // if mechanic is on crew, parts are more effective
    if ( mechanic.isPresent() )
    {
        
        // update lower / upper bounds
        damageIncreaseLowerBound = damageIncreaseLowerBound * mechanic.getAdvantage();
        damageIncreaseUpperBound = damageIncreaseUpperBound * mechanic.getAdvantage();
        
    }
    
    // use parts
    // check for parts
    if ( parts.checkQuantity() > 0 )
    {
        
        // update ship damage
        currentShipDamage = std::min(0.0, currentShipDamage - generateRandom(damageIncreaseLowerBound, damageIncreaseUpperBound));
        
        // decrease parts
        parts.changeQuantity(-1.0);
        
    } else {
        
        // not enough parts to fix ship
        std::cout << "You do not have enough parts to fix your ship." << std::endl;

    }
    
    // restore ship if down
    if (shipDown && currentShipDamage >= 100.0)
    {
        
        shipDown = 0;
        
    }
}


// continue jouney
void SpaceVoyage::continueMoving( void )
{
    
    // variables
    double maxDistanceDelta{600.0};     // total possible distance
    double lightyearsPerGallon{90.0};   // number of lightyears / gallon
    double distance{0.0};               // distance traveled
    double availableFuel{0.0};          // avalible fuel
    double attemptedFuel{0.0};          // fuel attempting to use
    
    double distanceFromLastPlanetPlusDistance{0.0};       // distance from last plus distance
    double extraDistance{0.0};          // distace from visiting planet
    double distanceLeftToPlanet{0.0};   // distance to planet
    bool notEnoughFuel{0};              // not enough fuel
    // calculate distance = f(damage, navigator)
    distance = maxDistanceDelta * ( 1 + navigator.getAdvantage() * (int)navigator.isPresent() - (( 100 - currentShipDamage )/100) * 0.5 ) * generateRandomZeroOne();
    
    // check avaliable fuel
    availableFuel = (double)fuel.checkQuantity();
    
    distanceFromLastPlanetPlusDistance = distanceFromLastPlanet + distance;
    
    // check if we hit a planet
    if (distanceFromLastPlanetPlusDistance >= distanceBetweenPlanets)
    {
        // visiting planets
        extraDistance = distanceFromLastPlanetPlusDistance - distanceBetweenPlanets;
        distanceLeftToPlanet = distance - extraDistance;
        
        // check if there's enough fuel
        attemptedFuel = distanceLeftToPlanet / lightyearsPerGallon;
        if ( attemptedFuel < availableFuel )
        {
            // decrement fuel quantity
            fuel.changeQuantity(-attemptedFuel);
            
            // increase progress
            distanceTraveled += distanceLeftToPlanet;
            
            // status update to user
            std::cout << "You have traveled " << distanceLeftToPlanet << " lightyears and have reached a planet. You may stop here to buy and sell materials." << std::endl;
            
            // go to planet
            checkPlanet();
            
            // set new distance to extra distance to keep going
            distance = extraDistance;
            distanceFromLastPlanet = 0.0;
            
        } else {
            // not enough fuel...
            notEnoughFuel = 1;
            
            // not enough fuel to planet, go as far as possible
            // calculate distance
            distance = availableFuel * lightyearsPerGallon;
            
            // decrement fuel quantity
            fuel.changeQuantity(-availableFuel);
            
            // increase progress
            distanceTraveled += distance;
            
            // if not at goal planet, and out of fuel shipDown, so game over
            if ( distanceTraveled < totalDistance )
            {
                shipDown = 1;
            }
            
            // status update to user
            std::cout << "You dont have enough fuel, you were only able to travel " << distance << " lightyears." << std::endl;
        }
    
    } else {
        distanceFromLastPlanet = distanceFromLastPlanet + distance;
    }
    
    
    if (!notEnoughFuel)
    {
        // check avaliable fuel
        availableFuel = (double)fuel.checkQuantity();
        
        // calculate attempted fuel
        attemptedFuel = distance/lightyearsPerGallon;
        
        // check if we run out of fuel
        if ( attemptedFuel < availableFuel )
        {
            
            // decrement fuel quantity
            fuel.changeQuantity(-attemptedFuel);
            
            // increase progress
            distanceTraveled += distance;
            
            // status update to user
            std::cout << "You have traveled " << distance << " lightyears today. Your total jouney has been " << distanceTraveled << " lightyears." << std::endl;
            
        } else {
            
            // not enough fuel for full distance, go as far as possible
            // calculate distance
            distance = availableFuel * lightyearsPerGallon;
            
            // decrement fuel quantity
            fuel.changeQuantity(-availableFuel);
            
            // increase progress
            distanceTraveled += distance;
            
            // if not at goal planet, and out of fuel shipDown, so game over
            if ( distanceTraveled < totalDistance )
            {
                shipDown = 1;
            }
            
            // status update to user
            std::cout << "You dont have enough fuel, you were only able to travel " << distance << " lightyears." << std::endl;
            
        }
    }

    // if past through an astroid belt
    asteroidBelt();

}


// traveling through astroid belt
void SpaceVoyage::asteroidBelt( void )
{
    
    // variables
    double asteroidProbability{25.0};   // probability of being in asteroid
    double potentialDamage{0.0};        // potential damage
    int damageLowerBound{0};            // damage lower bound
    int damageUpperBound{25};           // damage upper bound
    int potentialMinerals{0};           // potental minerals
    int miningLowerBound{0};            // mining lower bound
    int miningUpperBound{25};           // mining upper bound
    bool inAstroidBelt{0};              // bool, if in asteroid belt
    
    // calculate if in asteroid belt
    inAstroidBelt = (rand() % 100) < asteroidProbability;
    if (inAstroidBelt)
    {
        // traveling through asteroid belt
        std::cout << "You have traveled through an asteroid belt. Let's check for damage... ";
        
        // if mechanic is present, damage is less
        if ( mechanic.isPresent() )
        {
            
            // calculate new lower / upper bounds
            damageLowerBound = damageLowerBound / mechanic.getAdvantage();
            damageUpperBound = damageUpperBound / mechanic.getAdvantage();
            
        }
        
        // calculate potential damage
        potentialDamage = (double)generateRandom(damageLowerBound, damageUpperBound);
        
        // if there is damage
        if (potentialDamage > 0)
        {
            
            // add new damage to ship damage
            currentShipDamage = std::max(0.0, currentShipDamage + potentialDamage);
            std::cout << "Your ship has gained " << potentialDamage << " damage while traveling through the belt. Your total damage is now " << currentShipDamage << "." << std::endl;
            
        } else {
            
            // no new damage
            std::cout << "You lucked out, no damage this time." << std::endl;
            
        }
        
        // mining
        std::cout << "On the bright side, let's see if you can mine for some materials to sell at the next planet... ";
        
        // if scientist is present
        if ( scientist.isPresent() )
        {
            
            // modify upper / lower bound
            miningLowerBound = miningLowerBound / scientist.getAdvantage();
            miningUpperBound = miningUpperBound / scientist.getAdvantage();
            
        }
        
        // calculate potential minerals
        potentialMinerals = generateRandom(miningLowerBound, miningUpperBound);
        
        // if minerals
        if (potentialMinerals > 0)
        {
            
            // add new minerals to current
            currentSaleMaterial = currentSaleMaterial + potentialMinerals;
            std::cout << "You have gained " << potentialMinerals << " while traveling through the belt. Your total materials is now " << currentSaleMaterial << "." << std::endl;
            
        } else {
            
            // no new minerals
            std::cout << "Too bad, you didn't get anything this time." << std::endl;
            
        }
    }
}


// check on planet
void SpaceVoyage::checkPlanet( void )
{
    double materialCost{1.0};
    double numSell{0.0};

    // sell material
    if (currentSaleMaterial > 0)
    {
        std::cout << "You have " << currentSaleMaterial << " material to sell. ";
        
        // check for investor
        if ( investor.isPresent() )
        {
            materialCost = investor.getAdvantage() * materialCost;
        }
        std::cout << "Your material is worth " << materialCost << " per item. How much would you like to sell?";

        // get user response
        std::cin >> numSell;
        
        if ( numSell > currentSaleMaterial ) {
            std::cout << "You don't have that much material, selling all of it." << std::endl;
            numSell = currentSaleMaterial;
        }
        
        budget = budget + numSell*materialCost;
    }
    
    // buy all supplies except spaceship
    buyMoreSupplies();
}


// check if user is alive
bool SpaceVoyage::checkAlive( void )
{

    // variables
    bool status{1};  // status

    // check death conditions
    if ( currentHealth <= 0.0  )
    {

        // if current health is less than 0
        std::cout << "You have died. Game Over." << std::endl;
        status = 0;

    } else if ( currentHunger <= 0.0 )
    {

        // if hunger is less than 0
        std::cout << "You have died due to starvation. Game Over." << std::endl;
        status = 0;

    } else if ( fuel.checkQuantity() <=0 )
    {

        // if fuel is less than 0
        std::cout << "You have run out of fuel. Game Over." << std::endl;
        status = 0;

    }

    // return status
    return status;

}


// check win condition
bool SpaceVoyage::checkWin( void )
{

    // variables
    bool status{1}; // status

    // win if traveled distance >= total distance
    if ( distanceTraveled >= totalDistance )
    {

        // user won
        std::cout << "Congrats, you have reached the destination planet!" << std::endl;
        status = 0;

    }

    // return status
    return status;
}


// generate random number
double SpaceVoyage::generateRandom( int min, int max )
{

    // return random number between min and max
    return (double)(rand() % ( max - min + 1) + min);

}


// generate random between 0 and 1
double SpaceVoyage::generateRandomZeroOne()
{

    // return value between 0 and 1
    return ((double) rand() / (RAND_MAX));

}
