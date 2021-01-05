#include "Principal.h"

Principal::Principal()
{
	menu();
}
Principal::~Principal()
{

}

void Principal::menu()
{
	int opt = 0;
	while (opt != -1)
	{
		cout << "1 - Cadastrar um Livro" << endl
			<< "2 - Listar os Livros Cadastrados" << endl
			<< "3 - Retirar um Livro Cadastrado" << endl
			<< "-1 - Sair" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			cadastrarLivro();
			break;

		case 2:
			listarLivro();
			break;

		case 3:
			retirarLivro();
			break;

		case -1:
			cout << "Thank you for using my application." << endl;
			break;

		default:
			cout << "Opcao Invalida. Try again" << endl;
			break;
		}
	}
}

void Principal::cadastrarLivro()
{
	int id;
	string nome, genero;
	cout << "id do livro: ";
	cin >> id;
	cout << "Nome do livro: ";
	cin >> nome;
	cout << "Genero do livro: ";
	cin >> genero;

	os.cadastrarLivro(id, nome, genero);
}

void Principal::listarLivro()
{
	os.listarLivro();
}

void Principal::retirarLivro()
{
	int id;
	string nome, genero;
	cout << "id do livro A RETIRAR: ";
	cin >> id;
	cout << "Nome do livro A RETIRAR: ";
	cin >> nome;
	cout << "Genero do livro A RETIRAR: ";
	cin >> genero;

	os.retirarLivro(id, nome, genero);
}