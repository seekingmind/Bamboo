/*****************************************************************//**
 * \file   Sandbox.cpp
 * \brief  应用程序 Sandbox
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
 * 程序运行主函数.
 * 
 * \return 
 */
Bamboo::Application* Bamboo::CreateApplication()
{
	return new Sandbox();
}
