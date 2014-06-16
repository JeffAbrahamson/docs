Native Getting Started
======================

This example shows **how to install biicode and code a C++ led blink with WiringPi**. You don't need to have installed WiringPi, biicode will download and configure it automatically for you.

You will learn how to use the ``wiringpi.h`` file of the ``wiringpi/wiringpi`` block owner of ``drogon`` with the code line ``#include "drogon/wiringpi/wiringpi/wiringpi.h"`` .

1. Installing biicode and C/C++ tools
-------------------------------------

For reuse code, you need to install biicode and a group of external tools (CMake and MinGW or GCC).

   - Download the biicode installer.

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|Latest version 1.0                                                                                                                                                                                                                                                                                                           |
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+
|`MacOS <https://www.biicode.com/downloads>`_        |`Raspberry Pi <https://www.biicode.com/downloads>`_ |`Ubuntu 32 <https://www.biicode.com/downloads>`_    |`Ubuntu 64 <https://www.biicode.com/downloads>`_    |`Windows <https://www.biicode.com/downloads>`_      |`Devian Wheezy <https://www.biicode.com/downloads>`_|
+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+----------------------------------------------------+


   - Execute ``bii setup:cpp`` in your console and all the C++ tools will be installed automatically.

.. code-block:: bash

   ~$ bii setup:cpp

.. container:: infonote

    If you have any problem installing the C/C++ tools, you can see :ref:`how to install C/C++ tools manually <cpp_installation>`

2. Create your project
----------------------

To create a new project running ``bii init`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init rpi_hello_project
   
This command will create the following layout:

.. code-block:: text

   |-- rpi_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, we will create a block. a block is the place where you must place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd rpi_hello_project
   ~/rpi_hello_project$ bii new anonymous/my_first_block --hello=cpp

This command will create the following layout:

.. code-block:: text

   +-- rpi_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.cpp
   |    +-- deps

.. container:: infonote

    **why this layout?**

    This layout is because biicode analyse the dependencies of yours blocks and download it into de deps folder. It is important because biicode configure and build your project following this layout.

    For this reason, all the code you want to be analyzed must place into a block inside the blocks folder.

    The structure of this blocks is composed by two parts, the user owner and the block name. In this example we use the anonymous user, but if you want to publish your own blocks in the future, you need to create a biicode user and use that user name.


    If you want to change the user of a block into your blocks folder, just change the name folder where are this block.

3. Resolve your dependencies
----------------------------

Now, edit your main.cpp file with the following code and execute ``bii find``. With this command, all your dependencies will be downloaded.

**main.cpp**

.. code-block:: cpp
   :emphasize-lines: 1

   #include "drogon/wiringpi/wiringpi/wiringpi.h"
   #define LED 0
   int main (void){
       wiringPiSetup () ;
       pinMode (LED, OUTPUT) ;
       digitalWrite (LED, HIGH) ; // On
   }

.. code-block:: bash

   ~/rpi_hello_project$ bii find

Now, execute ``bii cpp:build`` and biicode will configure your project and compile your code into the bin folder.

.. code-block:: bash

   ~/rpi_hello_project$ bii cpp:build
   ~/rpi_hello_project$ cd bin
   ~/rpi_hello_project/bin$ #execute your blink

And that's all. Your program is working!