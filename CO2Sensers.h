#include <iostream>
#include <random>

class CO2Sensers{
private:
    double _persent;

    void UpDate(){
        double del = -10 + rand()%20;
        _persent += del / 10;
        if(_persent > MAX_PERCENT){
            _persent = MAX_PERCENT;
        }else if(_persent < 0){
            _persent = 0;
        }
    }

public:
    const double MAX_PERCENT = 100;

    CO2Sensers(){
        _persent = rand() % static_cast<int>(MAX_PERCENT);
    }

    double operator()(){
        UpDate();
        return _persent;
    }
};