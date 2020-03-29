/**
 * Author: Sergio Hernandez Castillo - A01025210
 * Date: 28/03/2020
 * Description: C++ implementation of the solution to the plumber problem
*/

#include <iostream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

/**
 * This struct represents a client's satisfaction,
 *      how much time their task or fix needs to be
 *      completed, and how much time they had to 
 *      wait for it to be done.
*/
struct Client{
    double satisfaction;
    int time;
    int waitingTime;
};//Close Client

/**
 * Fills the respective times of all the clients with a random number. 
 *      As in it initializes each task time with a random number.
 * 
 * @param[in] *c the pointer that points to the array of type Client,
 *      as in the array of clients
 * @param[in] clients the total amount of clients to be considered
*/
void fillTimes(Client *c, const int clients){
    /**
     * This "srand" seed makes sure that everytime a set of random 
     * numbers is generated its different than the last.
    */
    srand(time(0));

    for (int i = 0; i < clients; i++){
        // It assigns a random number between 5 and 60.
        c[i].time = rand() % 60 + 5;
    }//Close for
}//Close fillTimes

/**
 * Compares two clients' times at a time.
 * 
 * @param[in] c, d a client of type Client
 * 
 * @returns the "true" or "false" after comparing
 *      the two times 
*/
bool compare(Client c, Client d){
    if (c.time != d.time){
        return (c.time < d.time);
    }//Close if 
}//Close compare

/**
 * Calculates the waiting time for each client, their satisfactions,
 *      the average satisfaction percentage, prints the information of 
 *      every client, and prints the average satisfaction percentage.
 * 
 * @param[in] *c the pointer that points to the array of type Client,
 *      as in the array of clients
 * @param[in] clients the total amount of clients to be considered 
*/
void plumber(Client *c, const int clients){
    // A simple counter
    int i = 0;

    /**
     * The variable that saves the sum of times per client and tells 
     * how much time a client has to wait.
    */
    int timeSum = 0;

    // Saves up the sum of all the client satisfactions 
    double totalSatisfaction = 0;

    for (i = 0; i < clients; i++){
        /**
         * If its the first client we're analyzing, set the waiting 
         * time equal to the task time and make the sum of current 
         * time equal to the waiting time.
        */
        if (i == 0){
            c[i].waitingTime = c[i].time;
            timeSum = c[i].waitingTime;
        }//Close if

        /**
         * If we've already dealt with the first client, then also 
         * set the waiting time equal to the task time, add up the 
         * sum of current time the plumber has already taken, and 
         * make the sum of current time equal to the waiting time.
        */
        else {
            c[i].waitingTime = c[i].time;
            c[i].waitingTime += timeSum;
            timeSum = c[i].waitingTime;
        }//Close else

        /**
         * The client satisfaction will be determined depending on
         * the range of time to which it belongs (Between 5 and 15
         * minutes, between 16 and 25 minutes, and so on and so 
         * forth).
        */
        if ((c[i].waitingTime >= 5) && (c[i].waitingTime <= 15)){
            c[i].satisfaction = 100;
        }//Close if 

        else if ((c[i].waitingTime >= 16) && (c[i].waitingTime <= 25)){
            c[i].satisfaction = 90;
        }//Close else if

        else if ((c[i].waitingTime >= 26) && (c[i].waitingTime <= 35)){
            c[i].satisfaction = 70;
        }//Close else if

        else if ((c[i].waitingTime >= 36) && (c[i].waitingTime <= 45)){
            c[i].satisfaction = 50;
        }//Close else if

        else if ((c[i].waitingTime >= 46) && (c[i].waitingTime <= 60)){
            c[i].satisfaction = 30;
        }//Close else if

        else if (c[i].waitingTime > 60){
            c[i].satisfaction = 10;
        }//Close else if

        // Add up the total satisfaction 
        totalSatisfaction += c[i].satisfaction;
    }//Close for

    for (i = 0; i < clients; i++){
        cout << "\nThe time that task " << i + 1 << " needed was: " << c[i].time << " minutes" << endl;
        cout << "The client's waiting time was: " << c[i].waitingTime << " minutes" << endl; 
        cout << "The client's satisfaction percentage was: " << c[i].satisfaction << "%" << endl;
    }//Close for 

    cout << "\nThe average satisfaction percentage was: " << (totalSatisfaction / clients) << "%" << endl;
}//Close plumber

/**
 * Calculates the total time that all tasks will take, prints how 
 * many clients will be considered, the total time, the solution 
 * to the problem with the original order of the clients (before
 * calling "plumber"), and the solution to the problem with the 
 * tasks ordered from smallest to biggest depending on the time 
 * of each task (before actually sorting and calling "sort" and 
 * calling "plumber" again).
*/
int main(){
    /// The constant/total amount of clients to be considered
    const int clients = 4;

    // The array of type Client, as in the array of clients
    struct Client c[clients];

    // A simple counter
    int i = 0;

    // The variable that will hold the total time
    int totalTime = 0;

    fillTimes(c, clients);

    for (i = 0; i < clients; i++){
        totalTime += c[i].time;
    }//Close for 

    cout << "There are " << clients << " clients to be considered." << endl;
    cout << "The total time that all tasks will take is: " << totalTime << " minutes" << endl;

    cout << "\nThe solution to the problem with the original order of the clients is as follows:" << endl;
    plumber(c, clients);

    cout << "\nThe solution to the problem with the tasks ordered from smallest to biggest depeding on the time ";
    cout << "is as follows:" << endl;
    sort(c, c + clients, compare);
    plumber(c, clients);

    return 0;
}//Close main 