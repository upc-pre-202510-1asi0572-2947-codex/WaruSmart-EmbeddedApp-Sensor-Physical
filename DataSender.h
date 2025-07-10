#ifndef DATA_SENDER_H
#define DATA_SENDER_H

#include <HTTPClient.h>

class DataSender {
public:
    DataSender(const char* serverUrl, const char* apiKey, const char* deviceId, const char* zone);
    void sendData(float soilMoisture, float temperature, float humidity);

private:
    const char* serverUrl;
    const char* apiKey;
    const char* deviceId;
    const char* zone;
};

#endif
