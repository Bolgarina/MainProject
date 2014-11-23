#pragma once

class IController
{
public:
	virtual ~IController() {};
	virtual bool init(int &i_argc, char **i_argv) = 0;
};