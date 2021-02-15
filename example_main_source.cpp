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
