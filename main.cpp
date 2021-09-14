/****************************************************************************************************************************
 * Programmer: Wahidullah Rahimi																			                *
 * Class: CptS 223; 																			                            *
 * Programming Assignment: Solution to Programming Assignment #1        									                *
 * Date:                09/09/2021																			                *
 *																											                *
 * “ADVANTAGES/DISADVANTAGES LINKED LIST:”.                                                                                 */
//One of the advantages of using linked for storing commandsand descriptions in this program is that a linked list data
//structure is a dynamic data structure, it does not have a fixed sizeand its size can shrink or grow in runtime.Since we
//load information from a file and we don’t know the size / length of data to be loaded to the list in advance, the player 
//may also add / remove commands during the runtime, so linked list is the most efficient data structure we used in this
//program.
//The disadvantage of linked list is that it take more memory in compare to an array data structure, because each
//element / node in a linked list need to store the address of its next node.Since random / direct element access is not 
//possible in a linked list the traversing to find an element was expensive whit higher time complexity.

//“ADVANTAGES/DISADVANTAGES ARRAY:”.
//The advantage of using array data structure to store profile in this program was that array occupies less memory in 
//compare with a linked list data structureand also data / element access is very easy in an array, because we can 
//randomly / directly access any element in an array using its index number.
//The disadvantage of using array is it is a fixed size data structure, we need to determine the array size in advancedand 
//its size can not be shrunk or grown in run time.Since we load the profiles information from a csv file, we don’t know the
//data size in advance, also new profiles may be added during the run time.If the data size is greater than the fixed array
//size it will not be possible to store the extra dataand if the information is less than the fixed array size there will 
//be memory wastage.


#include<iostream>
#include "WrapperClass.h"

int main()
{
    srand((unsigned)time(NULL)); /* seed random-number generator */
    WrapperClass w;
    w.runGame();



}