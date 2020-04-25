//
// Created by Valar on 4/20/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_SHADER_CPP
#define OPENGLANDVULKANPLAYGROUND_SHADER_CPP

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include "shader.hpp"

Shader::BasicShader::BasicShader(const char* vertex_shader_full_path, const char* fragment_shader_full_path) noexcept {
    std::string vertex_shader_source {get_file_contents(vertex_shader_full_path)};
    std::string fragment_shader_source {get_file_contents(fragment_shader_full_path)};

    const char* vertex_shader_source_raw = vertex_shader_source.c_str();
    const char* fragment_shader_source_raw = fragment_shader_source.c_str();

    unsigned int vertex_shader_handle = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_handle, 1, &vertex_shader_source_raw, nullptr);
    glCompileShader(vertex_shader_handle);
    log_shader_error(vertex_shader_handle, ShaderType::VERTEX_SHADER);

    unsigned int fragment_shader_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_handle, 1, &fragment_shader_source_raw, nullptr);
    glCompileShader(fragment_shader_handle);
    log_shader_error(fragment_shader_handle, ShaderType::FRAGMENT_SHADER);

    this->m_ptr_shader_program_handle = std::make_unique<unsigned int>(glCreateProgram());
    glAttachShader(*this->m_ptr_shader_program_handle, vertex_shader_handle);
    glAttachShader(*this->m_ptr_shader_program_handle, fragment_shader_handle);
    glLinkProgram(*this->m_ptr_shader_program_handle);
    log_shader_program_error(*this->m_ptr_shader_program_handle);

    glDeleteShader(vertex_shader_handle);
    glDeleteShader(fragment_shader_handle);
}

unsigned int& Shader::BasicShader::get_shader_program_handle() {
    return *this->m_ptr_shader_program_handle;
}


void Shader::BasicShader::log_shader_program_error(unsigned int shader_program_handle) noexcept {
    int success;
    char infoLog[512];

    glGetProgramiv(shader_program_handle, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program_handle, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}


void Shader::BasicShader::log_shader_error(unsigned int shader_handle, ShaderType shader_type) noexcept {
    int success;
    char infoLog[512];

    glGetShaderiv(shader_handle, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader_handle, 512, nullptr, infoLog);

        std::string error_message{};
        switch (shader_type) {
            case ShaderType::VERTEX_SHADER: {
                error_message.append("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
                error_message.shrink_to_fit();
            }break;
            case ShaderType::FRAGMENT_SHADER: {
                error_message.append("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
                error_message.shrink_to_fit();
            }break;
        }
        std::cout << error_message.c_str() << infoLog << std::endl;
    }
}

std::string Shader::BasicShader::get_file_contents(const char* file_name_full_path) noexcept {
    std::ifstream in{file_name_full_path, std::ios::in | std::ios::binary};
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(static_cast<unsigned long long int>(in.tellg()));
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], static_cast<long long int>(contents.size()));
        in.close();
        return(contents);
    }
    return std::string {};
}

#endif //OPENGLANDVULKANPLAYGROUND_SHADER_CPP
