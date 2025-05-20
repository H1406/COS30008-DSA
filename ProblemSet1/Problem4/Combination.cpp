#include <cstddef>
#include <iostream>
#include "Combination.h"
using namespace std;
Combination::Combination(size_t aN, size_t aK){
    fN = aN;
    fK = aK;
}
size_t Combination::getK(){
    return fK;
}
size_t Combination::getN(){
    return fN;
}

size_t factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}
unsigned long long Combination::operator()(){
    return factorial(getN())/(factorial(getK())*factorial(getN()-getK()));
}

