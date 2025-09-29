#include <stdio.h>

struct lista
{
    int num;
    lista *sig;
};

void agregarLista(int num, lista *&list);
void liberarLista(lista *&list);
void mostrarLista(lista *list);
void ordenarLista(lista *&list);
lista *quitarLista(int num, lista *&list);

int main()
{
    lista *list = NULL;
    int ingresar;

    do
    {
        printf("Ingrese numero para ingresar al menu.\n 1-Agregar a la lista.\n 2-Quitar de la lista.\n 3-Ordenar la lista\n 4-Salir.\n");
        int num;
        scanf("%i", &ingresar);
        switch (ingresar)
        {
        case 1:
            printf("Ingrese numero a agregar a la lista: ");
            scanf("%i", &num);
            agregarLista(num, list);
            
            break;
        case 2:
        {
            printf("Ingrese numero a remover de la lista: ");
            scanf("%i", &num);
            lista *listaRemovida = quitarLista(num, list);
            if (listaRemovida != NULL)
            {
                printf("Lista removida: %i\n", listaRemovida->num);
                delete listaRemovida; 
            }
            else
            {
                printf("El numero no estaba en la lista.\n");
            }
            break;
        }
        case 3:
            ordenarLista(list);
            break;
        case 4:
            mostrarLista(list);
            break;
        default:
            printf("Ingrese un numero valido");
            break;
        }

    } while (ingresar != 4);

    liberarLista(list);
    return 0;
}

void agregarLista(int num, lista *&list)
{
    lista *tmp = new lista;
    tmp->num = num;
    if (list == NULL)
    {
        tmp->sig = NULL;
        list = tmp;
    }
    else
    {
        lista *aux = list;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = tmp;
        tmp->sig = NULL;
    }
}

void liberarLista(lista *&list) {
    while(list != NULL) {
        lista *tmp = list;
        list = list->sig;
        delete tmp; 
    }
}

void mostrarLista(lista *list)
{
    printf("\nLista completa:\n");
    while (list != NULL)
    {
        printf("%i -> ", list->num);
        list = list->sig;
    }
}

void ordenarLista(lista *&list) {
    if (list != NULL) {
        bool flag;
        do {
            flag = false;
            lista *tmp = list;
            while (tmp->sig != NULL) {
                if (tmp->num > tmp->sig->num) {
                    int aux = tmp->sig->num;
                    tmp->sig->num = tmp->num;
                    tmp->num = aux;
                    flag = true;
                }
                tmp = tmp->sig;
            }
        } while (flag);
    }
    mostrarLista(list);
}

lista *quitarLista(int num, lista *&list)
{
    if (list == NULL)
        return NULL;

    if (list->num == num)
    {
        lista *tmp = list;
        list = tmp->sig;
        return tmp;
    }

    lista *prev = list;
    lista *act = prev->sig;
    while (act != NULL)
    {
        if (act->num == num)
        {
            prev->sig = act->sig;
            return act;
        }
        prev = prev->sig;
        act = act->sig;
    }

    return NULL;
}

