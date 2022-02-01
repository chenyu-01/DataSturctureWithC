#include "Header.h"

int main()
{
	BiTree tree;
	//CreateBiTree(&tree);
	HirachicalBuild(&tree);
	LevelOrder(tree);
	//InOrder2(tree);
	//PreOrder(tree);
	while (true)
	{
		printf("yeschan\n");
	}
	return 0;
}