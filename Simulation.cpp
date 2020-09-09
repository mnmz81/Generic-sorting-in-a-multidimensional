/*code documentation in header file*/
#include "Simulation.h"
#include <cstring>
using namespace std;


Simulation::Simulation():array_element(new ArrayElement()),time1(5000),size(10){}
/**************************************************/
Simulation::Simulation(Simulation& temp):array_element(new ArrayElement()),time1(temp.time1),size(temp.size){*array_element=*temp.array_element;}
/**************************************************/
Simulation::Simulation(char* a, char* b){
   int u,n,m,t1;
   float temp;
   Element* e;
   char* get_line;

   //open input and output files and check if operation succeeded
   input_file.open(a);
   output_file.open(b);
   if(!output_file && !input_file){
      err_msg<<"ERROR: "<<a<<" does not exist or cannot be opened\n";
      throw err_msg.str(); //Main catches if needed
   }
   if(!input_file){
      err_msg<<"ERROR: "<<a<<" does not exist or cannot be opened\n";
      throw err_msg.str(); //Main catches if needed
   }
   if(!output_file){
      err_msg<<"ERROR: "<<b<<" does not exist or cannot be opened\n";
      throw err_msg.str(); //Main catches if needed
   }

   
   if(!(input_file>>u>>n>>m>>t1) || u<1 || m>n || n<0 || m<0 || t1<0){
      err_msg<<"ERROR: simulation definition in "<<a<<" is invalid\n";
      throw err_msg.str(); //Main catches if needed
   }

   array_element=new ArrayElement(u,n,m);
   time1=t1;
   size=u;
   for(int i=0;i<u;i++){
      float array[n];
      for(int j=0;j<n;j++){
         if(!(input_file>>temp)){
            err_msg<<"ERROR: population definition in "<<a<<" at line "<< i+2 <<" is invalid\n";
            throw err_msg.str(); //Main catches if needed
         }
         array[j]=temp;
         if(j+1 == n){
            get_line= new char[100];
            input_file.getline(get_line, 100);
            if(strlen(get_line)>2){
               err_msg<<"ERROR: population definition in "<<a<<" at line "<< i+2 <<" is invalid\n";
               throw err_msg.str(); //Main catches if needed
            }
         }
      }
      Vect<float> x(array,n);
      Vect<float> f(m,0);
      e=new Element(x,f);
      array_element->Insert(*e);
      delete e;
   }
   array_element->UpdateFvecAll();
}
/**************************************************/
Simulation::~Simulation(){
   delete array_element;
   input_file.close();
   output_file.close();
 }
/**************************************************/
Simulation& Simulation::operator=(const Simulation& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
       array_element=rhs.array_element;
       time1=rhs.time1;
       size=rhs.size;
    }
    return *this;
 }
/**************************************************/
void Simulation::Run(){
   array_element->PrintArray(&output_file);
   for(int i=0;i<time1;i++){
      array_element->Update();
   }
   array_element->PrintArray(&output_file);
   return;
 }
/**************************************************/
void Simulation::Error() {
    cerr << "ERROR: Invalid input."<<endl;
    exit(1);
 }
/**************************************************/