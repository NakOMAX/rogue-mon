#ifndef POKE_EVE_H
#define POKE_EVE_H

class Event{
public:
  Event(int layer);
  ~Event();
  short int init();
  short int run();
  short int getLayer();
  short int getEventType();
protected:
  /** @brief layer in the map, 0 means top layer */
  int layer;
  /** @brief */
  int eventType;
};

class Boss : public Event{

};

#endif
