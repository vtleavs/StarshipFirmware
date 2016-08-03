#ifndef _STEPPER_H_
#define _STEPPER_H_

#include <Arduino.h>

class StepperMotor
{
		public:
      StepperMotor():
              position(0),
              absolute_pos(true) {}
			StepperMotor(char s_pin, char d_pin, int pulse, bool polar_):
							step_pin(s_pin), dir_pin(d_pin), pulsewidth(pulse), polar(polar_),
							position(0),
							absolute_pos(true) {}
							
			void step(bool dir);
			void reset() { stepnum = 0; }
			void set_endstop_hit(bool trig) { endstop_hit = trig; }
			
			int get_stepnum() { return stepnum; }
      float get_pos() { return position; }
			int get_pulsewidth() { return stepnum; }
			bool is_absolute() { return absolute_pos; }
      bool is_polar() { return polar; }

      void set_pos(float position);
      void set_pulsewidth(int pw);
			void set_absolute(bool abs_) { absolute_pos = abs_; }
      void set_max_velocity(int vel);
      void set_max_accel(float accel);
      void set_speed_factor(float fact);

      void disable();
      void enable();
			
		private:
			// motor settings
			int pulsewidth; // In microseconds
			int stepnum;
			int max_steps; // max_steps = max_units * steps_per_unit
      int max_velocity;
			float steps_per_unit;
			float position; // stepnum * steps_per_unit
      float speed_factor;
      float max_accel;
			short max_units;
			char step_pin;
			char dir_pin;
			bool endstop_hit;
			bool absolute_pos;
      bool polar;
};

inline void StepperMotor::step(bool dir)
{
		digitalWrite(dir_pin, dir);
		digitalWrite(step_pin, 1);
		delayMicroseconds(pulsewidth);
		digitalWrite(step_pin, 0);
}

inline void StepperMotor::disable()
{
  
}

inline void StepperMotor::enable()
{
  
}

#endif //_STEPPER_H_
