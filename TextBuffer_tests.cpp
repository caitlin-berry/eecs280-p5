#include "TextBuffer.hpp"
#include "unit_test_framework.hpp"

using namespace std;
#include <iostream>


// Add your test cases here

// TEST(test_stub) {
//     // Add test code here
//     ASSERT_TRUE(true);
// }



// TEST(test_remove) {
//     TextBuffer buffer;
//     // Insert text
//     buffer.insert('A');
//     buffer.insert('B');
//     buffer.insert('C'); // Text is now: "ABC|"
//     buffer.backward();  // Move cursor to "AB|C"
//     ASSERT_EQUAL(buffer.get_column(), 2); // Column should be 2
//     cout << "^pass" << endl;
//     // Remove character at the cursor
//     ASSERT_TRUE(buffer.remove()); // Removes 'B', Text becomes: "A|C"
//     cout << "^pass" <<endl;
//     ASSERT_EQUAL(buffer.get_column(), 1); // Column should now be 1
//     cout << "^pass" << endl;
//     cout << buffer.stringify();
//     ASSERT_EQUAL(buffer.stringify(), "AC"); // Text should reflect the removal
//     cout << "^pass";
// }



TEST_MAIN()
