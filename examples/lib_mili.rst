MiLi
====

MiLi is a collection of useful C++ libraries, composed only by headers. For more information about this library, visit their `official website <https://code.google.com/p/mili/>`_ or `wiki <https://code.google.com/p/mili/w/list>`_ 

You can find here the `MiLi biicode library site <https://www.biicode.com/danielgutson/blocks/danielgutson/mili/branches/master>`_ .

The following example shows a simple use for doing type-safe bitwise operations. You can find this and other examples in `the biicode MiLi samples block <https://www.biicode.com/danielgutson/blocks/danielgutson/milisamples/branches/master>`_ .

.. code-block:: cpp
	:linenos:

	/*bitwise_enums: A minimal library for doing type-safe bitwise operations.
	This file is part of the MiLi Minimalistic Library.

	Copyright (C) Daniel Gutson, FuDePAN 2008-2009
				  Adrian Remonda FuDePAN 2011
	Distributed under the Boost Software License, Version 1.0.
	(See accompanying file LICENSE_1_0.txt in the root directory or 
	copy at http://www.boost.org/LICENSE_1_0.txt)

	MiLi IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
	SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
	FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
	ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	DEALINGS IN THE SOFTWARE.

	This is an example file.*/

	#include <iostream>
	#include "danielgutson/mili/mili.h"

	using namespace mili;
	using namespace std;

	enum MasksSet1
	{
		kZero   = 0,
		kOne    = 1,
		kTwo    = 2,
		kThree  = 4,
		kFour   = 8
	};
	BITWISE_ENUM_ENABLE(MasksSet1)

	enum MasksSet2
	{
		kEight   = 8,
		kSixteen = 16
	};

	typedef bitwise_enum<MasksSet1> M1;

	void show_bits(M1 b)
	{
		if (b.has_bits(kZero))  cout << "kZero  turned on\n";
		if (b.has_bits(kOne))   cout << "kOne   turned on\n";
		if (b.has_bits(kTwo))   cout << "kTwo   turned on\n";
		if (b.has_bits(kThree)) cout << "kThree turned on\n";
		if (b.has_bits(kFour))  cout << "kFour  turned on\n";
		cout << endl;
	}

	int main()
	{
		//with bitwise nums
		bitwise_enum<MasksSet1>  myEnum(kOne | kTwo | kFour);

		show_bits(myEnum);

		//enum with bitwise enum
		myEnum = kOne & myEnum;
		show_bits(myEnum);

		// 2 enums
		show_bits(kOne | kThree);

		// << operator
		cout << "<< Operator test: 0x" << hex << (myEnum << 2) << endl;

		//without bitwise nums (built-in types)
		int normalEnum = kEight | kSixteen;
		cout << "Normal Enum: 0x" << hex << normalEnum << endl;

		normalEnum = kEight << 2;
		cout << "Normal Enum: 0x" << hex << normalEnum << endl;

		return 0;
	}

First, you need to resolve all the dependencies of this ``main.cpp``
	
.. code-block:: bash
	
	$ bii find


You will see next console output after executing the command:
	
.. code-block:: bash

	$ bii cpp:run
	
	...
	
	kOne   turned on
	kTwo   turned on
	kFour  turned on

	kOne   turned on

	kOne   turned on
	kThree turned on

	<< Operator test: 0x4
	Normal Enum: 0x18
	Normal Enum: 0x20

