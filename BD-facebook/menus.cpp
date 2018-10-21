#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string>
#include "menus.h"

using namespace std;

void ApresentaMenuInicial(){
	cout << "\t*********BEM VINDO AO FACEBOOK ***************" <<endl<<endl;

	cout << "\nDigite a opcao que deseja:"<< endl;

	cout << "(1) - Login" <<endl;
	cout << "(2) - Cadastre-se" <<endl;
	cout << "(3) - Sair" <<endl;

}
void ApresentaMenuDoUsuario(){

	cout << "\nDigite a opcao que deseja:"<< endl;

	cout << "(1) - Buscar Usuarios" <<endl;
	cout << "(2) - Buscar Grupos" <<endl;
	cout << "(3) - Alterar Dados" <<endl;
	cout << "(4) - Ver Mural" <<endl;
	cout << "(5) - Ver amigos" <<endl;
	cout << "(6) - Ver Solicitacoes" << endl;
	cout << "(7) - Ver Lista de Bloqueados" << endl;
	cout << "(9) - Sair" <<endl;
}