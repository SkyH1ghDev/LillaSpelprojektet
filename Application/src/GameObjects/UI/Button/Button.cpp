#include "Button.hpp"

void Button::Update()
{
	  
}

void Button::OnStart()
{

}

void Button::Clicked()
{

	if (Input::GetMousePositionX() > m_position.x && Input::GetMousePositionX() < m_position.x + width &&
		Input::GetMousePositionY() > m_position.y && Input::GetMousePositionY() < m_position.y + height)
		ClickEvent();


}
