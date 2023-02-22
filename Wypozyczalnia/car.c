#include "car.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Car* cars;
int carExistenceIter = 0;
//admin's

void addCar(void)
{
	char name[MAX_STRING];
	char model[MAX_STRING];
	int price;
	int power;

	printf("Wprowadz markę: \n");
	scanf("%s", name);
	printf("Wprowadz model: \n");
	scanf("%s", model);
	printf("Wprowadz cenę: \n");
	scanf("%d", &price);
	printf("Wprowadz moc: \n");
	scanf("%d", &power);
	printf("\n");

	struct Car* carAdd = cars;
	carAdd = carAdd + carExistenceIter * sizeof(struct Car);

	memcpy(carAdd->name, name, sizeof(name));
	memcpy(carAdd->model, model, sizeof(model));
	carAdd->price = price;
	carAdd->power = power;
	carAdd->isTaken = false;

	printCar(carAdd);

	carExistenceIter++;
}

void removeCar(void)
{
	carExistenceIter--;
}

void serviceCar(void)
{
	printAllCars();
	printf("Ktory samochod chcesz serwisowac?\n");

	int carServiceIter = 0;
	scanf("%d", &carServiceIter);

	if(carServiceIter > carExistenceIter || carServiceIter == 0)
	{
		printf("Brak samochodu w bazie\n");
		printf("\n");
		return;
	}

	struct Car* carService = cars;
	carService = carService + (--carServiceIter) * sizeof(struct Car);

	carService->isTaken = !carService->isTaken;

	return;
}

//client's


void getCar(void)
{
	printAllCars();
	printf("Ktory samochod chcesz wypozyczyc?\n");

	int carGetIter = 0;
	scanf("%d", &carGetIter);

	if(carGetIter > carExistenceIter || carGetIter == 0)
	{
		printf("Brak samochodu w bazie\n");
		printf("\n");
		return;
	}

	struct Car* carGet = cars;
	carGet = carGet + (--carGetIter) * sizeof(struct Car);

	if(carGet->isTaken == true)
	{
		printf("Samochod jest niedostepny. Prosze wybrac inny\n");
		return;
	}

	carGet->isTaken = true;

	return;
}

void giveBackCar(void)
{
	printAllCars();
	printf("Ktory samochod chcesz oddac?\n");

	int carGiveBackIter = 0;
	scanf("%d", &carGiveBackIter);

	if(carGiveBackIter > carExistenceIter || carGiveBackIter == 0)
	{
		printf("Brak samochodu w bazie\n");
		printf("\n");
		return;
	}

	struct Car* carGiveBack = cars;
	carGiveBack = carGiveBack + (--carGiveBackIter) * sizeof(struct Car);

	if(carGiveBack->isTaken == false)
	{
		printf("Samochod jest juz oddany prosze wybrac inny\n");
		return;
	}

	carGiveBack->isTaken = false;

	return;
}

//common

void checkCar(void)
{
	printAllCars();
	while(getchar()!='\n'); // option TWO to clean stdin
        getchar();
}

struct Car* initCarBase(void)
{
	return malloc(MAX_NUM_OF_CARS * sizeof(struct Car));
}


void removeCarBase(void)
{
	free(cars);
}

static void printCar(struct Car* car)
{
	printf("***************\n");
	printf("Marka: %s\n", car->name);
	printf("Model: %s\n", car->model);
	printf("Cena: %d\n", car->price);
	printf("Moc: %d\n", car->power);
	printf("Zajety: %d\n", car->isTaken);
	printf("***************\n");
	printf("\n");
}

static void printAllCars(void)
{
	struct Car* car = cars;
	printf("###############\n");
	for(int carIt = 0; carIt < carExistenceIter; carIt++)
	{
		car = car + carIt * sizeof(struct Car);
		printf("Samochod nr %d\n", carIt+1);
		printCar(car);
	}
}

