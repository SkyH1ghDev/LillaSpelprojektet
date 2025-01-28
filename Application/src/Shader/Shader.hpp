#pragma once

#include <d3d11_4.h>
#include <d3dcompiler.h>
#include <iostream>

enum class ShaderType
{
	VERTEX_SHADER,
	HULL_SHADER,
	DOMAIN_SHADER,
	GEOMETRY_SHADER,
	PIXEL_SHADER,
	COMPUTE_SHADER
};

class Shader
{
private:

	ShaderType type;

	union
	{
		ID3D11VertexShader* vertex = nullptr;
		ID3D11HullShader* hull;
		ID3D11DomainShader* domain;
		ID3D11GeometryShader* geometry;
		ID3D11PixelShader* pixel;
		ID3D11ComputeShader* compute;
	} shader;

	ID3DBlob* shaderBlob = nullptr;

public:
	Shader() = default;
	~Shader();
	Shader(ID3D11Device* device, ShaderType shaderType, const void* dataPtr, size_t dataSize);
	Shader(ID3D11Device* device, ShaderType shaderType, const char* csoPath);
	Shader(const Shader& other) = delete;
	Shader& operator=(const Shader& other) = delete;
	Shader(Shader&& other) = delete;
	Shader& operator=(Shader&& other) = delete;

	void Initialize(ID3D11Device* device, ShaderType shaderType, const void* dataPtr, size_t dataSize);
	void Initialize(ID3D11Device* device, ShaderType shaderType, const char* csoPath);

	const void* GetShaderByteData() const;
	size_t GetShaderByteSize() const;

	void BindShader(ID3D11DeviceContext* immediateContext) const;
};