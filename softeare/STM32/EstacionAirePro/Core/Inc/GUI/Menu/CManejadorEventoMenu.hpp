/*
 * CManejadorEventoMenu.hpp
 *
 *  Created on: Sep 20, 2024
 *      Author: W10
 */

#ifndef INC_GUI_MENU_CMANEJADOREVENTOMENU_HPP_
#define INC_GUI_MENU_CMANEJADOREVENTOMENU_HPP_

class CManejadorEventoMenu
{
public:
	CManejadorEventoMenu();
	virtual ~CManejadorEventoMenu();
	virtual void OnMenuEvent(int identificador);
};

#endif /* INC_GUI_MENU_CMANEJADOREVENTOMENU_HPP_ */
