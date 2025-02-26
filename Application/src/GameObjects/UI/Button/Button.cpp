#include "Button.hpp"

#include "PlayClicked.hpp"
#include "ContinueClicked.hpp"
#include "QuitClicked.hpp"
#include "ExitClicked.hpp"



std::shared_ptr<IUIClicked> CreateClickComponent(ButtonType type) {
    switch (type) {
    case ButtonType::Play:
        return std::make_shared<PlayClicked>();
    case ButtonType::Continue:
        return std::make_shared<ContinueClicked>();
    case ButtonType::Quit:
        return std::make_shared<QuitClicked>();
    case ButtonType::Exit:
        return std::make_shared<ExitClicked>();
    default:
        throw std::invalid_argument("Invalid ButtonType");
    }
}

Button::Button(ButtonType type) :
    m_clicked(CreateClickComponent(type)),
    m_type(type)
{
}


void Button::PerformClicked()
{
    //Mouse over Button
    if (this->m_isActive)
    {
        if (Input::GetMousePositionX() > this->m_position.x && Input::GetMousePositionX() < this->m_position.x + 150 &&
            Input::GetMousePositionY() > this->m_position.y + 25 && Input::GetMousePositionY() < this->m_position.y + 75)
        {
            PerformHover();

            if (m_mouseClick->VL_Click()) {
                m_clicked->Clicked();
            }
        }
        else {
            PerformVisible();
        }
    }

}

void Button::PerformVisible()
{
    switch (m_type) {
    case ButtonType::Play:
        this->m_textureName = "button_play.png";
        break;
    case ButtonType::Continue:
        this->m_textureName = "button_continue.png";
        break;
    case ButtonType::Quit:
        this->m_textureName = "button_quit.png";
        break;
    case ButtonType::Exit:
        this->m_textureName = "button_exit.png";
        break;
    default:
        this->m_textureName = "button_basic.png";
        break;
    }
}

void Button::PerformHover()
{
    switch (m_type) {
    case ButtonType::Play:
        this->m_textureName = "button_play_hover.png";
        break;
    case ButtonType::Continue:
        this->m_textureName = "button_continue_hover.png";
        break;
    case ButtonType::Quit:
        this->m_textureName = "button_quit_hover.png";
        break;
    case ButtonType::Exit:
        this->m_textureName = "button_exit_hover.png";
        break;
    default:
        this->m_textureName = "button_basic.png";
        break;
    }
}

void Button::Update()
{
    PerformClicked();
}

void Button::OnStart()
{
    Input::GetKey(VK_LBUTTON)->Attach(m_mouseClick);

    PerformVisible();
    //SetActive(true);
    SetIsAlive(true);
    
    this->m_shouldRender = true;
    this->m_textureName = "button_basic.png";
    this->m_layerFloat = 0.9;
    this->m_scaleFloat = 1.0;
}
