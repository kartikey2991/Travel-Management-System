// Shree Ganeshaye Namah
// Coded by Kartikey Gupta & Silkie Agarwal

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>

#define infinity 999999999

using namespace std;

struct store
{
    long long int cost[20];
    int array[20];
} travel[15];

struct initialdata
{
    long long int cost[20];
} ini[15];

class datamodule
{
public:
    string city[15];

    // datamodule() constructor is used to intialize values of cities...
    datamodule() : city{"Delhi", "Mumbai", "Chennai", "Kolkata", "Kerala", "Hyderabad", "Pune", "Goa", "Bangalore", "Amritsar", "Jaipur", "Patna", "Puducherry", "Srinagar", "Bhopal"} {}

    void costdeclaration()
    {
        int N, i, j;
        N = 15;

        // 15 different major citites are considered
        // The cost of travelling between any two cities in direct flights is initialized. In further steps the minimum fare will be calculated
        long long int arr[15][15] = {{0, 3500, 2000, infinity, 1000, infinity, infinity, infinity, infinity, 7000, 4000, 1500, infinity, 6500, infinity},
                                     {3500, 0, infinity, 1520, infinity, infinity, infinity, 2500, infinity, infinity, infinity, infinity, infinity, infinity, 5000},
                                     {2000, infinity, 0, 1500, infinity, 3000, infinity, infinity, infinity, infinity, 2000, 1000, infinity, infinity, 1500},
                                     {infinity, 1520, 1500, 0, infinity, 1200, 4500, infinity, 6000, infinity, infinity, infinity, infinity, infinity, 1000},
                                     {1000, infinity, infinity, infinity, 0, 1500, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity},
                                     {infinity, infinity, 3000, 1200, 1500, 0, 1950, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity},
                                     {infinity, infinity, infinity, 4500, infinity, 1950, 0, infinity, infinity, 2050, infinity, infinity, infinity, infinity, infinity},
                                     {infinity, 2500, infinity, infinity, infinity, infinity, infinity, 0, 5000, infinity, infinity, infinity, infinity, infinity, infinity},
                                     {infinity, infinity, infinity, 6000, infinity, infinity, infinity, 5000, 0, 7000, infinity, infinity, infinity, infinity, infinity},
                                     {7000, infinity, infinity, infinity, infinity, infinity, 2050, infinity, 7000, 0, infinity, infinity, infinity, infinity, infinity},
                                     {4000, infinity, 2000, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity, infinity, infinity},
                                     {1500, infinity, 1000, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity, infinity},
                                     {infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity},
                                     {6500, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity},
                                     {infinity, 5000, 1500, 1000, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0}};

        // in the above step we have declared the cost of travel from one city to another
        // the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
        // minimum possible fare between any origin and destination

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                travel[i].cost[j] = arr[i][j];
                travel[i].array[j] = j;
                ini[i].cost[j] = arr[i][j];
            }
        }
    }
};

class bellmanfordalgorithm : public datamodule
{
public:
    int N, i, j, k;
    bellmanfordalgorithm()
    {
        N = 15;
    }

    void algorithm_implementation()
    {
        // 3 diff loops executed

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                for (k = 0; k < N; k++)
                {
                    if (travel[i].cost[j] > travel[i].cost[k] + travel[k].cost[j])
                    {
                        // if low fair is found for the same origin and dest. , the minimum possible fare is changed
                        travel[i].cost[j] = travel[i].cost[k] + travel[k].cost[j];
                        travel[i].array[j] = k;
                    }
                }
            }
        }
    }
};
