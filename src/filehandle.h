#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include "raylib.h"
typedef struct
{
    char* name;
    Vector2* points;
    int pointCount;
}AirfoilFile;

AirfoilFile* readAirfoilFile(char* filePath);

void freeAirfoilFile(AirfoilFile* airfoil);
#endif