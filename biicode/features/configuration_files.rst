.. _config_files:

Configuration files
===================

Biicode offers you a set of configuration files across your projects and blocks. These files empower you with full control of how biicode treats your code and dependencies. Some of these files were introduced in the :ref:`project layout section <project_layout>`. They can be grouped in two main categories:

1. **Project-level configuration files**, with ``.bii`` extension, contained in every project ``bii`` folder. These are two files, and are created when executing the ``bii init`` command:
	
	- The ``settings.bii`` file, contains specific information about your project: language, building and running tools, and predefined IDE.
	- The ``policies.bii`` file, which contains rules for downloading your dependencies (specifi branches and versions).

2. **Block-level configuration files**. These files allow a fine control of how biicode process and publishes your source blocks. Block configuration files can be grouped in two categories:

	- Files located inside the block ``bii`` folder. The block configuration ``bii`` folder is not created by default by the biicode client. However, you can create it by yourself (:ref:`see the project layout <project_layout>`) and include the following optional configuration files: ``dependencies.bii``, ``mains.bii``, ``virtual.bii``. The purpose of these files is described bellow.
	- Files located inside your block, but not inside your ``bii`` folder. These are files related with your code file types filtering settings: ``ignore.bii`` and ``types.bii``. As they are hierarchical configuration files (their contents apply to current and descendant folders files), theres is no sense in placing these files inside the block ``bii`` file, as it should not contain source code; just settings.


**All these configuration files are explained in detail in their corresponding subsections**:

.. toctree::
   :maxdepth: 1
   
   settings.bii: Defining your tools and preferences <configuration_files/settings>
   policies.bii: Defining the policies of the code you want to reuse <configuration_files/policies>
   dependencies.bii: Configuring custom file dependencies <configuration_files/dependencies>
   mains.bii: Defining entry points in your code <configuration_files/mains>
   virtual.bii: Defining virtual resources <configuration_files/virtual>
   ignore.bii: Filtering your files <configuration_files/ignore>
   types.bii: Configuring non-standar file extensions <configuration_files/types>
   requirements.bii: Configure the version of your blocks dependencies<configuration_files/requirements>
   parents.bii: Editing your tracking information <configuration_files/parents>
