#pragma once

#include "OperationalSystem.h"

class Principal
{
private:
	OperationalSystem os;

public:
	Principal();
	~Principal();

	void menu();
	void cadastrarLivro();
	void listarLivro();
	void retirarLivro();
};

