#include <fstream>
#include <vector>
#include <d3dcompiler.h>
#include <iostream>

#include "Shader.hpp"

Shader::~Shader()
{
    //release blob
    if (shaderBlob)
    {
        shaderBlob->Release();
        shaderBlob = nullptr;
    }

    //release correct shader resource
    switch (type)
    {
    case ShaderType::VERTEX_SHADER:
        if (shader.vertex)
        {
            shader.vertex->Release();
            shader.vertex = nullptr;
        }
        break;
    case ShaderType::HULL_SHADER:
        if (shader.hull)
        {
            shader.hull->Release();
        }
        break;
    case ShaderType::DOMAIN_SHADER:
        if (shader.domain)
        {
            shader.domain->Release();
        }
        break;
    case ShaderType::GEOMETRY_SHADER:
        if (shader.geometry)
        {
            shader.geometry->Release();
        }
        break;
    case ShaderType::PIXEL_SHADER:
        if (shader.pixel)
        {
            shader.pixel->Release();
        }
        break;
    case ShaderType::COMPUTE_SHADER:
        if (shader.compute)
        {
            shader.compute->Release();
        }
        break;
    default:
        break;
    }
}

Shader::Shader(ID3D11Device* device, ShaderType shaderType, const void* dataPtr, size_t dataSize)
{
    Initialize(device, shaderType, dataPtr, dataSize);
}

Shader::Shader(ID3D11Device* device, ShaderType shaderType, const char* csoPath)
{
    Initialize(device, shaderType, csoPath);
}

void Shader::Initialize(ID3D11Device* device, ShaderType shaderType, const void* dataPtr, size_t dataSize)
{
    this->type = shaderType;

    switch (shaderType)
    {
    case ShaderType::VERTEX_SHADER:
        device->CreateVertexShader(dataPtr, dataSize, nullptr, &shader.vertex);
        break;
    case ShaderType::HULL_SHADER:
        device->CreateHullShader(dataPtr, dataSize, nullptr, &shader.hull);
        break;
    case ShaderType::DOMAIN_SHADER:
        device->CreateDomainShader(dataPtr, dataSize, nullptr, &shader.domain);
        break;
    case ShaderType::GEOMETRY_SHADER:
        device->CreateGeometryShader(dataPtr, dataSize, nullptr, &shader.geometry);
        break;
    case ShaderType::PIXEL_SHADER:
        device->CreatePixelShader(dataPtr, dataSize, nullptr, &shader.pixel);
        break;
    case ShaderType::COMPUTE_SHADER:
        device->CreateComputeShader(dataPtr, dataSize, nullptr, &shader.compute);
        break;
    default:
        break;
    }

    D3DCreateBlob(dataSize, &shaderBlob);
    memcpy(shaderBlob->GetBufferPointer(), dataPtr, dataSize);
}

void Shader::Initialize(ID3D11Device* device, ShaderType shaderType, const char* csoPath)
{
    // Open the file
    std::ifstream file;
    file.open(csoPath, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Could not open shader file!" << std::endl;
        return;
    }

    // Determine file size
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the file content into a vector
    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    file.close();

    Initialize(device, shaderType, buffer.data(), fileSize);
}

const void* Shader::GetShaderByteData() const
{
    if (shaderBlob)
    {
        return shaderBlob->GetBufferPointer();
    }
    return nullptr;
}

size_t Shader::GetShaderByteSize() const
{
    if (shaderBlob)
    {
        return shaderBlob->GetBufferSize();
    }
    return 0;
}

void Shader::BindShader(ID3D11DeviceContext* immediateContext) const
{
    switch (type)
    {
    case ShaderType::VERTEX_SHADER:
        immediateContext->VSSetShader(shader.vertex, nullptr, 0);
        break;
    case ShaderType::HULL_SHADER:
        immediateContext->HSSetShader(shader.hull, nullptr, 0);
        break;
    case ShaderType::DOMAIN_SHADER:
        immediateContext->DSSetShader(shader.domain, nullptr, 0);
        break;
    case ShaderType::GEOMETRY_SHADER:
        immediateContext->GSSetShader(shader.geometry, nullptr, 0);
        break;
    case ShaderType::PIXEL_SHADER:
        immediateContext->PSSetShader(shader.pixel, nullptr, 0);
        break;
    case ShaderType::COMPUTE_SHADER:
        immediateContext->CSSetShader(shader.compute, nullptr, 0);
    default:
        break;
    }
}
