#pragma once

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

#include "nlohmann/json.hpp"
using json = nlohmann::json;

// erase this
#include <iostream>
using namespace std;

class OperationalSystem
{
public:
	OperationalSystem();
	~OperationalSystem();

	void cadastrarLivro(int id = 0, string nome = "", string genero = "");
	void listarLivro();
	void retirarLivro(int id = 0, string nome = "", string genero = "");
};

