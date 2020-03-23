// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Investor.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Investor_hpp
#define Investor_hpp

#include <stdio.h>
#include "Crew.hpp"


// investor class, inheritance from crew class
class Investor : public Crew {
public:
    
    // constructor
    Investor();
    
    // virtual destructor
    virtual ~Investor() = default;
    
    // print crew info
    virtual void getInfo() override;
    
    // print choose crew
    virtual void chooseIntro() override;
    
    // print crew name
    virtual void printCrewName() override;

    // get advantage
    int getAdvantage();
    
private:
    
    // get crew name
    std::string getCrewName();
    
    // get crew description
    std::string getCrewDescription();
    
    // crew name
    std::string crewName{"Investor"};
    
    // crew description
    std::string crewDescription{"Your money is worth more when buying items at planets."};
    
    // advantage
    double advantage{2.0};
};
#endif /* Investor_hpp */
