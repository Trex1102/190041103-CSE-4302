#include <iostream>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <process.h>
using namespace std;
const int LEN = 32;  
const int MAX = 100;

enum doctor_type{
    indoor,outdoor
};

class Doctor
{
private:
    char firstName[LEN];
    char lastName[LEN];
    char speciality[LEN];
    static int n;
    static Doctor *list[MAX];

public:
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout << " Enter First name : ";
        cin >> firstName;
        cout << " Enter Last name : ";
        cin >> lastName;
        cout << " Enter Speciality : ";
        cin >> speciality;
    }
    virtual void putdata()
    {
        cout << "\n Name : " << firstName<<' '<<lastName;
        cout << "\n Speciality : " << speciality;
    }
    virtual doctor_type get_type();
    static void add();                
    static void display();            
    static void read();               
    static void write();              
};
int Doctor::n;
Doctor *Doctor::list[MAX];


class Indoor: public Doctor
{
private:
    int chamberNO;
    int fees;

public:
    void getdata()
    {
        Doctor::getdata();
        cout << " Enter Chamber No : ";
        cin >> chamberNO;
        cout << " Enter fees : ";
        cin >> fees;
    }
    void putdata()
    {
        Doctor::putdata();
        cout << "\n Chamber No : " << chamberNO;
        cout << "\n Fees : " << fees;
    }
  
};

class Outdoor: public Doctor
{
private:
    int gateNO;
    int fees;

public:
    void getdata()
    {
        Doctor::getdata();
        cout << " Enter Gate No : ";
        cin >> gateNO;
        cout << " Enter fees : ";
        cin >> fees;
    }
    void putdata()
    {
        Doctor::putdata();
        cout << "\n Gate No : " << gateNO;
        cout << "\n Fees : " << fees;
    }
  
};

doctor_type Doctor::get_type()
{
    if (typeid(*this) == typeid(Indoor))
        return indoor;
    else if (typeid(*this) == typeid(Outdoor))
        return outdoor;
    else
    {
        cerr << "\nBad Doctor type";
        exit(1);
    }
}

void Doctor::add()
{
    char ch;
    cout << "'o' to add outdoor"
    "\n'i' to add a indoor"
    "\nEnter selection : ";
    cin >> ch;
    switch (ch)
    { //create specified Doctor type
    case 'o':
        list[n] = new Outdoor;
        break;
    case 'i':
        list[n] = new Indoor;
        break;
    default:
        cout << "\nUnknown Doctor type\n";
        return;
    }
    list[n++]->getdata();
}

void Doctor::display()
{
    for (int j = 0; j < n; j++)
    {
        cout << (j + 1);              
        switch (list[j]->get_type())
        {
        case indoor:
            cout << ".Type : Indoor";
            break;
        case outdoor:
            cout << ".Type : Outdoor";
            break;
        default:
            cout << ".Unknown type";
        }
        list[j]->putdata();
        cout << endl;
    }
}

void Doctor::read()
{
    int size;            
    doctor_type etype;
    ifstream inf;       
    inf.open("DOCTOR.DAT", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    { 
        inf.read((char *)&etype, sizeof(etype));
        if (inf.eof()) 
            break;
        if (!inf)
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype)
        {              
        case indoor: 
            list[n] = new Indoor;
            size = sizeof(Indoor);
            break;
        case outdoor:
            list[n] = new Outdoor;
            size = sizeof(Outdoor);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } 
        inf.read((char *)list[n], size);
        if (!inf) 
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++; 
    }        
    cout << "Reading " << n << " Doctors\n";
}

void Doctor::write()
{
    int size;
    cout << "Writing " << n << " Doctors.\n";
    ofstream ouf;
    doctor_type etype; 
    ouf.open("DOCTOR.DAT", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++) //for every Doctor object
    {                           //get its type
        etype = list[j]->get_type();
        //write type to file
        ouf.write((char *)&etype, sizeof(etype));
        switch (etype) //find its size
        {
        case indoor:
            size = sizeof(Indoor);
            break;
        case outdoor:
            size = sizeof(Outdoor);
            break;
        }
        ouf.write((char *)(list[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}

int main()
{
    char ch;
    while (true)
    {
        cout << "'a' -- add data for an Doctor"
                "\n'd' -- display data for all Doctors"
                "\n'w' -- write all Doctor data to file"
                "\n'r' -- read all Doctor data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a':
            Doctor::add();
            break;
        case 'd':
            Doctor::display();
            break;
        case 'w':
            Doctor::write();
            break;
        case 'r':
            Doctor::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        }
    }     
    return 0;
}