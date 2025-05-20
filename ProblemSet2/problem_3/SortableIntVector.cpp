#include "SortableIntVector.h"
#include "algorithm"
SortableIntVector::SortableIntVector(const int aArrayOfIntegers[],size_t aNumberOfElements):IntVector(aArrayOfIntegers,aNumberOfElements){
}
void SortableIntVector::sort(Comparable aOrderFunction){
    for(int i=0;i<IntVector::size()-1;i++){
        for(int j=i+1;j<IntVector::size();j++){
            if(aOrderFunction(get(i),get(j))){
                IntVector::swap(i,j);
            }
        }
    }
}