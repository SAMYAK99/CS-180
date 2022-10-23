#include <iostream>
#include <cmath>
#define G 6371000
#define PI 3.14159265
using namespace std;

enum{altitude = 0, latitude, longitude};

double Haversine(double *p1, double *p2){
    double D;
    //convert latitude and longitude info in degree to radian
    p1[latitude] = p1[latitude]*PI/180;
    p1[longitude] = p1[longitude]*PI/180;
    p2[latitude] = p2[latitude]*PI/180;
    p2[longitude] = p2[longitude]*PI/180;

    //haversine formula to find shortest plane distance between 2 places
    D = G * acos((sin(p1[latitude])*sin(p2[latitude]))+(cos(p1[latitude])*cos(p2[latitude])*cos(p1[longitude]-p2[longitude])));
    D = abs(D);

    return D;
}

//get height difference between 2 position
double Get_heightdistance(double *p1, double *p2){
    double H;
    H = abs(p1[altitude] - p2[altitude]);

    return H;
}

//get distance using basic pythagoras theorem
//   |\ 
//   | \ 
//  H|  \ d(distance)
//   |   \ 
//   |____\ 
//      D(haversine)
double Get_distance(double *p1, double *p2){
    double distance, D, H;

    D = Haversine(p1, p2);
    H = Get_heightdistance(p1, p2);
    distance = sqrt(pow(D, 2)+pow(H, 2));

    return distance;
}

int main(){
    double *ptr1, *ptr2;
    double p1[3], p2[3];
    ptr1 = p1;
    ptr2 = p2;

    cout << "p1 [alt(meter); lat; long]: ";
    cin >> p1[altitude] >> p1[latitude] >> p1[longitude]; 
    cout << "p2 [alt(meter); lat; long]: ";
    cin >> p2[altitude] >> p2[latitude] >> p2[longitude]; 

    double distance;
    distance = Get_distance(ptr1, ptr2);

    cout << "\nDistance: " << distance << " m"<< endl;

    return 0;
}
