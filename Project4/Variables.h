#define VARIABLES_H
using namespace std;

struct jobType {
	int number = -999, length, interArrival, IOBurstLength, CPUBurst[25], IOburstCount;
	int arrivalTime; //Holds the time at which the job entered the system
	int exitTime; //Holds the time at which the job exited the system
	int ltqWait, stqWait, ioWait, cpuWait; //Wait counters for each queue
	int responceTimer = 0;  // a timer to count per process until the cpu has the job
};

ifstream dataIN("SIM_DARA.txt");
ofstream dataOUT5("output.txt"); //Create and open the file to write data to.
int jobcount = 0;
const int MAXJOBNUMBER = 150; //Set the maximum number of jobs to 150
jobType jList[MAXJOBNUMBER]; //Declare and initialize the list of jobs
jobType statList[MAXJOBNUMBER]; //Declare and initialize the list of jobs
