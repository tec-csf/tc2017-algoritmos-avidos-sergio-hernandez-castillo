/**
 * Author: Sergio Hernandez Castillo - A01025210
 * Date: 27/03/2020
 * Description: C++ implementation of the solution to the backpack problem.
*/

#include <iostream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

/**
 * This struct represents an element's weight and value.
*/
struct Element{
    int weight;
    int value;
};//Close Element

/**
 * Fills the array of struct elements with random numbers. As in it 
 *      initializes the weight and value of an element with a random
 *      number.
 * 
 * @param[in] *e the pointer that points to the array of type Element,
 *      as in the array of elements
 * @param[in] elements the total amount of elements to be analyzed
 * @param[in] maxWeight the maximum weight that the backpack can hold
*/
void fillArray(Element *e, const int elements, const int maxWeight){
    /**
     * This "srand" seed makes sure that everytime a set of random 
     * numbers is generated its different than the last.
    */
    srand(time(0));

    for (int i = 0; i < elements; i++){
        /**
         * It assigns a random number between 1 and the maximum weight 
         * that the backpack can hold.
        */
        e[i].weight = rand() % maxWeight + 1;

        // It assigns a random number between 1 and 100.
        e[i].value = rand() % 100 + 1;
    }//Close for
}//Close fillArray

/**
 * Compares two elements' values at a time.
 * 
 * @param[in] e, f an element of type Element
 * 
 * @returns the "true" or "false" after comparing
 *      the two values
*/
bool compareByValue(Element e, Element f){
    if (e.value != f.value){
        return (e.value > f.value);
    }//Close if 
}//Close compareTwoElements

/**
 * Compares two elements' weights at a time.
 * 
 * @param[in] e, f an element of type Element
 * 
 * @returns the "true" or "false" after comparing
 *      the two weights
*/
bool compareByWeight(Element e, Element f){
    if (e.weight != f.weight){
        return (e.weight < f.weight);
    }//Close if 
}//Close compareTwoElements

/**
 * Prints important information for the user to know (total 
 *      elements to be analyzed, maximum weight of the backpack
 *      total value of the elements, the weight/value of each
 *      element) and calculates which element gets to go inside
 *      the backpack. Then it prints which elements were added to
 *      the backpack, its total weight, and the solution value 
 *      percentage.
 * 
 * @param[in] *e the pointer that points to the array of type Element,
 *      as in the array of elements
 * @param[in] elements the total amount of elements to be analyzed
 * @param[in] maxWeight the maximum weight that the backpack can hold
*/
void backpack(Element *e, const int elements, const int maxWeight){
    /**
     * An array the size of the total elements to be analyzed. It 
     * saves a 1 or 0 in each slot.
    */
    int sol[elements];

    // The current weight/value while the problem is being solved.
    int currentWeight = 0;
    double currentValue = 0;

    // The total value of all the elements.
    double totalValue = 0;

    // A simple counter.
    int i;

    // Sums up the total value 
    for (i = 0; i < elements; i++){
        totalValue += e[i].value;
    }//Close for 

    cout << "\nThere are " << elements << " elements to be considered." << endl;
    cout << "The maximum weight of the backpack is " << maxWeight << "." << endl;
    cout << "The total value of the elements is: " << totalValue << "\n" << endl;

    for (i = 0; i < elements; i++){
        cout << "The weight of element " << i + 1 << " is: " << e[i].weight << endl;
        cout << "The value of element " << i + 1 << " is: " << e[i].value << "\n" << endl;
    }//Close for

    i = 0;

    /**
     * While there are elements to be analyzed and the current weight of the backpack 
     * hasn't reached maximum weight...
    */
    while ((i < elements) && (currentWeight < maxWeight)){
        /**
         * If the element plus the current weight weighs less than the maximum weight, 
         * add it to the backpack (make the same index in "sol" equal to a 1).
        */
        if ((e[i].weight + currentWeight) <= maxWeight){
            sol[i] = 1;
        }//Close if 

        /**
         * If the element was too much weight for the backpack, discard it (make the 
         * same index in "sol" equal to 0).
        */
        else {
            sol[i] = 0;
        }//Close else

        // Adds up the current weight and value. Also increments the counter.
        currentWeight += (e[i].weight * sol[i]);
        currentValue += (e[i].value * sol[i]);
        i++;
    }//Close while

    // Prints which elements have been added, depending on the 1 or 0 from "sol".
    for (i = 0; i < elements; i++){
        if (sol[i] == 1){
            cout << "Element " << i + 1 << " was added to the backpack." << endl;
        }//Close if
    }//Close for

    cout << "\nThe total weight of the backpack is " << currentWeight << "." << endl;
    cout << "Solution value percentage: " << (currentValue / totalValue) * 100 << "%" << endl;
}//Close backpack

/**
 * Calls "fillArray", asks wether the program should solve the problem 
 *      while prioritizing weight or value, calls "sort" (depending 
 *      on the user's selection), and calls "backpack".
*/
int main(){
    /// The constant/total amount of elements to be analyzed.
    const int elements = 5;

    /// The constant/maximum weight that the backpack can hold.
    const int maxWeight = 50;

    /**
     * Creates an array of structs of type Element the size of all 
     * elements to be analyzed. As in an array of elements.
    */
    struct Element e[elements];

    // An answer that hasn't been initialized yet.
    string answer;

    /**
     * A boolean variable that will help decide if the program 
     * should ask the user again for an answer regarding the 
     * weight or value question.
    */
    bool keepAsking = true;

    fillArray(e, elements, maxWeight);

    cout << "Do you wish to solve this problem prioritizing the weight or value of an element?" << endl;
    cout << "Enter 'w' for weight or 'v' for value: " << endl;

    // This loop will repeat until the answer is "w" or "v".
    while (keepAsking == true){
        cin >> answer;

        if ((answer == "w") || (answer == "v")){
            keepAsking = false;
        }//Close if 

        else {
            cout << "\nPlease enter a 'w' or 'v':" << endl;
        }//Close else 
    }//Close while 

    /**
     * If the user prefers to prioritize weight, then the 
     * array of elements will be sorted in terms of the weights
     * (smallest to greatest).
    */
    if (answer == "w"){
        sort(e, e + elements, compareByWeight);
    }//Close if 

    /**
     * If the user prefers to prioritize value, then the 
     * array of elements will be sorted in terms of the values
     * (greatest to smallest).
    */
    else if (answer == "v"){
        sort(e, e + elements, compareByValue);
    }//Close else if 

    backpack(e, elements, maxWeight);

    return 0;
}//Close main 