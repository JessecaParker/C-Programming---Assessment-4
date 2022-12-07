/* Jesseca Wirtz - IT-FP2240 - Part 2
 * 5/20/2020
 */

 //include the appropriate headers
#include <stdio.h>
#include <unistd.h>

//declare the prototype functions
int getGradeFromUser (int grades[]);
int sizeofArray (int grades[]);
void displaytheGrades (int grades[], int arraySize);
float findAve (int grades[], int arraySize);
int findMin (int grades[], int arraySize);
int findMax (int grades[], int arraySize);

main()
{
    //declare the array and the variables
    int grades[100];
    int min, max;
    float average;
    int arraySize = 0;

    //call the function to get the grades
    getGradeFromUser(grades);

    //calls the function to get the size of the array
    arraySize = sizeofArray(grades);

    //calls the function to print out the grades entered
    displaytheGrades(grades, arraySize);

    //calls the function to print out the average of the grades
    average = findAve(grades, arraySize);
    printf("\nThe average is %.1f%%.", average);

    //calls the function to print out the lowest grade
    min = findMin(grades, arraySize);
    printf("\nThe lowest grade is %d%%.", min);

    //calls the function to print out the highest grade
    max = findMax(grades, arraySize);
    printf("\nThe highest grade is %d%%.", max);

    return 0;
}
/****************************************************************************/
//function to get the grades
int getGradeFromUser (int grades[])
{
    int ctr;
    char ans;

    //Uses a for loop to loop through the prompts until the user
    //indicates they are finished entering grades
    for (ctr = 0; ctr < 100; ctr++)
    {
        printf("\nEnter next grade: ");
        scanf(" %d", &grades[ctr]);

        printf("Enter another grade (Y/N)? ");
        scanf(" %c", &ans);

        //if the user types n or N, the loop ends
        if (ans == 'n' || ans == 'N')
        {
            break;
        }
    }
    //returns grades to main
    return grades;
}
/***************************************************************************/
//custom function for finding the size of the array grades
int sizeofArray (int grades[])
{
    int arraySize;
    //gets the size of the array
    arraySize = (sizeof(grades) / sizeof(int)) + 1;

    //returns arraySize to main
    return arraySize;
}
/****************************************************************************/
//function for displaying the grades
void displaytheGrades (int grades[], int arraySize)
{
    int ctr;
    printf("\nThe grades entered are: ");
    //loops through the array
    for (ctr = 0; ctr < arraySize; ctr++)
    {
        //grades outputted
        printf("\n%d", grades[ctr]);
    }
}
/****************************************************************************/
//function to get the average of the grades
float findAve (int grades[], int arraySize)
{
    float average;
    int ctr;
    int sum = 0;

    //loops through the array to get the sum of the grades
    for (ctr = 0; ctr < arraySize; ctr++)
    {
        sum += grades[ctr];
    }

    //average is the sum divided by the total number of grades
    average = (float) sum / arraySize;

    //average is returned to main
    return average;
}
/***************************************************************************/
//function to find the minimum
int findMin (int grades[], int arraySize)
{
    int ctr;
    int min = grades[0];

    //loop through the array to find the min
    for (ctr = 0; ctr < arraySize; ctr++)
    {
        //if the current grade is less than the minimum
        //then the current grade gets set to minimum
        if (min > grades[ctr])
            min = grades[ctr];
    }
    //return min to main
    return min;
}
/***************************************************************************/
//function to find the maximum
int findMax (int grades[], int arraySize)
{
    int ctr;
    int max = grades[0];

    //loop through the array to find the max
    for (ctr = 0; ctr < arraySize; ctr++)
    {
        //if the current grade is greater than the max
        //then the current grade is set to max
        if (max < grades[ctr])
            max = grades[ctr];
    }
    //returns max to main
    return max;
}
