#include <iostream>
#include "TempSensors.h"
#include "HumiditySensors.h"
#include "CO2Sensers.h"

int main(){   
    srand(time(NULL));

    TempSensors temp1;
    std::cout << "Temperature: "<< temp1() << std::endl;

    HumiditySensors hum1;
    std::cout << "Humidity: " << hum1() << std::endl;

    CO2Sensers co1;
    std::cout << "CO2: " << co1() << std::endl;
}