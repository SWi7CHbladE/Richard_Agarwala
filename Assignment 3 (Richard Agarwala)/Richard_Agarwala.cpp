/*This code emulates the behaviour of the Richart Agarwala algorithm for mutual exclusion*/

//Importing the stl library
#include<bits/stdc++.h>
using namespace std;


int main()
{

    int site_count, timestamp;
    cout<<"Enter number of sites :";
    cin>>site_count;

    //bookkeeping variables for the processes
    vector<int> time_stamp_list(site_count, 0);                                     //Holds the timestamp list indexed by the ProcessID
    vector<int> request;                                                            //
    map <int,int> mp;
    

    //Taking input form the user about the timestamp of the critical section access of each process
    for(int i=0; i<site_count; i++)
    {
        cout<<"\nEnter timestamp for process "<<i+1<<": ";
        cin>>timestamp;
        time_stamp_list[i] = timestamp;
        request.push_back(i+1);
        //Pushing the processes uniquely indexed by their timeline, Processes with same timestamp will be ignored
        mp[timestamp]=i+1;
    }

    //Print the list of the processes with their respective timestamps
    cout<<"\nSites and Timestamp:\n";
    for(int i=0; i < time_stamp_list.size();i++)
    {
        cout<<i+1<<" "<<time_stamp_list[i]<<endl;
    }


    //print the reply and deferred order
    for(int i = 0; i < request.size(); i++)                                         //runs for all the processes
    {
        cout<<"\n Request from site:"<<request[i]<<endl;
        //
        for(int j = 0; j < time_stamp_list.size(); j++)   
        {
            if(request[i]!=j)
            {
                if(time_stamp_list[j] > time_stamp_list[request[i]-1] || time_stamp_list[j]==0)
                {
                    cout<<j+1<<" Replied\n";
                }
                else
                {
                    cout<<j+1<<" Deferred\n";
                }
            }
        }
    }


    cout<<endl;
    map<int,int> :: iterator it;
    it=mp.begin();
    int c=0;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        cout<<"Site "<<it->second + 1<<" entered Critical Section \n";
        c++;
    }
    return 0;
}