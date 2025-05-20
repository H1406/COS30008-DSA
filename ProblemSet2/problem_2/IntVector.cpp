#include "IntVector.h"
#include<stdexcept>
using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[],size_t aNumberOfElements){
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];
    for(size_t i =0;i<fNumberOfElements;i++){
        fElements[i] = aArrayOfIntegers[i];
    }
}

size_t IntVector::size() const {
    return fNumberOfElements;
}
IntVector::~IntVector(){
    delete[] fElements;
}
const int IntVector::operator[](size_t aIndex) const{
    if(aIndex >= fNumberOfElements || aIndex < 0){
        throw std::out_of_range("Illegal vector index");
    }
    return *(fElements+aIndex);
}
const int IntVector::get(size_t aIndex)const{
    if(aIndex >= fNumberOfElements || aIndex < 0){
        throw std::out_of_range("Illegal vector indices");
    }
    return *(fElements+aIndex);
}
void IntVector::swap(size_t aSourceIndex,size_t aTargetIndex){
    int temp = get(aSourceIndex);
    *(fElements+aSourceIndex) = get(aTargetIndex);
    *(fElements+aTargetIndex) = temp;
}
