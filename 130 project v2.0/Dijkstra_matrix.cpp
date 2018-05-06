#include "Dijkstra_matrix.h"
#include <iostream>
#include <sstream>
#include <fstream>
dijkstra::dijkstra()
{
	//I initiate the matrix all the plots as infinite
	for (int i = 0; i <= city_number; i++)
		for (int j = 0; j <= city_number; j++)
			distance_matrix[i][j] = 1000000;
	for (int i = 0; i <= city_number; i++)
	{
		track_distance[i] = INFINITE;
	}

}
void dijkstra::_LOAD_DATA_(string fileName)
{
	//based on the each city's distance to another city which read from file, 
	//I put the distance (undriect graph it means that distance_matrix[i][j] = distance_matrix[j][i])
	// to the distance_matrix (2d vector
	string line; 
	int city_start;
	int city_end;
	int weight;
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.fail())
	{
	 	cout << "Cannot find the file" << endl;
	}
	while(!inFile.eof())
	{
		getline(inFile, line);
		stringstream(line) >> city_start >> city_end >> weight;
		distance_matrix[city_start][city_end] = weight;
		distance_matrix[city_end][city_start] = weight;
		
	}
	//show the matrix to check whether it is correct
	/*for (int i = 0; i <= city_number; i++)
	{
		for (int j = 0; j <= city_number; j++)
			std::cout << distance_matrix[i][j];
		std::cout << std::endl;
	}*/
}

void dijkstra::_EXPLORE_MATRIX_(int start_vertex)
{
	bool isVisited[cities];
	//check the start vertex, and put the start vertex as visited
	for (int i = 1; i <= city_number; ++i)
	{
		track_distance[i] = distance_matrix[start_vertex][i];
		isVisited[i] = false;
		if (track_distance[i] == INFINITE)
			prev[i] = 0;
		else
			prev[i] = start_vertex;
	}
	track_distance[start_vertex] = 0;
	isVisited[start_vertex] = true;

	for (int i = 2; i < city_number; i++)
	{
		int temp_distance = INFINITE;
		int temp_next_small_vetrix = start_vertex;
		for (int j = 1; j <= city_number; j++)
		{
			if (!isVisited[j] && track_distance[j] < temp_distance)
			{
				temp_next_small_vetrix = j;
				temp_distance = track_distance[j];
			}
		}
		//find the next vetrix based on the weight
		isVisited[temp_next_small_vetrix] = 1;


		//update the track_distance, I mean, the distance form the sratr_vetrix to current element
		for (int j = 1; j <= city_number; ++j)
		{
			if (!isVisited[j] && distance_matrix[temp_next_small_vetrix][j] < INFINITE)
			{
				int NewDistance = track_distance[temp_next_small_vetrix] + distance_matrix[temp_next_small_vetrix][j];
				if (NewDistance < track_distance[j])
				{
					track_distance[j] = NewDistance;
					prev[j] = temp_next_small_vetrix;
				}
			}
		}
	}
}

void dijkstra::_PRINT_PATH_(int start_vertex, int end_vertex)
{
	int element_in_path = 1;
	path_list[element_in_path] = end_vertex;
	element_in_path++;
	/*for (int i = 1; i <= 5; i++)
	{
		std::cout << prev[i];
	}*/
	int temp = prev[end_vertex];
	while (temp != start_vertex)
	{
		path_list[element_in_path] = temp;
		element_in_path++;
		temp = prev[temp];
	}
	// put the start vertex as the first print position
	path_list[element_in_path] = start_vertex;

	
	for (int i = element_in_path; i >= 1; --i)
	{

		if (i != 1)
			std::cout << city_name_stream[path_list[i]] << " -> ";
		else
			std::cout << city_name_stream[path_list[i]] << std::endl;
	}

}
void dijkstra::_LOAD_CITY_STRING_(string cityFileName)
{
	ifstream in;
	in.open(cityFileName);
	string str;
	string city;
	city_name_stream.push_back("dummy");
	if (in.fail())
	{
		cout << "Cannot find the file" << endl;
	}
	while(!in.eof())
	{
		getline(in, str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				city = city + str[i];
			}
			else if(str[i] >= 'a' && str[i] <= 'z')
			{
				city = city + str[i];
			}
			else if(str[i] == ' ')
			{
				city = city + ' ';
			}
		}
		city_name_stream.push_back(city);
		city = "";
	}

}
void dijkstra::_PRINT_LIST_OF_CITIES_(string cityFileName)
{
	ifstream in;
	in.open(cityFileName);
	string str;
	string city;
	if (in.fail())
	{
		cout << "Cannot find the file" << endl;
	}
	while(!in.eof())
	{
		getline(in, str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				city = city + str[i];
			}
			else if(str[i] >= 'a' && str[i] <= 'z')
			{
				city = city + str[i];
			}
			else if(str[i] == ' ')
			{
				city = city + ' ';
			}
		}
		city = city + ", ";
	}
	cout << city << endl;
}
void dijkstra::_SHOW_COST_()
{
	// car 20 cents a mile, 45 miles/h
	// bus 15 cents a mile, 30 miles/h
	double car_cost_money = track_distance[end_city] * 0.2;
	double car_cost_time = track_distance[end_city] / 45 * 60.00;

	double bus_cost_money = track_distance[end_city] * 0.15;
	double bus_cost_time = track_distance[end_city] / 30 * 60.00;
	cout << "The total length is: " << track_distance[end_city] << std::endl;
	cout << "Car use: \n" << "Financial Cost: $" << car_cost_money << " Time: " << car_cost_time << endl;
	cout << "Bus use: \n" << "Financial Cost: $" << bus_cost_money << " Time: " << bus_cost_time << endl;
}
