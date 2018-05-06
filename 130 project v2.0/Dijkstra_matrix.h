#pragma once
#pragma once
#ifndef  DIJKSTRA_H
#define DIJKSTRA_H
#include <string>
#include <vector>
const int INFINITE = 999999;
const int cities = 200;
using namespace std;
class dijkstra
{
public:
	dijkstra();
	void _LOAD_DATA_(string fileName);
	void _LOAD_CITY_STRING_(string cityFileName);
	void _EXPLORE_MATRIX_(int start_vertex);
	void _PRINT_PATH_(int start_vertex, int end_vertex);
	void _PRINT_LIST_OF_CITIES_ (string cityFileName);
	void _SHOW_COST_();

	int distance_matrix[cities][cities];
	double track_distance[cities];
	int prev[cities];
	int line_number;
	int city_number = 15;
	int path_list[cities];
	vector<string> city_name_stream;
	int end_city;
	string start;
	string end;
};
#endif // ! DIJKSTRA_H
