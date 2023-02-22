#pragma once

#include <stdbool.h>

#define EXIT 3

typedef int OPERATION;
typedef int USER_TYPE;

struct User
{
	void (*printOperations) (void);
	OPERATION (*getOperation) (void);
	bool (*handleOperation) (OPERATION);
};

extern struct User* user;

//constructor & destructor
struct User* initUser();
void removeUser();

//admin
static void printOperationsAdmin(void);
static OPERATION getOperationAdmin(void);
static bool handleOperationAdmin(OPERATION);

//client
static void printOperationsClient(void);
static OPERATION getOperationClient(void);
static bool handleOperationClient(OPERATION);

//common
static OPERATION getOperation(int);
void greetings(void);
USER_TYPE getUserType(void);
void handleUserType(USER_TYPE);
static void setUpAdmin(void);
static void setUpClient(void);
static void invalidUser(void);

