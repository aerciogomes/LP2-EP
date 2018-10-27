#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "menus.h"
#include "funcoes.h"

using namespace std;

int main(){

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	MYSQL *conn2;

	string user_id,mural_id,publicacao_id,grupo_id,comentario_id,reposta_id;

	string user_idvisita;

	int valor;
	int aux = 0;
	int parada = 1;

	conn = mysql_init(0);
	conn2 = mysql_real_connect(conn,"127.0.0.1","root","","teste2",3306,NULL,0);


	if(conn2){
		cout << "conection" << conn2 << endl;

		while(parada == 1){
			if(aux == 0){
				ApresentaMenuInicial();
				cin >> valor;

				switch(valor){
					case 1:
						user_id = LoginUsuario(conn2);
						if(user_id != ""){
							aux = 1;
							cout << "\n Entrando " <<endl;
						}else{
							cout<< "\n Dados Invalidos" <<endl;
						}
						break;
					case 2:
						CriaUsuario(conn2);
						break;
					case 3:
						parada = 0;
						break;
					default:
						cout << "\n Valor invalido" <<endl;
				}
			}
			if(aux ==1){
				ApresentaMenuDoUsuario();
				cin >> valor;

				switch(valor){
					case 1: //busca Usuario
						ExibeUsuarios(conn2, user_id); // feito, mas com algumas coisas faltando
						aux = 2;
						break;
					case 2: // Busca grupo
						ExibeGrupo(conn2); // falta configurar o acesso ao grupo apos a busca
						aux = 4;
						break;
					case 3: //alterar dados
						cout << "FAZER-OU NAO" <<endl;
						break;
					case 4: // vermural
						aux = 5;
						break;
					case 5: // ver amigos
						ExibeAmigos(conn2,user_id); // feito, mas com algumas coisas faltando
						aux = 3;
						break;
					case 6: // ver solicitações
						ConfigurarSolicitacoes(conn2,user_id); // ok
						break;
					case 7: // lista bloqueados
						ConfigurarBloqueio(conn2,user_id); // ok
						break;
					case 9: // sair
						cout << "Adeus" << endl;
						aux = 0;
						break;
				}
			}
			if(aux == 2){
				cout << "\n\n ****************************** \n" <<endl;
				ExibeUsuarios(conn2, user_id);
				cout << "Campo de visita" <<endl;
				cout << "Digite o numero do usuario a ser visitado ou '0' para sair " <<endl;
				cin >> user_idvisita;
				if(user_idvisita == "0"){
					aux = 1;
				}else{
					ConfigurarVisita(conn2, user_id, user_idvisita); // terminar - bloqueio
				}
			}
			if(aux == 3){
				cout << "\n\n ****************************** \n" <<endl;
				ExibeAmigos(conn2,user_id);
				cout << "Campo de visita" <<endl;
				cout << "Digite o numero do usuario a ser visitado ou '0' para sair " <<endl;
				cin >> user_idvisita;
				if(user_idvisita == "0"){
					aux = 1;
				}else{
					ConfigurarVisita(conn2, user_id, user_idvisita); // terminar - bloqueio
				}
			}
			
		}

	}else{
		cout << "Erro" << mysql_error(conn);		
	}



	return 0;
}