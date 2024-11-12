#include "filehandle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AirfoilFile* readAirfoilFile(char* filePath) {

    FILE* file = fopen(filePath, "r");

    AirfoilFile* airfoil = (AirfoilFile*)malloc(sizeof(AirfoilFile));
    // Read the name of the airfoil
    char line[256];
    fgets(line, sizeof(line), file);
    airfoil->name = strdup(line);  // Duplicate the name string
    airfoil->name[strcspn(airfoil->name, "\n")] = '\0';  // Remove newline

    // Estimate the number of points by counting lines
    int pointCount = 0;
    while (fgets(line, sizeof(line), file)) {
        pointCount++;
    }

    // Allocate memory for x and y coordinates
    airfoil->points = (Vector2*)malloc(pointCount * sizeof(Vector2));
    airfoil->pointCount = pointCount;

    // Rewind file pointer to read the data points
    rewind(file);
    fgets(line, sizeof(line), file); // Skip the name line

    // Read the data points
    int i = 0;
    while (fscanf(file, "%f %f", &airfoil->points[i].x, &airfoil->points[i].y) == 2) {
        i++;
    }

    fclose(file);
    return airfoil;
}

void freeAirfoilFile(AirfoilFile* airfoil) {
    if (airfoil) {
        free(airfoil->name);
        free(airfoil->points);
        free(airfoil);
    }
}