#include <stdio.h>

struct Nodo
{
    int num;
    Nodo *sig;
};

void cargar_lista(int num, Nodo *&lista);
void borrar_lista(Nodo *&lista, int &cont_borrador);
void mostrar_lista(Nodo *lista, int cont_borrador);

int main()
{
    int eleccion;
    Nodo *lista = NULL;
    int cont_borrados = 0;
    int num;

    do
    {
        printf("Ingresa numero para realizar operacion:\n1-Carga\n2-Borrar\n3-Mostrar\n");
        scanf("%i", &eleccion);
        switch (eleccion)
        {
        case 1:
            scanf("%i", &num);
            cargar_lista(num, lista);
            break;
        case 2:
            borrar_lista(lista, cont_borrados);
            break;
        case 3:
            mostrar_lista(lista, cont_borrados);
            break;
        default:
            printf("Ingrese numero valido");
            break;
        }
    } while (eleccion != 3);
}

void cargar_lista(int num, Nodo *&lista)
{
    Nodo *temp = new Nodo;
    temp->num = num;
    temp->sig = NULL;

    if (lista == NULL)
    {
        lista = temp;
    }
    else
    {
        Nodo *aux = lista;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = temp;
    }
}

void borrar_lista(Nodo *&lista, int &cont_borrador)
{
    Nodo *act = lista;
    Nodo *prev = NULL;

    while (act != NULL)
    {
        if (act->num > 0)
        {
            Nodo *tmp = act; // Guardamos nodo a borrar
            if (prev == NULL) // Si es el primer nodo
            {
                lista = act->sig;
            }
            else
            {
                prev->sig = act->sig;
            }
            act = act->sig; // Avanzamos act antes de liberar
            cont_borrador++;
            printf("Num borrado: %i\n", tmp->num);
            delete(tmp); // O delete tmp si es C++
        }
        else
        {
            prev = act;       // Solo avanzamos prev si no borramos
            act = act->sig;   // Siempre avanzamos act
        }
    }
}

void mostrar_lista(Nodo *lista, int cont_borrador)
{
    Nodo *aux = lista;
    while (aux != NULL)
    {
        printf("Numero en lista: %i\n", aux->num);
        aux = aux->sig;
    }
    printf("Cantidad de borrados: %i", cont_borrador);
}
int combinar(int n, int k);

int main() {
    int n; 
    int k;
    scanf("%i", &n);
    scanf("%i", &k);
    int combinacion = combinar(n, k);
    printf("Combinacion: %i", combinacion);
}

int combinar(int n, int k) {
    if (n == k || k == 0) return 1;

    return combinar(n-1, k-1) + combinar(n-1, k);
}
