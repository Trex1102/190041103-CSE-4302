#include "103_Task02.h"
using namespace std;

int main()
{
	N28_Building n28;
	Lab lab1("MPK1", 60), lab2("MPK2", 60), lab3("MPK3", 60);
	n28.input_lab(lab1);
	n28.input_lab(lab2);
	n28.input_lab(lab2);

	Lecture_Room r1("Hafiz" ,102 , 3), r2("Shafie" , 105, 3);
	n28.input_room(r1);
	n28.input_room(r2);

	cout<<"Welcome to N28 Building\n";
	n28.showAllLabs();
	n28.showAllLectureRooms();
}