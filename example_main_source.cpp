
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
