#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;

//This is class for the circular buffer
template <class T>
class CircularBuffer
{
private:
    size_t _size;
	unsigned current;
	unsigned currentMark;
	T *entry;
	int items;
	int temp;

public:
  CircularBuffer(size_t size, T v): _size(size)
	{
		entry = new T[_size(size)];
		reset(v);
	}
	~CircularBuffer()
	{
    delete [] entry;
	}

	inline void reset(T v)
	{
    fill(entry, entry + _size, v);
    current = 0;
    currentMark = 0;
	items = 0;
	temp = -1;
	}

	inline T & get(int position) const
	{
    int myIndex = current - position;
    if ( myIndex < 0 )
		myIndex += _size;
    return entry[myIndex] ;
	}
	inline T & getWhole()
	{
		//cout << current << " is current" << endl;
		int index = current - temp;
		if (index < 0){
			index += _size;}
		temp--;
		return entry[index];
	}

	inline void putArray(double *arr, int len)
	{
    if (current + len >= size) {
    	int first_slice = size - current - 1;
    	memcpy((char *)(entry + current + 1), (char *)arr, sizeof(double)*(first_slice));
    	memcpy((char *)(entry), (char *)(arr + first_slice), sizeof(double)*(len - first_slice));
    }
    else {
    	memcpy((char *)(entry + current + 1), (char *)arr, sizeof(double)*len);
    }
    current = (current + len) % size;
	}

	inline T & getFromMark(int position) const
	{
	int myIndex = currentMark - position;
	if (myIndex < 0 ) myIndex += size;
	return entry [myIndex];
	}

	inline void moveMark(int steps)
	{
	currentMark += steps;
	if (currentMark > size-1)
		currentMark -= size;
	}
    //Implements the circularity
	inline void put(const T &elem)
	{
    if (current < _size-1)
        current++;
    else
        current=0;

    entry[current] = elem;
	items++;
	temp++;
	}
	int SlotsAvailable(){
		return (29 - items);
	}
	int numitems(){
		return items;
	}
};

int ARRAY_SIZE = 30;
int interested[2] = {0, 0};
int turn;
ifstream inputFile;
ofstream outputFile;
CircularBuffer<int> Buffer(ARRAY_SIZE, 0);

//PRODUCER THREAD
DWORD WINAPI Producer(LPVOID Param)
{
	int count = 0;
	int integer = *(int*)Param;
	int other;
	interested[0] = 1;
	int numb[1];
	int c = 0;

	turn = 1;
	while(interested[1] == 1 && turn == 1)
		;//donothing
	while (count < integer && inputFile >> numb[0]){
		c = numb[0];
		Buffer.put(c);
		count++;
	}
	cout << endl;
	cout << "There are " << Buffer.numitems() << " element(s) in the Buffer" << endl;
	cout << endl;

	interested[0] = 0;
	return 0;
}
//CONSUMER THREAD
DWORD WINAPI Consumer(LPVOID Param)
{
	int integer2 = *(int*)Param;
	int other;
	int count = 0;

	interested[1] = 1;
	turn = 0;
	while(Buffer.numitems() == 0)
		;//donothing

	while(interested[0] == 1 && turn == 0)
		;//donothing
	int count_variable = Buffer.numitems() - 1;
	cout << "The Current Contents Of The Output File: " << endl;
	for(int index = count_variable; index >= 0; index--){
		cout << Buffer.get(index) << " ";
	}
	cout << endl;
	cout << endl;

	outputFile.open("Output.txt");
	for(count = count_variable; count >= 0; count--){
		outputFile << Buffer.get(count) << endl;
	}
	outputFile.close();

	interested[1] = 0;

	return 0;
}
//MAIN METHOD
int main()
{
	DWORD ThreadId;
	HANDLE ThreadHandle, ThreadConsumer;
	unsigned seed = time(0);
	//Seed The Random Number Generator
	srand(seed);
	int bound;
	int random_number;
	inputFile.open("numbers.txt");

	while(!inputFile.eof())
	{
		cout << "Specify An Upper Bound For The Number Of Bytes To Be Copied: " << endl;
		cin >> bound;
		//Come up with a random number between 1 and bound
		random_number = 1 + rand() % bound;
		cout << endl;
		cout << "N = " << random_number << endl;
		cout << endl;

		if(Buffer.SlotsAvailable() < random_number){
		cout << "Not Enough Empty Slots: Overwrite May Occur" << endl;
		cout << endl;
		continue;
		}

		//Create The Threads
		ThreadHandle = CreateThread(NULL, 0, Producer, &random_number, 0, &ThreadId);
		ThreadConsumer = CreateThread(NULL, 0, Consumer, &random_number, 0, &ThreadId);


		WaitForSingleObject(ThreadHandle,INFINITE);
		WaitForSingleObject(ThreadConsumer, INFINITE);
	}//endwhile
	cout << endl;
	cout << "The Input file has been copied entirely" << endl;
	cout << endl;
	inputFile.close();
}
