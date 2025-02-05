#include "Button.hpp"


#include "PlayVisible.hpp"
#include "ExitVisible.hpp"
#include "MenuVisible.hpp"
#include "ContinueVisible.hpp"
#include "ExitMenuVisible.hpp"

std::shared_ptr<IVisible> CreateVisibleComponent(ButtonType type) {
    switch (type) {
    case ButtonType::Play:
        return std::make_shared<PlayVisible>();
    case ButtonType::Exit:
        return std::make_shared<ExitVisible>();
    case ButtonType::Menu:
        return std::make_shared<MenuVisible>();
    case ButtonType::Continue:
        return std::make_shared<ContinueVisible>();
    case ButtonType::ExitMenu:
        return std::make_shared<ExitMenuVisible>();
    default:
        throw std::invalid_argument("Invalid ButtonType");
    }
}

Button::Button(ButtonType type) :
    m_visible(CreateVisibleComponent(type)),
    m_type(type)
{
    std::cout << "Button created" << std::endl;
}

void Button::Update()
{
    Clicked();
}

void Button::OnStart()
{
	this->m_position = { 0, 0 };
}

void Button::Clicked()
{

	if (Input::GetMousePositionX() > this->m_position.x && Input::GetMousePositionX() < this->m_position.x + width &&
		Input::GetMousePositionY() > this->m_position.y && Input::GetMousePositionY() < this->m_position.y + height)
		ClickEvent();


}
