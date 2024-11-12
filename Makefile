CC=gcc

AirfoilAnalyzer: 
	gcc -o AirfoilAnalyzer.exe -Iinc -Llib $(wildcard src/*.c) -O1 -Wall -std=c99 -Wno-missing-braces -lraylib -lopengl32 -lgdi32 -lwinmm
