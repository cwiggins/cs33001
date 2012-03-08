//  String class test program
//
//  Tests: XXX
//

#include "string.h"
#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string  str("X");

        // VERIFY
        assert(str == "X");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string  str("ert1234");

        // VERIFY
        assert(str == "ert1234");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string  str("0000))hgt1");

        // VERIFY
        assert(str == "0000))hgt1");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string  str("0000560000YT");

        // VERIFY
        assert(str == "0000560000YT");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        string  str("HJY*(1234");

        // VERIFY
        assert(str == "HJY*(1234");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY

}

