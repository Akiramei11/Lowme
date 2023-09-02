#include "Lowme.h"

class Soulou : public Lowme::Application
{
public:
	Soulou() 
	{

	}

	~Soulou()
	{

	}

};

Lowme::Application* Lowme::CreateApplication()
{
	return new Soulou();
}