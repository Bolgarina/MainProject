#pragma once

#include "./DllApi.h"

class CONTROLLER_API IController
{
public:
	virtual ~IController() {};
	virtual void init(int &i_argc, char **i_argv) = 0;
};