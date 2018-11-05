#include<stdio.h>
void main()
{
printf("\n IN SOURCE\n\n");
char msg[50]="how are you?";
printf("\n\nApplication layer\nmessage is :%s\nProtocol used is Hyper Text Transfer Protocol HTTP ",msg);
printf("\n\nPresentation layer\nmessage is encoded,encrypted and compresses into ASCII format\n");
printf("\n\nSessions layer:\nSession is created and session is is 123 and ensures synchronisation between source and destination\n");
printf("\n\nTransport layer\nTransmission control protocol is used for multiplexing and port number is 80\nmessage is segmented into 3 segments \n 0   1    2\nhow  are  you?\n");
printf("message is sent in the sequence 'how' are' 'you?' \n");
printf("Flow control: 1 segment at a time\n");
printf("\n\nNetwork layer:segments are given IP addresses of source as 192.168.1.1 and destination as 192.168.1.2  and are sent to the destination using IP protocol ans router routes the segments via the shortest route available\n");
printf("\n\nData link layer:\n The packets are further broken down into frames.Flow and error control is done.LLC uses WAN protocol PPP to transport the frames and MAC address of source is 00-20-18-C0-07-71 and destination is 00-20-18-C0-07-72\n");
printf("\n\nPhysical layer :\nFrames are converted to binary 0 and 1 and are transported in coaxial cable as signal.Transmission mode is duplex \n");

printf("\n IN DESTINATION\n\n");
printf("\n\nPhysical layer :\n Signal is recceived and converted to binary 0's and 1's\n");
printf("\nData link layer:\n Bits are reconverted to frames on destination whose MAC address is 00-20-18-C0-07-72\n");

printf("\n\nNetwork layer:frames from data link layer are assembled to packets on destination machine whose IP address is  192.168.1.2 using IP protocol\n");
printf("\n\nTransport layer:The packets are assembled to form 3 segments 'are' 'you?' 'how' and it is ordered to form correct message.The message is received in port number 125");
printf("\n\nSessions layer:\nSynchronized session  whose number is  123 ,is destroyed at destination\n");
printf("\n\nPresentation layer\nmessage is decoded,decrypted and decompressed from ASCII format to machine understandable code\n");
printf("\n\nApplication layer\nmessage is :%s\nHTTP protocol ensures the received message is given to the corresponding application.",msg);
}
