#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[],size_t aNumberOfElements):SortableIntVector(aArrayOfIntegers,aNumberOfElements){}

void ShakerSortableIntVector::sort(Comparable aOrderFunction){
    int left = 0;
    int right = IntVector::size()-1;
    while(left<right){
        for(int i=left;i<right;i++){
            if(aOrderFunction(get(i),get(i+1))){
                IntVector::swap(i,i+1);
            }
        }
        right--;
        for(int i=right;i>left;i--){
            if(aOrderFunction(get(i-1),get(i))){
                IntVector::swap(i,i-1);
            }
        }
        left++;
    }
}