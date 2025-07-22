#include <assert.h>
#include <iostream>
using namespace std;

bool isTemperatureOk(float temperature) {
  return (temperature >= 0 && temperature <= 45);
}

bool isSocOk(float soc) {
  return (soc >= 20 && soc <= 80);
}

bool isChargeRateOk(float chargeRate) {
  return (chargeRate <= 0.8);
}

void printBatteryStatus(float temperature, float soc, float chargeRate) {
  cout 
    << (isTemperatureOk(temperature) ? "" : "Temperature out of range!\n")
    << (isSocOk(soc) ? "" : "State of Charge out of range!\n")
    << (isChargeRateOk(chargeRate) ? "" : "Charge Rate out of range!\n");
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool tempOk = isTemperatureOk(temperature);
  bool socOk = isSocOk(soc);
  bool rateOk = isChargeRateOk(chargeRate);
  
  bool allOk = tempOk & socOk & rateOk;

  if (!allOk) {
    printBatteryStatus(temperature, soc, chargeRate);
  }

  return allOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}

