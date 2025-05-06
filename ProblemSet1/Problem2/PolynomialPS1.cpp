#include <iostream>
#include <cmath>
#include "Polynomial.h"

Polynomial::Polynomial() {
    fDegree = 0;
    for (int i = 0; i <= MAX_DEGREE; i++) {
        fCoeffs[i] = 0.0;
    }
}

Polynomial Polynomial::operator*(const Polynomial& aRHS) const {
    Polynomial result;

    result.fDegree = fDegree + aRHS.fDegree;

    for (size_t i = 0; i <= fDegree; i++) {
        for (size_t j = 0; j <= aRHS.fDegree; j++) {
            result.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
        }
    }

    return result;
}

bool Polynomial::operator==(const Polynomial& aRHS) const {
    if (fDegree != aRHS.fDegree)
        return false;

    for (size_t i = 0; i <= fDegree; i++) {
        if (fCoeffs[i] != aRHS.fCoeffs[i])
            return false;
    }

    return true;
}

std::istream& operator>>(std::istream& aIStream, Polynomial& aObject) {
    aIStream >> aObject.fDegree;

    for (int i = aObject.fDegree; i >= 0; i--) {
        aIStream >> aObject.fCoeffs[i];
    }

    return aIStream;
}

std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject) {
    bool first = true;

    for (int i = aObject.fDegree; i >= 0; i--) {
        double coeff = aObject.fCoeffs[i];

        if (coeff != 0.0) {
            if (!first && coeff > 0)
                aOStream << " + ";

            if (i == 0)
                aOStream << coeff;
            else if (i == 1)
                aOStream << coeff << "x";
            else
                aOStream << coeff << "x^" << i;

            first = false;
        }
    }

    if (first) // All coefficients were zero
        aOStream << "0";

    return aOStream;
}

// Already implemented versions (you can move these here or keep them in PolynomialPS1.cpp if you prefer):
double Polynomial::operator()(double aX) {
    double result = 0;
    for (int i = 0; i <= fDegree; i++) {
        result += fCoeffs[i] * pow(aX, i);
    }
    return result;
}

Polynomial Polynomial::getDerivative() {
    Polynomial result;
    for (int i = 1; i <= fDegree; i++) {
        result.fCoeffs[i - 1] = fCoeffs[i] * i;
    }
    result.fDegree = fDegree > 0 ? fDegree - 1 : 0;
    return result;
}

Polynomial Polynomial::getIndefiniteIntegral() {
    Polynomial result;
    for (int i = 0; i <= fDegree; i++) {
        result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }
    result.fDegree = fDegree + 1;
    return result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) {
    Polynomial result = getIndefiniteIntegral();
    return result(aXHigh) - result(aXLow);
}
