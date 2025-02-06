#include "Button.hpp"


#include "PlayVisible.hpp"
#include "ExitVisible.hpp"
#include "MenuVisible.hpp"
#include "ContinueVisible.hpp"
#include "ExitMenuVisible.hpp"
#include "PlayClicked.hpp"
#include "ExitClicked.hpp"
#include "MenuClicked.hpp"
#include "ContinueClicked.hpp"
#include "ExitMenuClicked.hpp"

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

std::shared_ptr<IClicked> CreateClickComponent(ButtonType type) {
    switch (type) {
    case ButtonType::Play:
        return std::make_shared<PlayClicked>();
    case ButtonType::Exit:
        return std::make_shared<ExitClicked>();
    case ButtonType::Menu:
        return std::make_shared<MenuClicked>();
    case ButtonType::Continue:
        return std::make_shared<ContinueClicked>();
    case ButtonType::ExitMenu:
        return std::make_shared<ExitMenuClicked>();
    default:
        throw std::invalid_argument("Invalid ButtonType");
    }
}

Button::Button(ButtonType type) :
    m_visible(CreateVisibleComponent(type)),
    m_clicked(CreateClickComponent(type)),
    m_type(type)
{
    std::cout << "Button created" << std::endl;
}

void Button::PerformClicked()
{
    //Mouse over Button
    if (Input::GetMousePositionX() > this->m_position.x && Input::GetMousePositionX() < this->m_position.x + 100 &&
        Input::GetMousePositionY() > this->m_position.y && Input::GetMousePositionY() < this->m_position.y + 100)
    {
        if (m_mouseClick->VL_Click()) {
            m_clicked->Clicked();
        }
    }


    //Keyboard bindings

}

void Button::Update()
{
    PerformClicked();
}

void Button::OnStart()
{
    Input::GetKey(VK_LBUTTON)->Attach(m_mouseClick);
      //Input::GetKey(VK_LBUTTON)->Attach(std::static_pointer_cast<IObserver, OnMouseClick>(m_mouseClick));

	this->m_position = { 200, 100 };
    PerformVisible();
    this->m_toRender = true;
}
