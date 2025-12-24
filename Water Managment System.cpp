#include<bits/stdc++.h>
using namespace std;

const int MAX = 1500;
string village[MAX];
int tankcapacity[MAX];
int currentwater[MAX];
int dailyusage[MAX];
double latitude[MAX];
double longitude[MAX];
int totalVillages = 0;

void openVillageOnMap(double lat, double lon) {
    string url =
        "https://www.google.com/maps?q=" +
        to_string(lat) + "," + to_string(lon);
    string command = "start " + url;
    system(command.c_str());
}



int menu(){
    int choice;
    cout << "--- JalRaskhak System ---" << endl;
    cout << "1. Add Village Data" << endl;
    cout << "2. Get Village Data" << endl;
    cout << "3. Display All Villages" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    return choice;
}


void addvillagedata(){
        cout << "Enter Village name:";
        cin >> village[totalVillages];

        cout << "Enter Water Tank Capacity:";
        cin >> tankcapacity[totalVillages];

        cout << "Enter Current Water Tank Capacity:";
        cin >> currentwater[totalVillages];

        cout << "Enter Daily Usage of water:";
        cin >> dailyusage[totalVillages];

        cout << "Enter  Latitude of Village:";
        cin >> latitude[totalVillages];

        cout << "Enter Longitude of Village:";
        cin >> longitude[totalVillages];

        totalVillages++;
    }

 void getvillagedata(){
       if(totalVillages==0){
        cout << "No Data avaialble";
        return;
       }
        string name;
        cout << "Enter Village name:";
        cin >> name;
      
        for(int i=0;i<totalVillages;i++){
           if(village[i]==name){
            cout << "Village name:" << village[i] << endl;
           cout << "Water Tank Capacity is:" << tankcapacity[i] << endl;
           cout << "Current Water Tank Capacity is:" << currentwater[i] << endl;
           cout << "Daily Usage of Villagers is:" << dailyusage[i] << endl;

       int daysleft = currentwater[i]/dailyusage[i];
      bool leak = false;
      
      if (dailyusage[i] > (0.3 * tankcapacity[i])) {
      leak = true;
}
     if (daysleft <= 1) {
    leak = true;
}

     if (leak) {
    cout << "LEAK ALERT: Possible water leakage detected" << endl;
} else {
    cout << "No Leak Detected" << endl;
}

       cout << "Days Water will last in village:" << daysleft << endl;
       if(daysleft<=2){
        cout << "ALERT:Severe Water Shortage is expected" << endl;
       }
       else if(daysleft<=5){
        cout << "Warning:Water level is low" << endl;
       }
       else {
        cout << "Water Availability is Sufficient" << endl;
       }
        
       int ch;
       cout << "Open exact village location on map? (1 = Yes, 0 = No): ";
       cin >> ch;

       if (ch == 1) {
       openVillageOnMap(latitude[i], longitude[i]);
}
           }
        }
    }


void displaydata(){
    if(totalVillages==0){
        cout << "No Data Available" << endl;
        return;
    }
    for(int i=0;i<totalVillages;i++){
        cout <<"Village:" << village[i] << endl;
        cout << "Village tank capacity:" << tankcapacity[i] << endl;
        cout << "Current Water Capacity of tank:" << currentwater[i] << endl;
        cout << "Water used daily in village:" << dailyusage[i] << endl;
    }
}

int main(){
    int choice;
    do{
        choice = menu();
        switch(choice){
            case 1:
               addvillagedata();
               break;
            case 2:
              getvillagedata();
              break;
            case 3:
                displaydata();
                break;
            case 4:
                cout << "Exiting System" << endl;
                break;
            default:
               cout << "Invalid choice" << endl;
               break;
        }
    } while(choice!=4);
    return 0;
        }
