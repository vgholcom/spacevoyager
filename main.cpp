// Fig. 12.19: fig12_19.cpp
// Demonstrating downcasting and runtime type information.
// NOTE: You may need to enable RTTI on your compiler
// before you can compile this application.
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
/*
#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"
*/
#include "SpaceVoyage.hpp"
//#include "Supplies.hpp"
//#include "Spaceship.hpp"
//#include "BlasterBolts.hpp"
//#include "Medicine.hpp"
//#include "Fuel.hpp"
//#include "Parts.hpp"

int main() {
    
    int continuePlaying = 1;

    SpaceVoyage spacevoyage(2);
    
    // start game
    if ( continuePlaying == 1 )
    {
        spacevoyage.startGame();
        std::cout << "Would you like to play again? 1 to play again, 0 to stop." << std::endl;
        std::cin >> continuePlaying;
    }
    
    std::cout << "Thanks for playing!" << std::endl;
    
}
