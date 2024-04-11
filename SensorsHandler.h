#pragma once
#include "HumiditySensors.h"
#include "CO2Sensers.h"
#include "ATH22.h"

class SensorsHandler{
private:
    TempSensors** Temp_array;
    HumiditySensors** Hum_array;
    CO2Sensers** CO2_array;
    ATH** ATH_array;

    size_t Temp_size = 10;
    size_t Hum_size = 10;
    size_t CO2_size = 10;
    size_t ATH_size = 10;

public:
    SensorsHandler(){
        Temp_array = new TempSensors*[Temp_size];
        Hum_array = new HumiditySensors*[Hum_size];
        CO2_array = new CO2Sensers*[CO2_size];
        ATH_array = new ATH*[ATH_size];
    }

    void add_SensorsTemp(TempSensors* temp){
        for(int i = 0; i < Temp_size; i++){
            if(Temp_array[i] == nullptr){
                Temp_array[i] = temp;
                break;
            }
        }
    }

    void add_SensorsHum(HumiditySensors* hum){
        for(int i = 0; i < Hum_size; i++){
            if(Hum_array[i] == nullptr){
                Hum_array[i] = hum;
                break;
            }
        }
    }

    void add_SensorsCO2(CO2Sensers* CO2){
        for(int i = 0; i < CO2_size; i++){
            if(CO2_array[i] == nullptr){
                CO2_array[i] = CO2;
                break;
            }
        }
    }

    void add_SensorsATH(ATH* ATH){
        for(int i = 0; i < ATH_size; i++){
            if(ATH_array[i] == nullptr){
                ATH_array[i] = ATH;
                break;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SensorsHandler& tmp){
        for(int i = 0; i < tmp.Temp_size; i++){
            os << "Temp" << i+1 << ": " << (*tmp.Temp_array[i])() <<std::endl;
        }
        return os;
    }
};

