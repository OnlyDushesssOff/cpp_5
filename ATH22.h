#pragma once
#include "TempSensors.h"
#include "HumiditySensors.h"
#include "tuple"

class ATH{
private:
    TempSensors _temp;
    HumiditySensors _hum;

public:
    double GetTemp(){
        return _temp();
    }

    double GetHum(){
        return _hum();
    }

    std::tuple<double, double> operator()(){
        return std::tuple<double, double>(_temp(), _hum());
    }

};