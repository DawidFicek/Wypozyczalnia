#pragma once

#include <stdbool.h>

#define MAX_NUM_OF_CARS 10
#define MAX_STRING 25

typedef char* STRING;

struct Car
{
	char name[MAX_STRING];
	char model[MAX_STRING];
	int price;
	int power;
	bool isTaken;
};

extern struct Car* cars;

//constructor & destructor
struct Car* initCarBase(void);
void removeCarBase(void);

//admin
void addCar(void);
void removeCar(void);
void serviceCar(void);

//cliens
void getCar(void);
void giveBackCar(void);

//common
void checkCar(void);
static void printCar(struct Car*);
static void printAllCars(void);

