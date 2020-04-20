#include "accel_designer.h"

#include <fstream>
#include <iostream>

void printCsv(const std::string &filebase, const ctrl::AccelDesigner &ad) {
  std::cout << ad << std::endl;
  const float Ts = 0.0001f;
  std::ofstream of;
  const auto ticks = ad.getTimeStamp();
  float t = 0;
  for (size_t i = 0; i < ticks.size(); ++i) {
    of = std::ofstream(filebase + "_" + std::to_string(i) + ".csv");
    while (t + Ts < ticks[i]) {
      of << t;
      of << "," << ad.j(t);
      of << "," << ad.a(t);
      of << "," << ad.v(t);
      of << "," << ad.x(t);
      of << std::endl;
      t += Ts;
    }
  }
}

int main(void) {
  ctrl::AccelDesigner ad;
  ad.reset(100, 10, 0, 4, 2, 4);
  // ad.reset(1000, 10, 0, 4, 2, 4);
  // ad.reset(100, 1, 0, 4, 2, 4);
  // ad.reset(100, 10, 0, 4, 2, 0.4);
  // ad.reset(100, 10, 0, 4, -2, -0.4);

  printCsv("accel", ad);

  return 0;
}
