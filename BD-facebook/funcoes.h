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
extern void CriarPublicacao(MYSQL* conn, string mural_id,string user_id); // Ajeitar para a data hora receber a data e hora do pc
extern void CriaComentario(MYSQL* conn,string publicacao_id,string mural_id,string user_idPublicacao,string user_idComentario);
extern void CriaResposta(MYSQL* conn,string publicacao_id,string comentario_id,string mural_id,string user_idPublicacao,string user_idComentario,string user_idResposta);

//FUNÇÕES DE BUSCA
extern string BuscarUsuarioNomes(MYSQL* conn, string nome);
extern int BuscaBloqueio(MYSQL* conn,string user_id, string user_idbloqueio);
extern int BuscaSolicitacoesUsuario(MYSQL* conn, string user_id);
extern int BuscaAmizade(MYSQL* conn, string user_id,string user_idamizade);
extern int BuscaPerfil(MYSQL* conn, string user_id);
extern string BuscaMural(MYSQL* conn, string user_id);
extern string BuscaUsuarioPublicacao(MYSQL* conn, string publicacao_id);
extern string BuscaUsuarioComentario(MYSQL* conn, string comentario_id);

//FUNÇÕES DE EXIBIÇÃO
extern void ExibeUsuarios(MYSQL* conn, string user_id);
extern void ExibeUsuariosId(MYSQL* conn, string user_id);
extern void ExibeGrupo(MYSQL* conn);
extern void ExibeAmigos(MYSQL* conn, string user_id);
extern void ExibeAmigosVisita(MYSQL* conn, string user_id, string user_idvisita);
extern void ExibeUsuarioMural(MYSQL* conn, string mural, string user_id);
extern void ExibePublicacaoUsuario(MYSQL* conn, string user_id);
extern void ExibeComentarioDaPublicacao(MYSQL *conn, string publicacao_id);
extern void ExibeRespostaDeComentario(MYSQL *conn, string comentario_id);
extern void ExibeBloqueio(MYSQL* conn,string user_id);
extern void ExibeNomeUsuario(MYSQL* conn, string user_id);

//Login
extern string LoginUsuario(MYSQL* conn);


extern void flush();

//Auxiliam a navegação
extern void ConfigurarSolicitacoes(MYSQL* conn, string user_id);
extern void ConfigurarBloqueio(MYSQL* conn, string user_id);
extern void ConfigurarMuralVisita(MYSQL* conn, string user_id, string user_idvisita);
extern void ConfigurarVisita(MYSQL* conn, string user_id, string user_idvisita); // FAZER
extern void ConfigurarPublicacaoVisita(MYSQL* conn, string publicacao_id, string mural_id, string user_idPublicacao, string user_id);
extern void ConfigurarRespostaVisita(MYSQL* conn, string publicacao_id, string comentario_id, string mural_id, string user_idPublicacao, string user_idComentario, string user_id);

//Funções extras
extern void DesbloquearUsuario(MYSQL* conn, string user_id, string user_idbloqueio);
extern void AceitarAmizade(MYSQL* conn,string user_id, string user_idamizade);
extern void DeletarAmizade(MYSQL* conn,string user_id, string user_idamizade);



#endif // FUNCOES_H_INCLUDED