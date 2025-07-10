#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>
#include "Sensor.h"

class DHTSensor : public Sensor {
private:
    DHT dht;
    float lastTemp;
    float lastHumidity;

public:
    static const int TEMP_READING_EVENT_ID = 1;
    static const int HUM_READING_EVENT_ID = 2;
    static const Event TEMP_READING_EVENT;
    static const Event HUM_READING_EVENT;

    /**
     * @brief Constructor del sensor.
     * @param pin GPIO del DHT22.
     * @param handler Event handler opcional.
     */
    DHTSensor(int pin, EventHandler* handler = nullptr);

    float getTemp() const;

    float getHum() const;

    /**
     * @brief Realiza una lectura del sensor y emite eventos.
     */
    void poll();
  
};

#endif
