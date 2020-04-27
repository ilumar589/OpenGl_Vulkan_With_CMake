//
// Created by eduard.parvu on 4/22/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_TEST_HPP
#define OPENGLANDVULKANPLAYGROUND_TEST_HPP

#include <memory>
#include <iostream>

struct TestData {
    int x,y;
};

auto get_unique_ptr_towards_l_value() {
    TestData v{};
    v.x = 42;
    v.y = 1;
    return std::make_unique<TestData>(v);
}

// works, so the value is copied for a l value
void use_unique_ptr_ref_for_l_value() {
    std::unique_ptr<TestData> ptr_l_value = get_unique_ptr_towards_l_value();
    std::cout << ptr_l_value->x;
}

#endif //OPENGLANDVULKANPLAYGROUND_TEST_HPP
