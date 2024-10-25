#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>



int main()
{
    int choice, i;
    bool running = true;
    
    while(running)
    {
        
        printf("1. Add Complaint\n2. Resolve Complaint\n3.Display Complaints\n4. Show Resolved Complaints\n5. Exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                // Addcomplaint       
            }
            case 2:
            {
                // ResolveComplaint
            }
            case 3:
            {
                // DisplayComplaint
            }
            case 4:
            {
                //DisplayResolvedComplaints
            }
            case 5:
            {   
                printf("Exiting...");
                running = false;
                return;
            }
            default:
            {
                printf("ERROR! Please Enter proper input.");
            }

        }
    }

}