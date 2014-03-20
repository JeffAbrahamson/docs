arduino code's adaptation guide
===============================

1. Simple .ino file
-------------------

**Generals rules**

* Change the file extension from .ino to .cpp, ex. ``sweep.ino`` to ``sweep.cpp``.
* Include the Arduino.h library, ex. ``#include"Arduino.h"``.
* Change the arcuino core library includes to the biicode format, ex. ``Servo.h`` to ``arduino/libraries/servo/servo.h``.
* Put the function prototypes at the code's beginning, ex. ``void servo_loop();``.

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			sweep.ino

		.. code-block:: cpp
			:emphasize-lines: 1,12

			#include <Servo.h>

			void setup()
			{
			}

			void loop()
			{
			  servo_loop(9);
			}

			void servo_loop(int pin) {
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1)
			  {
			    myservo.write(pos);
			    delay(15);
			  }
			}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			sweep.cpp

		.. code-block:: cpp
			:emphasize-lines: 1, 2, 4


			#include "Arduino.h"
			#include <arduino/libraries/servo/servo.h>

			void servo_loop();
			 
			void setup() 
			{ 
			} 
			 
			void loop()
			{
			  servo_loop(9);
			}

			void servo_loop(int pin) {
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1)
			  {
			    myservo.write(pos);
			    delay(15);
			  }
			}



2. multiple .ino files
----------------------

**Generals rules**

* Change the extension to the main file to .cpp and the other to .h, ex. ``sweep.ino`` to ``sweep.cpp`` and ``servo_functions.ino`` to ``servo_functions.h``

.. code-block:: text

   +-- sweep
   |    +-- sweep.ino
   |    +-- servo_functions.ino

.. code-block:: text

   +-- name_you_prefer
   |    +-- sweep.cpp
   |    +-- servo_functions.h

* Include the Arduino.h library, ex. ``#include"Arduino.h"``.
* Change the arcuino core library includes to the biicode format, ex. ``Servo.h`` to ``arduino/libraries/servo/servo.h``.
* Put the function prototypes, if you need, at the code's beginning, ex. ``void servo_loop();``.

.. container:: tabs-section
	
	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			sweep ino project

		sweep.ino

		.. code-block:: cpp

			void setup()
			{
			}

			void loop()
			{
			  servo_loop(9);
			}

		servo_functions.ino

		.. code-block:: cpp
			:emphasize-lines: 1

			#include <Servo.h>

			void servo_loop(int pin) {
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1)
			  {
			    myservo.write(pos);
			    delay(15);
			  }
			}

	.. container:: tabs-item

		.. rst-class:: tabs-title
			
			sweep C/C++ project

		sweep.cpp

		.. code-block:: cpp
			:emphasize-lines: 1

			#include "servo_functions.h"

			void setup()
			{
			}

			void loop()
			{
			  servo_loop(9);
			}

		servo_functions.h

		.. code-block:: cpp
			:emphasize-lines: 1,2

			#include "Arduino.h"
			#include <arduino/libraries/servo/servo.h>

			void servo_loop(int pin) {
			  Servo myservo;
			  myservo.attach(pin);
			  for (int pos = 0; pos <= 180; pos += 1)
			  {
			    myservo.write(pos);
			    delay(15);
			  }
			}