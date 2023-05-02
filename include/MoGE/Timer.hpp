#pragma once

namespace momo {
struct Timer {
  float accumulated;
  float ms;
  float sec;
  float min;

  Timer();

  void run(float delta);
  void reset(bool resetAcc = false);
};

struct Alarm : public Timer {
  float alarmTime;
  bool oneTime;

  Alarm();
  Alarm(float at);
  void init(float at);

  bool onAlarm(float delta);

private:
  bool calledOnce;
};
}; // namespace momo
