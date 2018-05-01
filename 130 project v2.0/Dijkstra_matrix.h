#pragma once
#pragma once
#ifndef  DIJKSTRA_H
#define DIJKSTRA_H
#include <string>
#include <vector>
const int INFINITE = 999999;
const int LINE_NUMBER = 17;
const int cities = 200;
class dijkstra
{
public:
	dijkstra();
	void _LOAD_DATA_(char *filename);
	void _LOAD_CITY_STRING_(std::string filename);
	void _EXPLORE_MATRIX_(int start_vertex);
	void _PRINT_PATH_(int start_vertex, int end_vertex);
	void _SHOW_COST_();

	int distance_matrix[cities][cities];
	double track_distance[cities];
	int prev[cities];
	int line_number = LINE_NUMBER;
	int city_number = 15;
	int path_list[cities];
	std::vector<std::string> city_name_stream;
	int end_city;
	std::string start;
	std:: string end;
};
#endif // ! DIJKSTRA_H