//Job Sequencing Problem - With Maximum profit
//Contribution : Yashithi Dharmawimala

#include<iostream> 
#include<algorithm> 
#include<string.h>

using namespace std; 
  

struct job //Represents the job that needs to be scheduled 
{ 
   string name;      // Name of the Job
   int end;    // Ending time of job 
   int profit;  // Profit of job
}; 
  
bool compare(job a, job b) //sorts the job array
{ 
		if (a.profit>b.profit){
			return true;
		}
		else{
			return false;
		}
} 
  
void printJobScheduling(job array[], int n) 
{ 
    // Sorts the job array
    sort(array, array+n, compare); 
  
    int result[n]; // Stores the sequence of jobs
    bool slot[n];  // Stores free time slots
  
     
    for (int i=0; i<n; i++) {  //Initializing = all slots to be free
    	 slot[i] = false; 
	}
       

    for (int i=0; i<n; i++)  { 
    

       for (int j=min(n, array[i].end)-1; j>=0; j--)   //Starts from the last slot = Determines the free slot for the job
       { 

          if (slot[j]==false) //If there is a free slot available
          { 
             result[j] = i;  // The job is added to the result array 
             slot[j] = true; // Changed the slot vacancy
             break; 
          } 
       } 
    } 
  
	cout<<"The Job sequence with the maximum profit: \n";
    for (int i=0; i<n; i++) { //Prints results
    	if (slot[i]) {
    		cout << array[result[i]].name << " \n"; 
		}
       
	}

} 
  

int main() { 

	//Example array
	
    job array[] = { {"Job 1", 2, 150}, {"Job 2", 7, 19}, {"Job 3", 3, 270}, 
                   {"Job 4", 1, 25}, {"Job 4", 3, 15},{"Job 5", 4, 150}, {"Job 6", 20, 250}, {"Job 7", 1, 200}, 
                   {"Job 8", 3, 35}}; 
                   
    int n = sizeof(array)/sizeof(array[0]); //No of array elements
    
    printJobScheduling(array, n); 
    return 0; 
} 
