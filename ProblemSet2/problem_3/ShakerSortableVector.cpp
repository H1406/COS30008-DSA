#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[],size_t aNumberOfElements):SortableIntVector(aArrayOfIntegers,aNumberOfElements){}

void ShakerSortableIntVector::sort(Comparable aOrderFunction){
    SortableIntVector::sort(aOrderFunction);
}