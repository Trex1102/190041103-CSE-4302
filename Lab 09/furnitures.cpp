#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    
    double getDiscount() const
    {
        return discount;
    }

    double getDiscountedPrice() 
    {
        double r = price - discount;
        return r;
    }

    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof() const
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails(string p_name = "null")=0;
    void getInfo() const
    {
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<discount<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
    }
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bedsize;
public:
    Bed(double p = 0,double d = 0,Material m= Material::Wood, BedSize b= BedSize::Single):
    Furniture(p,d,m), bedsize(b)
    {
        
    }
    void setBedsize(BedSize b)
    {
        bedsize = b;
    }
    string getBedsize()const
    {
        if(bedsize==BedSize::Double){
            return string("Double");
        }
        else if(bedsize==BedSize::SemiDouble){
            return string("Semi-Double");
        }
        else{
            return string("Single");
        }
    }

    void productDetails(string p_name ="null")
    {
        cout<<"Product : Bed"<<endl;
        cout<<"Produce Name: "<<p_name<<endl;
        getInfo();
        cout<<"Bed Size: "<<getBedsize()<<endl;
        cout<<"-------------------------------------------------------"<<endl;
    }
};
enum class SeatNumber{One, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    SeatNumber seatno;
public:
    Sofa(double p = 0,double d = 0,Material m= Material::Wood, SeatNumber s = SeatNumber::One)
    :Furniture(p,d,m), seatno(s)
    {

    }
    void setSeatNumber(SeatNumber s)
    {
        seatno=s;
    }

    string getSeatNumber() const
    {
        if(seatno==SeatNumber::One)
            return string("One");
        else if(seatno==SeatNumber::Two)
            return string("Two");
        else if(seatno==SeatNumber::Three)
            return string("Three");
        else if(seatno==SeatNumber::Four)
            return string("Four");
        else if(seatno==SeatNumber::Five)
            return string("Five");
    }

    void productDetails(string p_name ="null")
    {
       
        cout<<"Product : Sofa"<<endl;
        cout<<"Produce Name: "<<p_name<<endl;
        Furniture::getInfo();
        cout<<"Number of Seat: "<<getSeatNumber()<<endl;
        cout<<"-------------------------------------------------------"<<endl;
    }
};
enum class Door {Two , Three, Four };
class Almirah:public Furniture
{
private:
    Door door;
public:
    Almirah(double p = 0,double d = 0,Material m= Material::Wood, Door _d = Door::Two)
    :Furniture(p,d,m) , door(_d)
    {

    }
    void setAlmirahDoor(Door _d)
    {
        door=_d;
    }
    string getAlmirahDoor() const
    {
        if(door==Door::Two)
            return string("Two");
        else if(door==Door::Three)
            return string("Three");
        else if(door==Door::Four)
            return string("Four");
    }

    void productDetails(string p_name ="null")
    {
        cout<<"Product : Almirah"<<endl;
        cout<<"Produce Name: "<<p_name<<endl;
        Furniture::getInfo();
        cout<<"Number of doors in Almirah: "<<getAlmirahDoor()<<endl;
        cout<<"-------------------------------------------------------"<<endl;
    }

};

bool _sort(Furniture *a, Furniture *b)
{
    return a ->getDiscountedPrice() > b->getDiscountedPrice();
}

void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    sort(furnitures,furnitures+no_of_furnitures, _sort);
}

void del(Furniture *furnitures[], int no_of_furnitures)
{
    for(int i = 0 ; i<no_of_furnitures; i++){
        delete(furnitures[i]);
    }
}

int main()
{
    Furniture* f_list[100];
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,Door::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);
    f_list[2]->setDiscount(30);
    cout<<"-------------------------------------------------------"<<endl;
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    
    cout<<"Sorting:-----------------------------------------------"<<endl;

    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    del(f_list, 4);
}
