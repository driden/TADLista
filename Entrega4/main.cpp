#include "Puntero.h"
#include "Lista.h"
#include "Cadena.h"
#include "ListaEncadenada.h"

void PrintLista(Puntero<Lista<Cadena>> lista)
{
	Iterador<Cadena> iter = lista->ObtenerIterador();
	
	foreach (Cadena c, iter)
	{
		cout << c << ", ";
	}
	cout << endl;
}

void PrintByIndex(Puntero<Lista<Cadena>> lista)
{
	for (nat pos = 0; pos < lista->Largo();pos++)
		cout <<  lista->Obtener(pos) << ", ";

	cout << endl;
}

void PrintLista(Puntero<Lista<nat>> lista)
{
	Iterador<nat> iter = lista->ObtenerIterador();
	foreach(nat c, iter)
	{
		cout << c << ", ";
	}
	cout << endl;
}

void main()
{
	Puntero<Lista<Cadena>> listaCadena = new ListaEncadenada<Cadena>(Comparador<Cadena>::Default);

	listaCadena->Insertar("Uno");
	listaCadena->Insertar("Dos");
	listaCadena->Insertar("Tres");

	PrintLista(listaCadena);

	listaCadena->Eliminar("Uno");
	listaCadena->Insertar("Uno");
	listaCadena->Eliminar("Uno");

	listaCadena->Insertar("Cuatro");
	listaCadena->Eliminar("Tres");

	PrintLista(listaCadena);
	PrintByIndex(listaCadena);

	std::cout << listaCadena->Obtener(0) <<endl;
	std::cout << listaCadena->Obtener(1) << endl;

	system("pause");
}
