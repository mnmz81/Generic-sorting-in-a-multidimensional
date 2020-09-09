/*This is a self built and implemented container of type vector*/
#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Vect{
    private:
        T *p; //base pointer
        int size; //number of elements
    public:
    //constructors and destructor
        Vect(); //create a size 10 array
        Vect(int n); //create a size n array
        Vect(int n,T elemts); //create a size n array whit elemets
        Vect(const T a[], int n); //initialization by array
        Vect(const Vect<T>& v); //copy constructor
        ~Vect() { delete []p; } //dwtor
        int GetSize() const {return size;}
        Vect<T>& operator=(const Vect<T>& v);
        Vect<T>& operator+(const T& v);
        const T& operator[](int i) const; //range checked element
        T& operator[](int i); //obtain range checked element
}; 
/*****************************************************/
template <class T>
Vect<T>::Vect():size(10) {p = new T[size];}
/*****************************************************/
template <class T>
Vect<T>::Vect(int n,T elemts){
    if(n<0) n=10;
    size=n;
    p=new T[n];
    for(int i=0;i<n;i++) p[i]=elemts;
 }
/*****************************************************/
template <class T>
Vect<T>::Vect(int n){
    if(n<0) n=0;
    size=n;
    p=new T[size];
 }
/*****************************************************/
template <class T>//initialization by array
Vect<T>::Vect(const T a[], int n){
    if(n<0) exit(1);
    size=n;
    p = new T[n];
    for(int i=0; i<n; ++i)
            p[i] = a[i];
 }
/*****************************************************/
template <class T>
Vect<T>::Vect(const Vect<T>& v):size(1){
    p = 0; // enabling deletion
    *this = v; // uses overloaded operator=
 }
/*****************************************************/
template <class T>
Vect<T>& Vect<T>::operator=(const Vect<T>& v){
    if(&v==this) return *this;
    delete []p;
    size = v.size;
    p = new T[size];
    for(int i=0; i<size; ++i)
        p[i] = v.p[i];
    return *this;
 }
/*****************************************************/
template <class T>
Vect<T>& Vect<T>::operator+(const T& v){
    for(int i=0;i<size;i++)
        p[i]=p[i]+v;
    return *this;
 }
/*****************************************************/
template <class T>
inline const T& Vect<T>::operator[](int i) const {
    if(i<0 || i>=size) exit(1);
    return p[i];
 }
/*****************************************************/
template <class T>
inline T& Vect<T>::operator[](int i) {
    if(i<0 || i>=size) exit(1);
    return p[i];
 }
/*****************************************************/
template <class T>
ostream& operator<<(ostream& out, const Vect<T>& v){
    for(int i=0; i<v.GetSize(); ++i){
        out<< v[i];
        if(i+1==v.GetSize()) out<<endl;
        else out<<" ";
    }
    return out;
 }
/*****************************************************/
template <class T>
istream& operator>>(istream& in, Vect<T>& v){
    for(int i=0; i<v.Size(); ++i){
        cout<<"element "<< i <<" = ";
        in>>v[i];
    }
    return in;
 } 
/*****************************************************/
