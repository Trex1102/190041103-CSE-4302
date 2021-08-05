#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Lab{
private:
	string labName;
	int capacity;
public:
	Lab(string _labName = "", int _capacity = 0){
		labName = _labName;
		capacity = _capacity;
	}

	~Lab(){}
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
public:
	Lecture_Room(string _roomName = " ", int _roomNo = 0 , int _capacity = 0){
		roomName = _roomName;
		roomNo = _roomNo;
		capacity = _capacity;
	}
	~Lecture_Room(){}

	string get_roomName()const{return roomName;}
	int get_roomNo()const{return roomNo;}
	int get_capacity()const{return capacity;}

	void set_roomName(string _roomName){roomName = _roomName;}
	void set_roomNo(int _roomNo){roomNo = _roomNo;}
	void set_capacity(int _capacity){capacity = _capacity;}

};

class N28_Building{
private:
	vector<Lab*> labs; //vector of labs 
	vector<Lecture_Room*> lecture_rooms; // vector of lecture rooms
public:
	N28_Building(){}

	~N28_Building(){}

	void input_lab(Lab& lab){
		labs.push_back(&lab);
	}

	void input_room(Lecture_Room& room){
		lecture_rooms.push_back(&room);
	}

	void showAllLabs(){
		cout<<"Show all Labs:\n";
		for(auto it: labs){
			cout<<"Lab "<<it->get_labName()<<" "<<it->get_capacity()<<" Capacity"<<endl;
		}
	}

	void showAllLectureRooms(){
		cout<<"Show all lecturers room: \n";
		for(auto it: lecture_rooms){
			cout<<it->get_roomName()<<" "<<it->get_roomNo()<<" "<<it->get_capacity()<<" Capacity"<<endl;
		}
	}
};