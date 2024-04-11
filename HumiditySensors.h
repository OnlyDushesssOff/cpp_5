#include <random>
#include <iostream>

class HumiditySensors{
private:
    double _humidity;

    void UpDate(){
        double del = -10 + rand() % 20;
        _humidity += del / 10;
        if(_humidity > MAX_HUMIDITY){
            _humidity = MAX_HUMIDITY;
        }else if(_humidity < 0){
            _humidity = 0;
        }
    }

public:
    const double MAX_HUMIDITY = 100;

    HumiditySensors(){
        _humidity = rand() % static_cast<int>(MAX_HUMIDITY);
    }

    double operator()(){
        UpDate();
        return _humidity;
    }
};