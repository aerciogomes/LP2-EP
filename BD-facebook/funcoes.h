#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <string>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//FUNÇÕES DE CRIAÇÃO
extern int CriaUsuario(MYSQL *conn);
extern string CriarGrupo(MYSQL*conn);
extern void AdicionarAmigo(MYSQL* conn, string user_id, string user_idamizade,string tipo);
extern void BloquearAmigo(MYSQL *conn,string user_id,string user_idbloqueio);
extern void CriaComentario(MYSQL* conn,string comentario_id,string publicacao_id,string mural_id,string user_idPublicacao,string user_idComentario,string comentario_text);
extern void CriaResposta(MYSQL* conn,string resposta_id,string publicacao_id,string comentario_id,string mural_id,string user_idPublicacao,string user_idComentario,string user_idResposta,string resposta_text);

//FUNÇÕES DE BUSCA
extern string BuscarUsuarioNomes(MYSQL* conn, string nome);
extern int BuscaBloqueio(MYSQL* conn,string user_id, string user_idbloqueio);
extern int BuscaSolicitacoesUsuario(MYSQL* conn, string user_id);

//FUNÇÕES DE EXIBIÇÃO
extern void ExibeUsuarios(MYSQL* conn);
extern void ExibeUsuariosId(MYSQL* conn, string user_id);
extern void ExibeGrupo(MYSQL* conn);
extern void ExibeAmigos(MYSQL* conn, string user_id);
extern void ExibeUsuarioMural(MYSQL* conn, string mural);
extern void ExibePublicacaoUsuario(MYSQL* conn, string user_id);
extern void ExibeComentarioDaPublicacao(MYSQL *conn, string publicacao_id);
extern void ExibeRespostaDeComentario(MYSQL *conn, string comentario_id);
extern void ExibeBloqueio(MYSQL* conn,string user_id);

//Login
extern string LoginUsuario(MYSQL* conn);


extern void flush();

extern void ConfigurarSolicitacoes(MYSQL* conn, string user_id);
extern void ConfigurarBloqueio(MYSQL* conn, string user_id);

#endif // FUNCOES_H_INCLUDED