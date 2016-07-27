#ifndef _STEPPER_H_
#define _STEPPER_H_

#include <Arduino.h>

class Stepper
{
		public:
			Stepper(char s_pin, char d_pin, int pulse):
							step_pin(s_pin), dir_pin(d_pin), pulsewidth_micro(pulse);
							
			void step(bool dir);
			void reset() { stepnum = 0; }
			void set_endstop_hit(bool trig) { endstop_hit = trig; }
			
			int get_stepnum() { return stepnum; }
			int get_pulsewidth() { return stepnum; }
			
		private:
			// motor settings
			int pulsewidth; // In microseconds
			int stepnum;
			int max_steps; // max_steps = max_units * steps_per_unit
			float steps_per_unit;
			float position; // stepnum * steps_per_unit
			short max_units;
			char step_pin;
			char dir_pin;
			bool endstop_hit;
}

inline void Stepper::step(bool dir)
{
		digitalWrite(d_pin, dir);
		digitalWrite(s_pin, 1);
		delayMicro(pulsewidth_micro);
		digitalWrite(s_pin, 0);
}

#endif //_STEPPER_H_
