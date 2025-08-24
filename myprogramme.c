// write a program to create ,read ,write and append data to a file.
#include<stdio.h>
#include<stdlib.h> // using this for exit()
int main()
{
    FILE *fptr;
    char data[100];

    //1.creating and writing to a file (mode"w")
    //here iam using file "example.txt" because to enter the text if "example.txt" doesn't exist,it will be created.
    //If it exists,its content will be (erased).
    fptr = fopen("example.txt","w");
    if(fptr == NULL)
    { 
        printf("Error opening file for writing!\n");
        exit(1);
    }
    printf("Enter data to write to the file:");
  fgets(data,sizeof(data),stdin);//read input from user 
  fprintf(fptr,"%s",data);
 fclose(fptr);
 printf("Data written successfully.\n\n");
  
  //2.Readding from a file (mode"r")
   fptr = fopen("example.txt","r");
  if(fptr == NULL)
  {
  printf("Error opening file for reading !\n");
  exit(1);
  }
    printf("reading data :\n");

  while(fgets(data,sizeof(data),fptr)!= NULL)
  {
    printf("%s",data);
  }
  fclose(fptr);
  printf("\nData read successfully.\n\n");
  
   //3. appending data to a file (mode"a")
  //New data will be added to the end of existing content.
  fptr = fopen("example.txt","a");
  if(fptr == NULL)
  {
  printf("Error opening file for appending !\n");
  exit(1);
 }
  printf("Enter data to append to file :");
 fgets(data,sizeof(data),stdin);
  fclose(fptr);
 printf("data appended  Sucessfully.\n\n");
 
//4.Reading the updated file to verify append operation.
 fptr = fopen("example.txt","r");
 if(fptr == NULL)
 {
  printf("Error opening file for reading after append !\n");
  exit(1);
 }
 printf("Reading updated data from example.txt:\n");
 while (fgets(data,sizeof (data),fptr)!= NULL)
 {
 printf("%s",data);
 }
 fclose(fptr);
  printf("\nUpdated data read  Sucessfully.\n");
  return 0;
}
