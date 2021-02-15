# cpack

Cpack is a competitive programming helper tool, which packages the main source file along with included libraries into a single file, suitable for online judges.

### The problem

You want to make a library of common algorithms and use it while solving some tasks.
But, as you may know, having tens of algorithms clustered in one file is messy (and unmaintainable).
So you may want to try to split them, but here competitive programming hits you; you can't submit more than one file.

### The solution

Cpack attempts to cure this problem, by providing a standard script which can preprocess the main source file and include all needed libraries.
It makes use of standard gcc preprocessor to ensure all preprocessor directives work well, including `#pragma once` (commonly used for libraries).

Usage example:

~~~shell
$ cat example_main_source.cpp
// this is how you include a system library
#ifdef COMP_PROG_DEPLOY
#pragma DELETETHISPREFIX #include <bits/stdc++.h>
#else
#include <bits/stdc++.h>
#endif

// this is how you include your own library you want unpacked
#include "example_header.hpp"

using namespace std;

int main(){
    cout << header_fn() << endl;
}
$ cat example_header.hpp
#pragma once

int header_fn(){
    return 42;
}
$ cpack example_main_source.cpp
Packaging of source done!   (example_main_source.cpp.cpack.cpp)
$ cat example_main_source.cpp.cpack.cpp
 #include <bits/stdc++.h>

int header_fn(){
    return 42;
}
using namespace std;
int main(){
    cout << header_fn() << endl;
}
$ g++ example_main_source.cpp.cpack.cpp
$ ./a.out
42
~~~

As you can see, cpack both compiles the source using standard flags you can edit, and also packages the source for submission to online judges.

These sources can be found in the other [repo](https://github.com/PetarMihalj/cpack_lib_example), where you can see both the original source and the resulting packaged file.

### Limitations

The main limitation of this system is that it has to decide whether to include a file or not, and this has to be specified manually. This has to be done since some headers are non portable, and can't be expanded on your local pc and then submitted to online judges. 

Check out the `cpack_common.hpp` file; this is how you should include system dependant files (for example `bits/stdc++.h`). Having them wrapped in this format is necessary for cpack to ignore them while packaging your source. Alternatively, just include the `cpack_common.hpp`; this should be enough for all competitive programming use cases.

Even though the system libraries are included in a custom format on a source file level, this format is compatible with modern language servers; you will still get your IDE completition, as long as you have `cpack_common.hpp` included properly. Alternatively, just copy `cpack_common.hpp` in your library folder (check out the last paragraph for an example).

### Setup: (tested on linux system with gcc 10.2.0 and bash 5.1.0)

1. Download/clone the repo into some folder
2. Add a symbolic link to the `cpack` script or alias it in your `.bashrc`
3. (optional) Change compilation flags in the flags file

### How to build a library around this?
Check out the source [repo](https://github.com/PetarMihalj/cpack_lib_example), in which I describe how to create a library compatible with this system.

### Contact
Feel free to contact me with suggestions, questions, etc, at *petar.mihalj.other ATCHAR pm.me*   
