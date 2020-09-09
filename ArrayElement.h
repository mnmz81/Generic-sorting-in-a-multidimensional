/*This object is a self built array that contains objects of type "Element"*/
#ifndef ArrayElement_H
#define ArrayElement_H
#include "Element.h"
#include <fstream>
using namespace std;

class ArrayElement
{
private:
    Element* array;
    int size,currnt,dimNAll,dimMAll;
    void Swap(Element& a, Element& b);
    void QuickSort(Element* a, int left, int right);
    int* ParetoRanking(Vect<float>* array,int size);
    void ElementsReordering(Element* a,int size);
    void ParetoSorting(Element* a,int size);
public:
    ArrayElement(); //default c'tor
    ArrayElement(int size,int dimN,int dimM); //c'tor
    ArrayElement(const ArrayElement& e); //copy c'tor
    ~ArrayElement(); //d'tor
    bool IsFull() const; 
    bool IsEmpty() const;
    void Insert(Element& temp); 
    Element* GetElementAt(int i) const; //returns a pointer to an element in the array by index
    int GetSize(){return size;};
    int GetDimNAll(){return dimNAll;};
    int GetDimMAll(){return dimMAll;};
    void UpdateFvec(Element* element);
    void UpdateFvecAll();
    void Update(); //function called after each iteration
    void PrintArray(ofstream* of); //outputs the array to a specified file(overloaded function)
    void PrintArray(); //outputs the array to the terminal(overloaded function)
    ArrayElement& operator=(const ArrayElement& v); //overloaded operator
};

#endif