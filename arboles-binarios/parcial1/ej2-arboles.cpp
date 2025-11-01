#include <stdio.h>

struct tree
{
    int num;
    tree *l_branch;
    tree *r_branch;
};

void eliminar(tree *&root);
void insertar(tree *&root, int num);
void mostrar(tree *root);

int main()
{
    tree *root = NULL;
    int num;
    do
    {
        printf("Ingrese un numero. Para dejar de ingresar, escriba '-1'\n");
        scanf("%i", &num);
        if (num == -1)
            break;
        insertar(root, num);
    } while (num != -1);
    mostrar(root);
    eliminar(root);
    mostrar(root);
};

void eliminar(tree *&root)
{
    if (root != NULL)
    {
        eliminar(root->l_branch);
        eliminar(root->r_branch);
        delete root;
        root = NULL;
    }
};

void insertar(tree *&root, int num)
{
    if (root == NULL)
    {
        tree *arbol = new tree;
        arbol->l_branch = arbol->r_branch = NULL;
        arbol->num = num;
        root = arbol;
    }
    else
    {
        if (num < root->num)
        {
            insertar(root->l_branch, num);
        }
        else if (num > root->num)
        {
            insertar(root->r_branch, num);
        }
        else
            printf("No se pueden agregar numeros que ya han sido agregados al arbol");
    }
};

void mostrar(tree *root)
{
    if (root != NULL)
    {
        if (root->l_branch != NULL)
        {
            mostrar(root->l_branch);
        }
        printf("numero: %i\n", root->num);
        if (root->r_branch != NULL)
        {
            mostrar(root->r_branch);
        }
    }
    else {
        printf("Arbol borrado");
    }
};
