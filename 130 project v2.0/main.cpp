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
	cin >> start;
	DB.start = start;
	cout << "the end position: " << std::endl;
	cin >> end;
	DB.end = end;
	int start_city = 0;
	int end_city = 0;
	
	
	char filename[] = "input.txt";
	string city_name_string = "CITY.txt";
	DB._LOAD_DATA_(filename);
	DB._LOAD_CITY_STRING_(city_name_string);

	for (unsigned int i = 1; i < DB.city_name_stream.size(); i++)
	{
		if (DB.city_name_stream[i] == start)
			start_city = i;
		if (DB.city_name_stream[i] == end)
			end_city = DB.end_city = i;
	}

	DB._EXPLORE_MATRIX_(start_city);
	DB._PRINT_PATH_(start_city,end_city);
	DB._SHOW_COST_();
	system("pause");
}