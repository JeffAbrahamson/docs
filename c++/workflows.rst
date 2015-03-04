.. _cpp_workflows:

Workflows
==========

.. _workflows_own_blocks:

Working with your own blocks
------------------------------

In the :ref:`Getting Started guide <cpp_getting_started>` we built a program and reused the **sum function**. Now it's time to add new functionality to your published **myuser/math** block, like a **subtract function**, and use it in your block **myuser/calc**.

The layout is:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    +-- deps
  |    |    +-- myuser
  |    |    |    +-- math
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h

Opening your block
^^^^^^^^^^^^^^^^^^^
Open the block **myuser/math** for editing on the same project, execute:

.. code-block:: bash

  ~/mycalc$ bii open myuser/math

``bii open command`` retrieves the complete block to your ``blocks`` folder, and deletes it from your ``deps`` folder.
In this case, it will open the specific version you depend on. 

The resulting layout is:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Now, add the new function, **subtract** and use it on your main.cpp

**operations.h**

.. code-block:: cpp

   #pragma once
   int sum(int a, int b);
   int subtract(int a, int b);

**operations.cpp**

.. code-block:: cpp

   #include "operations.h"
   int sum(int a, int b) {return a+b;}
   int subtract(int a, int b){return a-b;}


**main.cpp**

.. code-block:: cpp

   #include "google/gtest/gtest.h"
   #include "operations.h"
   
   TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
   }
   TEST(Subtract, Normal) {
    EXPECT_EQ(-1, subtract(2, 3));
   }
   int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
   }


Build, ``bii cpp:build`` and run your tests ``myuser_math_main`` to check everything is working.


Publishing updated code
^^^^^^^^^^^^^^^^^^^^^^^

Publish the math block again. As you now have 2 blocks opened (calc, math), specify the name of the block you want to publish:

.. code-block:: bash

   ~/mycalc$ bii publish myuser/math

By default, ``bii publish`` uses the DEV tag. Check on your online biicode profile it's been published.

Using ``DEV`` tag, the latest ``DEV`` version is overrided, so ``[parents]`` section of your **biicode.conf**  remains unmodified:

.. code-block:: text

  [parent]
     myuser/math: 0


Closing edited block
^^^^^^^^^^^^^^^^^^^^

You can now close **myuser/math** block, it and it will return, with the code already updated, to your ``deps`` folder:

.. code-block:: bash

   ~/mycalc$ bii close myuser/math


Then you can modify the content of your **myuser/calc**:

**main.cpp**

.. code-block:: cpp
   
   #include <iostream>
   #include "myuser/math/operations.h"
   
   using namespace std;
   int main() {
      cout<<"2 + 3 = "<< sum(2, 3)<<endl;
      cout<<"2 - 3 = "<< subtract(2,3)<<endl;
   }


and build it, reusing also the new function:

.. code-block:: bash

   ~/mycalc$ bii cpp:build
   ~/mycalc$ bin\myuser_calc_main
   2 + 3 = 5
   2 - 3 = -1

Congrats! You just edited your dependencies and updated the changes. 
You know that we are available at |biicode_forum_link| for any problems.
You can also |biicode_write_us| for suggestions and feedback, they are always welcomed.

.. _workflows_any_block:

Working with any published block
---------------------------------

To **edit a published block**, follow the steps below:

Open a block
^^^^^^^^^^^^

Open a block locally to modify and publish a new version of a block.

.. code-block:: bash

  ~/$ bii init myproject
  ~/$ cd myproject
  ~/myproject$ bii open username/blockname:VERSION


**Example**

Let's open |example_block| (version=lastest by default) to edit it:

.. |example_block| raw:: html

   <a href="http://www.biicode.com/lasote/json11" target="_blank">lasote/json11 block</a>

.. code-block:: bash

  $ bii open lasote/json11 

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose that you want to open version ``1`` instead of the latest ``lasote/json11`` version, you should execute: 

.. code-block:: bash

  $ bii open lasote/json:1


Publish the changes
^^^^^^^^^^^^^^^^^^^

Once your changes build, publish your own version of the block. 

If **the block in edition isn't yours**:

  * Rename **lasote** folder with your **username**. 
  * Delete the ``[parents]`` section content in your **biicode.conf** file.

.. container:: infonote

    Remember to ``bii cpp:build`` before publishing!

And publish:

.. code-block:: bash

  $ bii publish  

.. container:: infonote
  
  Check :ref:`bii:publish command<bii_publish_command>` to know more.

Close the block
^^^^^^^^^^^^^^^

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

  $ bii close user_name/block_name

If you're following the **Example**, execute:

.. code-block:: bash

  $ bii close user_name/json11


Depend on the block you've just published
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Now, if you want to depend on the block you've just published:

  * Update your #include (s) to the ones referring to your new published version
  * If you didn't publish it as STABLE, do it or update your :ref:`policies.bii <policies>` file to accept DEV versions.
  * Execute ``bii find`` and you're ready to build as usual. Here's :ref:`bii find command documentation<bii_find_command>`.


.. container:: infonote

  If you need more information about publish or close command:

  * :ref:`Publish command <bii_publish_command>`
  * :ref:`Close command <bii_close_command>`

.. _git_workflows:

Git: Versioning your code
-------------------------

The natural way to work is maintaining a correspondence between a *biicode block* and a *Git repository*.
Just go to your block folder (**calc** and **math** if you followed the getting started) and initialize a new git repository.

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Go to the block's folder and initialize the git repository. Then add the changes to index and commit them:

.. code-block:: bash

  $ cd mycalc/blocks/myuser/calc
  $ git init .
  $ git add .
  $ git commit -m "Added new operation to operations.cpp"

You can also add a remote repository:

.. code-block:: bash

  $ git remote add origin https://github.com/user/repo.git

And push your commits: 

.. code-block:: bash

  $ git push origin master


.. container:: infonote
    
  You can learn more about adding remote repositories on |github_remote| or on|bitbucket_remote|
  Each computer may need their specific project settings, and the you can regenerate all build layout with ``bii cpp:configure`` or ``bii cpp:build`` command. 

As usual, you can publish your code to biicode when you want to, generally when you have a version to share.

.. code-block:: bash

  $ bii publish

That's all! Now you have your code under version control.

**Ignoring files**

Maybe you want to have all files on git, but there are some files you don't want to publish to biicode.
Use :ref:`ignore.bii file<ignore_bii>` to specify which files should be ignored and not published to biicode.


Git and any published blocks
----------------------------

In previous sections, it's explained how to work with any published block just using biicode (you would run ``bii open`` command). 

Well, that's still available, but when working with Git, it's best to ``clone`` the github repository.

Let's see an example:

User ``mike`` has pushed to github and published a block named ``mike/math`` to biicode. 
He was working at home, with Linux.

Next day Mike wants to develop further his block at work, with Windows.
If Mike executes ``bii open`` the source code is not a github repository, is only a copy of his block in biicode. 
So Mike should better init a new biicode project and run:

.. code-block:: bash

  $ bii init work_project
  $ cd work_project
  $ bii new mike/math
  $ cd blocks/mike/math
  $ git clone https://github.com/mike_on_github/math.git .

Now Mike has the github repository to continue developing his biicode block under a control version system.
From now on, Mike just needs to make ``git pull`` command to fetch and merge the remote changes.

Git repos with biicode support
-------------------------------

Take a git repo that also is a biicode block (for example: https://github.com/bamos/cpp-expression-parser) and build locally just doing:

.. code-block:: bash

  ~$ git clone https://Your_Repo_URL.git
  ~$ cd your_repository
  ~/your_repository$ bii init -l simple

Make sure the ``[parents]`` section of the ``biicode.conf`` file is empty or delete its content and:

.. code-block:: bash

  ~$ bii cpp:build

And this is it.

.. container:: infonote

    Here's how to :ref:`create a biicode block from a git repo <cpp_block_git>`

Check our |biicode_forum_link| and/or |biicode_stackoverflow_link| for questions and answers. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>

.. |biicode_write_us| raw:: html

   <a href="mailto:support@biicode.com" target="_blank">write us</a>

.. |biicode_stackoverflow_link| raw:: html

   <a href="http://stackoverflow.com/questions/tagged/biicode" target="_blank">StackOverflow tag</a>

.. |github_homepage| raw:: html

   <a href="https://github.com/" target="_blank">GitHub</a>

.. |bitbucket_homepage| raw:: html

   <a href="https://bitbucket.org/" target="_blank">Bitbucket</a>

.. |github_remote| raw:: html
    
    <a href="https://help.github.com/articles/adding-a-remote/" target="_blank">github here</a>

.. |bitbucket_remote| raw:: html
    
    <a href="https://confluence.atlassian.com/display/BITBUCKET/Create+a+repository" target="_blank">bitbucket docs</a>

**Got any doubts?** Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.

