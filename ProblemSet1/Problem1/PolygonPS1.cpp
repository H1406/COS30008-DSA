#include<iostream>
#include "Polygon.h"
#include <math.h>
float Polygon::getSignedArea(){
    float area = 0.0f;

    // There have to be at least three vertices
    if ( fNumberOfVertices > 2 )
    {
        for (int i = 0;i<fNumberOfVertices-1;i++){
            area += abs(fVertices[i].cross(fVertices[i+1]));
        }
        area+= abs(fVertices[fNumberOfVertices-1].cross(fVertices[0]));
        area /= 2;
    }else{
        return 0.0f;
    }
    return area;
}