#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "car.h"

struct User* user;

struct User* initUser()
{
	return malloc(sizeof(struct User));
}

void removeUser()
{
	free(user);
}

void greetings(void)
{
	printf("###############\n");
	printf("Witaj w programie wypożyczalni samochodów \n");
	printf("zaloguj się jako: \n");
	printf("1.Admin \n");
	printf("2.Klient \n");
	printf("3.Wyjdz \n");
	printf("\n");
}

USER_TYPE getUserType(void)
{
	USER_TYPE userType = 0;
	while(userType != 1 && userType != 2 && userType != 3)
	{
		scanf("%d", &userType);
	}

	return userType;
}
void handleUserType(USER_TYPE userType)
{
	switch (userType)
		{
			case 1:
				setUpAdmin();
				break;
			case 2:
				setUpClient();
				break;
			default:
				invalidUser();
		}
}
static void setUpAdmin(void)
{
	printf("Setting up admin...\n");
	user->printOperations = printOperationsAdmin;
	user->getOperation = getOperationAdmin;
	user->handleOperation = handleOperationAdmin;
}

static void setUpClient(void)
{
	printf("Setting up client...\n");
	user->printOperations = printOperationsClient;
	user->getOperation = getOperationClient;
	user->handleOperation = handleOperationClient;
}

static void invalidUser(void)
{
	printf("Invalid user!\n");
}

static void printOperationsAdmin(void)
{
	printf("###############\n");
	printf("Operacje admina:\n");
	printf("1.Dodaj auto\n");
	printf("2.Usun auto\n");
	printf("3.Serwisuj auto\n");
	printf("4.Sprawdz auto\n");
	printf("5.Wyloguj\n");
	printf("\n");
}

static OPERATION getOperationAdmin(void)
{
	return getOperation(5);
}

static bool handleOperationAdmin(OPERATION operation)
{
	switch (operation)
	{
		case 1:
			addCar();
			break;
		case 2:
			removeCar();
			break;
		case 3:
			serviceCar();
			break;
		case 4:
			checkCar();
			break;
		case 5:
			return true;
		default:
			printf("Invalid operation\n");
			break;
	}
	return false;
}

static void printOperationsClient(void)
{
	printf("###############\n");
	printf("Operacje klienta:\n");
	printf("1.Wypozycz auto\n");
	printf("2.Oddaj auto\n");
	printf("3.Sprawdz auto\n");
	printf("4.Wyloguj\n");
	printf("\n");
}

static OPERATION getOperationClient(void)
{
	return getOperation(6);
}

static bool handleOperationClient(OPERATION operation)
{
	switch (operation)
	{
		case 1:
			getCar();
			break;
		case 2:
			giveBackCar();
			break;
		case 3:
			checkCar();
			break;
		case 4:
			return true;
		default:
			printf("Invalid operation\n");
			break;
	}
	return false;
}

static OPERATION getOperation(int max)
{
	OPERATION operation = 0;
	while(operation <= 0 || operation > max)
	{
		scanf("%d", &operation);
	}

	return operation;
}

