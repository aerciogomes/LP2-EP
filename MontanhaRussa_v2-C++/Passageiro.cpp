/*
 * Passageiro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */
#include <iostream>
#include <ostream>
#include "include/Passageiro.h"
#include "include/Carro.h"
#include "include/Parque.h"
#include "windows.h"
#include <atomic>
#include "include/Pinter.h"
#include <time.h>

#define MAX_NUM_VOLTAS 10

using namespace std;

const int N = 0;
std::atomic<int> Carro::numPassageiros = ATOMIC_VAR_INIT(N);
std::atomic<int> Passageiro::data = ATOMIC_VAR_INIT(N);
bool Passeia = true;

Passageiro::Passageiro(int id, Carro *c, Parque *t) {
	this->id = id;
	this->carro = c;
	this->parque = t;
}

Passageiro::~Passageiro() {
}

void Passageiro::entraNoCarro() {
    int maior = 0;
    turn = 1;

    for(auto &p : parque->getPassageiros()){
        if(p->getTurn() > maior)
            maior = p->getTurn();
    }

    turn = maior + 1;

    for(auto &p : parque->getPassageiros()){
        if(this->id == p->getId())
            continue;
        while((p->getTurn() != 0 && (p->getTurn() < this->turn || (p->getTurn() < this->turn  && p->getId() < id))) || (Carro::numPassageiros == Carro::CAPACIDADE)|| (carro->voltaAcabou)){
        }
    }
    if(!parqueFechado()){
        std::atomic_fetch_add(&Carro::numPassageiros, 1);// incremente o número de pessoas no carro
        //Printer::printInt(Carro::numPassageiros, "+");
        Printer::printString("Entra no Carro", id);
    }
    turn = 0;

}

void Passageiro::esperaVoltaAcabar() {
	while (!(carro->getV())) {Sleep(500);}

}

void Passageiro::saiDoCarro() {
	std::atomic_fetch_sub(&Carro::numPassageiros, 1);// decrementa o número de pessoas do carro
	//Printer::printInt(Carro::numPassageiros, "-");
}

void Passageiro::passeiaPeloParque() {
    srand(time(NULL));
    std::atomic_fetch_add(&Passageiro::data, ((rand() % 200) + 10));
    //Printer::printString("Numero randomico", Passageiro::data);
    Sleep(Passageiro::data);
    //Printer::printString("Volta pra fila",id);
}

bool Passageiro::parqueFechado() {
	if (carro->getNVoltas() < MAX_NUM_VOLTAS)
		return false;

	return true;
}

void Passageiro::run() {
	while (!parqueFechado()) {
		entraNoCarro(); // protocolo de entrada
        if(parqueFechado()){break;}
		esperaVoltaAcabar();

		saiDoCarro(); // protocolo de saida

		passeiaPeloParque(); // secao nao critica
	}
    Printer::printNone("SAINDO");
	std::atomic_fetch_sub(&Parque::numPessoas, 1);  // decrementa o numero de pessoas no parque
}

int Passageiro::getId(){
    return id;
}

int Passageiro::getTurn(){
    return turn;
}
