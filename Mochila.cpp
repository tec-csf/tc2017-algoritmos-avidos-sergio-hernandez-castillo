/**
 * 1. Declare the maximum weight of the backpack.
 * 2. Create a Element struct containing the weight and value of an element.
 * 3. Create an array of elements.
 * 4. Fill the array of elements with random numbers for the weights (from 1 to the maximum weight of 
 *    the backpack) and the values (from 1 to 100).
 * 5. Sort the array of elements, depending on their weights and values.
 * 6. Open a loop. While there are elements to be analyzed and the current weight of the backpack hasn't reached
 *    maximum weight:
 *    a. Check if the element can be added to the backpack. If the element weighs less than the maximum 
 *       weight, add it to the backpack
 *    b. If the element is too much weight for the backpack, discard it.
 *    c. If an element was added, add its weight to the current weight of the backpack
 * 7. Print out which elements were added to the backpack and their total weight/value
*/

#include <iostream>
#include <time.h>

using namespace std;

struct Element{
    int weight;
    int value;
};//Close Element

void fillArray(Element *e, int elements, int maxWeight){
    srand(time(0));

    for (int i = 0; i < elements; i++){
        e[i].weight = rand() % maxWeight + 1;
        e[i].value = rand() % 100 + 1;
    }//Close for
}//Close fillArray

int main(){
    const int elements = 10;
    int maxWeight = 50;
    struct Element e[elements];

    fillArray(e, elements, maxWeight);

    for (int i = 0; i < elements; i++){
        cout << "The weight of element " << i + 1 << " is: " << e[i].weight << endl;
        cout << "The value of element " << i + 1 << " is: " << e[i].value << endl;
        //cout << "\n" << endl;
    }//Close for 
}//Close main 