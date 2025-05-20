#include<iostream>
#include "BernsteinBasisPolynomial.h"
#include "math.h"
BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN)
{
    fFactor = Combination(aN, aV);
}

double BernsteinBasisPolynomial::operator()(double aX)
{
    return fFactor.operator()() * pow(aX,fFactor.getK())*pow((1-aX),(fFactor.getN()-fFactor.getK()));
}