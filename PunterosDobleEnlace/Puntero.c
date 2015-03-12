#include <stdlib.h>

/*
Implementar un proyecto para el tipo lista simplemente enlazada. Debe tener las siguientes funciones:
- Crear lista (lista) -> Se crea conceptualmente, a NULL.
- Insertar lista (lista_donde_insertar, dato_a_insertar) -> Cnstruir listas
- Mostrar lista(lista) -> Escribir contneido.
- Longitud lista(lista) -> Numero de elementos que contiene
- Extraer lista(lista) -> Devuelve un entero que se corresponde con el último elemento insertado.
Es decir, en primera posición tras la cabeza.
- Eliminar lista(lista, elemento_a_borrar) -> Borrar el elemento de la lista.
- Buscar lista(lista, dato_a_buscar) -> Devuelve puntero al elemento. Recorre la lista con un puntero auxiliar,
si se encuentra se devuelve el puntero apuntando al elemento. De lo contrario, uno que apunte a NULL.
*/

struct tNodo {
	int info;
	struct tNodo *next;
	struct tNodo *prev;
};

typedef struct tNodo tNodo;

void crear_lista(tNodo **lista);
void insertar_lista(tNodo **lista, int dato);
int extraer_lista(tNodo **lista);
void mostrar_lista(tNodo *lista);
int longitud_lista(tNodo *lista);
void borrar_lista(tNodo **lista, int dato);

void crear_lista(tNodo **lista) {
	*lista = NULL;
}

void insertar_lista(tNodo **lista, int dato) {
	tNodo *nuevaLista;

	nuevaLista = malloc(sizeof(tNodo));

	nuevaLista->info = dato;
	nuevaLista->next = *lista;
	nuevaLista->prev = &lista;

	*lista = nuevaLista;
}

void mostrar_lista(tNodo *lista) {
	tNodo *p;
	for (p = lista; p != NULL; p = p->next) {
		printf("%d - ", p->info);
	}
}

int longitud_lista(tNodo *lista) {
	int longitud = 0;
	tNodo *p;
	for (p = lista; p != NULL; p = p->next) {
		longitud++;
	}
	return longitud;
}

int extraer_lista(tNodo **lista) {

	/*tNodo *extraccion = NULL;
	extraccion = *lista;
	*lista = extraccion->next;
	return extraccion->info;*/
	int valor;

	valor = (*lista)->info;
	*lista = (*lista)->next;

	return valor;
}

int buscarDato(tNodo *lista, int dato) {
	tNodo *p;
	int loc = NULL;
	for (p = lista; p != NULL; p = p->next) {
		if (p->info == dato)
			loc = 1;
	}
	return loc;
}

tNodo *buscarElemento(tNodo *lista, int valor, int tipo) {
	tNodo *localizado;
	int encontrado = 0;

	//-1 Elemento exacto que apunta al que busco
	// 0 Elemento que busco
}

void borrar_lista(tNodo **lista, int dato) {
	if (buscarDato(*lista, dato) != NULL) {
		tNodo *p, *q, *aux;
		aux = *lista;
		for (p = *lista; p != NULL; p = p->next) {
			if (p->info == dato) {
				for (q = *lista; q != NULL; q = q->next) {
					if (q->next == p) {
						q->next = p->next;
					}
				}
			}
		}
	}
}

/*void eliminarElemento(tNodo **lista, int dato) {
anterior = buscar-1
borrar = buscar0
}*/

void main() {

	tNodo *lista1, *lista2;
	int ext1;
	crear_lista(&lista1);
	crear_lista(&lista2);

	insertar_lista(&lista1, 4);
	insertar_lista(&lista1, 15);
	insertar_lista(&lista1, 20);
	insertar_lista(&lista1, 35);

	insertar_lista(&lista2, 14);
	insertar_lista(&lista2, 25);
	insertar_lista(&lista2, 30);
	insertar_lista(&lista2, 45);

	printf("\n");
	mostrar_lista(lista1); printf("Long: %d\n", longitud_lista(lista1));
	mostrar_lista(lista2); printf("Long: %d\n", longitud_lista(lista2));
	printf("\n");
	ext1 = extraer_lista(&lista1);
	printf("Numero Extraido en lista1 (primero): %d\n ", ext1);
	borrar_lista(&lista1, 20);
	printf("\n");
	mostrar_lista(lista1); printf("Long: %d\n", longitud_lista(lista1));
	mostrar_lista(lista2); printf("Long: %d\n", longitud_lista(lista2));

	getch();
	return;
}