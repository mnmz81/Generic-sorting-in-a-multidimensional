/*in order for this simulation to work the main function that calls this simulation needs to surround it with
    try & catch(should catch a string and print it)*/
    
#ifndef _SIMULATION_h
#define _SIMULATION_h
#include "ArrayElement.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

class Simulation{
    private:
        ArrayElement* array_element;
        int time1;
        int size;
        ifstream input_file;
        ofstream output_file;
        stringstream err_msg; //used for exception handling

    public:
        Simulation& operator=(const Simulation& rhs); //overloaded operator
        Simulation(); //default c'tor
        Simulation(Simulation& temp); //copy c'tor
        Simulation(char* a, char* b); //c'tor
        ~Simulation(); //d'tor
        void Run(); //run the program
        void Error(); //error
};
#endif