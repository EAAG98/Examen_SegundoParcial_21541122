#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
    int numero;
    struct nodo* izquierda, * derecha;
};

typedef struct nodo* ABC;

ABC crearNodo(int x)
{
    ABC nuevoNodo = new(struct nodo);
    nuevoNodo->numero = x;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    return nuevoNodo;
}
void insertar(ABC& arbol, int x)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x);
    }
    else if (x < arbol->numero)
        insertar(arbol->izquierda, x);
    else if (x > arbol->numero)
        insertar(arbol->derecha, x);
}

void preOrden(ABC arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->numero << " ";
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}

void enOrden(ABC arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izquierda);
        cout << arbol->numero << " ";
        enOrden(arbol->derecha);
    }
}

void postOrden(ABC arbol)
{
    if (arbol != NULL)
    {
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        cout << arbol->numero << " ";
    }
}

void verArbol(ABC arbol, int n)
{
    if (arbol == NULL)
        return;
    verArbol(arbol->derecha, n + 1);

    for (int i = 0; i < n; i++)
        cout << "   ";

    cout << arbol->numero << endl;

    verArbol(arbol->izquierda, n + 1);
}

int main()
{
    ABC arbol = NULL; 

    int n;  
    int x;

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " Numero del nodo " << i + 1 << ": ";
        cin >> x;
        insertar(arbol, x);
    }

    cout << "\n Mostrando ABC \n\n";
    verArbol(arbol, 0);

    cout << endl << endl;

    system("pause");
    return 0;
}