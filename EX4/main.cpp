#include <iostream>
#include <string>

using namespace std;

class car{
    private:
    string m_DriveMode;
    int m_MaxSeating;
    int m_price;
    void m_UpdatePrice(int base = 50000){
        m_price = m_MaxSeating * base;
    }
    
    public:
    string m_brand;
    string m_model;
    int m_year;

    int get_MaxSeating(){
        return m_MaxSeating;
    }
    int get_Price(){
        return m_price;
    }
    
};

class BMW_Car : public car {
    private:
    string m_DriveMode;
    
    public:
    string m_brand = "BMW";
    BMW_Car (string y, int z, int s) {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
    }
    
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Audi_Car : public car {
    private:
    string m_DriveMode;
    
    public:
    string m_brand = "Audi";
    Audi_Car (string y, int z, int s){
        cout << "Constructing Audi_Car\n";
        m_DriveMode = "Front-wheel";
    }
    
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Benz_Car : public car {
    private:
    string m_DriveMode;
    
    public:
    string m_brand = "Benz";
    Benz_Car (string y, int z, int s){
        cout << "Constructing Benz_Car\n";
        m_DriveMode = "Front-wheel";
    }
    
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){
    BMW_Car car_1("x5", 2023, 6);
    cout << car_1.m_brand;
    cout << " : Drive Mode = " << car_1.get_DriveMode() << endl;
    
    Audi_Car car_2("A1", 2021, 2);
    cout << car_2.m_brand;
    cout << " : Drive Mode = " << car_2.get_DriveMode() << endl;
    
    Benz_Car car_3("A1", 2021, 2);
    cout << car_3.m_brand;
    cout << " : Drive Mode = " << car_3.get_DriveMode() << endl;
}