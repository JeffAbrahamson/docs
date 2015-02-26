How to use the Arduino Yun
==========================

Download Arduino 1.5
--------------------

Download the **Arduino zip file** `from Arduino download page <http://arduino.cc/en/Main/Software>`_ and unzip it.

Configure your settings
-----------------------

Do **bii arduino:settings** to configure the new SDK path and the board as ``yun``.

**In this example** we have unziped our SDK into ``c:/biicode_env/arduino-1.5.8``.

.. code-block:: bash

	$ bii arduino:settings
	Enter SDK path (/../biicode_env/arduino-1.0.6): c:/biicode_env/arduino-1.5.8
	Enter board (/o list supported options): yun
	Using arduino port: COM13

And that's all. Now you can use your Yun with biicode.
