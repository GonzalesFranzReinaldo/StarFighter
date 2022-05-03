// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"


template<class T>
class Pila {

private:
	T* Datos;
	//EVector<T>Datos
	int Cima;
	const int NumeroElementos;

public:
	Pila(int _NumeroElementos) :NumeroElementos(_NumeroElementos) {
		
		Datos = new T[NumeroElementos];
		Cima = -1;
	}
	~Pila() { delete[] Datos; }

	//Funcionpush
	void Insertar(T c);

	//funcion Pop
	T Sacar();
	bool Vacia();
	bool Llena();

	int getCima() { return Cima; }
};

template<class T>
void Pila<T>::Insertar(T ElementoInsertar) {

	if (!Llena()) {
		Cima++;
		Datos[Cima] = ElementoInsertar;

		cout<< "Se a insertado saticfactoriamente"<<endl;
	}
	else {
		cout << "No se pudo ingresar el elemento de la pila" << endl;
	}
}

template<class T>
T Pila<T>::Sacar() {

	if (!Vacia()) {
		T ElementoSacar = Datos[Cima];
		Cima--;
		return ElementoSacar;
	}
	else {
		cout << "No se pudo sacar el elemento de la pila" << endl;
	}
}

template<class T>
bool Pila<T>::Vacia() {

	if (Cima < 0) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
bool Pila<T>::Llena() {

	if (Cima < NumeroElementos - 1) {
		return false;
	}
	else {
		return true;
	}
}