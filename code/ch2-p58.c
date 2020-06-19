//The following code is for receiving and sending messages with the help of semaphore:
// buffer slots
#define Number 200
// procedure to send message
void sender(void)
{
// declare variable of int data type
int data;
// declare a buffer for the messages
message msg;
// loop to send messages
while (TRUE)
{
// waiting message using semaphore
Wait(semaphore)
{
// produce the message data
data = produce_data( );
// wait for empty buffer
receive(receiver, &msg);
// build message to send
build_msg(&msg, data);
} } }



//The given procedure is used to receive the message from the sender. The received message is
//extracted and empty buffer is send back to the semaphore.
// procedure to receive message
void receiver(void)
{
// declare variable of int data type
int data, loop;
// declare a buffer for the messages
message msg;
// loop to set empty buffer to all the semaphores
for (loop = 0; loop < Number; loop++)
send(sender, &msg);
// loop to receive messages
while (TRUE)
{
// Signaling the message using semaphore
signal(semaphore)
{
// retrieve the message from the sender
receive(sender, &msg);
// extract the data of the message
data = extract_data(&msg);
// send empty buffer back
send(sender, &msg);
} } }
