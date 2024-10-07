/*****************************************************************//**
 * \file   Sandbox.cpp
 * \brief  Ӧ�ó��� Sandbox
 * 
 * \author zhongsheng
 * \date   October 2024
 *********************************************************************/

#include "Bamboo.h"

class Sandbox : public Bamboo::Application
{
public:
	Sandbox() { BB_TRACE("Hello!"); };
	~Sandbox() {};

private:

};

/**
 * ��������������.
 * 
 * \return 
 */
Bamboo::Application* Bamboo::CreateApplication()
{
	return new Sandbox();
}
