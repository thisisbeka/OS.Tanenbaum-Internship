// include library
#include
#include
// main function of the program
int main()
{
// declare a variable to set the process id
pid_t process_id;
// display output
printf("New process id=%d\n", process_id =getpid());
// execute a while loop till the condition is satisfied
while(1)
{
// display the id of process
printf( "forking \t process id=%d\n", process_id);
