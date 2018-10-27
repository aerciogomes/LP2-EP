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

void CriarPublicacao(MYSQL* conn, string mural_id, string user_id){
	string publicacao_id,publicacao_datahora,publicacao_foto,publicacao_text;
	publicacao_id = "0";

	cout << "Digite a data/hora: " <<endl;
	cin >> publicacao_datahora;

	cout << "Digite o texto para a publicacao: " <<endl;
	flush();
	getline(cin, publicacao_text);

	cout << "Digite o link para a foto: "<<endl;
	getline(cin, publicacao_foto);

	string query = "INSERT INTO Publicacao(publicacao_id,mural_id,user_id,publicacao_datahora,publicacao_foto,publicacao_text) value ('"+publicacao_id+"','"+mural_id+"','"+user_id+"','"+publicacao_datahora+"','"+publicacao_foto+"','"+publicacao_text+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert publicacao sucess " <<endl;
	}else{
		cout << "Insert publicacao Error " << mysql_error(conn)<<endl;
	}

}

void CriaComentario(MYSQL* conn,string publicacao_id,string mural_id,string user_idPublicacao,string user_idComentario){
	string comentario_id, comentario_text;
	comentario_id = "0";

	cout << "Digite o texto para o comentario: " <<endl;
	getline(cin, comentario_text);

	string query = "INSERT INTO Comentario(comentario_id,publicacao_id,mural_id,user_idPublicacao,user_idComentario,comentario_text) VALUE('"+comentario_id+"','"+publicacao_id+"','"+mural_id+"','"+user_idPublicacao+"','"+user_idComentario+"','"+comentario_text+"')";

	const char* q = query.c_str();

	int qstate = mysql_query(conn,q);

	if(!qstate){
		cout << "Insert Comentario sucess " <<endl;
	}else{
		cout << "Insert Error " << mysql_error(conn)<<endl;
	}
}

void CriaResposta(MYSQL* conn,string publicacao_id,string comentario_id,string mural_id,string user_idPublicacao,string user_idComentario,string user_idResposta){
	string resposta_id, resposta_text;
	resposta_id = "0";

	cout << "Digite o texto para a resposta: " <<endl;
	getline(cin, resposta_text);

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

int BuscaAmizade(MYSQL* conn, string user_id,string user_idamizade){
	MYSQL_RES* res;
	MYSQL_ROW row;
	int aux = 0;

	string c = "select * from Amizade where user_id = "+user_id+" and user_idamizade="+user_idamizade+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			if(row[2] == "0"){
				aux = 3;
			}else{
				aux = 1;
			}
		}else{
			aux = 0;
		}
	}else{
		c = "select * from Amizade where user_id = "+user_idamizade+" and user_idamizade="+user_id+"";

		const char *q2 = c.c_str();

		qstate = mysql_query(conn, q2);	

		if(!qstate){
			res = mysql_store_result(conn);

			if(row=mysql_fetch_row(res)){
				if(row[2] == "0"){
					aux = 2;
				}else{
					aux = 1;
				}
			}else{
				aux = 0;
			}
		}else{
			cout << "conn problem" << endl;
		}

	}
	

	return aux;

}
int BuscaPerfil(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;
	int aux = 0;

	string c = "select user_visibilidade from Usuario where user_id = "+user_id+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			if(row[0] == "1" || row[0] == "2"){
				aux = 1;
			}else{
				aux = 0;
			}
		}
	}else{
		cout << "conn problem" << endl;
	}
	return aux;
}
string BuscaMural(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string mural = "0";

	string c = "select mural_id from Usuario where user_id = "+user_id+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			mural = row[0];
		}
	}else{
		cout << "conn problem" << endl;
	}
	return mural;

}
string BuscaUsuarioPublicacao(MYSQL* conn, string publicacao_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string user_publicacao = "0";

	string query = "SELECT user_id FROM Publicacao where publicacao_id= "+publicacao_id+"";

	const char *q = query.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			user_publicacao = row[0];
		}
	}else{
		cout << "conn problem" << endl;
	}

	return user_publicacao;

}

string BuscaUsuarioComentario(MYSQL* conn, string comentario_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string user_comentario = "0";

	string query = "SELECT user_idComentario From Comentario where comentario_id = "+comentario_id+"";

	const char *q = query.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		if(row=mysql_fetch_row(res)){
			comentario_id = row[0];
		}
	}else{
		cout << "conn problem" << endl;
	}

	return comentario_id;
}

void ExibeUsuarios(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;
	string aux;
	int qstate = mysql_query(conn, "select * from Usuario");

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			aux = row[0];

			if(!BuscaBloqueio(conn,user_id,aux) && aux != user_id){
				cout << "Numero: " << row[0] << "\t";
				cout << "Nome: " << row[2] << "\t";
				cout << "Cidade: " << row[3] << "\t";
				cout << "Link-foto: " << row[4] << "\t";
				cout << "Genero: " << row[8] << "\t";
				cout << "" <<endl;
			}

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

	string c = "SELECT * FROM Amizade where (user_id = "+user_id+" or user_idamizade = "+user_id+") and amizade_tipo = 1";
	string user_idamizade;

	const char *q = c.c_str();


	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			if(user_id == row[0]){
				user_idamizade = row[1];
			}else{
				user_idamizade = row[0];
			}

			ExibeUsuariosId(conn,user_idamizade);

		}
	}else{
		cout << "conn problem" << endl;
	}
}

void ExibeAmigosVisita(MYSQL* conn, string user_id, string user_idvisita){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT * FROM Amizade where (user_id = "+user_idvisita+" or user_idamizade = "+user_idvisita+") and amizade_tipo = 1";
	string user_idamizade;
	int block;

	const char *q = c.c_str();


	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			if(user_idvisita == row[0]){
				user_idamizade = row[1];
				block = BuscaBloqueio(conn,user_id,user_idamizade);
			}else{
				user_idamizade = row[0];
				block = BuscaBloqueio(conn,user_id,user_idamizade);
			}

			if(!block){
				ExibeUsuariosId(conn,user_idamizade);
			}

		}
	}else{
		cout << "conn problem" << endl;
	}
}

void ExibeUsuarioMural(MYSQL* conn, string mural, string user_id){ 
	MYSQL_RES* res;
	MYSQL_ROW row;
	string codigo;
	string user_idnome;
	int block;

	string c = "select * from Publicacao where mural_id = "+mural+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			codigo = row[2];
			block = BuscaBloqueio(conn, user_id,codigo);

			if(!block){
				cout << "Numero: " << row[0] << "\t";
				//cout << "Codigo usuario: " << row[2] << "\t";
				ExibeNomeUsuario(conn, codigo);
				cout << "Data/hora: " << row[3] << "\t";
				cout << "foto: " << row[4] << "\t";
				cout << "Texto: " << row[5] << "\t";
				cout << "" <<endl;
			}

		}
	}else{
		cout << "conn problem" << endl;
	}

	cout << "sai?" <<endl;
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
void ExibeNomeUsuario(MYSQL* conn, string user_id){
	MYSQL_RES* res;
	MYSQL_ROW row;

	string c = "SELECT user_nome FROM Usuario WHERE user_id = "+user_id+"";

	const char* q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		res = mysql_store_result(conn);

		while(row=mysql_fetch_row(res)){
			cout << row[0] << endl;				
		}

	}else{
		cout << "conn problem exibe nome usuario " <<mysql_error(conn)<<endl;
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
	BuscaSolicitacoesUsuario(conn,user_id);
	int aux;
	int parada = 0;
	int valor;
	string user_idamizade;

	while(parada == 0){
		cout << "Digite (2) para Aceitar ou Recusar Solicitações\n Digite (1) para exibir solicitações \n Digite (0) para sair: " << endl;
		cin >> valor;
		switch(valor){
			case 2:
				cout << "Digite (1) para aceitar solicitação\n Digite (2) para recusar \n Digite (0) para sair: " <<endl;
				cin >> aux;
				switch(aux){
					case 1:
						cout << "Digite o numero do usuario para aceitar: " <<endl;
						cin >> user_idamizade;
						AceitarAmizade(conn,user_idamizade,user_id);
						break;
					case 2:
						cout << "Digite o numero do usuario para recusar: " <<endl;
						cin >> user_idamizade;
						DeletarAmizade(conn,user_id, user_idamizade);
						break;
				}
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

void ConfigurarBloqueio(MYSQL* conn, string user_id){
	ExibeBloqueio(conn,user_id);
	int parada = 0;
	int valor;
	string aux;

	while(parada == 0){
		cout << "Digite (2) para Retirar Bloqueio\n (1) para exibir lista de bloqueio \n (0) para sair: " << endl;
		cin >> valor;

		switch(valor){
			case 2:
				cout << "Digite o numero do usuario a ser desbloqueado" << endl;
				cin >> aux;
				DesbloquearUsuario(conn,user_id,aux);
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

void ConfigurarVisita(MYSQL* conn, string user_id, string user_idvisita){ /// FALTA CONFIGURARA PARA O PERFIL 
	//user_id é o usuario que esta logado no momento
	int aux;
	string aux2;
	string mural;
	int amizade = 0;

	int parada = 0;

	while(!parada){
		cout << "******************" <<endl;
		ExibeUsuariosId(conn,user_idvisita);
		cout << "\nDigite (1) - para ver amigos e/ou amigos em comum" <<endl; // Esta faltando a opção para bloquear
		cout << "Digite (2) - para ver mural" <<endl;

		amizade = BuscaAmizade(conn,user_id,user_idvisita);

		if(amizade == 0){
			cout << "Digite (3) - para solicitar amizade" <<endl;
		}else if(amizade == 2){
			cout << "Digite (3) - para aceitar amizade" <<endl;
		}else if(amizade == 1){

		}else if(amizade == 3){
			cout << "Solicitacao enviada" << endl;
		}else{
			cout << "erro visita"<<endl;
		}
		cout << "Digite (4) - para sair" <<endl;

		cin >> aux;
		switch(aux){
			case 1:
				ExibeAmigosVisita(conn,user_id,user_idvisita);//MELHORAR
				cout << "Digite o numero para visitar ou 0 para voltar: " <<endl;
				cin >> aux2;
				if(aux2 != "0"){
					ConfigurarVisita(conn, user_id,aux2);
				}else{
					//ConfigurarVisita(conn, user_id, user_idvisita);
				}
				break;
			case 2: // Configurar para o caso do tipo de visibilidade
				ConfigurarMuralVisita(conn,user_id,user_idvisita);
				break;
			case 3:
				if(amizade == 0){
					AdicionarAmigo(conn, user_id, user_idvisita,"0");
				}
				if(amizade == 2){
					AceitarAmizade(conn,user_id,user_idvisita);
				}
				//ConfigurarVisita(conn,user_id,user_idvisita);
				break;
			case 4:
				parada = 1;
				break;
		}
	}


}
void ConfigurarMuralVisita(MYSQL* conn, string user_id, string user_idvisita){
	//user_id é o usuario que esta logado no momento
	string mural_visita = BuscaMural(conn, user_idvisita);
	string publicacao_id;
	string user_idPublicacao;
	int parada = 0;
	int aux;

	while(!parada){
		ApresentaMenuDaPublicacao();
		cin >> aux;

		switch(aux){
			case 1://postar publicacao = criar publicacao
				CriarPublicacao(conn,mural_visita,user_id);
				break;
			case 2://Ver comentarios
				ExibeUsuarioMural(conn,mural_visita,user_id);
				cout << "Digite o numero da publicacao para ver os comentarios: " <<endl;
				cin >> publicacao_id;
				user_idPublicacao = BuscaUsuarioPublicacao(conn,publicacao_id);
				if(user_idPublicacao != "0"){
					ConfigurarPublicacaoVisita(conn,publicacao_id,mural_visita,user_idPublicacao,user_id);
				}
				break;
			case 3:
				ExibeUsuarioMural(conn,mural_visita,user_id); // Bloqueio feito
				break;
			case 0:
				parada = 1;
				break;
			default:
				cout << "Numero invalido" <<endl;

		}
	}
}
void ConfigurarPublicacaoVisita(MYSQL* conn, string publicacao_id, string mural_id, string user_idPublicacao, string user_id){
	//user_id é o usuario que esta logado no momento
	int parada = 0;
	int aux;
	string comentario_id;
	string user_idComentario;

	while(!parada){
		ApresentaMenuDoComentario();
		cin >> aux;
		switch(aux){
			case 1: // Postar comentario
				CriaComentario(conn,publicacao_id, mural_id,user_idPublicacao, user_id);
				break;
			case 2:// Ver respostas - FAZER
				ExibeComentarioDaPublicacao(conn,publicacao_id);
				cout << "\nDigite o numero do comentario para ver as respostas: " <<endl;
				cin >> comentario_id;

				user_idComentario = BuscaUsuarioComentario(conn, comentario_id);
	
				if(comentario_id != "0"){
					ConfigurarRespostaVisita(conn,publicacao_id, comentario_id, mural_id, user_idPublicacao, user_idComentario, user_id);					
				}
				break;
			case 3:// Ver todos os comentarios
				ExibeComentarioDaPublicacao(conn,publicacao_id);// FALTA CONFIGURAR PARA O BLOQUEIO
				break;
			case 0:
				break;
			default:
				cout << "Numero invalida " <<endl;
		}		
	}

}
void ConfigurarRespostaVisita(MYSQL* conn, string publicacao_id, string comentario_id, string mural_id, string user_idPublicacao, string user_idComentario, string user_id){
	int parada = 0;
	int aux;

	while(!parada){
		ApresentaResposta();
		cin >> aux;

		switch(aux){
			case 1: // Posta Resposta
				CriaResposta(conn,publicacao_id,comentario_id,mural_id,user_idPublicacao,user_idComentario,user_id);
				break;
			case 2:// Ver todas as respostas
				ExibeRespostaDeComentario(conn,comentario_id); // FALTA CONFIGURAR PARA O BLOQUEIO
				break;
			case 0:
				parada = 1;
				break;
			default:
				cout << "Numero invalida " <<endl;
		}
	}
}

void DesbloquearUsuario(MYSQL* conn, string user_id, string user_idbloqueio){

	string c = "DELETE FROM Bloqueio WHERE user_id = "+user_id+" AND user_idbloqueio = "+user_idbloqueio+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		cout << "usuario desbloqueado com sucesso" <<endl;
	}else{
		cout << "erro desbloqueio" <<endl;
	}
}

void AceitarAmizade(MYSQL* conn,string user_id, string user_idamizade){

	string c = "UPDATE Amizade SET amizade_tipo = 1 WHERE user_id = "+user_id+" AND user_idamizade = "+user_idamizade+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		cout << "amizade feita com sucesso" <<endl;
	}else{
		cout << "erro amizade" <<endl;
	}
}

void DeletarAmizade(MYSQL* conn,string user_id, string user_idamizade){

	string c = "DELETE FROM Amizade WHERE user_id = "+user_id+" AND user_idamizade = "+user_idamizade+"";

	const char *q = c.c_str();

	int qstate = mysql_query(conn, q);

	if(!qstate){
		cout << "amizade excluida com sucesso" <<endl;
	}else{
		cout << "erro exclusao-amizade" <<endl;
	}

}