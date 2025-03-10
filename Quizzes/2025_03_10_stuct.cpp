#include<iostream>
using namespace std;

struct WeatherData{
    double temperature;
    double humidity;
    double windVelocity;
};  // don't forget the `;`

void displayWD( WeatherData x );

int main(){
    // // error: cannot use dot operator on a type
    // // WeatherData is the type
    // // can only do `.temperature` on an instance of the type
    // WeatherData.temperature = 42;

    WeatherData wd1;
    // double can take an int fine
    wd1.temperature = 45;
    // can obviously it can take a double
    wd1.humidity = 3.14;
    // can use stod sTRING to dOUBLE over a string...
    wd1.windVelocity = stod( "6.28" );
    displayWD( wd1 );
    return 0;
}

void displayWD( WeatherData x )
{
    // sorry \n may not work on windows...
    // but it's like endl but quicker
    cout << "WeatherData: {\n\ttempurature: " << x.temperature
            << ",\n\thumidity: " << x.humidity
            << ",\n\twindVelocity: " << x.windVelocity
            << "\n}" << endl;
}

