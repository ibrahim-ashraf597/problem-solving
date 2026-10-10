/*
======================== LIST (C++ STL) ========================

Declaration:
    list<int> ls = {10, 20, 30};


------------------------ ITERATORS ----------------------------

ls.begin()       // Iterator to the first element
ls.end()         // Iterator past the last element
ls.rbegin()      // Reverse iterator to the last element
ls.rend()        // Reverse iterator past the first element

next(it)         // Iterator to the next element
prev(it)         // Iterator to the previous element
next(it, k)      // Iterator k steps forward
prev(it, k)      // Iterator k steps backward

*it              // Access the element's value
++it             // Move to the next element
--it             // Move to the previous element


------------------------ ACCESS --------------------------------

ls.front()       // First element (reference)
ls.back()        // Last element (reference)
ls.size()        // Number of elements
ls.empty()       // Check if empty (bool)


------------------------ INSERTION -----------------------------

ls.push_back(x)  // Add x to the end
ls.push_front(x) // Add x to the beginning

ls.insert(it, x) // Insert x BEFORE it
                  // Returns iterator to the new element


------------------------ DELETION ------------------------------

ls.pop_back()    // Remove the last element
ls.pop_front()   // Remove the first element

ls.erase(it)     // Remove element at it
                  // Returns iterator to the next element

ls.remove(x)     // Remove all elements equal to x
ls.clear()       // Remove all elements


------------------------ OTHER FUNCTIONS -----------------------

ls.sort()        // Sort in ascending order
ls.reverse()     // Reverse the list
ls.unique()      // Remove consecutive duplicates


------------------------ IMPORTANT NOTES -----------------------

1. ls.end() points AFTER the last element, not to it.
2. Never dereference ls.end().
3. Do NOT use it + 1 or it - 1 with list.
   Use next(it) and prev(it) instead.
4. insert(it, x) inserts BEFORE it.
5. erase(it) invalidates the iterator to the erased element.
6. Inserting or erasing does not invalidate iterators
   to other elements.
7. insert() and erase() take O(1) when the iterator is known.
8. next(it, k) and prev(it, k) take O(k).

===============================================================
*/
