.. _merge_branches:

Merge branches
=================

How to merge your current branch with a published one, just execute:

.. code-block:: bash

	$ bii merge BLOCK_VERSION


Examples
--------

Merge version ``2`` from block ``user22/math_libs`` and ``master`` branch 

.. code-block:: bash

	$ bii merge user22/math_libs:2


Merge version ``7`` from block ``user22/math_libs`` and ``develop`` branch 

.. code-block:: bash

	$ bii merge user22/math_libs(develop):7


Merge the last version from block ``user22/math_libs`` and ``master`` branch

.. code-block:: bash

	$ bii merge user22/math_libs

Merge the last version from block ``user22/math_libs`` and ``develop`` branch 

.. code-block:: bash

	$ bii merge user22/math_libs(develop)

.. container:: infonote

	Visit the section: :ref:`how to publish branches <publish_branches>`
	And don't doubt on `asking in our forum<http://forum.biicode.com>`_