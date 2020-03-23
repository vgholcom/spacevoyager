// Victoria Tenney
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// Final Project
// 3/24/20
// Scientist.hpp
// This is a text-based game based on getting a space traveler from one planet to the next.

#ifndef Scientist_hpp
#define Scientist_hpp

#include <stdio.h>
#include "Crew.hpp"


// scientist class, inheritance from crew class
class Scientist : public Crew {
public:
    
    // constructor
    Scientist();
    
    // virtual destructor
    virtual ~Scientist() = default;
    
    // print crew info
    virtual void getInfo() override;
    
    // choose crew
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
    std::string crewName{"Scientist"};
    
    // crew description
    std::string crewDescription{"Has a higher probability of mining when traveling through an ateroid belt."};

    // advantage
    double advantage{2.0};
};
#endif /* Scientist_hpp */
