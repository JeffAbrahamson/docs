"Blink" in Arduino
==================

The typical tutorial for learning new tools is a "Hello World" one. In Arduino, the typical first example is the LED "blink" one.
This example shows how to build a simple *blink* functionality with biicode that you can automatically integrate in
any project.

Remember that you need to :ref:`configure your biicode workspace <arduino_installation>` with CMake, MinGW and the Arduino SDK.

1. Create a new hive
--------------------

The first step is to create a new hive (a biicode project) inside your workspace with the ``bii new`` command.

.. code-block:: bash

   $ bii new arduino_blink_hive

The system will prompt you for your hive initial programming language, you can select among several options.
Select ``arduino`` here.

It will also prompt for your first block name. A block is a working unit you can publish and navigate in the web.
You can have more than one block in your hives, but now lets start with just one. Enter a descriptive name,
something that summarizes the functionality of all the files that will be in that block. Enter ``arduino_blink``.

Last, it will prompt to generate a default firmware, i.e. a code file with a setup() and loop() functions.
You can press ENTER to accept the default option here: ``yes``.

.. code-block:: bash

   Select language: (java/node/fortran/python/cpp/arduino/None)
   Introduce lang (default:None): arduino
   How would you like to name your first block?
   Introduce block name: arduino_blink
   Generate a default firmware?  (YES/no) [ENTER]

This command will create the following layout:

.. code-block:: text

   |-- arduino_blink_hive
   |    +-- bin
   |    +-- blocks
   |    |     +-- username
   |    |    |     +-- arduino_blink
   |    |    |     |       +-- main.cpp
   |    +-- build
   |    +-- cmake
   |    +-- deps
  

You can open the file **main.cpp** in your favorite editor.
biicode uses the ``// bii:#entry_point()`` comment line to define **main.cpp** like the starting point for your firmware.
Put **this comment in all** files you want to be **Arduino firmwares**, typically those files with a setup() and loop() functions.

.. literalinclude:: ../_static/code/arduino/hello-world/main_arduino.cpp
   :language: cpp
   :emphasize-lines: 15
		
2. Build and upload
-------------------

Now, you can build your firmware and upload it to your Arduino with the command ``arduino:upload``.
If you only want to build your firmware, just use ``arduino:build``.

.. code-block:: bash

	$ cd arduino_hive
	$ bii arduino:upload
	...
	Writing | ################################################## | 100% 0.00s

**Thats it!** Your board LED should start blinking. Try changing blink delay values in code and upload again.

.. container:: infonote

   The previous example will work with your default settings configured during the installation. If you need
   you can change your hive settings.bii file (**arduino_hive/bii/settings.bii**) with the info about your board and serial port.
   Here is a Windows example:

   .. code-block:: text

      arduino:
         board: {board: mega2560, no_autolibs: 'false', port: COM7, programmer: usbtinyisp}

   If you want to remember how to configure your settings:

      *  :ref:`Arduino settings in MacOS<arduino_default_settings_mac>`
      *  :ref:`Arduino settings in Linux<arduino_default_settings_linux>`
      *  :ref:`Arduino settings in Windows<arduino_default_settings_win>`

3. Creating reusable code
-------------------------

There is a problem with the above example. The use of ``delay()`` halts the execution flow of arduino, so if you want, for example, to control a motor, process serial port inputs, or whatever other work you have to do, you **cannot use** the previous blink version, as it holds execution.

The following code uses the method ``millis()`` and 2 control variables to count the elapsed time
and switch the LED accordingly. Replace the previous example code with the next files:
	
**blink.h**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.h
   :language: cpp
   :linenos:

**blink.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/blink.cpp
   :language: cpp
   :linenos:

**mainblink.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/mainblink.cpp
   :language: cpp
   :linenos:

You can download these files here: :download:`blink.zip <../_static/code/arduino/hello-world/blink.zip>`

Upload the new version to your arduino again and check that it works ok!

4. Publish your code
--------------------

You can easily publish your code using the ``bii publish`` command. You will be requested to provide a **tag** and a **message**. Valid tags are ``STABLE``, ``ALPHA``, ``BETA``, and ``DEV``. They provide information about the development state of your hive. The message is any information describing your publication. You can :ref:`read more about publishing here <biipublish>`.

.. code-block:: bash

	$ bii publish                                                            

	block:   username/arduino_blink
	Introduce tag: STABLE                                                           
	Introduce msg: My first arduino project with biicode                            
	
	INFO: Successfully published username/arduino_blink(username/master): 0


If your code has been published correctly —as it is the case in the previous example—, you can navigate it visiting the **www.biicode.com/username**, being *username* your biicode user name.

5. Reuse it!
------------

Reusing your ``blink`` files in other projects is straightforward. 

First, create insed your workspace a new hive with name ``arduino_reuse_blink``, with a default firmware, and a block named for example ``arduino_reuse_blink`` (the block can be named the same as the hive, no problem):

.. code-block:: bash

   $ bii new arduino_reuse_blink

Then modify the main.cpp file with the following code and substitute your own user name in the #include directive.
	
**main.cpp**

.. literalinclude:: ../_static/code/arduino/hello-world/main_reuse.cpp
   :language: cpp
   :linenos:
   :emphasize-lines: 1, 7


When you reference, or put #includes to files that have been published before, it is necessary to retrieve them.
Run ``find`` to resolve external dependencies, so the blink files are retrieved.

.. code-block:: bash

	$ bii find

You should see a success message. You can also explore your hive/deps folder to check that you have there a copy of the blink files.

.. container:: infonote

   Although you have probably run this latter hive in the same computer as the above, you can do it
   in any other computer. Biicode hosts your code for you, and serves as a central location or repository
   where you can maintain and share your code, and recover it just with a simple #include in your
   projects. No need to manually handle files any more!

Now, you can ``upload`` in your arduino as usual (don't forget to set your arduino settings in this new hive if necessary).

.. code-block:: bash

	$ bii arduino:upload

Congratulations! Your blink files have been successfully reused!

**Now you might be interested in:**

   - If something went wrong, you might want to search for `help in the forum <http://forum.biicode.com>`_, and open a new topic if necessary.
   - Seeing :ref:`more arduino examples <arduino>`
   - What happens if I modify my blink files in the original hive? Read about :ref:`publishing new versions <biipublish>` and :ref:`updating <dependencies>`
   - I don't want to publish my block, as it doesn't work yet, but I want to save my hive for continuing later in a different computer. :ref:`Read here to check how <hive_usage>`.
