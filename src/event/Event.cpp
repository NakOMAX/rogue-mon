#include "Event.h"

Event::Event() {
  scaling = 1;
}

Event::Event(int layer) {
  switch (layer) {
    default : scaling = 1;
  }
}

Event::~Event() {
}

short int Event::init() {
  return run();
}

short int Event::getScaling() {
  return scaling;
}

short int Event::run() {
  bool hasFinished = false;
  while (!hasFinished) {
    hasFinished = !hasFinished;
  }
  return 0;
}
