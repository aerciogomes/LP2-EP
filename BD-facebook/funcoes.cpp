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


int CriaUsuario(MYSQL *conn){
	int mural;
	int qstate;

	string user_id,mural2,user_nome,user_cidade,user_foto,user_visibilidade,user_email,user_senha,user_genero;

	cout << "\nDigite seu nome: " <<endl;
	//cin >> user_nome;
	flush();
	getline(cin, user_nome);
	cout << "\nDigite sua cidade: " <<endl;
	getline(cin, user_cidade);
	cout << "\nDigite o link para a foto: " <<endl;
	cin >> user_foto;
	cout << "\nDigite seu email: " <<endl;
	cin >> user_email;
	cout << "\nDigite sua senha: " <<endl;
	cin >> user_senha;
	cout << "\nDigite seu Genero: " <<endl;
	cin >> user_genero;
	cout << "\nDigite sua visibilidade do perfil: \n(1) - publico  \n(2) - para amigos \n(3) - para amigos de amigos: " <<endl;
	cin >> user_visibilidade;

	string query = "insert into Mural(mural_id) value('mural')";

	const char* q = query.c_str();

	cout << "query is: " <<q<<endl;
	qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert mural sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
		return 1;
	}

	MYSQL_RES* res;
	MYSQL_ROW row;
	qstate = mysql_query(conn, "select * from Mural");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			mural2 = row[0];
		}
	}else{
		cout << "conn problem" << endl;
	}
	
	query = "INSERT INTO Usuario(user_id,mural_id,user_nome,user_cidade,user_foto,user_visibilidade,user_email,user_senha,user_genero) VALUES('"+user_id+"','"+mural2+"','"+user_nome+"','"+user_cidade+"','"+user_foto+"','"+user_visibilidade+"','"+user_email+"','"+user_senha+"','"+user_genero+"')";

	//string query = "INSERT INTO Usuario(user_id,mural_id,user_nome,user_cidade,user_foto,user_visibilidade,user_email,user_senha,user_genero) VALUES(user_id,mural2,user_nome,user_cidade,user_foto,user_visibilidade,user_email,user_senha,user_genero)";


	const char* q2 = query.c_str();

	cout << "query is: " <<q2<<endl;
	qstate = mysql_query(conn,q2);

	if(!qstate){
		cout << "Insert usuario sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
		return 1;
	}

	return 0;

}
string CriarGrupo(MYSQL*conn){
	string grupo_id,mural_id,grupo_nome,grupo_foto,grupo_desc,grupo_visibilidade;

	string query = "insert into Mural(mural_id) value('mural')";

	const char* q = query.c_str();

	cout << "query is: " <<q<<endl;
	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert mural sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}

	MYSQL_RES* res;
	MYSQL_ROW row;

	qstate = mysql_query(conn, "SELECT * FROM Mural ORDER BY mural_id DESC LIMIT 1");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			mural_id = row[0];
		}
	}else{
		cout << "conn problem" << endl;
	}

	grupo_nome = "Centro de Informatica";
	grupo_foto = "Link";
	grupo_desc = "Grupo para alunos do ci";
	grupo_visibilidade = "0";

	query = "insert into Grupo(grupo_id,mural_id,grupo_nome,grupo_foto,grupo_desc,grupo_visibilidade) VALUES('"+grupo_id+"','"+mural_id+"','"+grupo_nome+"','"+grupo_foto+"','"+grupo_desc+"','"+grupo_visibilidade+"')";

	const char *q2 = query.c_str();
	qstate = mysql_query(conn,q2);


	if(!qstate){
		cout << "Insert grupo sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}

	return grupo_id;

}

void AdicionarAmigo(MYSQL* conn, string user_id, string user_idamizade,string tipo){

	string query = "insert into Amizade(user_id,user_idamizade,amizade_tipo) value('"+user_id+"','"+user_idamizade+"','"+tipo+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		cout << "Insert Amizade sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}
}

void BloquearAmigo(MYSQL *conn,string user_id,string user_idbloqueio){

	string query = "INSERT INTO Bloqueio(user_id,user_idbloqueio) value ('"+user_id+"','"+user_idbloqueio+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert Bloqueio sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}

}

void CriaComentario(MYSQL* conn,string comentario_id,string publicacao_id,string mural_id,string user_idPublicacao,string user_idComentario,string comentario_text){

	string query = "INSERT INTO Comentario(comentario_id,publicacao_id,mural_id,user_idPublicacao,user_idComentario,comentario_text) VALUE('"+comentario_id+"','"+publicacao_id+"','"+mural_id+"','"+user_idPublicacao+"','"+user_idComentario+"','"+comentario_text+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert Comentario sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}
}

void CriaResposta(MYSQL* conn,string resposta_id,string publicacao_id,string comentario_id,string mural_id,string user_idPublicacao,string user_idComentario,string user_idResposta,string resposta_text){

	string query = "INSERT INTO Resposta(resposta_id,publicacao_id,comentario_id,mural_id,user_idPublicacao,user_idComentario,user_idResposta,resposta_text) VALUE('"+resposta_id+"','"+publicacao_id+"','"+comentario_id+"','"+mural_id+"','"+user_idPublicacao+"','"+user_idComentario+"','"+user_idResposta+"','"+resposta_text+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert Resposta sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}

}

string BuscarUsuarioNomes(MYSQL* conn, string nome){
	MYSQL_RES* res;
	MYSQL_ROW row;
	string aux = "0";
	int qstate = mysql_query(conn, "select * from Usuario");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			//cout << "\nCompare: " << nome.compare(row[2]) << endl;
			if(nome.compare(row[2]) == 0 || nome.compare(row[2]) == 32){
				cout << "Numero: " << row[0] << "\t";
				cout << "Nome: " << row[2] << "\t";
				cout << "Cidade: " << row[3] << "\t";
				cout << "Link-foto: " << row[4] << "\t";
				cout << "Genero: " << row[8] << "\t";
				cout << "" <<endl;
				aux = row[0];
			}

		}
	}else{
		cout << "conn problem" << endl;
	}

	return aux;		
}

int BuscaBloqueio(MYSQL* conn,string user_id, string user_idbloqueio){
	MYSQL_RES* res;
	MYSQL_ROW row;
	int aux = 0;

	string c = "select * from Bloqueio where user_id = "+user_id+" and user_idbloqueio="+user_idbloqueio+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			aux = 1;
		}else{
			aux = 0;
		}
	}else{
		cout << "conn problem" << endl;
	}

	return aux;

}

int BuscaSolicitacoesUsuario(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;
	int aux = 1;
	string user;

	string c = "select * from Amizade where user_idamizade = "+user_id+" and amizade_tipo=0";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			user=row[0];

			ExibeUsuariosId(conn,user);
		}
	}else{
		cout << "conn problem" << endl;
	}

	return aux;
}

void ExibeUsuarios(MYSQL* conn){ //AJEITAR PARA BLOQUEADOS
	MYSQL_RES* res;
	MYSQL_ROW row;
	int qstate = mysql_query(conn, "select * from Usuario");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "Numero: " << row[0] << "\t";
			cout << "Nome: " << row[2] << "\t";
			cout << "Cidade: " << row[3] << "\t";
			cout << "Link-foto: " << row[4] << "\t";
			cout << "Genero: " << row[8] << "\t";
			cout << "" <<endl;

		}
	}else{
		cout << "conn problem" << endl;
	}	
}

void ExibeUsuariosId(MYSQL* conn, string user_id){

	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT * FROM Usuario where user_id = "+user_id+" ";

	const char *q = c.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "Numero: " << row[0] << "\t";
			cout << "Nome: " << row[2] << "\t";
			cout << "Cidade: " << row[3] << "\t";
			cout << "Link-foto: " << row[4] << "\t";
			cout << "Genero: " << row[8] << "\t";
			cout << "" <<endl;

		}
	}else{
		cout << "conn problem" << endl;
	}	

}

void ExibeGrupo(MYSQL* conn){ // Ajeitar para bloqueados
	MYSQL_RES* res;
	MYSQL_ROW row;
	int qstate = mysql_query(conn, "select * from Grupo");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "Numero: " << row[0] << "\t";
			cout << "Nome: " << row[2] << "\t";
			cout << "Link-foto: " << row[3] << "\t";
			cout << "Descricao: " << row[4] << "\t";
			cout << "" <<endl;

		}
	}else{
		cout << "conn problem" << endl;
	}	
}

void ExibeAmigos(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT * FROM Amizade where user_id = "+user_id+" and amizade_tipo = 1";
	string user_idamizade;

	const char *q = c.c_str();


	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			user_idamizade = row[1];

			ExibeUsuariosId(conn,user_idamizade);

		}
	}else{
		cout << "conn problem" << endl;
	}
}

void ExibeUsuarioMural(MYSQL* conn, string mural){
	MYSQL_RES* res;
	MYSQL_ROW row;
	/*int size = mural.size();
	char s[size];
	int i;
	for(i=0;i<size;i++){
		s[i] = mural[i];
	}
	char s1[] = "select * from Usuario where mural_id=";
	strcat(s1,s);*/

	string c = "select * from Usuario where mural_id = "+mural+"";

	const char* q = c.c_str();

	cout << endl << "" << q << endl;

	int qstate = mysql_query(conn, q);
	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "Numero: " << row[0] << "\t";
			cout << "Nome: " << row[2] << "\t";
			cout << "Cidade: " << row[3] << "\t";
			cout << "Link-foto: " << row[4] << "\t";
			cout << "Genero: " << row[8] << "\t";
			cout << "" <<endl;

		}
	}else{
		cout << "conn problem" << endl;
	}
}

void ExibePublicacaoUsuario(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "select * from Publicacao where user_id = "+user_id+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);
	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "Numero: " << row[0] << "\t";
			cout << "Mural: " << row[1] << "\t";
			cout << "Usuario: " << row[2] << "\t";
			cout << "Data/hora: " << row[3] << "\t";
			cout << "foto: " << row[4] << "\t";
			cout << "texto: " << row[5] << "\t" << endl;

		}
	}else{
		cout << "conn problem" << endl;
	}
}
void ExibeComentarioDaPublicacao(MYSQL *conn, string publicacao_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT * FROM Comentario WHERE publicacao_id = "+publicacao_id+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "\nComentario: " << row[0] << "\t";
			cout << "Publicacao: " << row[1] << "\t";
			cout << "User-Comentario: " << row[4] << endl;
			cout << "Texto: " << row[5] << endl<<endl;
		}

	}else{
		cout << "conn problem " <<endl;
	}

}
void ExibeRespostaDeComentario(MYSQL *conn, string comentario_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT * FROM Resposta WHERE comentario_id = "+comentario_id+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << "\n Resposta: " << row[0] << "\t";
			cout << "Comentario: " << row[2] << "\t";
			cout << "User-Resposta: " << row[6] << endl;
			cout << "Texto: " << row[7] << endl<<endl;
		}

	}else{
		cout << "conn problem " <<endl;
	}
}

void ExibeBloqueio(MYSQL* conn,string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;
	string user_idbloqueio;

	string c = "SELECT * FROM Bloqueio WHERE user_id = "+user_id+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			user_idbloqueio = row[1];

			ExibeUsuariosId(conn,user_idbloqueio);				
		}

	}else{
		cout << "conn problem " <<endl;
	}

}

string LoginUsuario(MYSQL* conn){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string user_email;
	string user_senha;
	string user_id;

	cout << "\nDigite o seu email: ";
	cin >> user_email;

	cout<< "\nDigite sua senha: ";
	cin >> user_senha;

	string c = "SELECT * FROM Usuario WHERE user_email = '"+user_email+"' and user_senha="+user_senha+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			user_id = row[0];		
		}

	}else{
		cout << "conn problem " <<endl;
	}

	return user_id;

}

void flush() {
    //funçao excelente para limpar o buffer de entrada.
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != EOF && ch != '\n' ) {}
}

void ConfigurarSolicitacoes(MYSQL* conn, string user_id){
	int aux = BuscaSolicitacoesUsuario(conn,user_id);
	int parada = 0;
	int valor;

	if(aux == 1){
		while(parada == 0){
			cout << "Digite (2) para Aceitar ou Recusar Solicitações\n (1) para exibir solicitações \n (0) para sair: " << endl;
			cin >> valor;

			switch(valor){
				case 2:
					// função para alterar dados da tabela amizade
					break;
				case 1:
					BuscaSolicitacoesUsuario(conn,user_id);
					break;
				case 0:
					parada = 1;
					break;
			}
		}
	}
}

void ConfigurarBloqueio(MYSQL* conn, string user_id){
	ExibeBloqueio(conn,user_id);
	int parada = 0;
	int valor;

	while(parada == 0){
		cout << "Digite (2) para Retirar Bloqueio\n (1) para exibir lista de bloqueio \n (0) para sair: " << endl;
		cin >> valor;

		switch(valor){
			case 2:
				// função para deletar dados da tabela Bloqueio
				break;
			case 1:
				ExibeBloqueio(conn,user_id);
				break;
			case 0:
				parada = 1;
				break;
		}

	}
	
}