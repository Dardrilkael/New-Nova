#include "novapch.h"
#include <Nova.h> 


class SandBoxApp : public Nova::Application
{
public:
	SandBoxApp(){}
	~SandBoxApp(){}
};

Nova::Application* Nova::CreateApplication()
{
	return new SandBoxApp;
}