#ifndef Element_H
#define Element_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vect.h"
using namespace std;

class Element{
    private:
        int Rank;
        int dimN;
        int dimM;
        Vect<float>* Xvec;
        Vect<float>* Fvec;
    public:
        //constructors and destructor
        Element(); //create a size null array
        Element(const Vect<float>& x,const Vect<float>& f); //c'tor;
        Element(const Element& e); //copy c'tor
        ~Element();

        //getters and setters
        int  GetRank() const {return Rank;}
        int  GetDimM() const {return dimM;}
        int  GetDimN() const {return dimN;}
        Vect<float> GetFvec() {return *Fvec;}
        Vect<float> GetXvec() {return *Xvec;}
        void SetRank(int temp)  { Rank=temp;};
        void SetF(Vect<float>* temp){*Fvec=*temp;dimM=temp->GetSize();};

        void MoveXvec();
        friend bool operator>(const Element& lhs, const Element& rhs);
        friend bool operator<(const Element& lhs, const Element& rhs);
        Element& operator=(const Element& v);
        friend ostream& operator<<(ostream&,Element& e);
}; 
/*****************************************************/
#endif



