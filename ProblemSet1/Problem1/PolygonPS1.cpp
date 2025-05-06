#include<iostream>
#include "Polygon.h"
#include "Vector2D.h"
float Polygon::getSignedArea(){
    float area = 0.0f;

    // There have to be at least three vertices
    if ( fNumberOfVertices > 2 )
    {
        for (int i = 0;i<fNumberOfVertices-1;i++){
            area += ((fVertices[i].getX() * fVertices[i+1].getY()) - (fVertices[i+1].getX() * fVertices[i].getY()));
        }
        area /= 2;
    }else{
        return 0.0f;
    }
    return area;
}