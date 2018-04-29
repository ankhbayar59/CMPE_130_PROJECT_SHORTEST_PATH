#include <iostream>
#include <vector>
#include "Dijkstra_matrix.h"
//using namespace std;
int main()
{
	dijkstra DB;
	char filename[] = "input.txt";
	DB._LOAD_DATA_(filename);
	std::cout << "the first element number: " << std::endl;
	int vertex_begin;
	std::cin >> vertex_begin;
	DB._EXPLORE_MATRIX(vertex_begin);
	DB._PRINT_PATH(vertex_begin);
	DB._SHOW_COST_();

}