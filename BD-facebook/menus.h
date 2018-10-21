#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <string>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

extern void ApresentaMenuInicial(); //login/cadastre
extern void ApresentaMenuDoUsuario(); //buscar - usuario e grupos.../Alterar Perfil/Ver mural/Ver grupos/Ver amigos
extern void ApresentaMenuDaVisita(int a,int b); //Solicitar-amizade/Ver amigos ou amigos em comum/Ver Mural
extern void ApresentaMenuDoMural1UG(int a); //Postar Publicação/Ver publicação
extern void ApresentaMenuDoMural2UG(); 
extern void ApresentaMenuDaPublicacao(); //Postar comentario/Ver comentario
extern void ApresentaResposta();


#endif // MENUS_H_INCLUDED