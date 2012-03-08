// bigint Test Program
//
// Tests:  times_10, uses ==
//

#include "bigint.h"

#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bigint result = bi.times_10(0);

        // Verify
        assert(result == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(4);

        // Test 
        bigint result = bi.times_10(1);

        // Verify
        assert(result == 40);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5);

        // Test 
        bigint result = bi.times_10(2);

        // Verify
        assert(result == 500);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(6);

        // Test 
        bigint result = bi.times_10(5);

        // Verify
        assert(result == 600000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(7);

        // Test 
        bigint result = bi.times_10(10);

        // Verify
        assert(result == "70000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(8);

        // Test 
        bigint result = bi.times_10(50);

        // Verify
        assert(result == "800000000000000000000000000000000000000000000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bigint result = bi.times_10(0);

        // Verify
        assert(result == 0);
    }

}

