//
// Created by eduard.parvu on 4/27/2020.
//

#include <glad/glad.h>
#include "gpu_data.hpp"

unsigned int& GpuData::BasicGpuData::get_vertex_buffer_object() noexcept {
    return m_vertex_buffer_object;
}


GpuData::TriangleGpuData::TriangleGpuData(const float* const triangle_data, size_t triangle_data_size, unsigned int & vertex_array_object) noexcept {
    glGenBuffers(1, &m_vertex_buffer_object);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(vertex_array_object);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(triangle_data_size), triangle_data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}
