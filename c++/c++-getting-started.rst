.. _cpp_getting_started:

Getting Started
===============

This example shows **how to install biicode and code a C++ test with GTest**. You don't need to have installed GTest, biicode will download and configure it automatically for you.

You will learn how to use the ``gtest.h`` file of the ``gtest`` block owner of ``google`` with the code line ``#include "google/gtest/gtest.h"`` .

1. Installing biicode and C/C++ tools
-------------------------------------

To reuse code, you need to install biicode and a group of external tools (CMake and MinGW, Visual Studio or GCC).

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

To create a new project run ``bii init <project_name>`` with the project name as a parameter.

.. code-block:: bash

   ~$ bii init cpp_hello_project

This command will create the following layout:

.. code-block:: text

   |-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, we will create a block. A block is the place where you must place your code. Execute ``bii new anonymous/my_fist_block`` into the project folder to create a block.

.. code-block:: bash

   ~$ cd cpp_hello_project
   ~/cpp_hello_project$ bii new anonymous/my_first_block --hello=cpp

This command will create the following layout:

.. code-block:: text

   +-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    |    +-- anonymous
   |    |    |    +-- my_first_block
   |    |    |    |    +-- main.cpp
   |    +-- deps

.. container:: infonote

    **What is the reason behind this layout?**

    This layout is enforced because biicode analyzes the dependencies of your blocks and downloads them into de deps folder. It is important because biicode configures and build your project following this layout.

    For this reason, all the code you want to be analyzed must be placed into a block inside the blocks folder.

    The structure of these blocks is composed by two parts, the owner (username) and the block name. In this example we use an anonymous user, but if you want to publish your own blocks in the future, you will need to register and user your username.

    If you want to change the user of a block into your blocks folder, just change the name of the owner folder where this block lies.

3. Resolve your dependencies
----------------------------

Now, edit your main.cpp file with the following code and execute ``bii find``. With this command, all your dependencies will be downloaded.

**main.cpp**

.. code-block:: cpp
   :emphasize-lines: 1

   #include "google/gtest/gtest.h"
   int sum(int a, int b) {return a+b;}
   TEST(Sum, Normal) {
     EXPECT_EQ(5, sum(2, 3));
   }
   int main(int argc, char **argv) {
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
   }

.. code-block:: bash

   ~/cpp_hello_project$ bii find

Now, execute ``bii cpp:build`` and biicode will configure your project and compile your code into the bin folder.

.. code-block:: bash

   ~/cpp_hello_project$ bii cpp:build
   ~/cpp_hello_project$ cd bin
   ~/cpp_hello_project/bin$ #execute your test

And that's all. Your program is working, you can go to the bin folder and execute it!
