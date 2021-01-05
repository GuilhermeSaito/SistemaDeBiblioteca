#include "OperationalSystem.h"

#include <iomanip>

OperationalSystem::OperationalSystem()
{
}
OperationalSystem::~OperationalSystem()
{
}

void OperationalSystem::cadastrarLivro(int id, string nome, string genero)
{
	ifstream in("../SistemaDeBiblioteca/SaveFile/bookshelf.json");
	// Testa se o arquivo existe
	if (!in.good())
	{
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file doesn't exist.";
		exit(EXIT_FAILURE);
	}
	// Testa se o arquivo ta vazio
	in.seekg(0, std::ios::end);
	if (!in.tellg())
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file is empty.";
	in.seekg(0, std::ios::beg);

	json j;

	try {
		in >> j;
	}
	catch (json::exception& e) {
		std::cerr << "[!] Erro na leitura do arquivo SistemaDeBiblioteca/SaveFile/bookshelf.json." << std::endl;
		std::cerr << e.what() << std::endl;
		in.close();
		exit(EXIT_FAILURE);
	}

	json bookshelf;
	bookshelf["id"] = id;
	bookshelf["nome"] = nome;
	bookshelf["genero"] = genero;

	if (j.find("books") == j.end())
		j["books"].push_back(bookshelf);
	else
		j["books"].insert(j["books"].end() - 1, bookshelf);
	
	in.close();

	ofstream out("../SistemaDeBiblioteca/SaveFile/bookshelf.json", ios::out | ios::trunc);
	out.exceptions(ios::badbit);
	try
	{
		out << setw(4) << j << endl;
		cout << "Livro Cadastrado com Sucesso!\n\n\n";
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "[!] Error writing SistemaDeBiblioteca/SaveFile/bookshelf.json.";
		exit(EXIT_FAILURE);
	}
	out.close();
}

void OperationalSystem::listarLivro()
{
	ifstream in("../SistemaDeBiblioteca/SaveFile/bookshelf.json");
	// Testa se o arquivo existe
	if (!in.good())
	{
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file doesn't exist.";
		exit(EXIT_FAILURE);
	}
	// Testa se o arquivo ta vazio
	in.seekg(0, std::ios::end);
	if (!in.tellg())
	{
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file is empty.";
		exit(EXIT_FAILURE);
	}
	in.seekg(0, std::ios::beg);

	json j;

	try {
		in >> j;
	}
	catch (json::exception& e) {
		std::cerr << "[!] Erro na leitura do arquivo SistemaDeBiblioteca/SaveFile/bookshelf.json." << std::endl;
		std::cerr << e.what() << std::endl;
		in.close();
		exit(EXIT_FAILURE);
	}
	
	for (auto it : j["books"])
	{
		cout << "id: " << it["id"] << endl;
		cout << "Nome do Livro: " << it["nome"] << endl;
		cout << "Genero do Livro: " << it["genero"] << endl << endl;
	}
	cout << "\n\n";
	
	in.close();
}

void OperationalSystem::retirarLivro(int id, string nome, string genero)
{
	ifstream in("../SistemaDeBiblioteca/SaveFile/bookshelf.json");
	// Testa se o arquivo existe
	if (!in.good())
	{
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file doesn't exist.";
		exit(EXIT_FAILURE);
	}
	// Testa se o arquivo ta vazio
	in.seekg(0, std::ios::end);
	if (!in.tellg())
	{
		throw "[!] SistemaDeBiblioteca/SaveFile/bookshelf.json file is empty.";
		exit(EXIT_FAILURE);
	}
	in.seekg(0, std::ios::beg);

	json j;

	try {
		in >> j;
	}
	catch (json::exception& e) {
		std::cerr << "[!] Erro na leitura do arquivo SistemaDeBiblioteca/SaveFile/bookshelf.json." << std::endl;
		std::cerr << e.what() << std::endl;
		in.close();
		exit(EXIT_FAILURE);
	}

	bool flag = false;

	try
	{
		for (auto& it : j["books"].items())
		{
			if ((it.value().at("id").get<int>() == id) &&
				(it.value().at("nome").get<string>() == nome) &&
				(it.value().at("genero").get<string>() == genero))
			{
				j["books"].erase(j["books"].begin() + stoi(it.key()));
				flag = true;
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	in.close();

	if (!flag)
	{
		cout << "Nao achei o Livro." << endl << endl << endl;
		return;
	}

	ofstream out("../SistemaDeBiblioteca/SaveFile/bookshelf.json", ios::out | ios::trunc);
	out.exceptions(ios::badbit);
	try
	{
		out << setw(4) << j << endl;
		cout << "Livro retirado com Sucesso." << endl << endl << endl;
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "[!] Error writing SistemaDeBiblioteca/SaveFile/bookshelf.json.";
		exit(EXIT_FAILURE);
	}
	out.close();
}