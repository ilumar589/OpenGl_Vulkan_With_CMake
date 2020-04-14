//
// Created by eduard.parvu on 3/28/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_TESTHEADER_H
#define OPENGLANDVULKANPLAYGROUND_TESTHEADER_H
#include <type_traits>

namespace test_scope {
    template<typename Number>
    auto sum(const Number n1, const Number n2) {
        return n1 + n2;
    }
}

//namespace test_concepts { // I guess it's a problem with the compiler on c++ 20 stuff
//    template<typename T>
//    concept floating_point = std::is_floating_point_v<T>;
//
//    template<floating_point U>
//    auto sum_of_two_floats(const U f1,const U f2) {
//        return f1 + f2;
//    }
//}

#endif //OPENGLANDVULKANPLAYGROUND_TESTHEADER_H
