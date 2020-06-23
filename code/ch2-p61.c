/*For multiple processes, assume an array turn which keeps a record of the process which can
enter critical section. If its element value is false, the process cannot enter the critical sections, if
it is true, it can enter and execute. The idea is to let each process enter the critical section one at
a time. Once all processes have executed the critical section, the counter starts from the first
process again and so on. The modified code for multiple processes (say n) is given below:
The flag allFinished is used to signify the end of array. Thus it should be reset to the first element
when this flag goes true. */;

i=0;
allFinished = false;
while (TRUE)
{
if(allFinished = true)
{
i = 0;
turn[i] = true;}
/* A process should wait until its turn is true.*/;
while (turn[i] !=true && allFinished!=true) 
critical_ region();
turn[i]=false;
i++;
//If end of array is encountered, set flag allFinished to true.
if(i==n-1)
{
allFinished = true;
}
//Otherwise let the next process execute critical section.
else
{
turn [i]= true ;
}
noncritical_ region();
}
