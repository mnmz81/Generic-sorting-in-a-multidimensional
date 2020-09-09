/*code documentation in header file*/
#include "ArrayElement.h"
using namespace std;


/**********************************************************/
ArrayElement::ArrayElement():array(new Element[10]),size(10),currnt(0),dimNAll(10),dimMAll(10){}
/**********************************************************/
ArrayElement::ArrayElement(int n,int dimN,int dimM):array(new Element[n]),size(n),currnt(0),dimNAll(dimN),dimMAll(dimM){}
/**********************************************************/
ArrayElement::ArrayElement(const ArrayElement& e):array(new Element[e.size]),size(e.size),currnt(e.currnt){
    for(int i=0;i<currnt;i++) array[i]=e.array[i];
 }
/**********************************************************/
ArrayElement::~ArrayElement(){delete []array;}
/**********************************************************/
bool ArrayElement::IsFull() const{
    if(currnt==size) return true;
    return false;
 }
/**********************************************************/
bool ArrayElement::IsEmpty() const{
    if(currnt==0) return true;
    return false;
 }
/**********************************************************/
void ArrayElement::Insert(Element& temp){
    if(IsFull()) return;
    if(temp.GetDimM()!=dimMAll) return;
    if(temp.GetDimN()!=dimNAll) return;
    array[currnt]=temp;
    currnt++;
 }
/**********************************************************/
Element* ArrayElement::GetElementAt(int i) const{
    if(i<0 ||i>currnt) return NULL;
    return &array[i]; 
 }
/**********************************************************/
void ArrayElement::UpdateFvec(Element* element){
    Vect<float> newFvec(element->GetDimM(),0);
    float sum,dis;
    for(int  i=0;i<element->GetDimM();i++){
        sum=0;
        Vect<float> temp(element->GetDimN(),i);
        for(int  j=0;j<element->GetDimN();j++){
            dis=element->GetXvec()[j]-temp[j];
            sum=sum+dis*dis;
        }
        newFvec[i]=sum;
    }
    element->SetF(&newFvec);
 }
/*****************************************************/
void ArrayElement::UpdateFvecAll(){
    for(int i=0;i<currnt;i++) UpdateFvec(&array[i]);
}
/*****************************************************/
void ArrayElement::Update(){
    Element* doubleArray=new Element[2*size];
    Vect <float>* doubleFvec=new Vect<float>[2*size];
    Element  temp;
    for(int i=0;i<size;i++){
        temp=array[i];
        doubleArray[2*i]=temp;
        doubleFvec[2*i]=temp.GetFvec();
        temp.MoveXvec();
        UpdateFvec(&temp);
        doubleArray[2*i+1]=temp;
        doubleFvec[2*i+1]=temp.GetFvec();
    }
    ParetoSorting(doubleArray,2*size);
    for(int i=0;i<size;i++) array[i]=doubleArray[i];
    delete []doubleArray;
    delete []doubleFvec;
 }
/*****************************************************/
int* ArrayElement::ParetoRanking(Vect<float>* array,int size){
    int* rankArray=new int[size];
    int i,j;
    int k;
    for(i=0;i<size;i++){
        rankArray[i]=0;
        for(j=0;j<size;j++){
            bool flage=false;
            for(k=0;k<array[j].GetSize();k++){
                if(array[i][k]>array[j][k]) flage=true;
                if(array[i][k]<array[j][k]) break;
            }
            if(flage==true && k==array[j].GetSize()) rankArray[i]++;
        }
    }
    return rankArray;
 }
/*****************************************************/
void ArrayElement::ElementsReordering(Element* a,int size){
    QuickSort(a,0,size-1);
 }
/*****************************************************/
void ArrayElement::ParetoSorting(Element* e,int size){
    Vect<float>* FvecArray=new Vect<float>[size];
    int* temp;
    for(int i=0;i<size;i++) FvecArray[i]=e[i].GetFvec();
    temp=ParetoRanking(FvecArray,size);
    for(int i=0;i<size;i++) e[i].SetRank(temp[i]);
    ElementsReordering(e,size);
    delete []temp;
 }
/*****************************************************/
void ArrayElement::Swap(Element& a, Element& b){
    Element temp;
    temp=a;
    a=b;
    b=temp;
 }
/*****************************************************/
void ArrayElement::QuickSort(Element* e, int left, int right){
    if (left >= right) return; //array contains less than 2 Elements<T>
    Swap(e[left], e[(left + right)/2]);
    int last = left;
    for (int i = left+1; i <= right; ++i)
        if (e[i] < e[left])
            Swap(e[++last], e[i]);
    Swap(e[left], e[last]);
    QuickSort(e, left, last-1);
    QuickSort(e, last+1, right);
 }
/*****************************************************/
void ArrayElement::PrintArray(ofstream* of){
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<array[i].GetDimM() ; j++){
            *of<<array[i].GetFvec()[j]<<" ";
        }
        *of<<endl;
    }
 }
/*****************************************************/
void ArrayElement::PrintArray(){
    for(int i=0;i<size;i++)
        cout<<array[i];
    cout<<endl;
 }
/*****************************************************/
ArrayElement& ArrayElement::operator=(const ArrayElement& v){
    if(&v==this) return *this;
    delete []array;
    array=new Element[v.size];
    this->size=v.size;
    this->currnt=v.currnt;
    for(int i=0;i<currnt;i++)
        array[i]=v.array[i];
    return *this;
 }
/**********************************************************/