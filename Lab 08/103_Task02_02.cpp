//#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Lab; // forward declaration
class N28_Building;
class Lecture_Room;

class Lab{
private:
	string labName;
	int capacity;
	static vector<Lab*> labs; // vector of labs which will increase with every object creation
	friend class N28_Building;
public:
	Lab(string _labName = "", int _capacity = 0){
		labName = _labName;
		capacity = _capacity;
		labs.push_back(this);
	}

	~Lab(){
		vector<Lab*>::iterator it;
		it = find(labs.begin(), labs.end() , this);
		labs.erase(it);
	}
	string get_labName()const{return labName;}
	int get_capacity()const{return capacity;}
	void set_labName(string _labName){labName = _labName;}
	void set_capacity(int _capacity){capacity= _capacity;}

};

class Lecture_Room{
private:
	string roomName;
	int roomNo;
	int capacity;
	static vector <Lecture_Room*> lrooms;
	friend class N28_Building;
public:
	Lecture_Room(string _roomName = " ", int _roomNo = 0 , int _capacity = 0){
		roomName = _roomName;
		roomNo = _roomNo;
		capacity = _capacity;
		lrooms.push_back(this);
	}
	~Lecture_Room(){
		vector <Lecture_Room*>::iterator it;
		it = find(lrooms.begin(), lrooms.end() , this);
		lrooms.erase(it);
	}

	string get_roomName()const{return roomName;}
	int get_roomNo()const{return roomNo;}
	int get_capacity()const{return capacity;}

	void set_roomName(string _roomName){roomName = _roomName;}
	void set_roomNo(int _roomNo){roomNo = _roomNo;}
	void set_capacity(int _capacity){capacity = _capacity;}

};

class N28_Building{
public:
	N28_Building(){
		cout<<"Welcome to N28 Building\n";
	}
	~N28_Building(){}
	
	void showAllLabs() const{
		cout<<"Show all Labs:\n";
		for(auto it: Lab::labs){
			cout<<"Lab "<<it->get_labName()<<" "<<it->get_capacity()<<" Capacity"<<endl;
		}
	}

	void showAllLectureRooms() const{
		cout<<"Show all lecturers room: \n";
		for(auto it: Lecture_Room::lrooms){
			cout<<it->get_roomName()<<" "<<it->get_roomNo()<<" "<<it->get_capacity()<<" Capacity"<<endl;
		}
	}
};

vector<Lab*> Lab:: labs{};
vector<Lecture_Room*> Lecture_Room::lrooms{};

int main()
{
	N28_Building n28;
	Lab lab1("MPK1", 60), lab2("MPK2", 60), lab3("MPK3", 60);
	n28.showAllLabs();
	Lecture_Room r1("Hafiz" ,102 , 3), r2("Shafie" , 105, 3);
	n28.showAllLectureRooms();
}