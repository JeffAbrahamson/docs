.. _first_steps:

Installation
============

This section describes the **first basic steps that are mandatory in order to use the biicode technology on any computer**, regardless the target platform (desktop, raspberry Pi, Arduino…) or operating system.

.. _download_client_binaries:

1. Download Biicode Installer
-----------------------------

Now, `download the appropriate installer for your development platform <https://www.biicode.com/downloads>`_, execute the setup program and follow the instructions.

**Biicode is an evolving technology**, and many modifications and improvements are introduced weekly with our releases. Rememeber to check frequently for new versions of the client, consult the :ref:`release notes <changelog>`.


.. _alternative_install_debian:

.. container:: infonote


    **Alternative install for Debian based distributions (Ubuntu, Raspbian)**

    You can use the ``apt-get`` program for installing biicode using our APT repository:

    Quick install: 

    .. code-block:: bash

        wget http://apt.biicode.com/install.sh && chmod +x install.sh && ./install.sh


    Step by step install:

    .. code-block:: bash

        # 1. Add this line to your /etc/apt/sources.list file
        deb http://apt.biicode.com/debian/ stable non-free
        
        # 2. Add our public key executing:
        wget -qO- http://apt.biicode.com/packages.biicode.key | sudo apt-key add -
        
        # 3. Execute apt-get update:
        sudo apt-get update 
        
        # 4. Execute apt-get install: 
        sudo apt-get install biicode


2. Choose the development tools
--------------------------------

Finally, **you may need to install some additional tools dependending on your development language**. Select your language from the list bellow. You will be redirected to the specific documentation section for that particular language, where you will find more information and resources. Don't forget to come back to this general section, and learn more about :ref:`advanced features <advanced_features>`.


.. container:: todo

    * :ref:`C/C++ Getting Started <cpp_getting_started>`
    * :ref:`Arduino Getting Started <arduino_getting_started>`
    * :ref:`Raspberry Pi (cross compiling) Getting Started <rpi_getting_started>`
    * :ref:`Node.js Getting Started <node_getting_started>`