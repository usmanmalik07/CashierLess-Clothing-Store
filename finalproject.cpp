#include <iostream>
#include <string.h>
#include <limits.h>
#include <String>
#define V 5
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;

//PUBLIC VARIABLES
string itemName;
int salecost;
int ksalecost;
int msalecost;
int wsalecost;
int DeliveryTime;
int DeliveryCharges;
string username;
int choice;
int distanceP[V];
int CityDistance[5];
int InterCityDistance[5];
string city[]={"Islamabad","Lahore","Karachi","Quetta","Peshawar"};
int totalDistance;
    
//LINK LIST
struct ord {
	int code ;
	//int price;
	string name;
	ord* next;
	int price;
	int distance;
	int delivered;
	};
ord* head = new ord();


class order{
public:	
	void Clone(int codeNo,string Nname,int Nprice,int totaltime) {
      ord* newNode = new ord();
      
      newNode->distance=totaltime;
      newNode->delivered=totaltime/15;
      newNode->price=totaltime/15+totalDistance*0.50;
      newNode->code = codeNo;
      newNode->name= Nname;
      newNode->price=Nprice;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        ord* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
      }    

}

};





class receipt
{
public:
    int salecost;
    int ksalecost;
    int msalecost;
    int wsalecost;
    receipt()
    {
        salecost=0;
        ksalecost=0;
        msalecost=0;
        wsalecost=0;
    }
    virtual void CalculateReceipt()
    {

    }
};





class kids
{
public:
    char ch6;
    char get()
    {
        cout<<"Do you want to shop from NEW ARRIVALS or SALE(n/s)? ";
        cin>>ch6;
        return ch6;
    }
};


  

class women
{
public:
    char ch3,ch4;
    char get()
    {
        cout<<"Do you want to shop from NEW ARRIVALS or SALE(n/s)? ";
        cin>>ch3;
        return ch3;
    }

};

class men
{
public:
    char ch3;
    char get()
    {
        cout<<"Do you want to shop from NEW ARRIVALS or SALE(n/s)? ";
        cin>>ch3;
        return ch3;
    }
};




class ICdijk{
public:
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
	cout << "Route \t\tExtra Distance\t\tTotal Charges\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t""\t"
			<< graph[i][parent[i]] <<"\t\t\t\t"<<graph[i][parent[i]]*20<<" \n";
}


void prims(int graph[V][V], int distanceP[])
{
	int parent[V];
	//int distanceP[V];
	bool visitedP[V];

	for (int i = 0; i < V; i++)
		distanceP[i] = INT_MAX, visitedP[i] = false;

	distanceP[0] = 0;
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) {

		int u = minKey(distanceP, visitedP);

		visitedP[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && visitedP[v] == false && graph[u][v] < distanceP[v])
				parent[v] = u, distanceP[v] = graph[u][v];
	}
	// copy the dist array to InterCityDistance
    for (int i = 0; i < V; i++) {
        InterCityDistance[i] = distanceP[i];
    }

}

//	printMST(parent, graph);


};
/*
***************************************************************************************************************

                                    INTER CITY CODE
                        


																																																							 

***************************************************************************************************************
*/
class islamabad:public ICdijk
{
	public:
	int AreaCode;
	void deliverToIsb(){
		int graph[V][V] = 
		   { 
		  	 { 0, 10,0, 15, 20},
				 { 10,0,7,26,40},
				 { 0,7,0,17,21},
				 { 15,26,17,0,50},
				 { 20,40,21,50,0},
				};	
		for(int i=1; i<60; i++)
		
        {
            cout<<"-";
        }
        cout<<"\n |  AREA CODE |Area NAME   |"<<endl;
        cout<<"\n |    1001    |I8-Markaz   |"<<endl;
        cout<<"\n |    1002    |Sector G-11 |"<<endl;
        cout<<"\n |    1003    |Sector F-9  |"<<endl;
        cout<<"\n |    1004    |PAF BASE ISB|"<<endl;
        cout<<"\n |    1005    |Barakahu    |"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        int ICcode;
        int IChouse;
        cout<<"\nEnter area code you want your item delivered to ?"<<endl;
       	cin>>ICcode;
       	if (ICcode == 1001){
       		prims(graph,distanceP);
	        totalDistance+=InterCityDistance[0];
      		cout<<"Enter the house number:";
      		cin>>IChouse;
					cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}	
			else if (ICcode == 1002){
		      prims(graph,distanceP);
					totalDistance+=InterCityDistance[1];
					cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;					
			}
			else if (ICcode == 1003){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[2];
					cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}
			else if (ICcode == 1004){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[3];
					cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}
			else if (ICcode == 1005){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[4];
					cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}
				else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
	}
       																	 
										  
      
        
        
	
};


class lahore:public ICdijk
{
	public:
	int AreaCode;
	void deliverToLhr(){
		int graph[V][V] = 
		   { 
		  	 { 0, 5,0, 10, 15},
				 { 5,0,0,20,35},
				 { 0,0,0,12,16},
				 { 10,20,12,0,45},
				 { 15,35,16,45,0},
				};	
		for(int i=1; i<60; i++)
		
        {
            cout<<"-";
        }
        cout<<"\n |  AREA CODE |Area NAME   |"<<endl;
        cout<<"\n |    2001    |Model Town  |"<<endl;
        cout<<"\n |    2002    |Johar Town  |"<<endl;
        cout<<"\n |    2003    |Gulberg     |"<<endl;
        cout<<"\n |    2004    |Baghban Pura|"<<endl;
        cout<<"\n |    2005    |Bahria Town |"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        int ICcode;
        int IChouse;
        cout<<"\nEnter area code you want your item delivered to ?"<<endl;
       	cin>>ICcode;
       	if (ICcode == 2001){
       		prims(graph,distanceP);
       		totalDistance+=InterCityDistance[0];
      		cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}	
			else if (ICcode == 2002){
		      prims(graph,distanceP);
		      totalDistance+=InterCityDistance[1];
		      cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;				
			}
			else if (ICcode == 2003){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[2];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 2004){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[3];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 2005){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[4];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
				else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
	}
       																	 
										  
      
        
        
	
};
class karachi:public ICdijk
{
	public:
	int AreaCode;
	void deliverToKhi(){
		int graph[V][V] = 
		   { 
		  	 { 0, 15,0, 20, 25},
				 { 15,0,10,30,45},
				 { 0,10,0,22,26},
				 { 20,30,22,0,55},
				 { 25,45,26,55,0},
				};	
		for(int i=1; i<60; i++)
		
        {
            cout<<"-";
        }
        cout<<"\n |  AREA CODE |Area NAME   |"<<endl;
        cout<<"\n |    3001    |Bahria Town |"<<endl;
        cout<<"\n |    3002    |Layari      |"<<endl;
        cout<<"\n |    3003    |Teen talwar |"<<endl;
        cout<<"\n |    3004    |Gulshan Town|"<<endl;
        cout<<"\n |    3005    |Korangi Town|"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        int ICcode;
        int IChouse;
        cout<<"\nEnter area code you want your item delivered to ?"<<endl;
       	cin>>ICcode;
 	    if (ICcode == 3001){
       		prims(graph,distanceP);
       		totalDistance+=InterCityDistance[0];
      		cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}	
			else if (ICcode == 3002){
		      prims(graph,distanceP);
					totalDistance+=InterCityDistance[1];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;				
			}
			else if (ICcode == 3003){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[2];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 3004){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[3];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 3005){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[4];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else{
				cout<<"Wrong command Program is closing";
			exit(1);
			}
			
	}
       																	 
										  
      
        
        
	
};


class quetta:public ICdijk
{
	public:
	int AreaCode;
	void deliverToQue(){
		int graph[V][V] = 
		   { 
		  	 { 0, 20,0, 25, 30},
				 { 15,0,10,35,50},
				 { 0,10,0,27,31},
				 { 25,35,27,0,60},
				 { 30,50,31,60,0},
				};	
		for(int i=1; i<60; i++)
		
        {
            cout<<"-";
        }
        cout<<"\n |  AREA CODE |Area NAME      |"<<endl;
        cout<<"\n |    4001    |Killa Abdullah |"<<endl;
        cout<<"\n |    4002    |Karezat 	     |"<<endl;
        cout<<"\n |    4003    |Pishin district|"<<endl;
        cout<<"\n |    4004    |Chaman district|"<<endl;
        cout<<"\n |    4005    |Quetta district|"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        int ICcode;
        int IChouse;
        cout<<"\nEnter area code you want your item delivered to ?"<<endl;
       	cin>>ICcode;
       	if (ICcode == 4001){
       		prims(graph,distanceP);
       		totalDistance+=InterCityDistance[0];
      		cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}	
			else if (ICcode == 4002){
		      prims(graph,distanceP);
					totalDistance+=InterCityDistance[1];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;				
			}
			else if (ICcode == 4003){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[2];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 4004){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[3];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 4005){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[4];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
				else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
	}
       																	 
										  
      
        
        
	
};

class peshawar:public ICdijk
{
	public:
	int AreaCode;
	void deliverToPesh(){
		int graph[V][V] = 
		   { 
		  	 { 0, 14,0, 19, 24},
				 { 14,0,9,29,44},
				 { 0,9,0,21,25},
				 { 19,29,22,0,54},
				 { 24,44,25,54,0},
				};	
		for(int i=1; i<60; i++)
		
        {
            cout<<"-";
        }
        cout<<"\n |  AREA CODE |Area NAME    |"<<endl;
        cout<<"\n |    5001    |Hayat abad   |"<<endl;
        cout<<"\n |    5002    |Regi Peshawar|"<<endl;
        cout<<"\n |    5003    |DHA Peshawar |"<<endl;
        cout<<"\n |    5004    |GulBahar     |"<<endl;
        cout<<"\n |    5005    |Warsak road  |"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        int ICcode;
        int IChouse;
        cout<<"\nEnter area code you want your item delivered to ?"<<endl;
       	cin>>ICcode;
       	if (ICcode == 5001){
       		prims(graph,distanceP);
       		totalDistance+=InterCityDistance[0];
      		cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
		      cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;	
			}	
			else if (ICcode == 5002){
		      prims(graph,distanceP);
					totalDistance+=InterCityDistance[1];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;				
			}
			else if (ICcode == 5003){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[2];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 5004){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[3];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
			else if (ICcode == 5005){
					prims(graph,distanceP);
					totalDistance+=InterCityDistance[4];
					cout<<"Enter the house number:";
      		cin>>IChouse;
      		cout<<"total distance: "<<totalDistance<<endl;
					cout<<"Your order will be delivered in ("<<totalDistance/15<<") hours. We appreciate you for waiting in this time."<<endl;
					cout<<"Your delivery charges include "<<totalDistance/15+totalDistance*0.50<< " including tax."<<endl;
			}
				else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
	}
};

class dijk
{
public:
	
	
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

//// A utility function to print the constructed distance array
int print(int dist[], int n)
{
	
	
	cout<<"Distance from Source City to Destination\n";
	//cout<<"source"<<"\t"<<"distance"<<"\t"<<"price"<<"\t"<<"time(hours)"<<endl;	
		
	for (int i = 0; i < V; i++)
	cout<<i<<"\t"<<dist[i]<<"\t"<<"\t"<<0.35*dist[i]+10<<"\t"<<"\t"<<dist[i]/30<<endl;
	  
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // copy the dist array to CityDistance
    for (int i = 0; i < V; i++) {
        CityDistance[i] = dist[i];
    }
}

};



class delivery:public dijk,public islamabad,public lahore,public karachi,public quetta,public peshawar
{
	public:
		void showDelivery(){
			
			 for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
        cout<<"Which city are you buying this item from(Our Outlet).Select from the following ones\n";
        cout<<"\n |CITY CODE |        City       |"<<endl;
        cout<<"\n |    901   |    Islamabad      |"<<endl;
        cout<<"\n |    902   |    Lahore         |"<<endl;
        cout<<"\n |    903   |    Karachi        |"<<endl;
        cout<<"\n |    904   |    Quetta         |"<<endl;
        cout<<"\n |    905   |    Peshawar       |"<<endl;
        for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
	}
	void askDelivery(){
	
//	 	int getFromCity(){
			int size = 5;
			int Cdistance;
			int Fdistance;
			int graph[V][V] = { 
											{ 0, 374, 0, 893, 186},
											{ 374,0,1025,0,0},
											{ 0,1025,0,709,0 },
											{ 893,0,709,0,0},
											{ 186,0,0,0,0 },
											  };																	 
											  
			int FromcityCode;
			cout<<"\nEnter the city code you want these items delivered from \n";
			cin>>FromcityCode;
			if (FromcityCode == 901){
				dijkstra(graph,0);	
			}	
			else if (FromcityCode == 902){
			dijkstra(graph,1);
			}
			else if (FromcityCode == 903){
				dijkstra(graph,2);
			}
			else if (FromcityCode == 904){
				dijkstra(graph,3);
			}
			else if (FromcityCode == 905){
				dijkstra(graph,4);
			}
				else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
			
			int TocityCode;
			cout<<"\nEnter the city code you want your items delivered to\n";
			cin>>TocityCode;
			if (TocityCode == 901){
				totalDistance+=CityDistance[0];
				cout<<"The distance to "<<city[0]<<" from your source city is "<<CityDistance[0]<<endl;
				deliverToIsb();
			}	
			else if (TocityCode == 902){
				totalDistance+=CityDistance[1];
				cout<<"The distance to "<<city[1]<<" from your source city is "<<CityDistance[1]<<endl;
				deliverToLhr();
			}
			else if (TocityCode == 903){
				totalDistance+=CityDistance[2];
				cout<<"The distance to "<<city[2]<<" from your source city is "<<CityDistance[2]<<endl;
				deliverToKhi();
			}
			else if (TocityCode == 904){
				totalDistance+=CityDistance[3];
				cout<<"The distance to "<<city[3]<<" from your source city is "<<CityDistance[3]<<endl;
				deliverToQue();
			}
			else if (TocityCode == 905){
				totalDistance+=CityDistance[4];
				cout<<"The distance to "<<city[4]<<" from your source city is "<<CityDistance[4]<<endl;
				deliverToPesh();
			}
			else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
	}
	
};






  





  

class sale:public receipt,public order
{
public:
    int SaleValue;
    int GetSale()
    {
        cout<<"\nThere is 30% and 50% off on selected items"<<endl;
        cout<<"\nWhich category would you like to view(30%/50%): ";
        cin>>SaleValue;
        return SaleValue;
    }
    void ShowWomen30()
    {
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |             ITEM NAME               | ORIGINAL PRICE | 30% off |"<<endl;
        cout<<"\n |    11    | Yellow printed Un-stitched shirt    |       1500     |   1050  |"<<endl;
        cout<<"\n |    12    | Blue embriodery Stitched shirt      |       2000     |   1400  |"<<endl;
        cout<<"\n |    13    |          White Handbag              |       3000     |   2100  |"<<endl;
        cout<<"\n |    14    |        Plain White Trouser          |       1420     |   1015  |"<<endl;
        cout<<"\n |    15    |     Orange Printed Duppatta         |       1000     |   700   |"<<endl;
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
    }
    void ShowWomen50()
    {
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |             ITEM NAME               | ORIGINAL PRICE | 50% off |"<<endl;
        cout<<"\n |    21    | Stitched Suit 2-piece white printed |       3500     |   1750  |"<<endl;
        cout<<"\n |    22    | UnStitched shirt Pink embriodery    |       2000     |   1000  |"<<endl;
        cout<<"\n |    23    |          Fancy Red Clutch           |       3000     |   1500  |"<<endl;
        cout<<"\n |    24    |        Plain Black Trouser          |       1300     |   650   |"<<endl;
        cout<<"\n |    25    |        Red Printed Duppatta         |       1000     |   500   |"<<endl;
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
    }
    void SaleBuy()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;
        if(itemCode==11)
        {
            cout<<"You have bought Yellow printed Un-stitched shirt for Rs.1050"<<endl;
            wsalecost = 1050;
            salecost+=wsalecost;
            itemName = "Yellow printed Un-stitched shirt";
        }
        else if(itemCode==12)
        {
            cout<<"You have bought Blue embriodery Stitched shirt for Rs.1400"<<endl;
            wsalecost = 1400;
            salecost+=wsalecost;
            itemName = "Blue embriodery Stitched shirt";
          }
            
        else if(itemCode==13)
        {
            cout<<"You have bought White Handbag for Rs.2100"<<endl;
            wsalecost = 2100;
            salecost+=wsalecost;
            itemName = "White Handbag";
        }
        else if(itemCode==14)
        {
            cout<<"You have bought Plain White Trouser for Rs.1015"<<endl;
            wsalecost = 1015;
            salecost+=wsalecost;
            itemName = "Plain White Trouser";
        }
        else if(itemCode==15)
        {
            cout<<"You have bought Orange Printed Duppatta  for Rs.700"<<endl;
            wsalecost = 700;
            salecost+=wsalecost;
            itemName = "Orange Printed Duppatta";
        }
        else if(itemCode==21)
        {
            cout<<"You have bought  Stitched Suit 2-piece white printed for Rs.1750"<<endl;
            wsalecost = 1750;
            salecost+=wsalecost;
            itemName = " Stitched Suit 2-piece white";
        }
        else if(itemCode==22)
        {
            cout<<"You have bought UnStitched shirt Pink embriodery  for Rs.1000"<<endl;
            wsalecost = 1000;
            itemName = "Unstiched shirt Pink embriodery";
      			}
        else if(itemCode==23)
        {
            cout<<"You have bought Fancy Red Clutch for Rs.1500"<<endl;
            wsalecost = 1500;
            salecost+=wsalecost;
            itemName = "Fancy Red Clutch";
            
        }
        else if(itemCode==24)
        {
            cout<<"You have bought Plain Black Trouser  for Rs.650"<<endl;
            wsalecost = 650;
            salecost+=wsalecost;
            itemName = "Plain Black Trouser";
        }
        else if(itemCode==25)
        {
            cout<<"You have bought Red Printed Duppatta for Rs.500"<<endl;
            wsalecost = 500;
            salecost+=wsalecost;
            itemName = "Red Printed Duppatta";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,wsalecost,totalDistance);
    }

    void CalculateReceipt()
    {
        cout<<"\n********************************"<<endl;
        cout<<"Your Total is Rs. "<<salecost<<endl;
        cout<<"Adding 7.5% GST"<<endl;
        salecost=((salecost/100)*7.5)+salecost;
        cout<<"Your Grand Total is: "<<salecost<<endl;
        cout<<"Thanks for shopping here!,Visit us again soon!"<<endl;
        cout<<"********************************"<<endl;
    }

};


  

class NewArrival:public order
{
public:
    void n_a_women()
    {
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |             ITEM NAME               | PRICE |"<<endl;
        cout<<"\n |    31    |    Unstitched 2-piece Pink&White    | 2500  |"<<endl;
        cout<<"\n |    32    |    3-piece Blue embriodery Suit     | 4000  |"<<endl;
        cout<<"\n |    33    |            Red Handbag              | 2300  |"<<endl;
        cout<<"\n |    34    |        Fancy White Trouser          | 2420  |"<<endl;
        cout<<"\n |    35    |      Red Embrioded Duppatta         | 1600  |"<<endl;
        cout<<"\n |    36    | Stitched Suit 3-piece Orange printed| 4500  |"<<endl;
        cout<<"\n |    37    | UnStitched 2-piece Pink embriodery  | 2400  |"<<endl;
        cout<<"\n |    38    |        White printed facemask       | 1300  |"<<endl;
        cout<<"\n |    39    |        Black Long Coat              | 6600  |"<<endl;
        cout<<"\n |    40    |        Women Denim Jacket           | 5000  |"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
    }
    void NewArrivalCost()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;
        
        

        if(itemCode==31)
        {
            cout<<"You have bought Unstitched 2-piece Pink&White for Rs.2500"<<endl;
            wsalecost = 2500;
            salecost+=wsalecost;
            itemName = "2-piece Pink&White";
        }
        else if(itemCode==32)
        {
            cout<<"You have bought 3-piece Blue embriodery Suit for Rs.4000"<<endl;
            wsalecost = 4000;
            salecost+=wsalecost;
            itemName = "3-piece Blue Suit";
        }
        else if(itemCode==33)
        {
            cout<<"You have bought Red Handbag for Rs.2300"<<endl;
            wsalecost = 2300;
            salecost+=wsalecost;
            itemName = "Red Handbag";
        }
        else if(itemCode==34)
        {
            cout<<"You have bought Fancy White Trouser for Rs.2420"<<endl;
            wsalecost = 2420;
            salecost+=wsalecost;
            itemName = "Fancy White Trouser";
        }
        else if(itemCode==35)
        {
            cout<<"You have bought Red Embrioded Duppatta for Rs.1600"<<endl;
            wsalecost = 1600;
            salecost+=wsalecost;
            itemName = "Red Embrioded Duppatta";
        }
        else if(itemCode==36)
        {
            cout<<"You have bought  Stitched Suit 3-piece Orange printed for Rs.4500"<<endl;
            wsalecost = 4500;
            salecost+=wsalecost;
            itemName = "3-piece Orange printed";
        }
        else if(itemCode==37)
        {
            cout<<"You have bought UnStitched 2-piece Pink embriodery for Rs.2400"<<endl;
            wsalecost = 2400;
            salecost+=wsalecost;
            itemName = "2-piece Pink embriodery";
        }
        else if(itemCode==38)
        {
            cout<<"You have bought White printed facemask for Rs.1300"<<endl;
            wsalecost = 1300;
            salecost+=wsalecost;
            itemName = "White printed facemask";
        }
        else if(itemCode==39)
        {
            cout<<"You have bought Black Long Coat for Rs.6600"<<endl;
            wsalecost = 6600;
            salecost+=wsalecost;
            itemName = "Black Long Coat";
        }
        else if(itemCode==40)
        {
            cout<<"You have bought Women Denim Jacket  for Rs.5000"<<endl;
            wsalecost = 5000;
            salecost+=wsalecost;
            itemName = "Women Denim Jacket";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,wsalecost,totalDistance);
    }

    void n_a_kids()
    {
        for(int i=1; i<86; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |      GIRLS     |    PRICE     |ITEM CODE|     BOYS     |    PRICE     | "<<endl;
        cout<<"\n |    711   |Frock embriodery|     2800     |   811   |  Wallet(skin)|     1000     | "<<endl;
        cout<<"\n |    722   |  skirt(yellow) |     2200     |   822   |trouser(black)|     1400     | "<<endl;
        cout<<"\n |    733   |  Tights(blue)  |     1600     |   833   | shlwar(brown)|     2200     | "<<endl;
        cout<<"\n |    744   |  Maxi(purple)  |     3000     |   844   | shorts(skin) |     1200     | "<<endl;
        cout<<"\n |    755   |   Socks(skin)  |     500      |   855   | polos(blue)  |     1900     | "<<endl;
        for(int i=1; i<86; i++)
        {
            cout<<"-";
        }
    }
    void newarrivalcost_kids()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;
        if(itemCode==711)
        {
            cout<<"You have bought trouser (pink) for Rs.2800"<<endl;
            ksalecost = 2800;
            salecost+=ksalecost;
            itemName="trouser(pink)";
        }
        else if(itemCode==722)
        {
            cout<<"You have bought skirt(yellow) for Rs.2000"<<endl;
            ksalecost = 2000;
            salecost+=ksalecost;
            itemName="skirt(yellow)";
        }
        else if(itemCode==733)
        {
            cout<<"You have bought Tights (blue) for Rs.1600"<<endl;
            ksalecost = 1600;
            salecost+=ksalecost;
            itemName="Tights(blue)";
        }
        else if(itemCode==744)
        {
            cout<<"You have bought Maxi (purple)r for Rs.3000"<<endl;
            ksalecost = 3000;
            salecost+=ksalecost;
            itemName="Maxi(purple)";
        }
        else if(itemCode==755)
        {
            cout<<"You have bought socks (skin)  for Rs.500"<<endl;
            ksalecost = 500;
            salecost+=ksalecost;
            itemName="socks(skin)";
        }
        else if(itemCode==811)
        {
            cout<<"You have bought belt (skin) for Rs.1000"<<endl;
            ksalecost = 1000;
            salecost+=ksalecost;
            itemName="belt(skin)";
        }
        else if(itemCode==822)
        {
            cout<<"You have bought Trouser(black) for Rs.1400"<<endl;
            ksalecost = 1400;
            salecost+=ksalecost;
            itemName="Trouser(black)";
        }
        else if(itemCode==833)
        {
            cout<<"You have bought shalwar(brown) for Rs.2200"<<endl;
            ksalecost = 2200;
            salecost+=ksalecost;
            itemName="shalwar(brown)";
        }
        else if(itemCode==844)
        {
            cout<<"You have bought shorts(skin) for Rs.1200"<<endl;
            ksalecost = 1200;
            salecost+=ksalecost;
            itemName="shorts(skin)";
        }
        else if(itemCode==855)
        {
            cout<<"You have bought polos(blue) for Rs.1900"<<endl;
            ksalecost = 1900;
            salecost+=ksalecost;
            itemName="polos(blue)";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,ksalecost,totalDistance);
    }

    void n_a_men()
    {
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |             ITEM NAME               | PRICE |"<<endl;
        cout<<"\n |    71    |   Unstitched shlwar kameez(black)   | 2500  |"<<endl;
        cout<<"\n |    72    |         Fancy WaistCoat(Red)        | 7000  |"<<endl;
        cout<<"\n |    73    |         Sherwani(mehroon,skin)      | 15000 |"<<endl;
        cout<<"\n |    74    |         Velvet WaistCoat(black)     | 2500  |"<<endl;
        cout<<"\n |    75    |  Stitched shlwar kameez(navy blue)  | 2700  |"<<endl;
        cout<<"\n |    76    |             Chapli(black)           | 2500  |"<<endl;
        cout<<"\n |    77    |               Fragrance             | 3000  |"<<endl;
        for(int i=1; i<60; i++)
        {
            cout<<"-";
        }
    }
    void newarrivalcost_men()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;

        if(itemCode==71)
        {
            cout<<"You have bought Unstitched shlwar kameez(black) for Rs.2500"<<endl;
            msalecost = 2500;
            salecost+=msalecost;
            itemName="Unstitched shlwar kameez(black)";
        }
        else if(itemCode==72)
        {
            cout<<"You have bought Fancy WaistCoat(Red) for Rs.7000"<<endl;
            msalecost = 7000;
            salecost+=msalecost;
            itemName="Fancy WaistCoat(Red)";
        }
        else if(itemCode==73)
        {
            cout<<"You have bought Sherwani(mehroon,skin) for Rs.15000"<<endl;
            msalecost = 15000;
            salecost+=msalecost;
            itemName="Sherwani(mehroon,skin)";
        }
        else if(itemCode==74)
        {
            cout<<"You have bought Velvet WaistCoat(black) for Rs.2500"<<endl;
            msalecost = 2500;
            salecost+=msalecost;
            itemName="Velvet Waistcoat(black)";
        }
        else if(itemCode==75)
        {
            cout<<"You have bought Stitched shalwar kameez(navy blue) for Rs.2700"<<endl;
            msalecost = 2700;
            salecost+=msalecost;
            itemName="shalwar kameez(navy blue)";
        }
        else if(itemCode==76)
        {
            cout<<"You have bought Chapli(black) for Rs.2500"<<endl;
            msalecost = 2500;
            salecost+=msalecost;
            itemName="Chapli(black)";
        }
        else if(itemCode==77)
        {
            cout<<"You have bought Fragrance for Rs.3000"<<endl;
            msalecost = 3000;
            salecost+=msalecost;
            itemName="Fragrance";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,msalecost,totalDistance);
    }
    void CalculateReceipt()
    {
        cout<<"\n********************************"<<endl;
        cout<<"Your Total is Rs. "<<salecost<<endl;
        cout<<"Adding 7.5% GST"<<endl;
        salecost=((salecost/100)*7.5)+salecost;
        cout<<"Your Grand Total is: "<<salecost<<endl;
        cout<<"Thanks for shopping here!,Visit us again soon!"<<endl;
        cout<<"********************************"<<endl;
    }
};


  





  

class mensale:public men,public receipt,public order
{
public:
    void showmen30()
    {
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |             ITEM NAME               | ORIGINAL PRICE | 30% off |"<<endl;
        cout<<"\n |    91    |          Chequered Shirt(red)       |       1700     |   1190  |"<<endl;
        cout<<"\n |    92    |           Cotton pent(brown)        |       2500     |   1750  |"<<endl;
        cout<<"\n |    93    |                Jeans                |       1700     |   1190  |"<<endl;
        cout<<"\n |    94    |              Denim shirt            |       1600     |   1120  |"<<endl;
        cout<<"\n |    95    |              Belt(black)            |       600      |   420   |"<<endl;
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
    }
     void showmen50()
    {
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |              ITEM NAME              | ORIGINAL PRICE | 50% off |"<<endl;
        cout<<"\n |    31    |             T-shirt(skin)           |       1500     |   750   |"<<endl;
        cout<<"\n |    32    |          Formal shirt(green)        |       2000     |   1000  |"<<endl;
        cout<<"\n |    33    |              Jeans(blue)            |       2000     |   1000  |"<<endl;
        cout<<"\n |    34    |           shalwar kameez(blue)      |       2300     |   1150  |"<<endl;
        cout<<"\n |    35    |                joggers              |       5000     |  2500   |"<<endl;
        for(int i=1; i<79; i++)
        {
            cout<<"-";
        }
    }
    void salebuymen()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;

        if(itemCode==91)
        {
            cout<<"You have bought Chequered Shirt(red) for Rs.1190"<<endl;
            msalecost = 1190;
            salecost+=msalecost;
            itemName="Chequered Shirt(red)";
        }
        else if(itemCode==92)
        {
            cout<<"You have bought Cotton pent(brown) for Rs.1750"<<endl;
            msalecost = 1750;
            salecost+=msalecost;
            itemName="Cotton pent(brown)";
        }
        else if(itemCode==93)
        {
            cout<<"You have bought Jeans for Rs.1190"<<endl;
            msalecost = 1190;
            salecost+=msalecost;
            itemName="Jeans";
        }
        else if(itemCode==94)
        {
            cout<<"You have bought Denim shirt for Rs.1120"<<endl;
            msalecost = 1120;
            salecost+=msalecost;
            itemName="Denim shirt";
        }
        else if(itemCode==95)
        {
            cout<<"You have bought Belt(black)  for Rs.420"<<endl;
            msalecost = 420;
            salecost+=msalecost;
            itemName="Belt(black)";
        }
        else if(itemCode==35)
        {
            cout<<"You have bought  joggers for Rs.2500"<<endl;
            msalecost = 1750;
            salecost+=msalecost;
            itemName="joggers";
        }
        else if(itemCode==34)
        {
            cout<<"You have bought shalwar kameez(blue) for Rs.1150"<<endl;
            msalecost = 1000;
            salecost+=msalecost;
            itemName="shalwar kameez(blue)";
        }
        else if(itemCode==33)
        {
            cout<<"You have bought Jeans(blue) for Rs.1000"<<endl;
            msalecost = 1500;
            salecost+=msalecost;
            itemName="Jeans(blue)";
        }
        else if(itemCode==32)
        {
            cout<<"You have Formal shirt(green)  for Rs.1000"<<endl;
            msalecost = 650;
            salecost+=msalecost;
            itemName="shirt(green)";
        }
        else if(itemCode==31)
        {
            cout<<"You have bought T-shirt(skin) for Rs.750"<<endl;
            msalecost = 750;
            salecost+=msalecost;
            itemName="T-shirt(skin)";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,msalecost,totalDistance);
    }
   
};






  





  

class kidssale:public kids,public receipt,public order
{
public:
    void Showkids30()
    {
        for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |        GIRLS      |ORIGINAL PRICE| 30% off |ITEM CODE|     BOYS     |ORIGINAL PRICE| 30% off|"<<endl;
        cout<<"\n |    311   |    T-shirt(pink)  |     1200     |   840   |    411  | shirt(yellow)|     1300     |   910  |"<<endl;
        cout<<"\n |    322   |   Blouse(yellow)  |     1800     |   1260  |    422  |trouser(black)|     1000     |   700  |"<<endl;
        cout<<"\n |    333   |     Frock(blue)   |     2200     |   1540  |    433  | pyjama(brown)|     1000     |   700  |"<<endl;
        cout<<"\n |    344   |  Jumpsuit(purple) |     3000     |   2100  |    444  | jeans(skin)  |     1300     |   910  |"<<endl;
        cout<<"\n |    355   |    Kurti(skin)    |     1900     |   1330  |    455  | kurta(blue)  |     1400     |   980  |"<<endl;
        for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
    }
    void salebuy30()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;
        if(itemCode==311)
        {
            cout<<"You have bought T-shirt (pink) for Rs.840"<<endl;
            ksalecost = 840;
            salecost+=ksalecost;
            itemName="T-shirt(pink)";
        }
        else if(itemCode==322)
        {
            cout<<"You have bought Blouse(yellow) for Rs.1250"<<endl;
            ksalecost = 1250;
            salecost+=ksalecost;
            itemName="Blouse(yellow)";
        }
        else if(itemCode==333)
        {
            cout<<"You have bought Frock(blue) for Rs.1540"<<endl;
            ksalecost = 1540;
            salecost+=ksalecost;
            itemName="Frock(blue)";
        }
        else if(itemCode==344)
        {
            cout<<"You have bought Jumpsuit (purple) for Rs.2100"<<endl;
            ksalecost = 2100;
            salecost+=ksalecost;
            itemName="Jumpsuit(purple)";
        }
        else if(itemCode==355)
        {
            cout<<"You have bought kurti (skin)  for Rs.1330"<<endl;
            ksalecost = 1330;
            salecost+=ksalecost;
            itemName="kurti(skin)";
        }
        else if(itemCode==411)
        {
            cout<<"You have bought shirt(yellow) for Rs.910"<<endl;
            ksalecost = 910;
            salecost+=ksalecost;
            itemName="shirt(yellow)";
        }
        else if(itemCode==422)
        {
            cout<<"You have bought Trouser(black) for Rs.700"<<endl;
            ksalecost = 700;
            salecost+=ksalecost;
            itemName="Trouser(black)";
        }
        else if(itemCode==433)
        {
            cout<<"You have bought pyjama(brown) for Rs.700"<<endl;
            ksalecost = 700;
            salecost+=ksalecost;
            itemName="pyjama(brown)";
        }
        else if(itemCode==444)
        {
            cout<<"You have bought jeans(skin) for Rs.910"<<endl;
            ksalecost = 910;
            salecost+=ksalecost;
            itemName="jeans(skin)";
        }
        else if(itemCode==455)
        {
            cout<<"You have bought kurta(blue) for Rs.980"<<endl;
            ksalecost = 980;
            salecost+=ksalecost;
            itemName="kurta(blue)";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,ksalecost,totalDistance);
    }
    void Showkids50()
    {
        for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
        cout<<"\n |ITEM CODE |      GIRLS     |ORIGINAL PRICE| 50% off |ITEM CODE|     BOYS     |ORIGINAL PRICE| 50% off|"<<endl;
        cout<<"\n |    511   |  Trouser(pink) |     1200     |   600   |    611  |  belt(skin)  |     400      |   200  |"<<endl;
        cout<<"\n |    522   |  skirt(yellow) |     1800     |   900   |    622  |trouser(black)|     1400     |   700  |"<<endl;
        cout<<"\n |    533   |  Tights(blue)  |     1600     |   800   |    633  | shlwar(brown)|     2000     |   1000 |"<<endl;
        cout<<"\n |    544   |  Maxi(purple)  |     3000     |   1500  |    644  | shorts(skin) |     800      |   400  |"<<endl;
        cout<<"\n |    555   |   Socks(skin)  |     500      |   250   |    655  | polos(blue)  |     1400     |   700  |"<<endl;
        for(int i=1; i<107; i++)
        {
            cout<<"-";
        }
    }
    void salebuy50()
    {
        cout<<"\nEnter the ITEM CODE Which you want to buy:    "<<endl;
        int itemCode;
        cin>>itemCode;
        if(itemCode==511)
        {
            cout<<"You have bought trouser (pink) for Rs.600"<<endl;
            ksalecost = 600;
            salecost+=ksalecost;
            itemName="trouser(pink)";
        }
        else if(itemCode==522)
        {
            cout<<"You have bought skirt(yellow) for Rs.900"<<endl;
            ksalecost = 900;
            salecost+=ksalecost;
            itemName="skirt(yellow)";
        }
        else if(itemCode==533)
        {
            cout<<"You have bought Tights (blue) for Rs.800"<<endl;
            ksalecost = 800;
            salecost+=ksalecost;
            itemName="Tights(blue)";
        }
        else if(itemCode==544)
        {
            cout<<"You have bought Maxi (purple) for Rs.1500"<<endl;
            ksalecost = 1500;
            salecost+=ksalecost;
            itemName="Maxi(purple)";
        }
        else if(itemCode==555)
        {
            cout<<"You have bought socks (skin)  for Rs.250"<<endl;
            ksalecost = 1330;
            salecost+=ksalecost;
            itemName="socks(skin)";
        }
        else if(itemCode==611)
        {
            cout<<"You have bought belt (skin) for Rs.200"<<endl;
            ksalecost = 200;
            salecost+=ksalecost;
            itemName="belt(skin)";
        }
        else if(itemCode==622)
        {
            cout<<"You have bought Trouser(black) for Rs.700"<<endl;
            ksalecost = 700;
            salecost+=ksalecost;
            itemName="Trouser(black)";
        }
        else if(itemCode==633)
        {
            cout<<"You have bought shalwar(brown) for Rs.1000"<<endl;
            ksalecost = 1000;
            salecost+=ksalecost;
            itemName="shalwar(brown)";
        }
        else if(itemCode==644)
        {
            cout<<"You have bought shorts(skin) for Rs.400"<<endl;
            ksalecost = 400;
            salecost+=ksalecost;
            itemName="shorts(skin)";
        }
        else if(itemCode==655)
        {
            cout<<"You have bought polos(blue) for Rs.700"<<endl;
            ksalecost = 700;
            salecost+=ksalecost;
            itemName="polos(blue)";
        }
        else{
					cout<<"Wrong command Program is closing";
			exit(1);
			}
        Clone(itemCode,itemName,ksalecost,totalDistance);
    }
    void CalculateReceipt()
    {
        cout<<"\n********************************"<<endl;
        cout<<"Your Total is Rs. "<<salecost<<endl;
        cout<<"Adding 7.5% GST"<<endl;
        salecost=((salecost/100)*7.5)+salecost;
        cout<<"Your Grand Total is: "<<salecost<<endl;
        cout<<"Thanks for shopping here!,Visit us again soon!"<<endl;
        cout<<"********************************"<<endl;
    }
};



class menu
{
public:
    void ShowMenu()
    {
        for(int i=1; i<55; i++)
        {
            cout<<" *~* ";
        }
        cout<<endl<<endl;
        for(int i=1; i<7; i++)
        {
            cout<<"\t";
        }
        cout<<"\n\t\t\t\tWelcome "<<username<<endl;
        cout<<"\n\t\t\t   WELCOME TO KHAADI CLOTHING STORE :)\n"<<endl;
        cout<<"\n\t\t\tHERE IS OUR CATALOGUE! HAVE A LOOK PLEASE!\n\n\n";
        for(int i=1; i<116; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tWOMEN\t\t\t|\t\t\tMEN\t\t\t|\t\tKIDS\t\t  |\n";
        for(int i=1; i<116; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tNew Arrivals\t\t|\t\tNew Arrivals\t\t\t|\tGirl\t|\tBoy\t  |\n";
        for(int i=1; i<82; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tStitched\t\t|\t\tStitched\t\t\t|\t    Stitched\t\t  |\n";
        cout<<endl<<"|`Fancy\t\t\t\t|`Kurta\t\t\t\t\t\t|`Skirts\t|`Jackets\t  |\n|`Casual\t\t\t|`Waistcoat\t\t\t\t\t|`Tops\t\t|`Shirts\t  |\n|`Embriodered\t\t\t|`Jeans\t\t\t\t\t\t|`Frocks\t|`pants\t\t  |\n";
        for(int i=1; i<82; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tUnstitched\t\t|\t\tUnstitched\t\t\t|\t   Unstitched\t\t  |\n";
        cout<<"|`1piece\t\t\t|`Kurta\t\t\t\t\t\t|\t-\t|\t-\t  |\n";
        cout<<"|`2piece\t\t\t|`kameez shalwar\t\t\t\t|\t-\t|\t-\t  |\n";
        cout<<"|`3piece\t\t\t|`Sherwani\t\t\t\t\t|\t-\t|\t-\t  |\n";
        for(int i=1; i<82; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tJewelery\t\t|\t\tFragrances\t\t\t|\t      Shoes\t\t  |\n";
        for(int i=1; i<82; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tScarves\t\t\t|\t\tDenim Shoes\t\t\t|`Jumpsuits\t|`Trousers\t  |\n";
        for(int i=1; i<116; i++)
        {
            cout<<"-";
        }
        cout<<endl<<"|\tSALE\t\t\t|\t\tSALE\t\t\t\t|\t     SALE\t\t  |\n";
        for(int i=1; i<116; i++)
        {
            cout<<"-";
        }
    }
    void CustomerType()
    {
        cout<<"\n\n\nAre you a regular customer or new here: (r/n)? ";
        char ch;
        cin>>ch;
        if(ch=='r') {}
        else if(ch=='n')
        {
            cout<<"\nHave some directions!..go upward for men's section, downward for basement and straight forward for women's section!"<<endl<<endl;
        }
        else
        {
            cout<<"\nChoose between r or n.!";
        }
    }
    char MenuChoice()
    {
        cout<<"\nDo you want to shop from Women,Men or Kids(w/m/k)? ";
        char ch1;
        cin>>ch1;
        return ch1;
    }
    char ShopMore()
    {
        cout<<"\nDo you wanna shop more or checkout?(y/n)";
        char shopchoice;
        cin>>shopchoice;
        return shopchoice;
    }
    char customerchoice()
    {
        cout<<endl<<"Are you interested in buying something(y/n)?\n";
        char ch4;
        cin >> ch4;
        return ch4;
    }
};









class userchoice
{
public:
    women w;
    kids kk;
    sale s;
    menu m;
    NewArrival n;
    kidssale k;
    men men1;
    mensale r; /// ----concept of Composition----///
    char ch4;
    int ch5;
    char ch6;
    char ch7,ch11,ch8,ch9,ch10;

    void WomenChoice()
    {
        ch4=w.get();
        if((ch4=='n')||(ch4=='N')) ///new arrivals
        {
            n.n_a_women();
            ch9 = m.customerchoice();
            if((ch9=='y')||(ch9=='Y'))
            {
                n.NewArrivalCost();
                n.CalculateReceipt();
                ch10 = m.ShopMore();
                if((ch10=='y')||(ch10=='Y'))
                {
                    ch11=m.MenuChoice();
                    if(ch11=='w')
                    {
                        WomenChoice();
                    }
                    else if(ch11=='m')
                    {
                        menChoice();
                    }
                    else if(ch11=='k')
                    {
                        kidsChoice();
                    }
                }
                else if((ch10=='n')||(ch10=='N'))
                {
                    cout<<"\nThanks for visiting us!See you soon"<<endl;
                }
            }
            else if((ch9=='n')||(ch9=='N'))
            {
                ch11 = m.ShopMore();
                if((ch11=='y')||(ch11=='Y'))
                {
                    char ch12 =m.MenuChoice();
                    if(ch12=='w')
                    {
                        WomenChoice();
                    }
                    else if(ch12=='m')
                    {
                        menChoice();
                    }
                    else if(ch12=='k')
                    {
                        kidsChoice();
                    }
                }
                else if((ch11=='n')||(ch11=='N'))
                {
                    cout<<"\nThanks for visiting us!See you soon"<<endl;
                }
            }
        }
        else if((ch4=='s')||(ch4=='S')) ///sale
        {
            ch5 = s.GetSale();
            if(ch5==30)                       ///30% sale
            {
                s.ShowWomen30();
                ch6=m.customerchoice();
                if((ch6=='y')||(ch6=='Y'))
                {
                    s.SaleBuy();
                    s.CalculateReceipt();
                    ch7 = m.ShopMore();
                    if((ch7=='y')||(ch7=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                    }
                    else if((ch7=='n')||(ch7=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if((ch6=='n')||(ch6=='N'))
                {
                    ch8 = m.ShopMore();
                    if((ch8=='y')||(ch8=='Y'))
                    {
                        char ch13 = m.MenuChoice();
                        if(ch13=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch13=='m')
                        {
                            menChoice();
                        }
                        else if(ch13=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch8=='n')||(ch8=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
            }
            else if(ch5==50)                   ///50% sale
            {
                s.ShowWomen50();
                ch6=m.customerchoice();
                if((ch6=='y')||(ch6=='Y'))
                {
                    s.SaleBuy();
                    s.CalculateReceipt();
                    ch7 = m.ShopMore();
                    if((ch7=='y')||(ch7=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch7=='n')||(ch7=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if((ch6=='n')||(ch6=='N'))
                {
                    ch8 = m.ShopMore();
                    if((ch8=='y')||(ch8=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch8=='n')||(ch8=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
            }
        }
    }


///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///


    void menChoice()
    {
        ch4=men1.get();
        if(ch4=='n' || ch4=='N')  ///NEW ARRIVALS
        {
            n.n_a_men();
            ch9=m.customerchoice();
            if(ch9=='y' || ch9=='Y')
            {
                n.newarrivalcost_men();
                ch10=m.ShopMore();
                if(ch10=='y' || ch10=='Y')
                {
                    ch11=m.MenuChoice();
                    if(ch11=='w')
                    {
                        WomenChoice();
                    }
                    if(ch11=='m')
                    {
                        menChoice();
                    }
                    if(ch11=='k')
                    {
                        kidsChoice();
                    }
                }
                else if(ch10=='n'||ch10=='N')
                {
                    n.CalculateReceipt();
                }
            }
            if(ch9=='n' || ch9=='N')
            {
                ch11=m.ShopMore();
                if(ch11=='y'|| ch11=='Y')
                {
                    ch11=m.MenuChoice();
                    if(ch11=='w')
                    {
                        WomenChoice();
                    }
                    if(ch11=='m')
                    {
                        menChoice();
                    }
                    if(ch11=='k')
                    {
                        kidsChoice();
                    }
                }
                else if(ch11=='n' || ch11=='N')
                {
                    cout<<"\nThanks for visiting us! see you soon!\n";
                }
            }
        }
        if(ch4=='s' || ch4=='S')  ///SALE
        {
            ch5=s.GetSale();
            if(ch5==30) /// 30% sale
            {
                r.showmen30();
                ch6=m.customerchoice();
                if(ch6=='y' || ch6=='Y')
                {
                    r.salebuymen();
                    r.CalculateReceipt();
                    ch7=m.ShopMore();
                    if(ch7=='y' || ch7=='Y')
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if(ch7=='n' || ch7=='N')
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if(ch6=='n' || ch6=='N')
                {
                    ch8=m.ShopMore();
                    if(ch8=='y' || ch8=='Y')
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        if(ch11=='m')
                        {
                            menChoice();
                        }
                        if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if(ch8=='n' || ch8=='N')
                    {
                        cout<<"\nThanks for visiting us! see you soon!\n";
                    }
                }
            }
            else if(ch5==50) /// 50% sale
            {
                r.showmen50();
                ch6=m.customerchoice();
                if(ch6=='y' || ch6=='Y')
                {
                    r.salebuymen();
                    r.CalculateReceipt();
                    ch7=m.ShopMore();
                    if(ch7=='y' || ch7=='Y')
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        if(ch11=='m')
                        {
                            menChoice();
                        }
                        if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if(ch7=='n' || ch7=='N')
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if(ch6=='n' || ch6=='N')
                {
                    ch8=m.ShopMore();
                    if(ch8=='y' || ch8=='Y')
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        if(ch11=='m')
                        {
                            menChoice();
                        }
                        if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if(ch8=='n' || ch8=='N')
                    {
                        cout<<"\nThanks for visiting us! see you soon!\n";
                    }
                }
            }
        }
    }



///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///
///-------------------------------------------------------------------------------------------------------------------------------------------------///


    void kidsChoice()
    {
        ch4=kk.get();
        if((ch4=='n')||(ch4=='N')) ///new arrivals
        {
            {
                n.n_a_kids();
                ch9 = m.customerchoice();
                if((ch9=='y')||(ch9=='Y'))
                {
                    n.newarrivalcost_kids();
                    n.CalculateReceipt();
                    ch10 = m.ShopMore();
                    if((ch10=='y')||(ch10=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch10=='n')||(ch10=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if((ch9=='n')||(ch9=='N'))
                {
                    ch11 = m.ShopMore();
                    if((ch11=='y')||(ch11=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        if(ch11=='m')
                        {
                            menChoice();
                        }
                        if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch11=='n')||(ch11=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
            }
        }
        else if((ch4=='s')||(ch4=='S'))         /// sale
        {
            ch5 = s.GetSale();
            if(ch5==30)           /// 30% sale
            {
                k.Showkids30();
                ch6=m.customerchoice();
                if((ch6=='y')||(ch6=='Y'))
                {
                    k.salebuy30();
                    k.CalculateReceipt();
                    ch7 = m.ShopMore();
                    if((ch7=='y')||(ch7=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                    }
                    else if((ch7=='n')||(ch7=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
            }
            else if((ch6=='n')||(ch6=='N'))
            {
                ch8 = m.ShopMore();
                if((ch8=='y')||(ch8=='Y'))
                {
                    ch11=m.MenuChoice();
                    if(ch11=='w')
                    {
                        WomenChoice();
                    }
                    if(ch11=='m')
                    {
                        menChoice();
                    }
                    if(ch11=='k')
                    {
                        kidsChoice();
                    }
                }
                else if((ch8=='n')||(ch8=='N'))
                {
                    cout<<"\nThanks for visiting us!See you soon"<<endl;
                }
            }
            else if(ch5==50)           /// 50% sale
            {
                k.Showkids50();
                ch6=m.customerchoice();
                if((ch6=='y')||(ch6=='Y'))
                {
                    k.salebuy50();
                    k.CalculateReceipt();
                    ch7 = m.ShopMore();
                    if((ch7=='y')||(ch7=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                    }
                    else if((ch7=='n')||(ch7=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
                else if((ch6=='n')||(ch6=='N'))
                {
                    ch8 = m.ShopMore();
                    if((ch8=='y')||(ch8=='Y'))
                    {
                        ch11=m.MenuChoice();
                        if(ch11=='w')
                        {
                            WomenChoice();
                        }
                        else if(ch11=='k')
                        {
                            kidsChoice();
                        }
                        else if(ch11=='m')
                        {
                            menChoice();
                        }
                    }
                    else if((ch8=='n')||(ch8=='N'))
                    {
                        cout<<"\nThanks for visiting us!See you soon"<<endl;
                    }
                }
            }
        }
    }
};




/*
DISPLAYING ORDERS TAKEN AS LINK LIST


*/

void display(ord* x){
	cout<<"\nHello "<<username<<" Current Orders:"<<endl;
	cout<<"Item code:\t"<<"Item price:\t"<<"\tItem Name:\t"<<endl;//<<"\t\tDistance:\t"<<"Delivery Time:"<<"\t Delivery Price"<<endl;
	while(x!=NULL){
		cout<<x->code<<"\t\t"<<x->price<<"\t\t"<<x->name<<" "<<endl;//  \t\t\t\t\t "<<x->distance<<"\t\t\t"<<x->delivered<<"\t\t"<<x->price<<" "<<endl;
		x=x->next;
		}
		//cout<<"\nThese items will be delivered in\t"<<DeliveryTime<<"\tdays/hours"<<endl;	
	}
		
	void mainscreen(){
		userchoice u;
    menu m;
    m.ShowMenu();
    m.CustomerType(); /// ----concept of Encapsulation----///
    char ch2;
    ch2 = m.MenuChoice();

    if((ch2=='w')||(ch2=='W')) /// shopping for women
    {
        u.WomenChoice();
    }

    else if(ch2=='m'||ch2=='M') ///shopping for men
    {
        u.menChoice();
    }

    else if(ch2=='k'||ch2=='K') ///shopping for kids
    {
        u.kidsChoice();
    }
    if(head->next==NULL){
    	cout<<"You did not order anything. So the program is closing";
			exit(1);
    	
		}
		else{
			delivery d; 
    d.showDelivery();	
    d.askDelivery();
		}
    
    
	}
void askPanel(){
cout<<"\nHello Mr/Ms "<<username<<" You have following options"<<endl;
cout << "1. View Catalogue And Order" << endl;
cout << "2. View Orders" << endl;
cout << "3. Main screen" << endl;
cout << "4. EXIT" << endl;
cin>>choice;
}
void mainCalling(){
	askPanel();
	switch (choice)
        {
  case 1:
        { 
		  mainscreen();
			mainCalling();
  			}
  case 2:
			 {
  	display(head);
  	mainCalling();
	 	   }		
	case 3:
			 {
		 mainCalling();
		 
		   }
  case 4:
  		 {
	   break;
			 }
		}
}


  
///----------------------------------------------CLOTHING STORE MANAGEMENT-------------------------------------------------///
///---------------------------------------GROUP MEMBERS: Usman Malik,Hammad Alvi-----------------------------------------///
///---------------------------------------REGISTRATION: FA21-BCS-072, FA21-BCS-055-----------------------------------------///

int main()
{
	cout<<"Please enter your name?"<<endl;
  cin>>username;
  mainCalling();
    return 0;
}

