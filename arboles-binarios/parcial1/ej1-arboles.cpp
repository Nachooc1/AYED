#include <stdio.h>

struct arbol
{
    int num;
    arbol *l_branch;
    arbol *r_branch;
};

int alturaArbol(arbol *root);
void cargarArbol(arbol *&root, int num);
int hojasArbol(arbol *root);
void mostrarArbol(arbol *root);
int nodosArbol(arbol *root);

int main()
{
    arbol *root = NULL;

    int opcion;
    do
    {
        printf("Ingrese numero para ingresar al menu:\n1: calcular altura del arbol.\n2: ingresar numeros al arbol.\n3: calcular cantidad de hojas del arbol.\n4: mostrar arbol en orden creciente.\n5: calcular cantidad de nodos en el arbol.\n6: salir.\n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
            printf("altura del arbol: %i\n", alturaArbol(root));
            break;
        case 2:
            int num;
            do
            {
                printf("Ingrese un numero\n");
                scanf("%i", &num);
                if (num == -1)
                    break;
                cargarArbol(root, num);
            } while (num != -1);
            break;
        case 3:
            printf("hojas del arbol: %i\n", hojasArbol(root));
            break;
        case 4:
            mostrarArbol(root);
            break;
        case 5:
            printf("cantidad de nodos en el arbol: %i\n", nodosArbol(root));
            break;
        case 6:
            break;
        default:
            printf("Ingrese una opcion correcta");
            break;
        }
    } while (opcion != 6);
};

int alturaArbol(arbol *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int cont_lb = alturaArbol(root->l_branch) + 1;
        int cont_rb = alturaArbol(root->r_branch) + 1;
        if (cont_lb > cont_rb)
            return cont_lb;
        else
            return cont_rb;
    }
};

void cargarArbol(arbol *&root, int num)
{
    if (root == NULL)
    {
        root = new arbol;
        root->l_branch = root->r_branch = NULL;
        root->num = num;
    }
    else
    {
        if (num < root->num)
        {
            cargarArbol(root->l_branch, num);
        }
        else if (num > root->num)
        {
            cargarArbol(root->r_branch, num);
        }
        else
            printf("No se pueden agregar numeros ya presentes en el arbol");
    }
};

int hojasArbol(arbol *root)
{
    if (root == NULL)
        return 0;

    if (root->l_branch == NULL && root->r_branch == NULL)
        return 1;

    return hojasArbol(root->l_branch) + hojasArbol(root->r_branch);
};

void mostrarArbol(arbol *root)
{
    if (root != NULL)
    {
        mostrarArbol(root->l_branch);
        printf("%i\n", root->num);
        mostrarArbol(root->r_branch);
    }
}

int nodosArbol(arbol *root) {
    if (root == NULL) return 0;
    else {
        return nodosArbol(root->l_branch) + nodosArbol(root->r_branch) + 1;
    }
}