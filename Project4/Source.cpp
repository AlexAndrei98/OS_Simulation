

#include <fstream>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Variables.h"

using namespace std;


void getData() {
	
	int i = 0, newJob = 0, burstLength = 0;
	dataIN >> ws >> newJob;
	while (newJob > 0) { //Read in jobs until the last negative value is reached
		jList[i].number = newJob;
		dataIN >> jList[i].length;
		dataIN >> jList[i].interArrival;
		dataIN >> jList[i].IOBurstLength;
		dataIN >> burstLength; 
		int j = 0;
		while (burstLength > 0) {
			jList[i].CPUBurst[j] = burstLength;
			dataIN >> burstLength; 
			j++; //Increment the burst count
		}
		jList[i].IOburstCount = j; // Set the number of bursts to the number of loops

		i++; // Increment the job counter
		if (burstLength < 0) { //Burst length < 0 is sentinel
							   //Copy the job list into a list from which values will not be deleted
			for (int z = 0; z < i; z++) {
				statList[z] = jList[z];
			}
			jobcount = i;
			return; //Exit the function if a burst length of -1 is reached
		}
		dataIN >> ws >> newJob;
	}
}


int main()
{
	getData();
	return 0;
}
