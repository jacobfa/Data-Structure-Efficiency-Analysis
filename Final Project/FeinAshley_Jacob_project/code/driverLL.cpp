#include "LinkedList.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <stdlib.h>
#include <fstream>
int main()
{
    LinkedList l = LinkedList();
    int testData[40000];
    float insert[400];
    float search[400];
    int count = 0;
    std::ifstream dataA("dataSetB.csv");
    std::string s = "";
    //insert all integers from dataSetA into the array of integers size 40000
    while (getline(dataA, s))
    {
        std::istringstream ss(s);
        while (ss)
        {
            std::string s;
            if (!getline(ss, s, ','))
                break;
            testData[count] = stoi(s);
            count++;
        }
    }
    dataA.close();
    using namespace std::chrono;
    auto start = steady_clock::now();
    int insertCount = 0;
    //measure the average time of insertion
    for (int i = 0; i < 40000; ++i)
    {

        if (i % 100 != 0 || i == 0)
        {
            l.insert(testData[i]);
        }
        else
        {
            l.insert(testData[i]);
            auto end = steady_clock::now();
            float ins = float(duration_cast<microseconds>(end - start).count());
            insert[insertCount] = ins / 100;
            insertCount++;
        }
    }
    //measure the average time for search functions

    //first need to initalize a randnums array with random numbers
    int randNumCount = 99;
    int randNums[40000];
    for (int j = 0; j < 40000; ++j)
    {
        if (j % 100 != 0 || j == 0)
        {
            randNums[j] = int(rand() % randNumCount);
        }
        else
        {
            randNumCount += 100;
            randNums[j] = int(rand() % randNumCount);
        }
    }
    //now we need to search for the numbers we created in the randNums array
    auto start1 = steady_clock::now();
    int searchCount = 0;
    //measure the average time of insertion
    for (int k = 0; k < 40000; ++k)
    {

        if (k % 100 != 0 || k == 0)
        {
            l.search(randNums[k]);
        }
        else
        {
            l.search(randNums[k]);
            auto end1 = steady_clock::now();
            float se = float(duration_cast<microseconds>(end1 - start1).count());
            search[searchCount] = se / 100;
            searchCount++;
        }
    }
    //now, time to insert the data from the search and insert arrays to csv files
    std::fstream fout;
    fout.open("insert_search_performance_linked_list_dataSetB.csv", std::ios::out | std::ios::app);
    for (int h = 0; h < 400; ++h)
    {
        if (h == 0)
            fout << "Insert Times\n";
        fout << (h + 1) << ".  " << insert[h] << "\n";
    }
    for (int g = 0; g < 400; ++g)
    {
        if (g == 0)
            fout << "Search Times\n";
        fout << (g + 1) << ". " << search[g] << "\n";
    }
}
