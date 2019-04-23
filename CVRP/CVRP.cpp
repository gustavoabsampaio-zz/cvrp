#include <iostream>
#include <fstream>

//#include <cmath>
using namespace std;

//Clientes: posição, demanda
class Node
{
	public:
		int xPos;
		int yPos;
		int demand;
		float cost[101];
};

float distances(Node n1, Node n2)
{
	int x = n2.xPos - n1.xPos;
	int y = n2.yPos - n1.yPos;
	float d = sqrt((x * x) + (y * y));
	cout << d << endl;
	return d;
}

int main()
{
	Node nodes[101];

	ifstream nodeData;
	int dump;

	nodeData.open("nodes.txt");
	for(int i=0;i<101;i++)
	{
		nodeData >> dump >> nodes[i].xPos >> nodes[i].yPos >> nodes[i].demand;
		//cout << nodes[i].xPos << nodes[i].yPos << nodes[i].demand<<endl;
	}
	nodeData.close();

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; i < 101; i++)
		{
			if (i != j)
			{
				nodes[i].cost[j] = distances(nodes[i], nodes[j]);
			}
		}
		nodes[i].cost[i] = 0;
	}

    cout << nodes[15].cost[15]; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
/*

*/