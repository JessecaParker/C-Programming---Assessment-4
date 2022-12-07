/* Jesseca Wirtz - IT-FP2240 - Part 1
 * 5/14/20
 */

 #include <stdio.h>
 #include <stdlib.h>

 main()
 {
     //declare the variables
     int i = 0;
     int j = 0;
     char ans;
     //using heap memory for the grades instead of an array
     int * grades = (int *) malloc(25 * sizeof(int));

     for (i = 0; i < 25; i++)
     {
         printf("\nEnter next grade: ");
         scanf(" %d", &grades[i]);

         printf("\nEnter another grade (Y/N)?");
         scanf(" %c", &ans);

         if (ans == 'n' || ans == 'N')
         {
             break;
         }
     }


     //output the grades
     printf("You have entered %d grades.", i + 1);
     printf("\nThe grades you have entered are: \n");

     for (j = 0; j <= i; j++)
     {
         printf("\nGrade %d is %d.", j + 1, grades[j]);
     }

     //releases the heap memory used for this program back to the
     //heap pile
     free(grades);

     return 0;
 }
