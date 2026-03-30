#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_default_ctor){
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_push_front){
    List<int> list;
    list.push_front(10);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    list.push_front(20);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 20);
}

TEST(test_push_back){
    List<int> list;
    list.push_back(10);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.back(), 10);
    list.push_back(20);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.back(), 20);
    ASSERT_EQUAL(list.front(), 10);
}

TEST(test_pop_front){
    List<int> list;
    list.push_front(10);
    list.push_front(20);
    ASSERT_EQUAL(list.size(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    ASSERT_EQUAL(list.size(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.back(), 10);
    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_iterator) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());
}

TEST(test_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    it = list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(*it, 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    it = list.insert(it, 2);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQUAL(list.size(), 3);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_TRUE(list.begin() == list.end());
}

TEST(test_pop_front_single) {
    List<int> list;
    list.push_front(10);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back_single) {
    List<int> list;
    list.push_back(10);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.back(), 10);
    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_insert_front) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    it = list.insert(it, 1);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(*it, 1);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_erase_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.end();
    --it;
    it = list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
    ASSERT_TRUE(list.end() == it);
}

TEST(test_erase_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    it = list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_iterator_empty) {
    List<int> list;
    List<int>::Iterator it = list.begin();
    ASSERT_TRUE(it == list.end());
}

TEST(test_const_iterator) {
    const List<int> list = []() {
        List<int> temp;
        temp.push_back(1);
        temp.push_back(2);
        temp.push_back(3);
        return temp;
    }();
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());
}

TEST(test_modify_through_iterator) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    *it = 10;
    ASSERT_EQUAL(*it, 10);
    ++it;
    *it = 20;
    ASSERT_EQUAL(*it, 20);
    ++it;
    *it = 30;
    ASSERT_EQUAL(*it, 30);
}



TEST(test_assignment_operator) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2.push_back(4);
    list2.push_back(5);
    list2 = list1;
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
    list1.push_back(6);
    ASSERT_EQUAL(list1.size(), 4);
    ASSERT_EQUAL(list2.size(), 3);
    ASSERT_EQUAL(list1.back(), 6);
    ASSERT_EQUAL(list2.back(), 3);
}

TEST(test_assignment_to_empty) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2 = list1;
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_assignment_from_empty) {
    List<int> list1;
    List<int> list2;
    list2.push_back(4);
    list2.push_back(5);
    list2 = list1;
    ASSERT_TRUE(list2.empty());
    ASSERT_EQUAL(list2.size(), 0);
}

TEST(test_assignment_overwrites_existing_elements) {
    List<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    List<int> target;
    target.push_back(4);
    target.push_back(5);
    target = source;
    ASSERT_EQUAL(source.size(), target.size());
    List<int>::Iterator it_src = source.begin();
    List<int>::Iterator it_tgt = target.begin();
    while (it_src != source.end() && it_tgt != target.end()) {
        ASSERT_EQUAL(*it_src, *it_tgt);
        ++it_src;
        ++it_tgt;
    }
    source.push_back(6);
    ASSERT_EQUAL(source.size(), 4);
    ASSERT_EQUAL(target.size(), 3); 
    ASSERT_EQUAL(source.back(), 6);
    ASSERT_EQUAL(target.back(), 3);
}

TEST(test_assignment_to_empty_list) {
    List<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    List<int> target;
    target = source;
    ASSERT_EQUAL(source.size(), target.size());
    List<int>::Iterator it_src = source.begin();
    List<int>::Iterator it_tgt = target.begin();
    while (it_src != source.end() && it_tgt != target.end()) {
        ASSERT_EQUAL(*it_src, *it_tgt);
        ++it_src;
        ++it_tgt;
    }
    source.push_back(4);
    ASSERT_EQUAL(source.size(), 4);
    ASSERT_EQUAL(target.size(), 3); 
    ASSERT_EQUAL(source.back(), 4);
    ASSERT_EQUAL(target.back(), 3);
}

TEST(test_assignment_from_empty_list) {
    List<int> source;
    List<int> target;
    target.push_back(1);
    target.push_back(2);
    target = source;
    ASSERT_TRUE(target.empty());
    ASSERT_EQUAL(target.size(), 0);
    ASSERT_TRUE(target.begin() == target.end());
}

TEST(test_assignment_operator_non_int) {
    List<std::string> source;
    source.push_back("apple");
    source.push_back("banana");
    source.push_back("cherry");
    List<std::string> target;
    target.push_back("x");
    target.push_back("y");
    target = source;
    ASSERT_EQUAL(source.size(), target.size());
    List<std::string>::Iterator it_src = source.begin();
    List<std::string>::Iterator it_tgt = target.begin();
    while (it_src != source.end() && it_tgt != target.end()) {
        ASSERT_EQUAL(*it_src, *it_tgt);
        ++it_src;
        ++it_tgt;
    }
}

TEST(test_destructor_no_leak) {
    List<int>* list = new List<int>();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    delete list; 
}

TEST(test_copy_constructor_no_leak) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    // use the copy ctor
    List<int> list2 = list1; 
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_assignment_operator_no_leak) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2.push_back(4);
    list2.push_back(5);
    list2 = list1; 
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
}


TEST(test_front_back_consistency) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 2);
    ASSERT_EQUAL(list.front(), list.back());
}

TEST(test_iterator_reverse_iteration) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.end();
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
    ASSERT_TRUE(it == list.begin());
}

TEST(test_clear_and_push_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    list.push_back(3);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_insert_and_erase_combination) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    auto it = list.begin();
    ++it;
    it = list.insert(it, 2); // Insert 2 between 1 and 3
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    it = list.erase(it); // Erase the inserted 2
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(*it, 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_multiple_push_pop) {
    List<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_front(0);
    list.push_back(3);
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.front(), 0);
    ASSERT_EQUAL(list.back(), 3);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.back(), 2);
    list.pop_front();
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_multiple_insertions_at_beginning) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.back(), 1);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_TRUE(it == list.end());
}

TEST(test_pop_front_back_combination) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 4);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 3);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 3);
    ASSERT_EQUAL(list.size(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_iterator_post_increment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    List<int>::Iterator it2 = it++;
    ASSERT_EQUAL(*it2, 1);
    ASSERT_EQUAL(*it, 2);
    it2 = it++;
    ASSERT_EQUAL(*it2, 2);
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());
}

TEST(test_copy_constructor_deep_copy) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2 = list1; 
    ASSERT_EQUAL(list1.size(), list2.size());
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    while (it1 != list1.end() && it2 != list2.end()) {
        ASSERT_EQUAL(*it1, *it2);
        ++it1;
        ++it2;
    }
    list1.push_back(4);
    ASSERT_EQUAL(list1.size(), 4);
    ASSERT_EQUAL(list2.size(), 3);
    ASSERT_EQUAL(list1.back(), 4);
    ASSERT_EQUAL(list2.back(), 3);
}

TEST(test_clear_and_reuse) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    list.push_back(3);
    list.push_back(4);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 3);
    ASSERT_EQUAL(list.back(), 4);
}

TEST(test_erase_multiple_elements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    auto it = list.begin();
    ++it;
    it = list.erase(it); 
    ASSERT_EQUAL(*it, 3);
    ASSERT_EQUAL(list.size(), 3);
    it = list.erase(it);
    ASSERT_EQUAL(*it, 4);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 4);
}

TEST(test_iterator_after_clear_no_throw) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1); 
    ++it;
    ASSERT_EQUAL(*it, 2); 
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_TRUE(list.begin() == list.end()); 
    ASSERT_TRUE(it != list.begin()); 
    ASSERT_TRUE(it != list.end());  
}

TEST(test_assignment_self) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.operator=(list);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());
}

TEST(test_assignment_larger_target) {
    List<int> source;
    source.push_back(1);
    source.push_back(2);
    List<int> target;
    target.push_back(10);
    target.push_back(20);
    target.push_back(30);
    target = source; 
    ASSERT_EQUAL(target.size(), source.size());
    ASSERT_EQUAL(target.front(), 1);
    ASSERT_EQUAL(target.back(), 2);
}

TEST(test_assignment_smaller_target) {
    List<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    List<int> target;
    target.push_back(10);
    target = source; 
    ASSERT_EQUAL(target.size(), source.size());
    ASSERT_EQUAL(target.front(), 1);
    ASSERT_EQUAL(target.back(), 3);
}

TEST(test_assignment_empty_to_nonempty) {
    List<int> source; 
    List<int> target;
    target.push_back(1);
    target.push_back(2);
    target = source;
    ASSERT_TRUE(target.empty());
    ASSERT_EQUAL(target.size(), 0);
}

TEST(test_explicit_operator_self_assignment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int original_size = list.size();
    List<int>::Iterator it = list.begin();
    std::vector<int> original_values;
    while (it != list.end()) {
        original_values.push_back(*it);
        ++it;
    }
    list.operator=(list);
    ASSERT_EQUAL(list.size(), original_size);
    List<int>::Iterator it_after = list.begin();
    for (int value : original_values) {
        ASSERT_EQUAL(*it_after, value);
        ++it_after;
    }
    ASSERT_TRUE(it_after == list.end());
}

TEST(test_operator_equals_function) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.begin();
    List<int>::Iterator it3 = list1.end();
    ASSERT_TRUE(it1.operator==(it2)); 
    ASSERT_FALSE(it1.operator==(it3)); 
    ++it1;
    ASSERT_FALSE(it1.operator==(it2)); 
    ASSERT_FALSE(it1.operator==(it3)); 
    List<int> list2;
    list2.push_back(4);
    List<int>::Iterator it4 = list2.begin();
    ASSERT_FALSE(it1.operator==(it4));
}

TEST(test_operator_equals_end_iterators) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    List<int>::Iterator it1 = list1.end();
    List<int>::Iterator it2 = list1.end();
    ASSERT_TRUE(it1.operator==(it2)); 
    List<int> list2;
    List<int>::Iterator it3 = list2.end();
    ASSERT_FALSE(it1.operator==(it3));
}

TEST(test_operator_equals_empty_list_iterators) {
    List<int> list1;
    List<int> list2;
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    ASSERT_FALSE(it1.operator==(it2));
    ASSERT_TRUE(it1.operator==(list1.end()));
}

TEST(test_operator_equals_self_comparison) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    List<int>::Iterator it = list1.begin();
    ASSERT_TRUE(it.operator==(it));
}

TEST(test_operator_equals_after_erase) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.begin();
    ++it2;
    it1 = list1.erase(it1);
    ASSERT_TRUE(it1.operator==(list1.begin())); 
    ASSERT_TRUE(it1.operator==(it2)); 
    ASSERT_EQUAL(*it1, 2); 
}


TEST_MAIN()
