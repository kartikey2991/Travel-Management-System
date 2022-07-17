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