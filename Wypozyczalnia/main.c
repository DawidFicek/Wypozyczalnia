#include "car.h"
#include "user.h"


int main(int argv, char** argc)
{
	cars = initCarBase();
	user = initUser();
	while(true)
	{
		greetings();
		USER_TYPE userType = getUserType();
		if(userType == EXIT)
		{
			break;
		}
		handleUserType(userType);
		bool logout = 0;
		while(!logout)
		{
			user->printOperations();
			OPERATION operation = user->getOperation();
			logout = user->handleOperation(operation);
		}
	}
	removeCarBase();
	removeUser();
	return 0;
}

