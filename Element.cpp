/*code documentation in header file*/
#include "Element.h"
using namespace std;


Element::Element():Rank(0),dimN(0),dimM(0),Xvec(new Vect<float>(0)),Fvec(new Vect<float>(0)){}
/*****************************************************/
Element::Element(const Element& e):Rank(e.Rank),dimN(e.dimN),dimM(e.dimM),Xvec(new Vect<float>(*e.Xvec)),Fvec(new Vect<float>(*e.Fvec)){}
/*****************************************************/
Element::Element(const Vect<float>& x,const Vect<float>& f):Rank(0),dimN(x.GetSize()),dimM(f.GetSize()),Xvec(new Vect<float>(x)),Fvec(new Vect<float>(f)){}
/*****************************************************/
Element::~Element(){
    delete Xvec;
    delete Fvec;
 }
/*****************************************************/
void Element::MoveXvec(){
    float r1;
    srand(time(NULL));
    r1=((float)(rand())/RAND_MAX);
    *Xvec=*Xvec+r1;
 }
/*****************************************************/
Element& Element::operator=(const Element& e){
    if(&e==this) return *this;
    *Xvec=*e.Xvec;
    *Fvec=*e.Fvec;
    Rank=e.Rank;
    dimN=e.dimN;
    dimM=e.dimM;
    return *this;
 }
/*****************************************************/
bool operator>(const Element& lhs, const Element& rhs){
    if(lhs.GetRank()>rhs.GetRank()) return true;
    return false;
 }
/*****************************************************/
bool operator<(const Element& lhs, const Element& rhs){
    if(lhs.GetRank()<rhs.GetRank()) return true;
    return false;
 }
/*****************************************************/
ostream& operator<<(ostream& out,Element& e){
    Vect<float> temp;
    temp=e.GetXvec();
    cout<<temp;
    return out;
 }
/*****************************************************/