# cpack

Cpack is a competitive programming helper tool, which packages the main source file along with included libraries into a single file, suitable for online judges.

### The problem

You want to make a library of common algorithms and use it while solving some tasks.
But, as you may know, having tens of algorithms clustered in one file is messy (and unmaintainable).
So you may want to try to split them, but here competitive programming hits you; you can't submit more than one file.

### The solution

The next shell block contains your main source file which uses system libraries `bits/stdc++.h` and `algorithm` and your own library `example_header.hpp`. Libraries you don't want packaged must be specified in a protected block, check out the example. This block will allow language servers to function properly while you develop the source, and prevent cpack from packaging system headers, which would prevent portability. 

~~~shell
$ cat example_main_source.cpp

// this is how you include a system library
#ifdef COMP_PROG_DEPLOY
#pragma DELETETHISPREFIX #include <bits/stdc++.h>
#else
#include <bits/stdc++.h>
#endif

// one more system library, just for the demo
#ifdef COMP_PROG_DEPLOY
#pragma DELETETHISPREFIX #include <algorithm>
#else
#include <algorithm>
#endif

// this is how you include your own library you want unpacked
#include "example_header.hpp"

//twice to demonstrate functionality of #pragma once
#include "example_header.hpp" 

using namespace std;

int main(){
    cout << header_fn() << endl;
}
~~~

Also, check out the simple header for demonstration purposes. Notice that it uses `#pragma once`; since this script uses gcc compiler internally, you can include all your standard preprocessor functions and they will function properly. 

~~~shell
$ cat example_header.hpp

#pragma once

int header_fn(){
    return 42;
}
~~~

Run cpack utility and observe the packaged source, which can be easily submitted to online judges.

~~~shell
$ cpack example_main_source.cpp
Packaging of source done!   (example_main_source.cpp.cpack.cpp)

$ cat example_main_source.cpp.cpack.cpp
 #include <bits/stdc++.h>
 #include <algorithm>

int header_fn(){
    return 42;
}
using namespace std;
int main(){
    cout << header_fn() << endl;
}
~~~

Compiling and running the packaged source.

~~~shell
$ g++ example_main_source.cpp.cpack.cpp
$ ./a.out
42
~~~

The main limitation of this system is that you have to decide whether to include a header file or not. This has to be done since some headers are non-portable, and can't be expanded on your local pc and then submitted to online judges. 

### Setup: (tested on linux system with gcc 10.2.0 and bash 5.1.0)

1. Download/clone the repo (or just the `cpack` script) into some folder
2. Add a symbolic link to the `cpack` script or alias it in your `.bashrc`

### Contact
Feel free to contact me with suggestions, questions, etc, at *petar.mihalj.other ATCHAR pm.me*   
