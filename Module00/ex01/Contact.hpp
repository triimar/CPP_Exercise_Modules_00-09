/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:31 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/31 17:48:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>


class	Contact {

private:
	std::string _FirstName;
	std::string _LastName;
	std::string	_Nickname;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	

public:
	Contact();
	~Contact();
	
	void		setFirstName(std::string input);
	void		setLastName(std::string input);
	void		setNickname(std::string input);
	void		setPhoneNumber(std::string input);
	void		setDarkestSecret(std::string input);
	
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif