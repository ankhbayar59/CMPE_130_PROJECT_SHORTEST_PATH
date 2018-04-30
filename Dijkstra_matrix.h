#pragma once
#pragma once
#ifndef  DIJKSTRA_H
#define DIJKSTRA_H
#include <string>
#include <vector>
const int INFINITE = 999999;
const int LINE_NUMBER = 7;
const int cities = 200;
class dijkstra
{
public:
	dijkstra();
	void _LOAD_DATA_(char *filename);
	void _LOAD_CITY_STRING_(std::string filename);
	void _EXPLORE_MATRIX(int start_vertex);
	void _PRINT_PATH(int start_vertex);
	void _SHOW_COST_();

	int distance_matrix[cities][cities];
	double track_distance[cities];
	int prev[cities];
	int line_number = LINE_NUMBER;
	int city_number;
	int path_list[cities];
	std::vector<std::string> city_name_stream;
};
#endif // ! DIJKSTRA_H