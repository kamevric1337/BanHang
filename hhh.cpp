#include<iostream>
#include<string>
using namespace std;
class Vehicle{
  
  string Make;
  string Color;
  int Year;
  
  protected:
  string Model;
  
  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
  }
};

class Car: public Vehicle{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string mk, string col, int yr, string mdl, string ts){
    trunk_size = ts;
  }

  void car_details(){
    cout << "Trunk size: " << trunk_size << endl;
    cout << "Model: " << Model << endl;
  }
};

int main(){
  Car car;
  // car.Year = 2000;
   //car.Model = "Accord";
  
 // car.car_details();
  //car.print_details();
}