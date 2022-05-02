#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BinarySearchTreeClass.h"

using namespace std;

int main()
{
	BinarySearchTree<int> tree;
	int max = 5000;
	int value;
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		value = rand() % max;
		tree.insert(value);
	}

	cout << string(10, '=') << "INORDER" << string(10, '=') << endl;
	tree.inorder(cout);
	cout << "\n\n";

	cout << string(10, '=') << "PREORDER" << string(10, '=') << endl;
	tree.preorder(cout);
	cout << "\n\n";

	cout << string(10, '=') << "POSTORDER" << string(10, '=')<< endl;
	tree.postorder(cout);
	cout << "\n\n";

	cout << string(10, '=') << "TREE HEIGHT" << string(10, '=') << endl;
	cout << tree.height();
	cout << "\n\n";

	tree.destroy();

	return 0;
}

/*

==========INORDER==========
26
841
946
1142
2575
2653
2769
3567
4166
4832


==========PREORDER==========
946
26
841
1142
2575
4166
3567
2769
2653
4832


==========POSTORDER==========
841
26
2653
2769
3567
4832
4166
2575
1142
946


==========TREE HEIGHT==========
7


C:\Users\WillG\OneDrive\Desktop\Webster\FA2020\DataStructures\DataStructures II\Week3\BinarySearchTree\Debug\BinarySearchTree.exe (process 19640) exited with code 0.
Press any key to close this window . . .

*/