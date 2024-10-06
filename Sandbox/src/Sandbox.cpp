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
	Sandbox() {};
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
