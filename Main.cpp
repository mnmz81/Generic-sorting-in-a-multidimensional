#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 3){
        cerr << "ERROR: Invalid input."<<endl;
        exit(1);  
    }

    try{
        Simulation s(argv[1], argv[2]);
        s.Run();
    }
    catch (string err_msg){
        cout<<err_msg;
    }
}