#include
#include
#include
#include
#include
#include
#define MAXIMUM_ARGUMENTS10
#define MAXIMUM_LENGTH 100
Define the function prototype
//Function pototype
void child(int argument, char *argumentV[MAXIMUM_ARGUMENTS]);
//Main function
int main()
{
//Declare the varaibles declaration
int argument, n = 0, status;
char input_line[MAXIMUM_LENGTH],
*argumentV[MAXIMUM_ARGUMENTS], *cp;
const char *delimiter = " \t\n";
The loop is executed till true is set. The input is taken from the user and stop when key
combination Ctrl+d is pressed by the user.
//Repeat the loop until the condition is true
while (1)
{
Prompting the user to enter an input values from the keyboard
//Read the input line
printf("sh-> ");
//condition to read the line
if (fgets(input_line, sizeof(input_line),
stdin) == NULL)
{
printf("Thanks!\n");
// exit from read mode
exit(0);
}//End if
//Assing thr input value to cp
cp = input_line;
// loop to split the tabs and blank spaces
for(argument = 0; argument <
MAXIMUM_ARGUMENTS; argument++)
{
// condition to break
if ((argumentV[argument] = strtok(cp,
delimiter)) == NULL)
break;
// set the pointer to NULL
cp = NULL;
}//End for loop
Condition to stop shell when specific word is entered by the user
//Check the condition
if(strcmp(argumentV[0], "Stop") == 0)
{
// display output
printf("Thanks!\n");
// exit from the shell
exit(0);
}//End if
//set the fork to the process id
pid_t process_id = fork();
// condition to check failure of fork
if(process_id == -1)
{
// display error message
perror("fork is failed ");
// exit from the shell
exit(1);
}//End if
else if(process_id == 0)
{
//execute the child process
child(argument, argumentV);
}//End else if
else
{
//Call the wait system call
wait(&status);
}//End else
}//End while
}//End main
Define the function for child process
//Function defintion
void child(int argument, char *argumentV[MAXIMUM_ARGUMENTS])
{
execvp(argumentV[0], argumentV);
}//End function
