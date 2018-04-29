#pragma once
#ifndef  DIJKSTRA_H
#define DIJKSTRA_H
#include <string>
#include <vector>
#define INFINITE 999999
#define LINE_NUMBER 7
#define CITY_NUMBER 5
class dijkstra
{
public:
	dijkstra();
	void _LOAD_DATA_(char *filename);
	void _EXPLORE_MATRIX(int start_vertex);
	void _PRINT_PATH(int start_vertex);
	void _SHOW_COST_();
private:

	std::vector<std::vector <double>> distance_matrix;
	std::vector<double> track_distance;
	std::vector<double> prev;
	int line_number = LINE_NUMBER;
	int city_number = CITY_NUMBER;
	std::vector<bool> isVisited;
	std::vector<double> path_list;
};
#endif // ! DIJKSTRA_H
