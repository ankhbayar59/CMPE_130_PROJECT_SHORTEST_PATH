#include <iostream>
#include <vector>
#include <fstream>
#include "Dijkstra_matrix.h"
using namespace std;
int main()
{
	dijkstra DB;
	cout << "All Cities" << endl;
	cout << "the start position: " << endl;
	string city_name_string = "CITY.txt";
	DB._PRINT_LIST_OF_CITIES_(city_name_string);
	string start;
	string end;
	getline(cin, start);
	DB.start = start;
	cout << "All Cities" << endl;
	DB._PRINT_LIST_OF_CITIES_(city_name_string);
	cout << "the end position: " << std::endl;
	getline(cin, end);
	DB.end = end;
	int start_city = 0;
	int end_city = 0;
	
	
	string filename = "input.txt";
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
