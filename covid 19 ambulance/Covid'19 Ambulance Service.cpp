#include <bits/stdc++.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<conio.h>
#define infinity 500
#define V 11 //since we have included 11 areas in our project 
using namespace std;

int totalKeys=0;

string areasName[11]={"Gulshan-E-Iqbal", "Defence&Clifton", "North-Nazimabad", "Shah-Latif-Town", "Garden-West", "Nathakhan",
	             "Bahadurabad", "Dhoraji", "Gulistan-E-Jauhar", "PECHS", "Tariq-Road"}; //areas to be mapped on the graph

class Node{
	string name, cnic, area, pno;
	int age;
	Node* next;
	public:
	Node()
	{
		name = "";
		cnic = "";
		area = "";
		age = 0;
		pno = "";
		next = NULL;
	}
	Node(string n, string c, string a, int ag, string p)
	{
		name = n;
		cnic = c;
		area = a;
		age = ag;
		pno = p;
		next = NULL;
	}
	string getName()
	{
		return name;
	}
	string getCnic()
	{
		return cnic;
	}
	string getPhone()
	{
		return pno;
	}
	string getArea()
	{
		return area;
	}
	int getAge()
	{
		return age;
	}
	friend class SLL;
	friend class Hash;
};

class SLL {
	Node* Head;
	unsigned int size;
public:
	SLL()
	{
		Head = NULL;
		size = 0;
	}
	SLL(Node* t)
	{
		Head = t;
		size = 0;
	}
	SLL(int size, Node* t)
	{
		Head = t;
		this->size = size;
	}
	SLL(const SLL& list1)
	{
		this->size = list1.size;
		Node* newNode = list1.Head;
		while (newNode->next != NULL)
		{
			Node* temp = new Node(newNode->name, newNode->cnic, newNode->area, newNode->age, newNode->pno);
			if (this->Head == NULL)
			{
				temp->next = NULL;
				this->Head = temp;
			}
			else
			{
				Node* cur = this->Head;
				while (cur->next != NULL)
				{
					cur = cur->next;
				}
				cur->next = temp;
				temp->next = NULL;
			}
		}
	}
	SLL& operator = (const SLL& list1)
	{
		if (this != &list1)
		{
			Node* newNode = list1.Head;
			this->size = list1.size;
			Node* temp = new Node(newNode->name, newNode->cnic, newNode->area, newNode->age, newNode->pno);
			if (this->Head == NULL)
			{
				temp->next = NULL;
				this->Head = temp;
			}
			else
			{
				Node* cur = this->Head;
				while (cur->next != NULL)
				{
					cur = cur->next;
				}
				cur->next = temp;
				temp->next = NULL;
			}
		}
		else
		{
			return *this;
		}
	}
	~SLL()
	{
		if (Head != NULL)
		{
			DeleteAll();
		}
	}
	Node* getHead()
	{
		return Head;
	}
	void DeleteAll()
	{
		Node* cur = Head;
		Node* temp = new Node;
		while (cur->next != NULL)
		{
			temp = cur;
			cur = cur->next;
			temp = 0;
			delete temp;
		}
		Head = 0;
	}
	void addAtEnd(string n, string c, string ar, int a, string p)
	{
		size++;
		Node* newNode = new Node(n, c, ar, a, p);
		if (Head == NULL)
		{
			newNode->next = NULL;
			Head = newNode;
		}
		else
		{
			Node* cur = Head;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = newNode;
			newNode->next = NULL;
		}
	}
	void addAtFront(string n, string c, string ar, int a, string p)
	{
		size++;
		Node* newNode = new Node(n, c, ar, a, p);
		if (Head == NULL)
		{
			newNode->next = NULL;
			Head = newNode;
		}
		else
		{
			newNode->next = Head;
			Head = newNode;
		}
	}
	void display()
	{
		Node* cur = Head;
		if(cur == NULL)
		{
			return;
		}
        cout<<"========================================================================================================\n"; 
        cout<<"P.NO                        Cnic                      Age         Name                        Area Name"<<endl;
        cout<<"========================================================================================================\n";
		while (cur != NULL)
		{
			cout<<cur->pno<<"               "<<cur->cnic<<"            "<<cur->age<<"         "<<cur->name<<"                "<<cur->area<<endl;
            cur = cur->next;
		}
		cout << endl;
	}
	friend class Hash;
};

SLL* hashTable;

class Hash{
	public:
		void insertToHash(string n, string c, string ar, int a, string p)
		{
			int index = a % totalKeys;
			hashTable[index].addAtFront(n, c, ar, a, p);			
		}
		void deleteFromHash(string n, int ag)
		{
			int index = ag % totalKeys, flag = 0;
			Node* temp;
			Node* cur = hashTable[index].Head;
			if(cur == NULL)
			{
				cout << "Entry not present in the directory!";
				return;
			}
			else
			{
				while(cur != NULL)
				{
					flag = 1;
					if(cur->name == n && cur->age == ag)
					{
						if(cur == hashTable[index].Head)
						{
							hashTable[index].Head = cur->next;
						}
						else
						{
							temp->next = cur->next;
						}
						hashTable[index].size--;
						free(cur);
						break;
					}
					temp = cur;
					cur = cur->next;
				}
				if(flag == 1)
				{
					cout << "Data deleted successfully!!";
				}
				else
				{
					cout << "Data not present!";
				}
				return;
			}
		}
		Node* search(string n, int ag)
		{
			int index = ag % totalKeys, flag = 0;
			Node* cur = hashTable[index].Head;
			while(cur != NULL)
			{
				if(cur->name == n && cur->age == ag)
				{
					flag == 1;
					cout<<"========================================================================================================\n"; 
                    cout<<"P.NO                        Cnic                      Age         Name                        Area Name"<<endl;
                    cout<<"========================================================================================================\n";
                    cout<<cur->pno<<"               "<<cur->cnic<<"            "<<cur->age<<"         "<<cur->name<<"                "<<cur->area<<endl;
				    return cur;
					break;
				}
				else
				{
					cur = cur->next;
				}
			}
			if(flag == 0)
			{
				cout << "Searched data is not present in the directory!";
				return NULL;
			}
		}
		void display()
		{
			for(int i = 0; i < totalKeys; i++)
			{
				if(hashTable[i].size == 0)
				{
					continue;
				}
				else
				{
					cout << "Data at index: " << i << " in hash table:\n ";
					hashTable[i].display();
				}
			}
		}
		Node* selectPatient(int ag)
		{
			if(ag <= 0 && ag > 83)
			{
				cout << "Re-enter age: ";
				cin >> ag;
				selectPatient(ag);
			}
			else
			{
				if(hashTable[ag].size == 0)
				{
					cout << "Patients of this age doesn't exist";
					return NULL;
				}
				cout << "Data with age: " << ag << ": " << endl;
				hashTable[ag].display();
				string n;
                cout<<endl<<endl<<endl<<"Enter Name And Age Of The Particular Patient You Want To Visit First: (From The Above List)"<<endl;
                cout<<"Name: ";
                cin>>n;
				cout<<endl<<endl<<endl<<"Following Patient Is Set As The Priority Pateint: "<<endl;
                Node *newNode = search(n, ag);
		        return newNode;
			}
		}
};

class gNode{
	string from;
	string to;
	int distance;
	public:
		gNode()
		{
			from = "";
			to = "";
			distance = 0;
		}
		gNode(string f, string t, int d)
		{
			from = f;
			to = t;
			distance = d;
		}
		string getFrom()
		{
			return from;
		}
		string getTo()
		{
			return to;
		}
		int getDis()
		{
			return distance;
		}
		friend class Graph;
};

gNode graph[V][V];

class Graph{
	public:
		void graphInit()
		{
			for(int i = 0; i < V; i++)
			{
				for(int j = 0; j < V; j++)
				{
					graph[i][j].from = areasName[j];
				}
			}
			int flag = 0;
			for(int i = 0; i < V; i++)
			{
				for(int j = 0; j < V; j++)
				{
					graph[j][i].to = areasName[j];
				}
			}
			
			int matrix[11][11] = { {infinity, 4, infinity, infinity, infinity, infinity, infinity, 8, infinity, 8, infinity}, //giving weights/distances to 2D array
							       {4, infinity, 8, infinity, infinity, infinity, infinity, 11, infinity, 3, infinity}, 
							       {infinity, 8, infinity, 7, infinity, 4, infinity, infinity, 2, infinity, 9}, 
							       {infinity, infinity, 7, infinity, 9, 14, infinity, infinity, infinity, 10, infinity}, 
							       {infinity, infinity, infinity, 9, infinity, 10, infinity, infinity, infinity, infinity, 3}, 
						           {infinity, infinity, 4, infinity, 10, infinity, 2, infinity, infinity, infinity, 6}, 
							       {infinity, infinity, infinity, 14, infinity, 2, infinity, infinity, 6, 5, 2}, 
							       {8, 11, infinity, infinity, infinity, infinity, 1, infinity, 7, 1, infinity}, 
							       {infinity, infinity, 2, infinity, infinity, infinity, 6, 7, infinity, infinity, 3},
							       {8, 3, infinity, 10, infinity, infinity, 5, 1, infinity, infinity, 1},
							       {infinity, infinity, 9, infinity, 3, 6, 2, infinity, 3, 1, infinity}
							       };
			for(int i = 0; i < V; i++)
			{
				for(int j = 0; j < V; j++)
				{
					graph[i][j].distance = matrix[i][j];
				}			
			}				
		}
		
		int ambulanceSource()
		{
			int choice, location;
			cout<<"===================================================\n";             
	        cout<<"Choose Location for placing the Ambulance: "<<endl;
	        cout<<"===================================================\n";
			for(int i = 0; i < 11; i++)
			{
				cout << i + 1 << "- " << areasName[i] << endl;
			}
			cout << "Enter your choice: ";
			cin >> choice;
			location = choice - 1;
			return location;
		}
		
		int destinaton(string n)
		{
			int location;
			for(int i = 0, j = 0; i < 11; i++, j++)
			{
				if(graph[i][j].from == n)
				{
					location = i;
				}
			}
			return location;
		}
		
		void distances()
		{
			int flag=0;
            cout<<"=====================================================================\n"; //display area to area distance
            cout<<"Distance In Kilometeres      "<<"Locations"<<endl;
            cout<<"=====================================================================\n";
            for(int i=0; i<11; i++)
			{ // print area to area distances with weights in kilometeres
                for(int j=0; j<11; j++)
			    {
                    if(flag != j)
					{
                        if(graph[i][j].distance != infinity)
						{
                            cout << "|" << graph[i][j].distance << "|" << "\t\t\t     " << graph[i][j].from << " - " << graph[i][j].to << endl;
		                }
		                else
					    {
		    	            cout << "|NR|\t\t\t     " << graph[i][j].from << " - " << graph[i][j].to << endl; //No Route
			            }
                    }
                    flag++;
                    cout<<endl;
                }
            }
		}
		int shortestPath(int source, int destination, int visited[], gNode matrix[][V])  //modified version of depth first search
        {   
	        if (source == destination)
			{ //recursive step
	            return 0; 
	        }
	    
	        visited[source] = 1; //marking the source node as visited 
	        int minCost = infinity; 
	    
	        for(int i = 0; i < V; i++)
			{ //traversing through all adjacent nodes of source
	            if(matrix[source][i].distance != infinity && !visited[i]) 
				{  
	                int curr;
	                cout << endl << matrix[source][i].from << " to " << matrix[source][i].to << ": " << matrix[source][i].distance << "KM's" << endl;
				    curr = shortestPath(i, destination, visited, graph); 
	            
	                if (curr < infinity) 
					{  //destination reached
	                    minCost = min(minCost, matrix[source][i].distance + curr); //minimum cost path
	                } 
	           } 
	        } 
	        return minCost; 
        }
};

void gotoxy(int x, int y) 
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void titlePage()
{
	system("cls");
	gotoxy(40, 0);
	cout << "Covid'19 Ambulance Service.";
    gotoxy(40, 2);
    cout << " -------------------------\n";
    gotoxy(40, 4);
    cout <<"|   ALL RIGHTS RESERVED   |";
    gotoxy(40, 5);
    cout <<" -------------------------\n";
    gotoxy(40, 6);
    cout <<"| Made By: M. Tuaha Ajaz  |";
    gotoxy(40, 7);
    cout <<"| \t     Nayab Nathani  |";
    gotoxy(40, 8);
    cout <<"| \t     Hammad Jabbar |";
    gotoxy(40, 9);
    cout <<" -------------------------\n";
    gotoxy(40, 11);

    cout << "Loading  ";
    int j, a;
    for (a = 0; a <= 5; a++) 
	{
        cout <<".";
        for (j = 0; j <= 380000000; j++);
    }
    system("cls");
}

int main()
{
	system("COLOR E4");
	int choice, age;
    string name, pno, cnic, area;
    
	ifstream pcnic,pname,page,pphno,areas;
	
	pcnic.open("cnic.txt");
	pname.open("name.txt");
	pphno.open("phonenumbers.txt");
	page.open("age.txt");
	areas.open("area.txt");
	
	pcnic >> cnic;
	pname >> name;
	pphno >> pno;
	page >> age;
	areas >> area;
	
	totalKeys = 84;
	
	hashTable = new SLL[totalKeys];
	Hash h;
	
    titlePage();
	
	while(1)
	{
		page1:
		system("cls");
		cout << "\n\n\n\n\n\n\n\n=================================================================\n";	
	    cout << "Enter 1 For Loading Data From File Directory.(MUST)\n";
	    cout << "=================================================================\n\n";
	    cout << "Enter 2 To Delete A Patient's Data.\n"; //incase the patient cures somehow
	    cout << "=======================================\n\n";
	    cout << "Enter 3 To Search A Patient's Data.\n"; //searching a particular individual/maybe out of priority
	    cout << "=======================================\n\n";
	    cout << "Enter 4 to Display Ordered Data.\n"; //Display the whole data set (ordered)
	    cout << "=======================================\n\n";
	    cout << "Enter 5 For Ambulance Access.\n";       
	    cout << "=======================================\n\n";
	    cout << "Enter 6 to Exit.\n";
	    cout << "=======================================\n\n";
        cout << "Enter Choice: ";
        cin >> choice;
        if(choice == 1)
        {
        	system("cls");
            cout << "========================================================================================================\n"; 
            cout << "P.NO                        Cnic                      Age         Name                        Area Name"<<endl;
            cout << "========================================================================================================\n";
            while(!pcnic.eof() )
	        {	
		        cout << pno << "               " << cnic << "            " << age << "         " << name << "                " << area << endl; 
	            pcnic >> cnic;
	            pphno >> pno;
	            pname >> name;
	            page >> age;
	            areas >> area;
	            h.insertToHash(name , cnic, area, age, pno);              
	        }
            system("pause");
		}
		else if(choice == 2)
        {
        	system("cls");
            cout << "Enter the age to perform deletion: ";
            cin >> age;
            cout << "Enter name: ";
            cin >> name;
            /* delete node with "age" from hash table */
            h.deleteFromHash(name, age);
            system("pause");
		}
		else if(choice == 3)
        {
        	system("cls");
            cout << "=====================\n";
            cout << "Enter Age To Search: ";
            cin >> age;
            cout << "=====================\n";
            cout << "Enter Name: ";
            cin >> name;
            cout << "=====================\n";
            h.search(name, age);
            system("pause");
		}
		else if(choice == 4)
        {
        	system("cls");
            h.display();
            system("pause");
		}
		else if(choice == 5)
        {
        	Graph g;
        	g.graphInit(); //assign properties to the graph
		    int source = infinity, destination = infinity;
		    Node *destination_node;
		    int visited[V] = {0};
            visited[source] = 1; 
            page2:
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n================================================================\n\n";	
	        cout<<"Enter 1 To View Routes And Distances Between Areas.\n\n";
	    	cout<<"================================================================\n\n";
			cout<<"Enter 2 For Placing/Replace Ambulance At A Source/Starting Location.\n\n"; 
			cout<<"================================================================\n\n";
			cout<<"Enter 3 To Select Priority Pateint (Assigning Destination Location).\n\n";
			cout<<"================================================================\n\n";
			cout<<"Enter 4 To View The Shortest Route In Reaching The Priority Patient.\n\n";  
			cout<<"================================================================\n\n";
			cout<<"Enter 5 To View The Current Pateint And Ambulance's Location.\n\n";  
			cout<<"================================================================\n\n";
			cout<<"Enter 6 To Return To Main.\n\n";
			cout<<"================================================================\n\n";
			cout<<"Enter Choice: ";
			cin>>choice;
			
			if(choice == 1)
			{
				system("cls");
				g.distances(); //display area to area distances
				system("pause");
				goto page2;
			}
			else if(choice == 2)
			{
				system("cls");
				source = g.ambulanceSource(); //return a source point for ambulance to start the journey 
				system("pause");
				goto page2;
			}
			else if(choice == 3)
			{
				system("cls");
				cout << "Enter Age You Want To Prioritize: ";
				cin >> age;
				destination_node = h.selectPatient(age); //A node to save priority patient's information
				destination = g.destinaton(destination_node->getArea());
				system("pause");
				goto page2;
			}
			else if(choice == 4)
			{
				system("cls");
                if(source != infinity && destination != infinity)
				{ //source and destination must be initialized
				    cout << "============================================\n";
					cout << "Possible Routes For The Ambulance"<<endl;
					cout << "============================================\n";				                    
				    cout << "=====================================================================================\n";
					cout << endl<<endl<<endl<<endl<<"Shortest Route From "<<graph[source][0].getTo()<< " To " << graph[destination][0].getTo()<<" is : "<<g.shortestPath(source, destination, visited, graph)<<" KM's"<<endl;
					cout << "=====================================================================================\n";
					cout << "\n\n\n\n\n===================================================\n";          
					cout << endl<<endl<<"Enter 1 for DELETING this Patient's Data: ";
					cin >> choice;
					cout << "===================================================\n";  
					if(choice==1)
					{
						ofstream myfile;
                        myfile.open ("DoneWithPatients.txt",ios::app);
						myfile << destination_node->getPhone() << "               " << destination_node->getCnic() << "            " << destination_node->getAge() << "         " << destination_node->getName() << "                " << destination_node->getArea() << endl; 
						h.deleteFromHash( destination_node->getName(), destination_node->getAge()); //delete data after ambulance picks that individual
						destination = 0;
				    }
			    }
				else
				{
					cout<<"One of soruce or destination is not set by the user!!!"<<endl;
				}
				system("pause");
				goto page2;
				break;
			}
			else if(choice == 5)
			{
				system("cls");
                if(source != infinity && destination != infinity)
				{ //source and destination must be initialized
	                cout << "============================================\n";
				    cout << "Current Source Location / Ambulance's Location: " << graph[source][source].getFrom() << endl;
				    cout << "============================================\n";
				    cout << endl<<endl<<endl;
			        cout << "============================================\n";
				    cout << "Current Destination Location / Patient's Location: " << graph[destination][destination].getFrom() << endl;
				    cout << "============================================\n";
			    }
				else
				{
					cout << "One of soruce or destination is not set by the user!!!" << endl;
				}
                system("pause");
                goto page2;
				break;
			}
			else if(choice == 6)
			{
				goto page1;
				break;
			}
			else
			{
				system("cls");
		        cout<<"=======================================\n";
		        cout<<"U have entered wrong option!!\n";
		        cout<<"=======================================\n";
		        system("pause");
		        goto page2;
		        break;
			}
		}
		else if(choice == 6)
        {
        	exit(0);
		}
		else
		{
			system("cls");
		    cout<<"=======================================\n";
		    cout<<"U have entered wrong option!!\n";
		    cout<<"=======================================\n";
		    system("pause");
		    goto page1;
		    break;
		}
	}
}
