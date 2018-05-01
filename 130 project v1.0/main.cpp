#include <iostream>
#include <vector>
#include "Dijkstra_matrix.h"
using namespace std;
int main()
{
	dijkstra DB;
	cout << "the start position: " << std::endl;
	string start;
	string end;
	int vertex_begin;
	cin >> start;
	cout << "the end position: " << std::endl;
	cin >> end;
	
	char filename[] = "input.txt";
	string city_name_string = "CITY.txt";
	DB._LOAD_DATA_(filename);
	DB._LOAD_CITY_STRING_(city_name_string);

	//cout << DB.city_name_stream.size() << endl;
	for (unsigned int i = 1; i < DB.city_name_stream.size(); i++)
	{
		if (DB.city_name_stream[i] == end)
		{
			DB.city_number = i;
			break;
		}
		if (DB.city_name_stream[i] == start)
		{
			vertex_begin = i;
		}

	}

	//cout << vertex_begin << " " << DB.city_number;


	DB._EXPLORE_MATRIX(vertex_begin);
	DB._PRINT_PATH(vertex_begin);
	DB._SHOW_COST_();
	system("pause");
}