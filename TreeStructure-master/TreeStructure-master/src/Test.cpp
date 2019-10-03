#include <stdio.h>
#include <iostream>




struct dugum
{
    int data;
    dugum * left;
    dugum * right;
};

typedef dugum element;
element* add(element* tree, int addnecekDeger)
{
    if (tree == NULL)
    {
        element* kok = (element*)malloc(sizeof(element));
        kok->right = NULL;
        kok->left = NULL;
        kok->data = addnecekDeger;
        return kok;
    }
    if (tree->data < addnecekDeger)
    {
        tree->right = add(tree->right, addnecekDeger);
    }
    else
    {
        tree->left = add(tree->left, addnecekDeger);
    }
    return tree;
}

void soldansaga(element* tree)
{
    if (tree == NULL)
    {
        return;
    }
    soldansaga(tree->left);
    std::cout << tree->data << " ";
    soldansaga(tree->right);
}
void koktensaga(element* tree)
{
    if (tree == NULL)
    {
        return;
    }
    std::cout << tree->data << " ";
    koktensaga(tree->left);
    koktensaga(tree->right);
}
void soldankoke(element* tree)
{
    if (tree == NULL)
    {
        return;
    }
    soldankoke(tree->left);
    soldankoke(tree->right);
    std::cout << tree->data << " ";
}
int enKucukDegeriBul(element* tree)
{
    element* arayici = tree;
    while(arayici->left != NULL)
        arayici = arayici->left;
    return arayici->data;
}

int enBuyukDegeriBul(element* tree)
{
    element* arayici = tree;
    while(arayici->right != NULL)
        arayici = arayici->right;
    return arayici->data;
}

element* sil(element* tree, int silinecekDeger)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (silinecekDeger == tree->data)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            return NULL;
        }
        if (tree->right != NULL)
        {
            tree->data = enKucukDegeriBul(tree->right);
            tree->right = sil(tree->right, enKucukDegeriBul(tree->right));

            return tree;
        }
        if (tree->left != NULL)
        {
            tree->data = enBuyukDegeriBul(tree->left);
            tree->left = sil(tree->left, enBuyukDegeriBul(tree->left));
            return tree;
        }
    }
    if (silinecekDeger < tree->data)
    {
        tree->left = sil(tree->left, silinecekDeger);
        return tree;
    }
    tree->right = sil(tree->right, silinecekDeger);
    return tree;
}


int main(int argc, char *argv[])
{
    element* tree = NULL;
    tree = add(tree, 15);
    tree = add(tree, 5);
    tree = add(tree, 20);
    tree = add(tree, 3);
    tree = add(tree, 12);
    tree = add(tree, 18);
    tree = add(tree, 23);
    tree = add(tree, 10);
    tree = add(tree, 13);
    tree = add(tree, 6);
	tree = add(tree, 7);

    soldansaga(tree);
    std::cout << std::endl;
    koktensaga(tree);
    std::cout << std::endl;
    soldankoke(tree);
    std::cout << std::endl;


    std::cout << enKucukDegeriBul(tree) << std::endl;
    std::cout << enBuyukDegeriBul(tree) << std::endl;


    tree = sil(tree, 2);
    soldansaga(tree);
    std::cout << std::endl;

    tree = sil(tree, 20);
    soldansaga(tree);
    std::cout << std::endl;

    tree = sil(tree, 13);
    soldansaga(tree);
    std::cout << std::endl;
	
	std::cin.get();

    return 0;

}
