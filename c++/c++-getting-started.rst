.. _hello_world:

Getting Started
===============

This example shows how to install biicode and code a C++ test with GTest. You don't need to have installed GTest, biicode will download and configure it automatically for you.

1. Installing the Tools
-----------------------

For reuse code, you need to install biicode and a group of external tools (CMake and MinGW or GCC).

   - `Download the biicode installer <https://www.biicode.com/downloads>`_ 
   - Execute ``bii setup:cpp`` in your console and all the C++ tools will be installed automatically.

.. code-block:: bash

   $ bii setup:cpp


2. Create your project
----------------------

To create a new project running ``bii init`` with the project name as a parameter.

.. code-block:: bash

   $ bii init cpp_hello_project
   
This command will create the following layout:

.. code-block:: text

   |-- cpp_hello_project
   |    +-- bii
   |    +-- blocks
   |    +-- deps

Now, we will create a block. a block is the place where you must place your code. To create a block execute ``bii new anonymous/my_fist_block`` into the project folder.

.. code-block:: bash

   $ bii init cpp_hello_project --hello=cpp

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

    **why this?**

    This layout is because biicode analyse the dependencies of yours blocks and download it into de deps folder. It is important because biicode configure and build your project following this layout.

    For this reason, all the code you want to be analyzed must place into a block inside the blocks folder.

    The structure of this blocks is composed by two parts, the user owner and the block name. In this example we use the anonymous user, but if you want to publish your own blocks in the future, you need to create a biicode user and use that user name.


    If you want to change the user of a block into your blocks folder, just change the name folder where are this block.

3. Resolve your dependencies
----------------------------

Now, edit your main.cpp file with the following code and execute ``bii find``.

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

   $ bii find

Now, execute ``bii cpp:build`` and biicode will configure your project and compile your code into the bin folder.
