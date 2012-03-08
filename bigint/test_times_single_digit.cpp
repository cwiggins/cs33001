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
        bigint bi(3), result;

        // Test 
        result = bi * 1;

        // Verify
        assert(bi == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3), result;

        // Test 
        result = bi * 5;

        // Verify
        assert(result == 15);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(99999), result;

        // Test 
        result = bi * 2;

        // Verify
        assert(result == 199998);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(99999999), result;

        // Test 
        result = bi * 9;

        // Verify
        assert(result == 899999991);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1), result;

        // Test 
        result = bi * 1;

        // Verify
        assert(result == 1);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5555), result;

        // Test 
        result = bi * 0;

        // Verify
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1), result;

        // Test 
        result = bi * 0;

        // Verify
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0), result;

        // Test 
        result = bi * 1;

        // Verify
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0), result;

        // Test 
        result = bi * 0;

        // Verify
        assert(result == 0);
    }

}
