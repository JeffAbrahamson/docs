IDE configuration
=================

Biicode offers integration with `Eclipse <https://www.eclipse.org/downloads/>`_ for Arduino programmers. It is able to do the appropriate project setup on your behalf. This way you can work on your biicode project, using the underlying infrastructure and services provided by Eclipse. In fact, this configuration can be established from the very first momment, when you create a new project with the ``bii init`` command (see the :ref:`commands reference <bii_init_command>` for more information).

This section details the steps you should follow to achieve this integration.

First of all, you need to configure your project for **Eclipse IDE for C/C++**. If you already did so when creating the project with the help of the ``bii init`` command, you can skip this section. Otherwise, you can define your preferences in your Arduino configure with ``arduino:configure``:

.. code-block:: bash

	$ bii arduino:configure -G "Eclipse CDT4 - MinGW Makefiles"



If you have successfully configured your project as in the previous example, your are ready to import your project into the Eclipse IDE. It is important that you use a version of Eclipse that contains the C/C++ Toolkit. So we recommend using `Eclipse IDE for C/C++ Developers <https://www.eclipse.org/downloads/>`_.

How to import your project
--------------------------

#. From the main Eclipse menu choose: *File > import...*
#. Now, select *general > Existing Projects into Workspace*, and clic next.
#. Select the root directory as the **root folder of your project**.
#. You should see a project already selected in the *projects* box. Click *finish*.

If you want to add new files to your block, just right-click on the folder of your block and create a new file.

**Note:** If you add new dependencies to your project you'll need to manually invoke ``bii find``.

You can build your application in *Project > Build project* if you don't have automated builds set.

If you are using **Mac** as developing platform, you will need some aditional setup:

#. Right-click on your project and select *Properties*.
#. Select *C/C++ Make project* and click on the *Binary Parser* subsection tab.
#. Unselect Mach-O Parser (deprecated).
#. Select Mach-O 64 Parser.
#. Click *OK*.

And this is all you need to work as usual with the Eclipse IDE.
