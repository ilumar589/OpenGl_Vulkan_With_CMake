//
// Created by eduard.parvu on 4/27/2020.
//

#include <glad/glad.h>
#include "gpu_data.hpp"

unsigned int& GpuData::BasicGpuData::get_vertex_array_object() noexcept {
    return m_vertex_array_object;
}


GpuData::TriangleGpuData::TriangleGpuData(std::array<float, 9> data) noexcept {
    std::array<float,9> m_data = data;
    unsigned int m_vertex_buffer_object;

    glGenVertexArrays(1, &m_vertex_array_object);
    glGenBuffers(1, &m_vertex_buffer_object);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(m_vertex_array_object);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_data), m_data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}
